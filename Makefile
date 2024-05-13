all:
	$(MAKE) -C src all

clean: local_clean sub_clean

local_clean:
	rm -f *~ lib*.a
	rm -rf autom4te.cache

sub_clean:
	$(MAKE) -C src  -f clean.mk clean
	$(MAKE) -C docs -f clean.mk clean

distclean: local_distclean sub_distclean

local_distclean: local_clean
	rm -f config.log config.status

sub_distclean:
	$(MAKE) -C src  -f clean.mk distclean
	$(MAKE) -C docs -f clean.mk distclean
