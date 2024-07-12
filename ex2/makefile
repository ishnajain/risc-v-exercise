SHELL	:= /bin/bash
VERBOSE	?= 0

SRC	:= src
OUT	:= out
ELF	:= $(OUT)/test.elf
#OBJ	:= $(ELF:%.elf=%.o)
COBJ	:= $(wildcard $(SRC)/*.c)
COBJ	:= $(addprefix $(OUT)/,$(COBJ:.c=.o))
SOBJ	:= $(wildcard $(SRC)/*.S)
SOBJ	:= $(addprefix $(OUT)/,$(SOBJ:.S=.o))
OBJ	:= $(COBJ) $(SOBJ)
#OBJ	:= $(wildcard $(SRC)/*.c $(SRC)/*.S)
#OBJ	:= $(addprefix $(OUT)/,$(OBJ:.*=.o)) 

TC	:= ../../cyancore/tools/risc-v-toolchain/bin/riscv64-unknown-elf-
LD	:= $(TC)ld 
AS	:= $(TC)as
CC	:= $(TC)gcc
OD	:= $(TC)objdump

CFLAGS  := -g -Werror -Wall -I./inc -march=rv32i -mabi=ilp32
LDFLAGS	:= -dT section.ld -b elf32-littleriscv
ASFLAGS	:= -march=rv32ic -mabi=ilp32 -D -g
#$(info $(SRC))
default : $(ELF)

.SECONDEXPANSION : 

$(ELF): $(OBJ)  |$$(@D)/
	@echo building $(@F)
	$(LD)  $(LDFLAGS)  $^ -o $@ #-lgcc 
	$(OD) -Dx $@ > $(@:%.elf=%.lst)

$(COBJ): $(OUT)/%.o:%.c |$$(@D)/
	@echo compiling $(@F)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(SOBJ): $(OUT)/%.o:%.S |$$(@D)/
	@echo compiling $(@F)
	$(AS) $(ASFLAGS) $< -o $@ 
./%/: 
	mkdir -p $@

ifeq ($(VERBOSE),0)
.SILENT:
endif

clean:
	rm -rf $(OUT)
