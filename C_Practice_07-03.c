#include <stdio.h>

int count_bits(unsigned x);
int int_bits(void);
void print_bits(unsigned x);

int main (void){
    unsigned n;
    printf("Type in a number : "); scanf("%u", &n);

    printf("ビットシフトなし :");       print_bits(n);     printf("\n");
    printf("右に1ビットシフト:");   print_bits(n>>1);   printf("\n");
    printf("左に1ビットシフト:");   print_bits(n<<1);   printf("\n");

    return 0;
}

/* unsigned型xのビットを書き出す */
void print_bits(unsigned x){
    for(int i = int_bits() - 1; i >= 0; i--){
        printf("%u",(x>>i) & 1U);
    } 
}

/* int型のbit数を数える関数 */
int int_bits(void){
    return count_bits(~0U);
}

/* unsigned型xでセットされているbit数を数える */
int count_bits(unsigned x){
    int bits = 0;
    while(x) {
        if(x & 1U)bits++;
        x >>= 1;
    }
    return bits;
}