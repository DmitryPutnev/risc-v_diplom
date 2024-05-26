.PHONY: all clean

GCC = riscv64-unknown-elf-gcc
AR = riscv64-unknown-elf-ar
INCLUDE=-Iinclude
LIBRARY=libstatic.a
SRCS=$(wildcard src/*.c)
INCS=$(wildcard include/*.h)
OBJS=$(patsubst src/%.c,obj/%.o,$(SRCS))

all: $(LIBRARY)

obj:
	mkdir obj

obj/%.o: src/%.c $(INCS) | obj
	$(GCC) $(INCLUDE) -c $< -o $@

$(LIBRARY): $(OBJS)
	$(AR) rcs $(LIBRARY) $(OBJS)

clean:
	rm -rf obj
	rm $(LIBRARY)
