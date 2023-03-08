#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  //printf("请输入学生的人数:");
  int N;
  scanf("%d",&N);

  int grade[N];
  for (int k = 0;k < N; k++)
  {
    scanf("%d",&grade[k]);
  }

  float pass_rate = 0,good_rate = 0;
  for (int i = 0; i < N; i++)
  {
    if(grade[i] >= 60)
    {
        pass_rate = pass_rate + 1;
        if(grade[i] >= 85)
            good_rate = good_rate + 1;
    }
  }
  
  float n = N;
  pass_rate = (int)(100*(pass_rate / n)+0.5); //四舍五入
  good_rate = (int)(100*(good_rate / n)+0.5);


  printf("%2.0f%%\n%2.0f%%\n",pass_rate,good_rate);
  return 0;
}