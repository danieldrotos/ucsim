all:
	$(MAKE) -C src all

clean:
	$(MAKE) -C src -f clean.mk clean

distclean:
	$(MAKE) -C src -f clean.mk distclean
