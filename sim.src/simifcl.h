/*@1@*/

#ifndef SIMIFCL_HEADER
#define SIMIFCL_HEADER

#include "uccl.h"


#define SIMIF_VERSION	1

enum sif_command {
  SIFCM_COMMANDS	= 0x01,	// get info about commands
  SIFCM_IFVER		= 0x02,	// interface version
  SIFCM_SIMVER		= 0x03, // simulator version
  SIFCM_IFRESET		= 0x04,	// reset the interface
  SIFCM_CMDINFO		= 0x05	// info about a command
};

enum sif_answer_type {
  SIFAT_UNKNOWN		= 0x00,	// we don't know...
  SIFAT_BYTE		= 0x01,	// just a byte
  SIFAT_ARRAY		= 0x02,	// array of some bytes
  SIFAT_STRING		= 0x03,	// a string
  SIFAT_NONE		= 0x04	// no answer at all
};

class cl_simulator_interface;

/* Base of commands */

class cl_sif_command: public cl_base
{
protected:
  enum sif_command command;
  char *description;
  enum sif_answer_type answer_type;
  class cl_simulator_interface *sif;
  t_mem *parameters;
  int params_needed, nuof_params, params_received;
  t_mem *answer;
  int answer_length, answered_bytes;
  bool answering;
public:
  cl_sif_command(enum sif_command cmd,
		 const char *the_name,
		 const char *the_description,
		 enum sif_answer_type the_answer_type,
		 int the_params_needed,
		 class cl_simulator_interface *the_sif);
  virtual ~cl_sif_command(void);
  virtual int init(void);
  virtual void clear_params(void);
  virtual void clear_answer(void);
  virtual void clear(void);

  enum sif_command get_command(void) { return(command); }
  char *get_description(void) { return(description); }
  int get_nuof_params(void) { return(nuof_params); }
  int get_params_received(void) { return(params_received); }
  int get_answer_length(void) { return(answer_length); }
  int get_answered_bytes(void) { return(answered_bytes); }
  bool get_answering(void) { return(answering); }
  enum sif_answer_type get_answer_type(void) { return(answer_type); }
  int get_params_needed(void) { return(params_needed); }
  bool get_parameter(int nr, t_mem *into);

  virtual t_mem read(class cl_memory_cell *cel);
  virtual void write(class cl_memory_cell *cel, t_mem *val);

  virtual void start(void);
  virtual void produce_answer(void);

private:
  virtual void need_params(int nr);
public:
  virtual void set_answer(t_mem ans);
  virtual void set_answer(int nr, t_mem ans[]);
  virtual void set_answer(const char *ans);
  virtual void start_answer(void);
};

/* Command: interface version */
class cl_sif_ifver: public cl_sif_command
{
public:
  cl_sif_ifver(class cl_simulator_interface *the_sif):
    cl_sif_command(SIFCM_IFVER, "if_ver",
		   "Get version of simulator interface",
		   SIFAT_BYTE, 0, the_sif)
  {}
  virtual void produce_answer(void) { set_answer(t_mem(SIMIF_VERSION)); }
};

/* Command: simulator version */
class cl_sif_simver: public cl_sif_command
{
public:
  cl_sif_simver(class cl_simulator_interface *the_sif):
    cl_sif_command(SIFCM_SIMVER, "sim_ver",
		   "Get version of simulator",
		   SIFAT_STRING, 0, the_sif)
  {}
  virtual void produce_answer(void) { set_answer(VERSIONSTR); }
};

/* Command: reset interface */
class cl_sif_ifreset: public cl_sif_command
{
public:
  cl_sif_ifreset(class cl_simulator_interface *the_sif):
    cl_sif_command(SIFCM_IFRESET, "if_reset",
		   "Reset interface to default state",
		   SIFAT_NONE, 0, the_sif)
  {}
};

/* Command: get info about commands */
class cl_sif_commands: public cl_sif_command
{
public:
  cl_sif_commands(class cl_simulator_interface *the_sif):
    cl_sif_command(SIFCM_COMMANDS, "commands",
		   "Get information about known commands",
		   SIFAT_ARRAY, 0, the_sif)
  {}
  virtual void produce_answer(void);
};

/* Command: get info about a command */
class cl_sif_cmdinfo: public cl_sif_command
{
public:
  cl_sif_cmdinfo(class cl_simulator_interface *the_sif):
    cl_sif_command(SIFCM_CMDINFO, "cmdinfo",
		   "Get information about a command",
		   SIFAT_ARRAY, 1, the_sif)
  {}
  virtual void produce_answer(void);
};


/*
 * Virtual hardware: simulator interface
 */

class cl_simulator_interface: public cl_hw
{
private:
  int version;
  const char *as_name;
  t_addr addr;
  class cl_address_space *as;
  t_addr address;
  class cl_memory_cell *cell;
  class cl_sif_command *active_command;
public:
  class cl_list *commands;
public:
  cl_simulator_interface(class cl_uc *auc, const char *the_as_name, t_addr the_addr);
  virtual ~cl_simulator_interface(void);
  virtual int init(void);

  virtual void set_cmd(class cl_cmdline *cmdline, class cl_console_base *con);
  virtual t_mem read(class cl_memory_cell *cell);
  virtual void write(class cl_memory_cell *cell, t_mem *val);
  
  virtual void finish_command(void);

  virtual void print_info(class cl_console_base *con);
};


#endif
