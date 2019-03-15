#
# Makefile targets to remake configuration
#

freshconf: Makefile

Makefile: $(srcdir)/Makefile.in $(top_srcdir)/configure.ac
	cd $(top_builddir) && $(SHELL) ./config.status

# End of pdk.src/conf.mk
#
# Makefile targets to remake configuration
#

freshconf: main.mk ddconfig.h

main.mk: $(srcdir)/main_in.mk config.status
	$(SHELL) ./config.status

ddconfig.h: ddconfig_in.h config.status
	@echo "Re-making ddconfig.h"
	$(SHELL) ./config.status
	touch ddconfig.h

# End of conf.mk
