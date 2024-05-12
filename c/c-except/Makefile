.PHONY: clean, dump

TARGET = except

PREFIX = ./../..

SRC = $(wildcard $(PREFIX)/bsp/*.c)\
	$(wildcard $(PREFIX)/bsp/*.S)\
	$(wildcard ./*.c)\

OBJ = $(addsuffix .o, $(basename $(notdir $(SRC))))

GCC = riscv64-unknown-elf-gcc
COMPILER_FLAGS = -mcmodel=medany -std=gnu99 -fno-builtin-printf -march=rv64gcv -mabi=lp64d
LINKER_FLAGS = -static -nostdlib -nostartfiles -T $(PREFIX)/bsp/link.ld

DISASM = riscv64-unknown-elf-objdump -d

$(TARGET): $(OBJ)
	$(GCC) $(LINKER_FLAGS) $(OBJ) -o $(TARGET)

$(OBJ): $(SRC)
	$(GCC) $(COMPILER_FLAGS) -c $(SRC)

clean:
	rm $(TARGET) $(OBJ)

dump:
	$(DISASM) $(TARGET)
