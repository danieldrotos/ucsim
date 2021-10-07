
#define GEN_WRAPPER(PAGE,CODE,INST,ADDR_MODE) int wrap_ ##PAGE ##_ ##CODE(class CL12 *uc, t_mem code) { return uc-> INST ( ADDR_MODE , code); }

#define GEN_DECL(PAGE,CODE) extern int wrap_ ## PAGE ## _ ## CODE (class CL12 *uc, t_mem code);

#define GEN_FILLER_METHOD(PAGE,CODE) virtual void fill_##PAGE ##_##CODE() { page##PAGE[0x## CODE ]= wrap_ ##PAGE ##_ ##CODE; }


#define DEC(PAGE,CODE,INST,ADDR_MODE)	"NL"\
GEN_WRAPPER(PAGE,CODE,INST,ADDR_MODE)   "NL"\
GEN_DECL(PAGE,CODE)			"NL"\
GEN_FILLER_METHOD(PAGE,CODE)

DEC(0, 00,	proba	,_II)
DEC(0, 01,	prob1	,_II)

