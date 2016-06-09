/*@1@*/

#ifndef TLCSCL_HEADER
#define TLCSCL_HEADER

// sim.src
#include "uccl.h"
#include "memcl.h"


enum {
  FLAG_S= 0x80,
  FLAG_Z= 0x40,
  FLAG_I= 0x20,
  FLAG_H= 0x10,
  FLAG_X= 0x08,
  FLAG_V= 0x04,
  FLAG_N= 0x02,
  FLAG_C= 0x01
};

/*
 * Base type of TLCS microcontrollers
 */

class cl_tlcs: public cl_uc
{
 protected:
  struct {
    union {
      uint16_t af;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t a;
	uint8_t f;
#else
	uint8_t f;
	uint8_t a;
#endif
      };
    };
    union {
      uint16_t bc;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t b;
	uint8_t c;
#else
	uint8_t c;
	uint8_t b;
#endif
      };
    };
    union {
      uint16_t de;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t d;
	uint8_t e;
#else
	uint8_t e;
	uint8_t d;
#endif
      };
    };
    union {
      uint16_t hl;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t h;
	uint8_t l;
#else
	uint8_t l;
	uint8_t h;
#endif
      };
    };
    uint16_t ix;
    uint16_t iy;
    uint16_t sp;
    uint8_t dummy;
    uint16_t dummy16;
    union {
      uint16_t alt_af;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t alt_a;
	uint8_t alt_f;
#else
	uint8_t alt_f;
	uint8_t alt_a;
#endif
      };
    };
    union {
      uint16_t alt_bc;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t alt_b;
	uint8_t alt_c;
#else
	uint8_t alt_c;
	uint8_t alt_b;
#endif
      };
    };
    union {
      uint16_t alt_de;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t alt_d;
	uint8_t alt_e;
#else
	uint8_t alt_e;
	uint8_t alt_d;
#endif
      };
    };
    union {
      uint16_t alt_hl;
      struct {
#ifdef WORDS_BIGENDIAN
	uint8_t alt_h;
	uint8_t alt_l;
#else
	uint8_t alt_l;
	uint8_t alt_h;
#endif
      };
    };
  } reg;

 public:
  class cl_address_space *nas;
  class cl_address_space *das;
 public:
  cl_tlcs(class cl_sim *asim);
  virtual int init(void);
  virtual char *id_string(void);

  //virtual t_addr get_mem_size(enum mem_class type);
  //virtual int get_mem_width(enum mem_class type);
  virtual void mk_hw_elements(void);
  virtual void make_memories(void);

  virtual struct dis_entry *dis_tbl(void);
  //virtual struct name_entry *sfr_tbl(void);
  //virtual struct name_entry *bit_tbl(void);
  virtual const char *regname_r(uint8_t r);
  virtual const char *regname_Q(uint8_t Q);
  virtual const char *regname_R(uint8_t R);
  virtual const char *disass(t_addr addr, const char *sep);
  virtual void print_regs(class cl_console_base *con);

  virtual int exec_inst(void);
  virtual t_addr do_push(t_mem data);
  virtual t_addr do_pop(t_mem *data);
  virtual int exec_push(t_addr PC_of_inst, t_mem data);
  virtual int exec_ret(t_addr PC_of_inst, t_mem *data);
  virtual int exec_reti(t_addr PC_of_inst, t_mem *data);
  virtual int exec_pop(t_addr PC_of_inst, t_mem *data);
  virtual int exec_intr(t_addr PC_of_inst, t_addr called, t_mem data);
  virtual void set_p(uint8_t data);
  virtual uint8_t *aof_reg8(uint8_t data_r);
  virtual uint16_t *aof_reg16_rr(uint8_t data_rr);
  virtual uint16_t *aof_reg16_qq(uint8_t data_qq);
  
  // block
  virtual int ex_de_hl();		// 08
  virtual int ex_af_alt_af();		// 09
  virtual int exx();			// 0a

  // cpu control and others
  virtual int daa_a();			// 0b
  virtual int cpl_a();			// 10
  virtual int neg_a();			// 11
  virtual int ccf();			// 0e
  virtual int scf();			// 0d
  virtual int rcf();			// 0c
  //virtual int nop();			// 00
  //virtual int halt();			// 01
  //virtual int di();			// 02
  //virtual int ei();			// 03
  virtual int swi();			// ff
  virtual uint8_t rlc(uint8_t data, bool set_sz);	// RLC
  virtual uint8_t rrc(uint8_t data, bool set_sz);	// RRC
  virtual uint8_t rl(uint8_t data, bool set_sz);	// RL
  virtual uint8_t rr(uint8_t data, bool set_sz);	// RL
  virtual uint8_t sla(uint8_t data, bool set_sz);	// SLA
  virtual uint8_t sra(uint8_t data, bool set_sz);	// SRA
  virtual uint8_t srl(uint8_t data, bool set_sz);	// SRL
  virtual int ret();			// 1e
  virtual int reti();			// 1f
  virtual uint8_t inc(uint8_t data);			// INC 8 bit
  virtual uint8_t dec(uint8_t data);			// DEC 8 bit
  virtual uint16_t inc16(uint16_t data);		// INC 16 bit
  virtual uint16_t dec16(uint16_t data);		// DEC 16 bit

  virtual int pop(t_mem c1);		// 58+qq
};


#endif

/* End of tlcs.src/tlcscl.h */
