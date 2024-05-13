#
# uCsim p1516.src/Makefile
#
# (c) Drotos Daniel, Talker Bt. 1997
#

# tool name
PKG		= p1516

include ../../common.mk

srcdir          = @srcdir@
VPATH           = @srcdir@

top_builddir	= @top_builddir@
top_srcdir	= @top_srcdir@

LOCAL_LIB_PREREQU	=
LOCAL_LIB_OPTIONS	=


# Compiling entire program or any subproject
# ------------------------------------------
all: otherlibs app
	echo TN=$(TN) PKG=$(PKG)

include $(top_srcdir)/src/app.mk

local_install:

local_uninstall:

# Creating dependencies
# ---------------------
dep: Makefile.dep

Makefile.dep: $(srcdir)/*.cc $(srcdir)/*.h objs.mk
	$(MAKEDEP) $(CPPFLAGS) $(filter %.cc,$^) >Makefile.dep

-include Makefile.dep
include $(srcdir)/clean.mk


# End of p1516.src/Makefile.in
