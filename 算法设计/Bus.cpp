#include<iostream>
using namespace std;

void Value(int *a,int n){
    int i,j,dp[11];                               //dp[i]用来记录里程
    dp[0] = 0;
    for(i = 1; i <= 10; i++)    
        dp[i] = a[i];                         //默认初值为直接乘车到第i距离到花费                    
    for(i = 1; i <= 10; i++)
        for(j = i; j <= n; j++)
            dp[j] = min(dp[j],dp[j-i]+a[i]);
    cout << "花费为:" << dp[n] << endl;
}

int main(){
    int n,a[11];
    cout << "车站费用信息:" << endl;
    for(int i = 1; i <= 10; i++)
        cin >> a[i];
    cout << "请输入你想要去往的站点的公里数:" << endl;
    cin >> n;
    Value(a,n);
    return 0;
}