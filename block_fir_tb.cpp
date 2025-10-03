#include "block_fir.h"
#include <cmath>

int main() {
    ap_int<8> in_sample;
    ap_int<10> out_sample;
    ap_int<8> shift_reg[N] = {0};

    double angle_step = (2.0 * M_PI) / (SIZE / 2.0);

    for (int i = 0; i < SIZE; i++) {
        in_sample = 63 * std::sin(angle_step * i);

        fir(in_sample, &out_sample, shift_reg);

        printf("input = %d, output = %d\n", (int)in_sample, (int)out_sample);
    }

    return 0; 
}
