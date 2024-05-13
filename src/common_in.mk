TN		= $(PKG)

STARTYEAR	= 1997

SHELL		= /bin/sh
CXX		= @CXX@
CXXCPP		= @CXXCPP@
RANLIB		= @RANLIB@
INSTALL		= @INSTALL@
STRIP		= @STRIP@
MAKEDEP         = @MAKEDEP@
AR		= @AR@
LEX		= @LEX@
YACC		= @YACC@

UTLDIR		= src/core/utils.src
SIMDIR		= src/core/sim.src
CMDDIR		= src/core/cmd.src
GUIDIR		= src/core/gui.src
MOTDIR		= src/core/motorola.src

PICOPT		= @PICOPT@
CPPFLAGS        = @CPPFLAGS@ \
		  -I. -I$(srcdir) \
                  -I$(top_srcdir)/$(UTLDIR) \
                  -I$(top_srcdir)/$(SIMDIR) \
		  -I$(top_srcdir)/$(CMDDIR) \
		  -I$(top_srcdir)/$(GUIDIR)
OPT		?= 2
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

curses_ok	= @curses_ok@

ALL_OBJECTS	= $(OBJECTS) $(LOCAL_OBJECTS)
SOURCES		= $(patsubst %.o,%.cc,$(ALL_OBJECTS))

.cc.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $< -o $@

.l.cc:
	rm -f $@
	$(LEX) -t $< > $@

.y.cc:
	$(YACC) -d $<
	mv y.tab.c $*.cc
	mv y.tab.h $*.hh
