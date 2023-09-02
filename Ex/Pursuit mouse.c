#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring> //memset function
#define N 5

void print_positon(int *p){
    for(int i = 0;i< N;i++){
        printf("%d \t",p[i]);
    }
    printf("\n");
}

int main()
{   srand((unsigned int)time(NULL));
    int ip = rand() % N+1;    //ip means initial position.
    printf("-------------------------------------------\n");
    printf("the initial position = %d\n",ip);
    int p[N];
    memset(p,-1,sizeof(p)); //all number become -1 , -1 means unknown.
    p[ip-1] = 1; // 1 means the mouse is here.
    int c = 2; // c means the catch positon of mouse. The first catch position is 2 (No.2 box)
    int t = 1; // t means the time 
    int icm = 0;
    int rp = ip;
    printf("--------------第%d天开始的情况--------------\n",t);
    print_positon(p);   
    for(t = 1; t<=3 ;t++){
        if(p[c-1]==1){
            break;
        }
        else{
            p[c-1] = 0;
            printf("The catch position is %d \n",c);
            do{
                icm = rand() % 3 - 1; // create a rand to imitate the moving of mouse.
            }
            while(icm==0||(rp+icm)<1||(rp+icm)>5); //the mouse only move at one direction when it situate at the No.1 box and No.5 box
            p[rp-1] = -1;
            rp = rp + icm; // upgrade the real position.
            p[rp-1] = 1;
            if(c!=N-1){c++;};
            printf("--------------第%d天结束的情况--------------\n",t);
            print_positon(p);
        }
    }
    while(p[c-1]!=1){
        printf("The catch position is %d \n",c);
        p[c-1] = 0;
        do{
            icm = rand() % 3 - 1; // create a rand to imitate the moving of mouse.
        }
        while(icm==0||(rp+icm)<1||(rp+icm)>5); //the mouse only move at one direction when it situate at the No.1 box and No.5 box
        p[rp-1] = -1;
        rp = rp + icm;
        p[rp-1] = 1;
        printf("--------------第%d天结束的情况--------------\n",t);
        print_positon(p); 
        c--;   
        t++; 
    }
    printf("the real postion is %d. \n",rp);
    printf("Caught!the postion is %d in the day %d \n",c,t);
    printf("-------------------------------------------\n");
    return  0;
}