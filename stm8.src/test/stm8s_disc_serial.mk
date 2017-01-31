MAIN		= stm8s_disc_serial

OTHERS		= serial

include sdcc.mk

CPPFLAGS	= -DDEVICE=DEV_STM8S105 -DUSART=USART2 -DUSART_RX_IRQ=21
