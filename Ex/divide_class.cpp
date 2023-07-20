#include <iostream>
using namespace std;
int main()
{
  int num=0, i=0, s=0 ;
    for (i=0; num<2021; i++){  
    s = i ;
    for (int j=1; s!=0; j++){
        if(s%10==1) num++;
        s/=10 ;
       }
    }
    cout<< i-1 <<endl;
  return 0;
}