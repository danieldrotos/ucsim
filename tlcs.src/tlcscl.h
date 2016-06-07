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

  //virtual struct dis_entry *dis_tbl(void);
  //virtual struct name_entry *sfr_tbl(void);
  //virtual struct name_entry *bit_tbl(void);
  //virtual const char *disass(t_addr addr, const char *sep);
  virtual void print_regs(class cl_console_base *con);

  //virtual int exec_inst(void);
};


#endif

/* End of tlcs.src/tlcscl.h */
