#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  int T_w,n,i;
  scanf("%d",&T_w);
  for(i = 1;pow(3,i)<2*T_w; i++){}
  printf("%d\n",i);  
  return 0;
}
