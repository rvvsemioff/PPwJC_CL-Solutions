#ifndef DATA_INPUT_H_
#define DATA_INPUT_H_

#include <windows.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char check_posix(void);
unsigned char input(char str[], short bottom, unsigned char top);
short define_year(time_t time);
void generate_name(char name[], unsigned char N, unsigned char space);
double random(long mult);

#endif
