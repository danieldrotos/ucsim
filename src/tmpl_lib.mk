#
# uCsim utils.src/Makefile
#
# (c) 1997 Drotos Daniel
#

PKG		= ucsimutil

include ../../common.mk

srcdir          = @srcdir@
VPATH           = @srcdir@

top_builddir	= @top_builddir@
top_srcdir	= @top_srcdir@


# Compiling entire program or any subproject
# ------------------------------------------
all: libs

include $(top_srcdir)/src/lib.mk


# Performing self-test
# --------------------
check:

test:

baseline:


# End of utils.src/Makefile
