# This Makefile is for Dropbear SSH Server and Client
# Makefile.  Generated from Makefile.in by configure.

# invocation:
# make PROGRAMS="dropbear dbclient scp" MULTI=1 STATIC=1 SCPPROGRESS=1
#
# to make a multiple-program statically linked binary "staticdropbearmulti".
# This example will include dropbear, scp, dropbearkey, dropbearconvert, and
# dbclient functionality, and includes the progress-bar functionality in scp.
# Hopefully that seems intuitive.

ifndef PROGRAMS
	PROGRAMS=dropbear dbclient dropbearkey dropbearconvert
endif

LTC=libtomcrypt/libtomcrypt.a
LTM=libtommath/libtommath.a

ifeq (1, 1)
LIBTOM_DEPS=$(LTC) $(LTM)
CFLAGS+=-I$(srcdir)/libtomcrypt/src/headers/ 
LIBS+=$(LTC) $(LTM)
endif

COMMONOBJS=dbutil.o buffer.o \
		dss.o bignum.o \
		signkey.o rsa.o random.o \
		queue.o \
		atomicio.o compat.o  fake-rfc2553.o 

SVROBJS=svr-kex.o svr-auth.o sshpty.o \
		svr-authpasswd.o svr-authpubkey.o svr-authpubkeyoptions.o svr-session.o svr-service.o \
		svr-chansession.o svr-runopts.o svr-agentfwd.o svr-main.o svr-x11fwd.o\
		svr-tcpfwd.o svr-authpam.o

CLIOBJS=cli-main.o cli-auth.o cli-authpasswd.o cli-kex.o \
		cli-session.o cli-runopts.o cli-chansession.o \
		cli-authpubkey.o cli-tcpfwd.o cli-channel.o cli-authinteract.o \
		cli-agentfwd.o list.o

CLISVROBJS=common-session.o packet.o common-algo.o common-kex.o \
			common-channel.o common-chansession.o termcodes.o loginrec.o \
			tcp-accept.o listener.o process-packet.o \
			common-runopts.o circbuffer.o

KEYOBJS=dropbearkey.o gendss.o genrsa.o

CONVERTOBJS=dropbearconvert.o keyimport.o

SCPOBJS=scp.o progressmeter.o atomicio.o scpmisc.o compat.o

HEADERS=options.h dbutil.h session.h packet.h algo.h ssh.h buffer.h kex.h \
		dss.h bignum.h signkey.h rsa.h random.h service.h auth.h \
		debug.h channel.h chansession.h config.h queue.h sshpty.h \
		termcodes.h gendss.h genrsa.h runopts.h includes.h \
		loginrec.h atomicio.h x11fwd.h agentfwd.h tcpfwd.h compat.h \
		listener.h fake-rfc2553.h

dropbearobjs=$(COMMONOBJS) $(CLISVROBJS) $(SVROBJS) -lcrypt 
dbclientobjs=$(COMMONOBJS) $(CLISVROBJS) $(CLIOBJS)
dropbearkeyobjs=$(COMMONOBJS) $(KEYOBJS)
dropbearconvertobjs=$(COMMONOBJS) $(CONVERTOBJS)
scpobjs=$(SCPOBJS)


srcdir=.

prefix=/home/devicenull/ipmi/SDK/output/filesystem
exec_prefix=${prefix}
datarootdir = ${prefix}/share
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin
mandir=${datarootdir}/man

CC=/home/devicenull/ipmi/SDK/ToolChain/Host/HERMON/gcc-3.4.4-glibc-2.3.5-armv4/arm-linux/bin/arm-linux-gcc
AR=/home/devicenull/ipmi/SDK/ToolChain/Host/HERMON/gcc-3.4.4-glibc-2.3.5-armv4/arm-linux/bin/arm-linux-ar
RANLIB=/home/devicenull/ipmi/SDK/ToolChain/Host/HERMON/gcc-3.4.4-glibc-2.3.5-armv4/arm-linux/bin/arm-linux-ranlib
STRIP=/home/devicenull/ipmi/SDK/ToolChain/Host/HERMON/gcc-3.4.4-glibc-2.3.5-armv4/arm-linux/bin/arm-linux-strip
INSTALL=install
CPPFLAGS=-I/home/devicenull/ipmi/SDK/SFCB/zlib-1.2.3/zlib/include
CFLAGS+=-I. -I$(srcdir) $(CPPFLAGS) -Os -W -Wall
LIBS+=-lutil -lz 
LDFLAGS=-L/home/devicenull/ipmi/SDK/src/openssl/openssl/local/lib -L/home/devicenull/ipmi/SDK/lib -L/home/devicenull/ipmi/SDK/FileSystem/clean_filesystem/lib/ -lcrypto -lssl -lcgi -lipmi -lchnl  -lm -lsol  -lutility -lnvram  -lipmicrypt -lcommon -lsys -lrt -luart -lupdate -lnet -lmqueue -lgpio -lxml2 -lldap_client -lradius_client -lwdt -L/home/devicenull/ipmi/SDK/SFCB/zlib-1.2.3/zlib/lib

EXEEXT=

# whether we're building client, server, or both for the common objects.
# evilness so we detect 'dropbear' by itself as a word
space:= $(empty) $(empty)
ifneq (,$(strip $(foreach prog, $(PROGRAMS), $(findstring ZdropbearZ, Z$(prog)Z))))
	CFLAGS+= -DDROPBEAR_SERVER
endif
ifneq (,$(strip $(foreach prog, $(PROGRAMS), $(findstring ZdbclientZ, Z$(prog)Z))))
	CFLAGS+= -DDROPBEAR_CLIENT
endif


# these are exported so that libtomcrypt's makefile will use them
export CC
export CFLAGS
export RANLIB AR STRIP

ifeq ($(STATIC), 1)
	LDFLAGS+=-static
endif

ifeq ($(MULTI), 1)
	TARGETS=dropbearmulti
else
	TARGETS=$(PROGRAMS)
endif

# for the scp progress meter. The -D doesn't affect anything else.
ifeq ($(SCPPROGRESS), 1)
	CFLAGS+=-DPROGRESS_METER
endif

all: $(TARGETS)

strip: $(TARGETS)
	$(STRIP) $(addsuffix $(EXEEXT), $(TARGETS))

install: $(addprefix inst_, $(TARGETS))

insmultidropbear: dropbearmulti
	$(INSTALL) -d $(DESTDIR)$(sbindir)
	-rm -f $(DESTDIR)$(sbindir)/dropbear$(EXEEXT)
	-ln -s $(bindir)/dropbearmulti$(EXEEXT) $(DESTDIR)$(sbindir)/dropbear$(EXEEXT) 
	$(INSTALL) -d $(DESTDIR)$(mandir)/man8
	$(INSTALL) -m 644 dropbear.8  $(DESTDIR)$(mandir)/man8/dropbear.8

insmulti%: dropbearmulti
	$(INSTALL) -d $(DESTDIR)$(bindir)
	-rm -f $(DESTDIR)$(bindir)/$*$(EXEEXT) 
	-ln -s $(bindir)/dropbearmulti$(EXEEXT) $(DESTDIR)$(bindir)/$*$(EXEEXT) 
	$(INSTALL) -d $(DESTDIR)$(mandir)/man1
	$(INSTALL) -m 644 $*.1  $(DESTDIR)$(mandir)/man1/$*.1

# dropbear should go in sbin, so it needs a seperate rule
inst_dropbear: dropbear
	$(INSTALL) -d $(DESTDIR)$(sbindir)
	$(INSTALL) dropbear$(EXEEXT) $(DESTDIR)$(sbindir)
	$(INSTALL) -d $(DESTDIR)$(mandir)/man8
	$(INSTALL) -m 644 dropbear.8 $(DESTDIR)$(mandir)/man8/dropbear.8

inst_%: $*
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL) $*$(EXEEXT) $(DESTDIR)$(bindir)
	$(INSTALL) -d $(DESTDIR)$(mandir)/man1
	if test -e $*.1; then $(INSTALL) -m 644 $*.1 $(DESTDIR)$(mandir)/man1/$*.1; fi

inst_dropbearmulti: $(addprefix insmulti, $(PROGRAMS)) 


# for some reason the rule further down doesn't like $($@objs) as a prereq.
dropbear: $(dropbearobjs)
dbclient: $(dbclientobjs)
dropbearkey: $(dropbearkeyobjs)
dropbearconvert: $(dropbearconvertobjs)

dropbear dbclient dropbearkey dropbearconvert: $(HEADERS) $(LIBTOM_DEPS) Makefile
	$(CC) $(LDFLAGS) -o $@$(EXEEXT) $($@objs) $(LIBS)

# scp doesn't use the libs so is special.
scp: $(SCPOBJS)  $(HEADERS) Makefile
	$(CC) $(LDFLAGS) -o $@$(EXEEXT) $(SCPOBJS)


# multi-binary compilation.
MULTIOBJS=
ifeq ($(MULTI),1)
	MULTIOBJS=dbmulti.o $(sort $(foreach prog, $(PROGRAMS), $($(prog)objs))) -lcrypt 
	CFLAGS+=$(addprefix -DDBMULTI_, $(PROGRAMS)) -DDROPBEAR_MULTI
endif

dropbearmulti: multilink 

multibinary: $(HEADERS) $(MULTIOBJS) $(LIBTOM_DEPS) Makefile
	$(CC) $(LDFLAGS) -o dropbearmulti$(EXEEXT) $(MULTIOBJS) $(LIBS)

multilink: multibinary $(addprefix link, $(PROGRAMS))

link%:
	-rm -f $*$(EXEEXT)
	-ln -s dropbearmulti$(EXEEXT) $*$(EXEEXT)

$(LTC): options.h
	cd libtomcrypt && $(MAKE) clean && $(MAKE)

$(LTM): options.h
	cd libtommath && $(MAKE)

.PHONY : clean sizes thisclean distclean tidy ltc-clean ltm-clean

ltc-clean:
	cd libtomcrypt && $(MAKE) clean

ltm-clean:
	cd libtommath && $(MAKE) clean

sizes: dropbear
	objdump -t dropbear|grep ".text"|cut -d "." -f 2|sort -rn

clean: ltc-clean ltm-clean thisclean

thisclean:
	-rm -f dropbear dbclient dropbearkey dropbearconvert scp scp-progress \
			dropbearmulti *.o *.da *.bb *.bbg *.prof 

distclean: clean tidy
	-rm -f config.h
	-rm -f Makefile

tidy:
	-rm -f *~ *.gcov */*~
