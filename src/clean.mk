all: clean

clean: local_clean sub_clean

local_clean:

sub_clean:
	$(MAKE) -C core -f clean.mk clean
	$(MAKE) -C sims -f clean.mk clean
	$(MAKE) -C apps -f clean.mk clean

distclean: local_distclean sub_distclean

local_distclean: local_clean

sub_distclean:
	$(MAKE) -C core -f clean.mk distclean
	$(MAKE) -C sims -f clean.mk distclean
	$(MAKE) -C apps -f clean.mk distclean
