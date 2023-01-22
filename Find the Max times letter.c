#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) //
{
  // 请在此输入您的代码
  int times[26] = {0},max = 0, i; //先分别创建存放26个字母出现次数的数组
  char ch;
  while((ch = getchar()) != '\n') //依次读取字符串中字符，遇到'\n'停止。
    times[ch-'a']++;
  for(i = 1; i < 26; i++)
    if(times[i] > times[max]) 
      max = i;
  printf("%c\n%d",max+'a',times[max]);
  return 0;
}
