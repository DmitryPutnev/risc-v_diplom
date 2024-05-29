.PHONY: all clean

GCC = riscv64-unknown-elf-gcc
AR = riscv64-unknown-elf-ar
COMPILER_FLAGS = -mcmodel=medany -std=gnu99 -fno-builtin-printf -march=rv64gcv -mabi=lp64d
INCLUDE=-Iinclude
LIBMACHINE=libmachine.a
LIBUSER=libuser.a
SRCS=$(wildcard src/*.c)
INCS=$(wildcard include/*.h)
MOBJS=$(patsubst src/%.c,obj/%.o,$(SRCS)) obj/mcrt.o obj/msyscalls.o
UOBJS=$(patsubst src/%.c,obj/%.o,$(SRCS)) obj/ucrt.o obj/usyscalls.o

all: $(LIBMACHINE) $(LIBUSER)

obj:
	mkdir obj

obj/%.o: src/%.c $(INCS) | obj
	$(GCC) $(INCLUDE) -c $< -o $@
	
obj/mcrt.o: ../bsp/machine/crt.S | obj
	$(GCC) $(COMPILER_FLAGS) -c $< -o $@

obj/msyscalls.o: ../bsp/machine/syscalls.c | obj
	$(GCC) $(COMPILER_FLAGS) -c $< -o $@

obj/ucrt.o: ../bsp/user/crt.S | obj
	$(GCC) $(COMPILER_FLAGS) -c $< -o $@

obj/usyscalls.o: ../bsp/user/syscalls.c | obj
	$(GCC) $(COMPILER_FLAGS) -c $< -o $@

$(LIBMACHINE): $(MOBJS)
	$(AR) rcs $(LIBMACHINE) $(MOBJS)
	
$(LIBUSER): $(UOBJS)
	$(AR) rcs $(LIBUSER) $(UOBJS)

clean:
	rm -rf obj
	rm $(LIBMACHINE) $(LIBUSER)
