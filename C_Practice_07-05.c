#include <stdio.h>

int count_bits(unsigned x);
int int_bits(void);
void print_bits(unsigned);
unsigned set(unsigned x, int pos);
unsigned reset(unsigned x, int pos);
unsigned inverse(unsigned x, int pos);
unsigned set_n(unsigned x, int pos, int n);
unsigned reset_n(unsigned x, int pos, int n);
unsigned inverse_n(unsigned x, int pos, int n);

int main (void){
    int x, pos, n;

    printf("整数を入力してください:"); scanf("%u", &x);
    printf("操作するビットの番号を入力せしてください:"); scanf("%u", &pos);
    printf("操作するビットの範囲を入力してください:"); scanf("%u", &n);
    
    printf("元の整数                                 整数:%4d ビット:", x);
    print_bits(x);

    printf("%2d番ビットをセット。                     整数:%4d ビット:", pos,  set(x, pos));
    print_bits(set(x, pos));

    printf("%2d番ビットをリセット。                   整数:%4d ビット:", pos, reset(x, pos));
    print_bits(reset(x, pos));

    printf("%2d番ビットを反転。                       整数:%4d ビット:", pos ,inverse(x, pos));
    print_bits(inverse(x, pos));

    printf("%2d番から%2d個までのビットをセット。       整数:%4d ビット:", pos, pos + n-1, set_n(x, pos, n));
    print_bits(set_n(x, pos, n));

    printf("%2d番から%2d個までのビットをリセット。     整数:%4d ビット:", pos, pos + n-1, reset_n(x, pos, n));
    print_bits(reset_n(x, pos, n));

    printf("%2d番から%2d個までのビットを反転。         整数:%4d ビット:", pos, pos + n-1, inverse_n(x, pos, n));
    print_bits(inverse_n(x, pos, n));

    return 0;
}

// 引数のビット数を返す //
int count_bits(unsigned x){
    int bits = 0;
    while(x){
        if(x&1U) bits++;
        x >>= 1;
    }
    return bits;
}

// int型のビット数を返す //
int int_bits(void){
    return count_bits(~0);
}

// 引数のビットを書き出す //
void print_bits(unsigned x){
    for(int i = int_bits()-1 ; i >= 0; i--){
        printf("%u", (x>>i) & 1U);
    }
    printf("\n");
}

//ビットをセットする関数//
unsigned set(unsigned x, int pos){
    int n = 1;
    n <<= (pos - 1);
    return(x | n);
}

//ビットリセットする関数//
unsigned reset(unsigned x, int pos){
    int n = 1;
    n <<= (pos - 1);
    return(x & ~n);
}

//ビット反転する関数//
unsigned inverse(unsigned x, int pos){
    int n = 1;
    n <<= (pos - 1);
    return(x ^ n);
}

// pos番目からn-1個のビットをセットする関数 //
unsigned set_n(unsigned x, int pos, int n){
    int y;
    y = x;
    for(int i = pos; i < pos + n; i++)
        y = set(y ,i);
    return y;
}

// pos番目からn-1個のビットをリセットする関数 //
unsigned reset_n(unsigned x, int pos, int n){
    int y;
    y = x;
    for(int i = pos; i < pos + n; i++)
        y = reset(y, i);
    return y;
}

// pos番目からn-1個のビットをリセットする関数 //
unsigned inverse_n(unsigned x, int pos, int n){
    int y;
    y = x;
    for(int i = pos; i < pos + n; i++)
        y = inverse(y, i);
    return y;
}