.PHONY: clean, dump
FILE = timer.c
EXE = timer
LINKER = ./../../bsp/link.ld
HEADER = ./../../bsp/encoding.h
CRT = ./../../bsp/crt.S
SYSCALLS = ./../../bsp/syscalls.c

COMPILER = riscv64-unknown-elf-gcc -mcmodel=medany -std=gnu99 -fno-builtin-printf -march=rv64gcv -mabi=lp64d -o $(EXE) $(FILE) $(HEADER) $(CRT) $(SYSCALLS) -static -nostdlib -nostartfiles -T $(LINKER)
DISASM = riscv64-unknown-elf-objdump -d

$(EXE): $(FILE)
	$(COMPILER)

clean:
	rm $(EXE)
	
dump:
	$(DISASM) $(EXE)
