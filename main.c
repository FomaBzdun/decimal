#include <stdio.h>

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

void s21_add(s21_decimal dec1, s21_decimal dec2, s21_decimal *result) {
   unsigned int fpos = 0;
   result->bits[fpos] = dec1.bits[fpos] + dec2.bits[fpos];
   if(result->bits[fpos] < )
}

int main() {
    s21_decimal dec1 = {{4294967295, 0, 0, 0}};
    s21_decimal dec2 = {{2, 0, 0, 0}};
    s21_decimal dec_result = {{0, 0, 0, 0}};
    s21_add(dec1, dec2, &dec_result); 
    print_dec(dec_result);
}
