STARTYEAR	= 1997

SHELL		= /bin/sh
CXX		= @CXX@
#CPP		= @CPP@
CXXCPP		= @CXXCPP@
RANLIB		= @RANLIB@
INSTALL		= @INSTALL@
STRIP		= @STRIP@
MAKEDEP         = @MAKEDEP@
AR		= @AR@

top_builddir	= @top_builddir@
top_srcdir	= @top_srcdir@
UTLDIR		= utils.src
SIMDIR		= sim.src
CMDDIR		= cmd.src
GUIDIR		= gui.src

PICOPT		= @PICOPT@
CPPFLAGS        = @CPPFLAGS@ \
		  -I. -I$(srcdir) \
                  -I$(top_srcdir)/$(UTLDIR) \
                  -I$(top_srcdir)/$(SIMDIR) \
		  -I$(top_srcdir)/$(CMDDIR) \
		  -I$(top_srcdir)/$(GUIDIR)
CFLAGS          = @WALL_FLAG@ @CFLAGS@ -O$(OPT)
CXXFLAGS        = @WALL_FLAG@ @CXXFLAGS@ -O$(OPT) $(PICOPT)
LDFLAGS		= @LDFLAGS@

WINSOCK_AVAIL   = @WINSOCK_AVAIL@
LDFLAGS		= @LDFLAGS@

EXEEXT		= @EXEEXT@
UCSIM_LIBS	= -L$(top_builddir) -lsim -lucsimutil -lguiucsim -lcmd -lsim

prefix          = @prefix@
exec_prefix     = @exec_prefix@
bindir          = @bindir@
libdir          = @libdir@
datadir         = @datadir@
datarootdir     = @datarootdir@
includedir      = @includedir@
mandir          = @mandir@
man1dir         = $(mandir)/man1
man2dir         = $(mandir)/man2
infodir         = @infodir@

SOURCES		= $(patsubst %.o,%.cc,$(OBJECTS))

.cc.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $< -o $@
