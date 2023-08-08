#include <stdio.h>

int main(void){
    int a;
    int sft;
    int beki, shift;

    printf("整数を入力してください"); scanf("%d", &a);
    printf("整数aのビットをシフトする値を、正:左にシフト、負:右にシフトで入力してください:"); scanf("%d", &sft);
    
    beki = a;
    shift = a;

    if(sft>0){
        for(int i =0; i<sft; i++){
            beki *= 2;
        }
        shift <<= sft;
    }
    else{
        for(int i =0; i < -sft; i++){
            beki /= 2;
        }
        shift >>= (-sft);
    }
    printf("2のべき乗:%d, ビットシフトした値:%d\n", beki, shift);

    return 0;
}