#include<bits/stdc++.h>
using namespace std;
const int n = 10;
char mp[n+2][n+2];
bool vis[n+2][n+2];
int solve[n+2][n+2]; 
/* 若某位置的人可以走出去，那么处于他走出去路径上的人也一定可以走出去
所以，我们建造一个可以存储能走出去的位置的数组。 可以大大降低复杂度 o(n^4) -> o(n^2)
*/
int ans = 0;
int cnt = 0;
bool dfs(int i, int j){
    if(i < 0 || i > n-1 || j < 0 || j > n-1)
        return true;
    /* 
    if(solve[i][j] == 1) return true; //等于1代表能出去
    if(solve[i][j] == 2) return false;
    */
    if(vis[i][j]) //碰壁代表死胡同，无法走出去
        return false;
    cnt++;
    vis[i][j] = true; //代表第[i,j]个位置被走过了
    // 先判断第一次走的方向,然后进入递归开始判断下一次要走的方向
    /*
    if(mp[i][j] == 'L'){
        if(dfs(i,j-1)) //路径记录: 回溯，记录整条路径都能走出去，从出口反向映射到[i,j];
            solve[i][j] = 1; // 若位于[i,j]先左走能走通,则认为[i,j]能走通
        else    
            solve[i][j] = 2;
        }
    */
    if(mp[i][j] == 'L') return dfs(i,j-1);
    if(mp[i][j] == 'R') return dfs(i,j+1);
    if(mp[i][j] == 'U') return dfs(i-1,j);
    if(mp[i][j] == 'D') return dfs(i+1,j);
}

int main(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mp[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dfs(i,j)) ans++;
            memset(vis, 0 ,sizeof(vis)); //下一个人走之前清空记忆矩阵
        }
    }
    cout << "ans = " << ans << ",cnt = " << cnt << endl;
}
/*
测试数据:
UDDLUULRUL
UURLLLRRRU
RRUURLDLRD
RUDDDDUUUU
URUDLLRRUU
DURLRLDLRL
ULLURLLRDU
RDLULLRDDD
UUDDUDUDLL
ULRDLUURRR

ans = 31 
*/