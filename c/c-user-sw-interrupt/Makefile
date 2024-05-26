.PHONY: clean, dump

TARGET = ecall_sw-interrupt
PRIV_LVL = user

PREFIX = ./../..

SRC = $(wildcard $(PREFIX)/bsp/$(PRIV_LVL)/*.c)\
	$(wildcard $(PREFIX)/bsp/$(PRIV_LVL)/*.S)\
	$(wildcard ./*.c)\

OBJ = $(addprefix obj/, $(addsuffix .o, $(basename $(notdir $(SRC)))))

LIB_DIR = $(PREFIX)/lib
LIB = $(LIB_DIR)/libstatic.a

GCC = riscv64-unknown-elf-gcc
COMPILER_FLAGS = -mcmodel=medany -std=gnu99 -fno-builtin-printf -march=rv64gcv -mabi=lp64d
LINKER_FLAGS = -static -nostdlib -nostartfiles -T $(PREFIX)/bsp/$(PRIV_LVL)/link.ld

DISASM = riscv64-unknown-elf-objdump -d

all: $(TARGET)

$(TARGET): $(OBJ) $(LIB)
	$(GCC) $(LINKER_FLAGS) $(OBJ) -o $(TARGET) -L$(LIB_DIR) -lstatic

obj/%.o: $(PREFIX)/bsp/$(PRIV_LVL)/%.c | obj
	$(GCC) $(COMPILER_FLAGS) -c $< -o $@

obj/%.o: $(PREFIX)/bsp/$(PRIV_LVL)/%.S | obj
	$(GCC) $(COMPILER_FLAGS) -c $< -o $@
	
obj/%.o: %.c | obj
	$(GCC) $(COMPILER_FLAGS) -c $< -o $@
	
obj:
	mkdir obj

clean:
	rm $(TARGET) -R obj/

dump:
	$(DISASM) $(TARGET)
