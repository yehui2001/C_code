#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum_digit(int n){
    int sum = 0,i = 0,j = 0,num = n,temp;
    //先判断一手，n是个几位的数字？
    while(n > 0){
        n = n / 10;
        i++;
    }
    while(i-j >= 0){
        temp = pow(10,i-j);
        sum += num / temp;
        num = num % temp;
        j++;
    }
    printf("%d",sum);
    return sum;
}

int main(){
    int n,sort[n];
    //请输入一个整数n
    scanf("%d",&n);
    
    return 0;
}