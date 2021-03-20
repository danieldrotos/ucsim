# stm8.src/test/Makefile.  Generated from Makefile.in by configure.

srcdir           = .

abs_top_builddir = /mhome/staff/drdani/prj/ucsim/main
abs_top_srcdir   = /mhome/staff/drdani/prj/ucsim/main


include $(abs_top_srcdir)/test-target.mk


# The old *.mk tests here work slightly differently to those for all the
# other simulators so we can't just use the test-target.mk default rules.

PROJECTS	= s0 s1 s2 s3 t1 t2 t3 t4 $(TESTS_OLD)

.PHONY: $(PROJECTS)

all_old:: $(PROJECTS)

$(PROJECTS):
	@$(MAKE) --no-print-directory MAIN=$@ srcdir='$(srcdir)' -f '$(srcdir)'/sdcc.mk

clean_old::
	@for p in $(PROJECTS); do \
		$(MAKE) --no-print-directory MAIN=$$p srcdir='$(srcdir)' -f '$(srcdir)'/sdcc.mk clean ;\
		rm -rf $$p*.hex ;\
		rm -rf $$p*.cdb ;\
	done
