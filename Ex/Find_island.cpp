#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char mp[N][N];
int vis[N][N];
int flag;
int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void bfs(int x, int y){
    queue<pair<int, int>> q; //
    q.push({x,y});           //把点(x,y)放进队列
    vis[x][y] = 1;
    while(q.size()){         //处理队列，直到队列为空
        pair<int, int> t = q.front()
        q.pop();             //弹出队首
    }
}


int main(){
    int n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mp[i][j];

}