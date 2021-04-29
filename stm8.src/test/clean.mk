clean:

distclean:
	rm -f Makefile
	find . -type d -name out -exec rm -rf {} \;
	rm -rf vcd-in/*.ihx vcd-in/*.lst vcd-in/*.sym
	rm -rf vcd-out/*.ihx vcd-out/*.lst vcd-out/*.sym
<<<<<<< HEAD

=======
>>>>>>> fb49c318b34598e21724763d5e57f753902287fc
