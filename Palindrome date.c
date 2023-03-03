#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define N 8

//判断写入的时间是否合理
bool Judgement_date(int *arr){
    int year,month,day;
    year = arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
    month = 10*arr[4] + arr[5];
    day = 10*arr[6] + arr[7];
/*     printf("year=%d \n",year);
    printf("month=%d \n",month);
    printf("day=%d \n",day); */
    if(month <= 12){
        if(month ==2&& day <=29){  //判断是否为闰年（普通闰年，世纪闰年)
            if((year % 4 == 0 && year % 100 != 0)||year % 400 == 0){
                printf("输入时间合法\n");
                return 1;
            }
            else{
                if(day != 29){
                    printf("输入时间合法\n");
                    return 1;
                }
            }
        }

        if((month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)&&(day <= 31)){
            printf("输入时间合法\n");
            return 1;
        }
        else if((month == 4||month == 6||month == 8||month == 9||month == 11)&&(day <= 30)){
            printf("输入时间合法\n");
            return 1;
        }
        printf("输入时间不合法\n");
        return 0;
    }
    else{
        printf("输入时间不合法\n");
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
    for(int i = 0; i < N ;i++ ){
        a[i] = arr[N-i-1];
    }
    for(int k = 0; k < N ;k++ )
    if(a[k] != arr[k]){
        //printf("N \n");
        return 0;
    }
        //printf("Y \n");
    return 1;
}

//查找下一个回文日期
void find_Palindrome_date(int *arr){
    int year;
    year = arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
    int A = 0,b = 0;
    while(A != 2){
        A = Judge_Palindrome(arr) + Judgement_date(arr);
        year++;
        for(int i = 0;i < N/2;i++){
        b = pow(10,3-i);
        arr[i]= arr[i+4] = year /b;
        year = year % b;
        }
    }
    printf("%d",year);
    //return arr;
}


int main(int argc, char *argv[])
{
    int date[N];
    int num,year;
    printf("请输入形如yyyymmdd形式的日期:");
    scanf("%d",&num);
    Array_transfrom(num,date);
    Judgement_date(date);
    Judge_Palindrome(date);
    //find_Palindrome_date(date);
    //year = date[0]*1000+date[1]*100+date[2]*10+date[3];
    int A = 0,b,C=0;
    while(A !=2){
    year = date[0]*1000+date[1]*100+date[2]*10+date[3];
    printf("%d \n",year);
    printf("第一个条件 = %d \n",Judge_Palindrome(date));
    printf("第二个条件 = %d \n",Judgement_date(date));
    A = Judge_Palindrome(date) + Judgement_date(date);
    printf("A = %d \n",A);
    year++;
    for(int i = 0;i < N/2;i++){
        b = pow(10,3-i);
        date[i]= date[N-i-1] = year /b;
        year = year % b;
    }
}
    return 0;
}