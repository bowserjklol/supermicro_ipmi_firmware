#define CONFIG_CMDLINE "mem=100M console=ttyS0,115200n8 root=/dev/mtdblock2 rootfstype=cramfs noinitrd rw mtdparts=spi0.0:256k(bootloader),1280k(nvram),8192k(1stFS),2048k(kernel),4096k(2ndFS),15360k@256k(all_part),16384k@0k(dump_flash) quiet"
