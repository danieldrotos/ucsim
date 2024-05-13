# Deleting all files created by building the program
# --------------------------------------------------
clean:
	rm -f *core *[%~] *.[oa]
	rm -f .[a-z]*~
	rm -f shc08 shc08.exe ucsim_hc08 ucsim_hc08.exe
	rm -f sm68hc08 sm68hc08.exe ucsim_m68hc08 ucsim_m68hc08.exe
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

# End of m68hc08.src/clean.mk
