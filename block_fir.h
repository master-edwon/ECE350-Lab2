#pragma once

#include "stdio.h"
#include "ap_int.h"

#define SIZE 256
#define N 16

void fir(ap_int<8> input, ap_int<10>* output, ap_int<8> shift_reg[N]);
