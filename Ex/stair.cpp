#include<iostream>
using namespace std;

int climbStairs(int n) {
    int *dp = new int[n+1];
    dp[1] = 1,dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-2] + dp[i-1];
    return dp[n];
}

string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;
        int dp[n][n];       
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;

        for(int j = 1; j < n; j++)
            for(int i = 0; i < j; i++){
                if(s[i]==s[j]&&(j-i<=2||dp[i+1][j-1])){
                    dp[i][j] = 1;
                    if(j-i > end-start){
                        start = i;
                        end = j;
                    }
                }
            }
    return s.substr(start, end-start+1);    //substr(起始下标，截取字符串的长度)
}

int maxProfit(int prices[5]) {
        int n = sizeof(prices);
        int inf = 1e9;
        int minprice = inf,maxprofit = 0;
        for(int i = 0; i < n; i++){
            maxprofit = max(maxprofit,prices[i]-minprice);
            minprice = min(prices[i],minprice);
        }
        return maxprofit;
}

/*
int climbStairs(int n) {
        int *dp = new int[n+1];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i-2] + dp[i-1];
        return dp[n];
    }
*/



int main(){
    //cout << climbStairs(10) << endl;  
    cout << longestPalindrome("cbbd");   
    cout << longestPalindrome("babcd");  
    int prices[] = {7,1,5,6,3,4};
    cout << maxProfit(prices);
    return 0;
}