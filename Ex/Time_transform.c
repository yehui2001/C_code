#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int* Time_transf(long long time){
    int t[6],N,B;
    long long s = time/1000.0;
    //printf("S = %lld \n",s);
    int m = s/60;
    int h = m/60;
    int day = h/24;
    int t_h = h - 24*day;
    m = m - h*60;
    s = s - h*3600 - m*60;
    printf("%02d:",t_h);
    printf("%02d:",m);
    printf("%02d",s);
    return t;
}

int main(){
    long long time;
    int *t;
    scanf("%lld",&time);
    t = Time_transf(time);
    return 0;
}