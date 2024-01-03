#include<iostream>
using namespace std;

// Value[i][j] = Min{Value[i][j-1],Value[i-1][j]} + A[i][j]
int Getmin(int map[4][4],int n,int m){
    if(n<=0||m<=0)  return 0;
    //创建动态规划结果矩阵dp[][]
    int dp[n][m];
    //求解第一行第一列的结果值，将边界值先求出
    dp[0][0] = map[0][0];
    for(int j = 1; j < m; j++){
        dp[0][j] = dp[0][j-1] + map[0][j];
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + map[i-1][0];
    }
    //从上到下，从左到右，求任意dp[i][j]
    for(int i = 1; i < n; i++)
        for(int j = 1 ; j < m; j++)
        dp[i][j] = map[i][j] + min(dp[i-1][j],dp[i][j-1]);
    return dp[n-1][m-1];
}

int main(){
    int n  = 4,m = 4;
    int dp[4][4] = {
        {1,2,3,4},
        {4,8,3,2},
        {6,1,4,5},
        {7,3,7,8},
    };
    cout << Getmin(dp,n,m);
    return 0;
}