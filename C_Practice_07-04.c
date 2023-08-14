#include <stdio.h>

int count_bits(unsigned x);
int int_bits(void);
void print_bits(unsigned x);

unsigned set(unsigned x, int pos);
unsigned reset(unsigned x, int pos);
unsigned inverse(unsigned x, int pos);

int main (void){
    int x, pos;

    printf("整数を入力してください。"); scanf("%u", &x);
    printf("セットするビットの番号を入力せしてください"); scanf("%u", &pos);
    printf("元の整数              整数:%4d ビット:", x);
    print_bits(x);

    printf("%2d番ビットをセット。  整数:%4d ビット:", pos,  set(x, pos));
    print_bits(set(x, pos));

    printf("%2d番ビットをリセット。整数:%4d ビット:", pos, reset(x, pos));
    print_bits(reset(x, pos));

    printf("%2d番ビットを反転。    整数:%4d ビット:", pos ,inverse(x, pos));
    print_bits(inverse(x, pos));

    return 0;
}

int count_bits(unsigned x){
    int bits = 0;
    while(x) {
        if(x & 1U) bits++;
        x >>= 1;
    }
    return bits;
}

int int_bits(void){
    return count_bits(~0U);
}

void print_bits(unsigned x){
    for(int i = int_bits() - 1; i>=0; i--){
    printf("%u",(x>>i) & 1U);
    }
    printf("\n");
}

//ビットをセットする関数//
unsigned set(unsigned x, int pos){
    int n = 1;
    n <<= pos;
    return(x | n);
}
//ビットリセットする関数//
unsigned reset(unsigned x, int pos){
    int n = 1;
    n <<= pos;
    return(x & ~n);
}
//ビット反転する関数//
unsigned inverse(unsigned x, int pos){
    int n = 1;
    n <<= pos;
    return(x ^ n);
}