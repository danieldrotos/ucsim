# i8085.src/clean.mk

srcdir		= .

# Deleting all files created by building the program
# --------------------------------------------------
clean:
	rm -f *core *[%~] *.[oa] *.map
	rm -f .[a-z]*~
	rm -f si8085$(EXEEXT) si8085.exe
	rm -f smcs6502$(EXEEXT) smcs6502.exe
	rm -f ucsim_i8085$(EXEEXT) ucsim_i8085.exe
ifneq ($(shell test -f test/Makefile && echo ok), )
	$(MAKE) -C test -f clean.mk clean
endif


# Deleting all files created by configuring or building the program
# -----------------------------------------------------------------
distclean: clean
	rm -f config.cache config.log config.status
	rm -f Makefile *.dep
	rm -f *.obj *.list *.lst *.hex
	rm -f test/Makefile


# Like clean but some files may still exist
# -----------------------------------------
mostlyclean: clean


# Deleting everything that can reconstructed by this Makefile. It deletes
# everything deleted by distclean plus files created by bison, etc.
# -----------------------------------------------------------------------
realclean: distclean

# End of i8085.src/clean.mk
