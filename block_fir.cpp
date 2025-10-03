#include "block_fir.h"

void fir(ap_int<8> in, ap_int<10>* out, ap_int<8> shift_reg[N]) {
#pragma HLS PIPELINE

    const ap_int<8> taps[N] = {1, 2, 0, -3, 0, 4, -5, 0, 1, -2, 0, -3, 0, 4, -5, 0};

#pragma HLS ARRAY_PARTITION variable=taps complete dim=1
#pragma HLS ARRAY_PARTITION variable=shift_reg complete dim=1

    SHIFT_LOOP:
    for (int i = N - 1; i > 0; i--) {
#pragma HLS UNROLL
        shift_reg[i] = shift_reg[i - 1];
    }

    shift_reg[0] = in;

    ap_int<10> acc = 0;
    MAC_LOOP:
    for (int i = 0; i < N; i++) {
#pragma HLS UNROLL
        acc += shift_reg[i] * taps[i];
    }

    *out = acc;
}
