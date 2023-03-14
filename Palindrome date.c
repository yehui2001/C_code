#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define N 8

//判断写入的时间是否合理
bool Judgement_date(int *arr){
    int year,month,day;
    year = arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
    month = 10*arr[4] + arr[5];
    day = 10*arr[6] + arr[7];

    if(month <= 12){
        if(month ==2&& day <=29){  //判断是否为闰年（普通闰年，世纪闰年)
            if((year % 4 == 0 && year % 100 != 0)||year % 400 == 0){
                //printf("输入时间合法\n");
                return 1;
            }
            else{
                if(day != 29){
                    //printf("输入时间合法\n");
                    return 1;
                }
            }
        }

        if((month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)&&(day <= 31)){
            //printf("输入时间合法\n");
            return 1;
        }
        else if((month == 4||month == 6||month == 8||month == 9||month == 11)&&(day <= 30)){
            //printf("输入时间合法\n");
            return 1;
        }
        //printf("输入时间不合法\n");
        return 0;
    }
    else{
        //printf("输入时间不合法\n");
        return 0;
    }
}

//把日期存放到数组中处理
void Array_transfrom(int num,int *arr){
    int a[N];
    for (int i = 0; i < 8; i++)
    {
        a[i] = pow(10,7-i);
        arr[i] = num /a[i];
        num = num % a[i];
    }
}

//判断是否是回文日期
bool Judge_Palindrome(int *arr){
    int a[N];
   /* 
    for(int i = 0; i < N ;i++ ){
        a[i] = arr[N-i-1];
    }
    */

    for(int k = 0; k < N ;k++ )
    if(arr[k] != arr[N-k-1]){
        //printf("N \n");
        return 0;
    }
        //printf("Y \n");
    return 1;
}

//判断是否是ABABABAB日期
bool Judge_ABABBABA(int *arr){
    for(int i = 0; i < N/4;i++){
        if(arr[i] != arr[i+2] || arr[i] != arr[N-i-3] || arr[i] != arr[N-i-1])
        return 0;
    }
    return 1;
}

//查找下一个回文日期
void find_Palindrome_date(int date[N]){
    int arr[N];
    int A = 0,b=0;
    for(int k = 0; k < N; k++){
        arr[k] = date[k];
    }

    for(int i = 0; i < N/2 ;i++ ){
        arr[N-i-1] = arr[i];
    }

    A = Judge_Palindrome(arr)+Judgement_date(arr);

    if(A == 2){ 
        if(10*arr[4]+arr[5] > 10*date[4]+date[5]||(10*arr[4]+arr[5] == 10*date[4]+date[5]&&10*arr[6]+arr[7]>10*date[6]+date[7]))
            {}
        else
            A = 0;
        }
    
    do{
        int year = arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];

        if(A==2){
            //if(10*arr[4]+arr[5] > 10*date[4]+date[5]||(10*arr[4]+arr[5] == 10*date[4]+date[5]&&10*arr[6]+arr[7]>10*date[6]+date[7]))
                break;
            }
        
        year++;

        for(int i = 0;i < N/2;i++){
            b = pow(10,3-i);
            arr[i]= arr[N-i-1] = year /b;
            year = year % b;
        }
        A = Judge_Palindrome(arr) + Judgement_date(arr);
    }
    while(A !=2);

    for(int j = 0;j < N;j++){
        printf("%d",arr[j]);
    }
    printf("\n");
}

//查找下一个ABABBABA日期
void find_ABABBABA_date(int date[N]){
    int arr[N];
    for(int k = 0; k < N; k++){
        arr[k] = date[k];
    }

    int A = 0,b,C=0;
    //先判断当前年份是否可以构造成ABABBABA
    for(int i = 0; i < N/4;i++ ){
        arr[N-i-1] = arr[N-i-3] = arr[i+2] = arr[i];
    }
    A = Judge_ABABBABA(arr)+Judgement_date(arr);

    //若下一个ABABBABA日期大于当前日期，我们设定A为2
    if(A==2){ 
        if(arr[0]*1000+arr[1]*100+arr[2]*10+arr[3] >date[0]*1000+date[1]*100+date[2]*10+date[3]||(arr[0]*1000+arr[1]*100+arr[2]*10+arr[3] == date[0]*1000+date[1]*100+date[2]*10+date[3]&&(arr[4]*1000+arr[5]*100+arr[6]*10+arr[7] >date[4]*1000+date[5]*100+date[6]*10+date[7])))
        {;}
        else{
            A = 0;
        }
    }

    do{
        int year = arr[0]*10+arr[1]*1;//千年位 跟 百年位;
        if(A==2){ 
                break;
        }

        year++;

        for(int i = 0;i < N/4;i++){
            b = pow(10,1-i);
            arr[i] = arr[i+2] = arr[N-i-3] = arr[N-i-1] = year/b;
            year = year % b;
        }
        A = Judge_ABABBABA(arr)+Judgement_date(arr);
        }
        while(A!=2);
        
    for(int j = 0;j < N;j++){
        printf("%d",arr[j]);
    }
}

int main(int argc, char *argv[])
{
    int date[N];
    int num,year;
    //printf("请输入形如yyyymmdd形式的日期:");
    scanf("%d",&num);
    Array_transfrom(num,date);
    //Judgement_date(date);
    //Judge_Palindrome(date);
    find_Palindrome_date(date);
    find_ABABBABA_date(date);
    printf("\n");
    return 0;
}