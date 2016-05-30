all: simif.ihx

simif.ihx: simif.c
	sdcc --model-large --debug simif.c

clean:
	rm -f *.asm *.ihx *.lk *.lst *.map *.mem *.rel *.rst *.sym
