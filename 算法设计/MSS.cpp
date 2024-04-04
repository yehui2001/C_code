//Max subsequence sum problem
#include<iostream>
using namespace std;

int Maxsum(int a[],int n){
    int sum = 0,b = 0;                  //sum用来记录最大子段和,b[i]用来记录前i个元素的子段和
    for(int i = 1; i <= n; i++){
        if(b>0)b+=a[i];                 
        else b = a[i];                  //若当前子段和已经小于0，则重新开始取正元素为新子段和的首元素
        if(b>sum) sum = b;              //等同于max{b[i-1]+a[i],a[i]}     
    }
    return sum;
}

int main(){
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maxsum = "<< Maxsum(a,sizeof(a)/sizeof(int)-1) << endl;
    return 0;
}