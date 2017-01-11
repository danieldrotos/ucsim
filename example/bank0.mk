
MAIN		= bank0

OTHERS		= bank1 bank2

include sdcc.mk

TARGET		= -mmcs51

LDFLAGS		= -Wl-bBANK1=0x18000 -Wl-bBANK2=0x28000 --code-size 0x1000000 -Wl-r
