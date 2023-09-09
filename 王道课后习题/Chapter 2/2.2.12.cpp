#include<iostream>
using namespace std;
//#define n 10 

int Main_element(int A[],int n){
    int i,c,count = 0;
    c = A[0];                                   //默认c = A[0]为主元素
    for(i = 0; i < n; i++){
        if(A[i] == c)                           
            count++;
        else
            if(count==0){
                c = A[i];
                count++;
            }
            else
                count--;
    }
    if(count > 0)                               //统计主元素真正出现的次数
        for(i = count = 0; i < n; i++){
            if(A[i]==c)
                count++;
        }
    if(count>n/2)                               //出现次数大于n/2才算主元素
        return c;
    else
        return -1;
}

int main(){
    int A[] = {1,4,8,6,8,8,8,8,8,9};
    int n = 10;
    cout <<"主元素是"<< Main_element(A,10) << endl;
    return 0;
}