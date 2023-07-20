#include<bits/stdc++.h>
using namespace std;
int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
bool vis[20]; //用来记录第i个数是否已经被选过，在单次递归中选过的数不能在后面继续选
int b[20];    //生成一个全排列
void dfs(int s, int t){
    if(s == t){ //递归结束
        for(int i = 0; i < t; i++)
            cout << b[i] << " ";
            cout << endl;
            return;
    }
    for(int i = 0; i < t ; i++){
        if(!vis[i]){    // 直到知道没有被访问过的数，才赋值
            vis[i] = true;
            b[s] = a[i]; // 当第二次递归时，此处的s为s+1 代表第二个数是a[i]
            dfs(s+1,t);
            vis[i] = false;
        }
    }
}
int main(){
    int n = 6;
    printf("----------%d的全排列为:----------\n",n);
    dfs(0,n);
    printf("\n-------------------------------\n");
    return 0;
}