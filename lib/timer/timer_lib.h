#ifndef TIMER_LIB_H
#define TIMER_LIB_H

#define ADDR_MTIMECMP 0x02004000
#define ADDR_MTIME 0x0200bff8

void init_timer(int time);

void enable_timer_interrupt();

void reset_timer();

#endif
