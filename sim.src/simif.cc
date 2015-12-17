/*@1@*/

#include <stdlib.h>
#include "i_string.h"

// sim
#include "simifcl.h"


/* Interface command */

cl_sif_command::cl_sif_command(enum sif_command cmd,
			       const char *the_name,
			       const char *the_description,
			       enum sif_answer_type the_answer_type,
			       int the_params_needed,
			       class cl_simulator_interface *the_sif):
  cl_base()
{
  command= cmd;
  set_name(the_name);
  description= strdup(the_description);
  answer_type= the_answer_type;
  sif= the_sif;
  parameters= 0;
  answer= 0;
  params_needed= the_params_needed;
  nuof_params= params_received= 0;
  answer_length= answered_bytes= 0;
  answering= DD_FALSE;
}

cl_sif_command::~cl_sif_command(void)
{
  if (description)
    free(description);
  clear_params();
  clear_answer();
}

int
cl_sif_command::init(void)
{
  clear_params();
  clear_answer();
  return(0);
}

void
cl_sif_command::clear_params(void)
{
  nuof_params= 0;
  params_received= 0;
  if (parameters)
    free(parameters);
}

void
cl_sif_command::clear_answer(void)
{
  answer_length= 0;
  answered_bytes= 0;
  if (answer)
    free(answer);
}

void
cl_sif_command::clear(void)
{
  clear_params();
  clear_answer();
}


bool
cl_sif_command::get_parameter(int nr, t_mem *into)
{
  if (!parameters ||
      nr >= nuof_params)
    return(DD_FALSE);
  if (into)
    *into= parameters[nr];
  return(DD_TRUE);
}


t_mem
cl_sif_command::read(class cl_memory_cell *cel)
{
  t_mem ret= cel->get();

  printf("%s read: (%x)\n", get_name(), ret);
  if (answering &&
      answer)
    {
      printf("answering...\n");
      if (answered_bytes < answer_length)
	{
	  ret= answer[answered_bytes];
	  answered_bytes++;
	  printf("answer=%x\n", ret);
	}
      if (answered_bytes >= answer_length)
	{
	  printf("finishing command...\n");
	  sif->finish_command();
	}
    }
  return(ret);
}

void
cl_sif_command::write(class cl_memory_cell *cel, t_mem *val)
{
  printf("%s write: 0x%x %d of %d at %p\n", get_name(), *val,
	 params_received, nuof_params, parameters);
  if (nuof_params &&
      params_received < nuof_params &&
      parameters)
    {
      printf("storing param 0x%x at %d\n",*val,params_received);
      parameters[params_received]= *val;
      params_received++;
      if (params_received >= nuof_params)
	{
	  printf("got all params, prod ans\n");
	  produce_answer();
	  printf("ans produced, start answering\n");
	  start_answer();
	}
    }
  else
    printf("%s write: do nothing\n", get_name());
}


void
cl_sif_command::start(void)
{
  printf("Command %d (%s) started\n", command, get_name());
  need_params(params_needed);
}

void
cl_sif_command::need_params(int nr)
{
  clear_params();
  if (nr <= 0)
    {
      produce_answer();
      start_answer();
    }
  nuof_params= nr;
  params_received= 0;
  parameters= (t_mem *)calloc(nr, sizeof(t_mem));
}

void
cl_sif_command::produce_answer(void)
{
  clear_answer();
  //produce_answer("ABC");
}

void
cl_sif_command::set_answer(t_mem ans)
{
  clear_answer();
  answer= (t_mem *)calloc(1, sizeof(t_mem));
  answer[0]= ans;
  answer_length= 1;
}

void
cl_sif_command::set_answer(int nr, t_mem ans[])
{
  clear_answer();
  answer= (t_mem *)calloc(nr+1, sizeof(t_mem));
  answer[0]= nr;
  int i;
  for (i= 0; i < nr; i++)
    answer[i+1]= ans[i];
  answer_length= nr+1;
}

void
cl_sif_command::set_answer(const char *ans)
{
  clear_answer();
  if (ans &&
      *ans)
    {
      answer= (t_mem *)calloc(strlen(ans)+2, sizeof(char));
      int i= 0;
      answer[0]= strlen(ans);
      while (ans[i])
	{
	  answer[i+1]= ans[i];
	  i++;
	}
      answer[i+1]= '\0';
      answer_length= i+2;
    }
}

void
cl_sif_command::start_answer(void)
{
  if (answer_length)
    answering= DD_TRUE;
  else
    {
      answering= DD_FALSE;
      sif->finish_command();
    }
}


/* Command: get info about commands */

void
cl_sif_commands::produce_answer(void)
{
  int c, i;
  if (!sif)
    return;
  c= sif->commands->count;
  answer= (t_mem*)calloc(c+1, sizeof(t_mem));
  answer[0]= c;
  for (i= 0; i < c; i++)
    {
      answer[i+1]= 0;
      class cl_sif_command *sc=
	dynamic_cast<class cl_sif_command *>(sif->commands->object_at(i));
      if (!sc)
	continue;
      answer[i+1]= sc->get_command();
    }
  answer_length= c+1;
}


/* Command: get info about a command */

void
cl_sif_cmdinfo::produce_answer(void)
{
  int i;
  if (!sif)
    return;
  t_mem cm;
  if (!get_parameter(0, &cm))
    return;
  answer= (t_mem*)calloc(1+2, sizeof(t_mem));
  answer[0]= 2;
  class cl_sif_command *about= 0;
  for (i= 0; i < sif->commands->count; i++)
    {
      class cl_sif_command *sc=
	dynamic_cast<class cl_sif_command *>(sif->commands->object_at(i));
      if (sc->get_command() == cm)
	{
	  about= sc;
	  break;
	}
    }
  //if (about != this) about->start();
  if (about)
    {
      answer[1]= about->get_params_needed();
      answer[2]= about->get_answer_type();
    }
  //if (about != this) clear_params();
  answer_length= 3;
}


/*
 * Virtual HW: simulator interface
 */

cl_simulator_interface::cl_simulator_interface(class cl_uc *auc,
					       const char *the_as_name,
					       t_addr the_addr):
  cl_hw(auc, HW_SIMIF, 0, "simif")
{
  version= 1;
  as_name= strdup(the_as_name);
  addr= the_addr;
  commands= new cl_list(2, 2, "sif_commands");
  active_command= 0;
}

cl_simulator_interface::~cl_simulator_interface(void)
{
  if (as_name)
    free((void*)as_name);
  delete commands;
}

int
cl_simulator_interface::init(void)
{
  as= uc->address_space(as_name);
  if (as)
    {
      address= addr;
      if (addr < 0)
	address= as->highest_valid_address();
      register_cell(as, address, &cell, wtd_restore_write);
    }
  class cl_sif_command *c;
  commands->add(c= new cl_sif_commands(this));
  c->init();
  commands->add(c= new cl_sif_ifver(this));
  c->init();
  commands->add(c= new cl_sif_simver(this));
  c->init();
  commands->add(c= new cl_sif_ifreset(this));
  c->init();
  commands->add(c= new cl_sif_cmdinfo(this));
  c->init();
  return(0);
}


void
cl_simulator_interface::set_cmd(class cl_cmdline *cmdline,
				class cl_console_base *con)
{
  class cl_cmd_arg *params[2]= {
    cmdline->param(0),
    cmdline->param(1)
  };

  if (cmdline->syntax_match(uc, MEMORY ADDRESS))
    {
      class cl_memory *mem= params[0]->value.memory.memory;
      t_addr a= params[1]->value.address;
      if (!mem->is_address_space())
	{
	  con->dd_printf("%s is not an address space\n");
	  return;
	}
      if (!mem->valid_address(a))
	{
	  con->dd_printf("Address must be between 0x%x and 0x%x\n",
			 mem->lowest_valid_address(),
			 mem->highest_valid_address());
	  return;
	}
      as_name= (char*)mem->get_name();
      addr= a;
      if ((as= dynamic_cast<class cl_address_space *>(mem)) != 0)
	{
	  address= addr;
	  if (addr < 0)
	    address= as->highest_valid_address();
	  register_cell(as, address, &cell, wtd_restore_write);
	}
    }
  else
    {
      con->dd_printf("set hardware simif memory address\n");
    }
}


t_mem
cl_simulator_interface::read(class cl_memory_cell *cel)
{
  printf("simif read: ");
  if (!active_command)
    {
      t_mem d= cel->get();
      printf("no-active, cel=0x%02x\n", d);
      return(~d & cel->get_mask());
    }
  else
    {
      printf("active=%s\n",active_command->get_name());
      t_mem ret= active_command->read(cel);
      if (active_command)
	printf("active got 0x%02x (cel=0x%02x)\n", ret, cel->get());
      return(ret);
    }
  return(cel->get());
}

void
cl_simulator_interface::write(class cl_memory_cell *cel, t_mem *val)
{
  printf("simif write %d 0x%x\n",*val,*val);
  if (!active_command)
    {
      printf("No active command, look for %d\n", *val);
      int i;
      for (i= 0; i < commands->count; i++)
	{
	  class cl_sif_command *c=
	    dynamic_cast<class cl_sif_command *>(commands->object_at(i));
	  if (!c)
	    continue;
	  enum sif_command cm= c->get_command();
	  //printf("Checking %s %d<->%d\n", c->get_name(), cm, *val);
	  if (*val == cm)
	    {
	      printf("Command %s activated\n", c->get_name());
	      active_command= c;
	      c->start();
	      printf("needs %d params\n", c->get_nuof_params());
	      return;
	    }
	}
      printf("command 0x%x not found, just store\n", *val);
    }
  else
    {
      printf("write passing to %s\n",active_command->get_name());
      active_command->write(cel, val);
    }
}


void
cl_simulator_interface::finish_command(void)
{
  if (active_command)
    {
      printf("Command %s finished\n", active_command->get_name());
      active_command->clear_answer();
    }
  else
    printf("Command (non-active) finished\n");
  active_command= 0;
}


void
cl_simulator_interface::print_info(class cl_console_base *con)
{
  con->dd_printf("uCsim simulator interface, version %d, ", version);
  con->dd_printf("at %s[", as_name);
  if (as)
    con->dd_printf(as->addr_format, address);
  else
    con->dd_printf("0x%x", address);
  con->dd_printf("]\n");
  
  con->dd_printf("Active command: ");
  if (!active_command)
    con->dd_printf("none.\n");
  else
    {
      class cl_sif_command *c= active_command;
      con->dd_printf("0x%02x %s %s\n", c->get_command(),
		     c->get_name(), c->get_description());
      con->dd_printf("Parameters received %d bytes of %d\n",
		     c->get_params_received(), c->get_nuof_params());
      if (c->get_nuof_params())
	{
	  con->dd_printf(" ");
	  int i;
	  for (i= 0; i < c->get_nuof_params(); i++)
	    {
	      t_mem p;
	      if (c->get_parameter(i, &p))
		con->dd_printf(" %02x", p);
	      else
		con->dd_printf(" --");
	    }
	  con->dd_printf("\n");
	}
      con->dd_printf("Answered %d bytes of %d\n",
		     c->get_answered_bytes(), c->get_answer_length());
      con->dd_printf("Answering: %s\n", (c->get_answering())?"yes":"no");
    }
  
  int i;
  con->dd_printf("Known commands:\n");
  for (i= 0; i < commands->count; i++)
    {
      class cl_sif_command *c=
	dynamic_cast<class cl_sif_command *>(commands->object_at(i));
      if (!c)
	continue;
      con->dd_printf("0x%02x %s %s\n", c->get_command(),
		     c->get_name(), c->get_description());
    }
}


/* End of sim.src/simif.cc */
