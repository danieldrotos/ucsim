# uCsim s51.src/clean.mk

# Deleting all files created by building the program
# --------------------------------------------------
clean:
	rm -f *core *[%~] *.[oa]
	rm -f test_*.??* '(null).cdb' *.lnk *.ihx
	rm -f .[a-z]*~
	rm -f s51 s51.exe
	rm -f ucsim_51 ucsim_51.exe ucsim_i8051
ifneq ($(shell test -f test/Makefile && echo ok), )
	$(MAKE) -C test -f clean.mk clean
endif


# Deleting all files created by configuring or building the program
# -----------------------------------------------------------------
distclean: clean
	rm -f config.cache config.log config.status
	rm -f Makefile *.dep
	rm -f test/Makefile


# Like clean but some files may still exist
# -----------------------------------------
mostlyclean: clean


# Deleting everything that can reconstructed by this Makefile. It deletes
# everything deleted by distclean plus files created by bison, etc.
# -----------------------------------------------------------------------
realclean: distclean

# End of s51.src/clean.mk
