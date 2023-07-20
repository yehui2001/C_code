#include <bits/stdc++.h>
using namespace std;
int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int b[20];
int ans = 0; //记录步长
bool vis[20];

void dfs(int s,int t){
    if( s == 12){
        if(b[9] == b[10] * b[11])
            ans++;
        return;
    }
    //剪枝:提前停止搜索到优化技术,可以极大减少无效搜索。
    if(s == 3 && b[0] + b[1] != b[2]) return;
    if(s == 6 && b[3] - b[4] != b[5]) return;
    if(s == 9 && b[6] * b[7] != b[8]) return;

    for(int i = 0; i < t; i++){
        if(!vis[i]){
            vis[i] = true;
            b[s] = a[i];
            dfs(s + 1, t);
            vis[i] = false;
        }
    }
}

int main(){
    dfs(0,13);
    cout << ans << endl;
    return 0;
}