#include <stdio.h>
#include <math.h>
#include <limits.h>

typedef struct s21_decimal {
    unsigned int bits[4];
} s21_decimal;

void to_bin(unsigned int num) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void print_dec(s21_decimal dec) {
    for(int i = 3; i >= 0; i--){
        to_bin(dec.bits[i]);
    }
}

void bits_shift_left(s21_decimal *dec, int val) {
    for(int i = 0; i < val; i++) {
        for(int j = 2; j >= 0; --j) {
            dec->bits[j] <<= 1;
            if(dec->bits[j - 1] >= pow(2, 31) && j < 3)
                dec->bits[j] |= 1;
        }
    }
}

void bits_shift_right(s21_decimal *dec, int val) {
    for(int i = 0; i < val; i++) {
        for(int j = 0; j <= 2; ++j) {
            dec->bits[j] >>= 1;
            if((dec->bits[j + 1] - 1) == 0)
                dec->bits[j] |= UINT_MAX;
        }
    }
}

int main() {
    s21_decimal dec1 = {{UINT_MAX - 6482, 0, 0, 0}};
    print_dec(dec1);
    printf("\n\n");
    bits_shift_left(&dec1, 39);
    print_dec(dec1);
    printf("\n\n");
    bits_shift_right(&dec1, 11);
    print_dec(dec1);
}
