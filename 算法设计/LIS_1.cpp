//使用动态规划算法查找序列的最长公共上升子序列
#include<iostream>
using namespace std;

int LISlength(int a[],int n){
    int dp[n+1],len = 1;
    for(int i = 1; i <= n;i++){
        dp[i]=  1;                              //默认以a[i]结尾的最长上升子序列都是1，因为一个元素算长度为1的上升子序列
        for(int j = 1; j <i; j++){
            if(a[j]<a[i])
                dp[i] = max(dp[i],dp[j]+1);     //dp[i]不是一定比dp[j]+1小的，例如 1 5 3 4 2 8  i = 6,j = 5时，此时dp[6] = 4, dp[5]+ 1 = 3;
        }
        len = max(len,dp[i]);
        cout <<"dp["<<i <<"] = "<< dp[i]<<endl;
    }
    cout << "len =" << len << endl;
    return len;
}


int main(){
    int a[] = {0,1,5,3,4,2,8};
    int n = sizeof(a)/sizeof(int)-1;
    LISlength(a,n);
    return 0;
}