-include .config
-include .machine
-include ./ProjectConfig-HERMON

CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AR=$(CROSS_COMPILE)ar
CXX=$(CROSS_COMPILE)g++
NM=$(CROSS_COMPILE)nm
RANLIB=$(CROSS_COMPILE)ranlib
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump 
STRIP = $(CROSS_COMPILE)strip
export CC LD AR CXX NM RANLIB OBJCOPY OBJDUMP STRIP CROSS_COMPILE CROSS_COMPILE_INCLUDE

BASEDIR = $(shell pwd)
# The plan is to move all the source code to this directory, to prevent conflicts with make targets
SRCDIR = $(BASEDIR)/src
OUTPUT_PATH = $(BASEDIR)/output
FS_PATH = $(OUTPUT_PATH)/filesystem/
# legacy defines :(
PRJ_PATH = $(BASEDIR)
BINPATH = $(BASEDIR)/bin
MODULEPATH = $(BASEDIR)/bin/module
LIBPATH = $(BASEDIR)/lib
IMAGE_PATH = $(BASEDIR)/images
OUTPUT_IMG-y = $(BASEDIR)/MKIMG_Tool/
BOARD = test
Q = @
export BASEDIR SRCDIR PRJ_PATH BINPATH LIBPATH IMAGE_PATH MODULEPATH OUTPUT_IMG-y Q FS_PATH BOARD

LIBS += -lcgi -lipmi -lchnl  -lm -lsol  -lutility -lnvram  -lipmicrypt -lcommon -lsys -lrt -luart -lupdate -lnet -lmqueue -lgpio -lxml2 -lldap_client -lradius_client -lwdt
LDFLAGS += -L$(SRCDIR)/openssl/openssl/local/lib -L$(BASEDIR)/lib -L$(BASEDIR)/FileSystem/clean_filesystem/lib/ -lcrypto -lssl $(LIBS)
export LDFLAGS

MYMCU=HERMON
export MYMCU

all: outputdir kernel libxml2 openssl openldap ipmi vusb ikvm busybox dhcpv6 lighttpd sfcc sfcb openwsman dropbear smtp ntp lldp nwfirewall webpage baselibs closed_source mdinfo utils

outputdir:
	mkdir -p  $(FS_PATH)/bin $(FS_PATH)/sbin $(FS_PATH)/lib $(FS_PATH)/etc/init.d $(FS_PATH)/usr/local/etc/ntp

kernel:
	$(Q)echo
	$(Q)echo =================== kernel ===================
	$(Q)echo
	cd $(BASEDIR)/Kernel/Host/HERMON/linux && LDFLAGS="" make

libxml2:
	$(Q)echo
	$(Q)echo =================== libxml2 ===================
	$(Q)echo
	cd $(SRCDIR)/libxml2 && make

openssl:
	$(Q)echo
	$(Q)echo =================== openssl ===================
	$(Q)echo
	cd $(SRCDIR)/openssl && make

openldap:
	$(Q)echo
	$(Q)echo =================== openldap ===================
	$(Q)echo
	cd $(BASEDIR)/OpenLDAP && make

ipmi:
	$(Q)echo
	$(Q)echo =================== ipmi ===================
	$(Q)echo
	cd $(BASEDIR)/IPMI && make
	cd $(BASEDIR)/IPMI/INIT && make

vusb:
	$(Q)echo
	$(Q)echo =================== vusb ===================
	$(Q)echo
	cd $(BASEDIR)/USB_VD && make

ikvm:
	$(Q)echo
	$(Q)echo =================== ikvm ===================
	$(Q)echo
	cd $(BASEDIR)/IKVM && make

busybox:
	$(Q)echo
	$(Q)echo =================== busybox ===================
	$(Q)echo
	cd $(SRCDIR)/busybox && make

dhcpv6:
	$(Q)echo
	$(Q)echo =================== dhcpv6 ===================
	$(Q)echo
	cd $(SRCDIR)/dhcpv6 && make

lighttpd:
	$(Q)echo
	$(Q)echo =================== lighttpd ===================
	$(Q)echo
	cd $(SRCDIR)/lighttpd && make

sfcc:
	$(Q)echo
	$(Q)echo =================== sfcc ===================
	$(Q)echo
	cd $(BASEDIR)/SFCC && make

sfcb:
	$(Q)echo
	$(Q)echo =================== sfcb ===================
	$(Q)echo
	cd $(BASEDIR)/SFCB && make

openwsman:
	$(Q)echo
	$(Q)echo =================== openwsman ===================
	$(Q)echo
	cd $(BASEDIR)/OpenWSMAN && make

dropbear:
	$(Q)echo
	$(Q)echo =================== dropbear ===================
	$(Q)echo
	cd $(SRCDIR)/dropbear && make

smtp:
	$(Q)echo
	$(Q)echo =================== smtp ===================
	$(Q)echo
	cd $(SRCDIR)/smtp && make

ddns:
	$(Q)echo
	$(Q)echo =================== ddns ===================
	$(Q)echo
	cd $(BASEDIR)/DDNS && make

ntp:
	$(Q)echo
	$(Q)echo =================== ntp ===================
	$(Q)echo
	cd $(SRCDIR)/ntp && make

lldp:
	$(Q)echo
	$(Q)echo =================== lldp ===================
	$(Q)echo
	cd $(SRCDIR)/lldp && make

nwfirewall:
	$(Q)echo
	$(Q)echo =================== nwfirewall ===================
	$(Q)echo
	cd $(BASEDIR)/NW_FIREWALL && make

webpage:
	$(Q)echo
	$(Q)echo =================== webpage ===================
	$(Q)echo
	cd $(BASEDIR)/Web_Server && make

baselibs:
	$(Q)echo
	$(Q)echo =================== baselibs ===================
	$(Q)echo
	cd $(SRCDIR)/baselibs && make

mdinfo:
	$(Q)echo
	$(Q)echo =================== mdinfo ===================
	$(Q)echo
	cd $(BASEDIR)/PKConfig/MDInfo && make

closed_source:
	$(Q)echo
	$(Q)echo =================== closed_source ===================
	$(Q)echo
	cd $(SRCDIR)/closed_source && make

utils:
	$(Q)echo
	$(Q)echo =================== closed_source ===================
	$(Q)echo
	cd $(BASEDIR)/Utils && make



# This really just generates the output image.  Called install for legacy reasons :)
install:
ifneq ($(shell id -u),0)
	$(error make install must be run as root)
endif
	$(Q)echo
	$(Q)echo =================== install ===================
	$(Q)echo
	cd $(BASEDIR)/Kernel/Host/HERMON/linux && LDFLAGS="" make install
	cd $(BASEDIR)/FileSystem && make install

test:
	cp `which qemu-arm-static` $(FS_PATH)/
	cd $(FS_PATH); sudo chroot . ./qemu-arm-static ./linuxrc
