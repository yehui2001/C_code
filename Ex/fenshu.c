#include <stdio.h>
#define n 2020;

int gcd(int a, int b){
    return b ? gcd(b, a % b):a;
}

int main(){
    int count = 0;
    for(int i = 1; i <= 2020 ; i++)
        for(int j = 1; j <= 2020; j++){
            if(gcd(i,j) == 1){
                count++;
            }
        }
    printf("%d",count);
    return 0;
} 