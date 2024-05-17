.PHONY: clean, dump

TARGET = sw-interrupt
PRIV_LVL = machine

PREFIX = ./../..

SRC = $(wildcard $(PREFIX)/bsp/$(PRIV_LVL)/*.c)\
	$(wildcard $(PREFIX)/bsp/$(PRIV_LVL)/*.S)\
	$(wildcard ./*.c)\
	$(wildcard $(PREFIX)/lib/*/*.c)\

OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(notdir $(SRC)))))

GCC = riscv64-unknown-elf-gcc
COMPILER_FLAGS = -mcmodel=medany -std=gnu99 -fno-builtin-printf -march=rv64gcv -mabi=lp64d
LINKER_FLAGS = -static -nostdlib -nostartfiles -T $(PREFIX)/bsp/$(PRIV_LVL)/link.ld

DISASM = riscv64-unknown-elf-objdump -d

$(TARGET): $(OBJ)
	$(GCC) $(LINKER_FLAGS) $(OBJ) -o $(TARGET)

$(OBJ): $(SRC)
	mkdir obj/
	cd obj/ && $(GCC) $(COMPILER_FLAGS) -c $(addprefix ../, $(SRC))

clean:
	rm $(TARGET) -R obj/

dump:
	$(DISASM) $(TARGET)
