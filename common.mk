#
# uCsim common.mk
#
# (c) 2024, Drotos Daniel, Talker Bt.
#

SILENT		= yes
OPT		= -O2

.cc.o:
ifeq ($(SILENT),yes)
	@echo "CXX $(TN)-$<"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $< -o $@ 	>>$(top_srcdir)/compile.log 2>&1
else
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $< -o $@
endif


.l.cc:
ifeq ($(SILENT),yes)
	@echo LEX $TN-$<
	@rm -f $@ 		>>$(top_srcdir)/compile.log 2>&1
	@$(LEX) -t $< > $@ 	>>$(top_srcdir)/compile.log 2>&1
else
	rm -f $@
	$(LEX) -t $< > $@
endif


# End of common.mk
