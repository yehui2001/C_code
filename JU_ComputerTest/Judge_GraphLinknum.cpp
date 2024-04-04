#include<iostream>
#define MAXSUM 1000
using namespace std;

int Group[MAXSUM];
int Dist[MAXSUM][MAXSUM];

void DFS(int i, int n){                     //深度优先算法
    Group[i] = 1;                           //访问第i个结点
    for(int j = 0; j < n; j++){
        if(Dist[i][j]==1)                   //如果与之有相邻的结点，且未被访问，则继续访问
            if(Group[j]!=1)
                DFS(j,n);
    }
}
    

int main(){
    int n,m,p,q,k=0;
    for(int i = 0; i < MAXSUM; i++)
        for(int j = 0; j < MAXSUM; j++){
            Dist[i][j] = 0;                 //初始化邻接矩阵，初始值为0
            Group[i] = 0;
        }  

    cout << "输入图的节点数n和边数m:" << endl;
    cin >> n >> m;                  //输入图的节点数n,和边数m
    cout << "依次输入边点信息:" << endl;

    for(int i = 0; i < m; i++){             //依次输入边点信息
        cin >> p >> q;
        Dist[p-1][q-1] = 1;
        Dist[q-1][p-1] = 1;                 //无向图需要记录两遍边的信息
    }

    for(int i = 0; i < n; i++){
        if(Group[i]!=1){
            DFS(i,n);                           
            k++;                            //执行完DFS之后，若有剩余的结点未被访问，则将连通子图数+1
        }
    }
    cout << "连通子图"<< k << endl;
    return 0;
}