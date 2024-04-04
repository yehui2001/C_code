#include<iostream>
#include<vector>
using namespace std;

/*
    算法思想：动态规划问题
    dp[i]用来表示前i个元素的最大字段和，a[i]表示第i个元素的值
    dp[i] = max（dp[i-1]+a[i],a[i]）
*/
void maxSum(vector<int>&a,int n){
    vector<int>dp(n);
    dp[0] = a[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i-1]+a[i],a[i]);
    }
    int max = dp[0];
    for(int i = 1; i < n; i++)
        max<dp[i]?max=dp[i]:0;
    cout << "最大字段和为" << max << endl;
}


int main(){
    int n;
    cout << "请输入元素个数："<< endl;
    cin >> n;
    vector<int>a(n);
    cout << "请输入数据"<< endl;
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    maxSum(a,n); 
    return 0;
}