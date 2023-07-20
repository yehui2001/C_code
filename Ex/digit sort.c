#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
int sum_digit(int n){  //时间复杂度过高
    int sum = 0,i = 0,j = 0,num = n,temp;
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
    return sum;
}
*/

int sum_digit(int n){
    int sum = 0;
    while(n){
        sum += n%10;                    //计算位数之和 
        n /= 10;
  }
    return sum;
}

int main(){
    int n,m,i,j,l,k = 1;
    scanf("%d",&n);
    int sort[n];
    scanf("%d",&m);
    for(j = 1; j <= 54; j++){
        for(i = 1; i <= n; i++){
            if(sum_digit(i) == j){
                sort[k++] = i;
            }
        }
    }
    printf("%d\n",sort[m]);
    return 0;
}
