
#define WRAP_HEAD(PP,CC) int \
  instruction_wrapper_6k ##PP ##_ ##CC \
  (class cl_uc *uc, t_mem code)

#if defined(WRAPPER_SOURCE)

#  define GEN(PP,CC) WRAP_HEAD(PP,CC) \
  { \
    return ((class cl_r6k *)uc)->instruction_6k ##PP ##_ ##CC (code); \
  }

#elif defined(WRAPPER_HEADER)

#  define GEN(PP,CC) extern WRAP_HEAD(PP,CC);

#elif defined(WRAPPER_FILLER)

#  define GEN(PP,CC) itab_ ##PP [0x ##CC ]= instruction_wrapper_6k ##PP ##_ ##CC ;

#endif

GEN(11,43)
GEN(11,44)
GEN(11,4b)
GEN(11,53)
GEN(11,59)
GEN(11,69)
GEN(11,80)
GEN(11,88)
GEN(11,90)

GEN(ed,5c)
GEN(ed,86)
GEN(ed,87)
GEN(ed,96)
GEN(ed,97)
GEN(ed,9a)
GEN(ed,9b)
GEN(ed,9c)
GEN(ed,a6)
GEN(ed,a7)
GEN(ed,b6)
GEN(ed,b7)
GEN(ed,c7)
GEN(ed,ce)
GEN(ed,cf)
GEN(ed,d7)
GEN(ed,de)
GEN(ed,df)
GEN(ed,e2)
GEN(ed,e3)
GEN(ed,e4)
GEN(ed,ef)
GEN(ed,f2)
GEN(ed,f3)
GEN(ed,f4)
GEN(ed,f7)
GEN(ed,ff)

GEN(dd,32)
GEN(dd,80)
GEN(dd,81)
GEN(dd,82)
GEN(dd,83)
GEN(dd,90)
GEN(dd,91)
GEN(dd,92)
GEN(dd,93)
GEN(dd,a0)
GEN(dd,a1)
GEN(dd,a2)
GEN(dd,a3)
GEN(dd,b0)
GEN(dd,b1)
GEN(dd,b2)
GEN(dd,b3)
GEN(dd,c5)

GEN(49,8a)
GEN(49,9a)

#undef WRAP_HEAD
#undef GEN
