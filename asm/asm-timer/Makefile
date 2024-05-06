.PHONY: clean, dump
FILE = timer.S
EXE = timer
LINKER = ./../../bsp/link.ld
HEADER = ./../../bsp/encoding.h

COMPILER = riscv64-unknown-elf-gcc -nostdlib -nostartfiles -T $(LINKER) $(FILE) $(HEADER) -o $(EXE)
DISASM = riscv64-unknown-elf-objdump -d

$(EXE): $(FILE)
	$(COMPILER)

clean:
	rm $(EXE)
	
dump:
	$(DISASM) $(EXE)
