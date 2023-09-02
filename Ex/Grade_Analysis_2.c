#include <stdio.h>
#include <stdlib.h>

int Max(int *grade,int N){
    int max = grade[0];
    int i;
    for(i  = 0;i < N ; i++){
        if(max < grade[i]){
            max = grade[i];
        }
    }
    return max;
}

int Min(int *grade,int N){
    int min = grade[0];
    int i;
    for(i  = 0;i < N ; i++){
        if(min > grade[i]){
            min = grade[i];
        }
    }
    return min;
}

float Avg(int *grade,int N){
    float Avg = 0,Sum = 0;
    int i;
    for(i  = 0;i < N ; i++){
        Sum = Sum + grade[i];
    }
    return Avg = Sum/N;
}


int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  //printf("请输入学生的人数:");
  int N;
  scanf("%d",&N);

  int grade[N],max,min,k;
  float avg;
  for (k = 0;k < N; k++)
  {
    scanf("%d",&grade[k]);
  }
   max = Max(grade,N);
   min = Min(grade,N);
   avg = Avg(grade,N);
   printf("%d\n%d\n%4.2f",max,min,avg);
   return 0;
}
