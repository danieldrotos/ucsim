MAIN		= stm8s_disc_monitor

OTHERS		= serial flash

include sdcc.mk

CPPFLAGS	= -DDEVICE=DEV_STM8S105
