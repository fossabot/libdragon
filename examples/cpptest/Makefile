ROOTDIR = $(N64_INST)
GCCN64PREFIX = $(ROOTDIR)/bin/mips64-elf-
CHKSUM64PATH = $(ROOTDIR)/bin/chksum64
MKDFSPATH = $(ROOTDIR)/bin/mkdfs
HEADERPATH = $(ROOTDIR)/mips64-elf/lib
N64TOOL = $(ROOTDIR)/bin/n64tool
HEADERNAME = header
LINK_FLAGS = -G32767 -L$(ROOTDIR)/mips64-elf/lib -ldragonpp -lc -lm -ldragonsys -Tn64ld_cpp.x
CFLAGS = -std=c++17 -march=vr4300 -mtune=vr4300 -O2 -G32767 -Wall -Werror -I$(ROOTDIR)/mips64-elf/include
ASFLAGS = -mtune=vr4300 -march=vr4300
CC = $(GCCN64PREFIX)gcc
AS = $(GCCN64PREFIX)as
LD = $(GCCN64PREFIX)ld
OBJCOPY = $(GCCN64PREFIX)objcopy

ifeq ($(N64_BYTE_SWAP),true)
ROM_EXTENSION = .v64
N64_FLAGS = -b -l 2M -h $(HEADERPATH)/$(HEADERNAME) -o $(PROG_NAME)$(ROM_EXTENSION) $(PROG_NAME).bin
else
ROM_EXTENSION = .z64
N64_FLAGS = -l 2M -h $(HEADERPATH)/$(HEADERNAME) -o $(PROG_NAME)$(ROM_EXTENSION) $(PROG_NAME).bin
endif

PROG_NAME = cpptest

$(PROG_NAME)$(ROM_EXTENSION): $(PROG_NAME).elf
	$(OBJCOPY) $(PROG_NAME).elf $(PROG_NAME).bin -O binary
	rm -f $(PROG_NAME)$(ROM_EXTENSION)
	$(N64TOOL) $(N64_FLAGS) -t "Controller Test"
	$(CHKSUM64PATH) $(PROG_NAME)$(ROM_EXTENSION)

$(PROG_NAME).elf: $(PROG_NAME).cpp
	$(CC) $(PROG_NAME).cpp -o $(PROG_NAME).elf $(LINK_FLAGS) $(C_FLAGS)

all: $(PROG_NAME)$(ROM_EXTENSION)

disassemble: $(PROG_NAME).S

$(PROG_NAME).S: $(PROG_NAME).elf
	$(CC) -S -fverbose-asm -g -O2 $(PROG_NAME).cpp -o $(PROG_NAME).S

clean:
	rm -f *.v64 *.z64 *.elf *.o *.bin
