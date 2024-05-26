#ifndef SYS_LIB_H
#define SYS_LIB_H

#define SYS_start_timer 10
#define SYS_stop_timer 11

#define SYS_start_sw_interrupt 20

#define SYS_write 64

void start_timer(int time);
void stop_timer();
void start_sw_interrupt();

#endif
