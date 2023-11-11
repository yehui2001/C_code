#include<iostream>
using namespace std;
#define MAXSIZE 100
#define INFINITE 9999

typedef struct Graph{
    char Vertex[MAXSIZE];               //顶点数组
    int Edge[MAXSIZE][MAXSIZE];         //邻接矩阵
    int numV,numE;                      //V顶点数，E边数
}AdjMatrix;

void CreateGraph(AdjMatrix *G){
    int v,e,vi,vj,w;
    cout << "请输入该图的顶点数和边数:" << endl;
    cin >> v >> e;
    G->numV = v;
    G->numE = e;

    //图的初始化
    for(int i = 0; i < G->numV; i++)
        for(int j = 0; j < G->numE; j++)
            i==j?G->Edge[i][j]=0:G->Edge[i][j] = INFINITE;

    //将顶点传入数组
    for(int i = 0; i < v;i++){
        cout <<"请输入第"<< i+1 << "结点的值" << endl;
        cin >> G->Vertex[i];
    } 

    //开始建立边与边的关系 vi -> vj  w
    for(int i = 0; i < G->numE; i++){
        cout << "请输入边的信息 vi vj w" << endl;
        cin >> vi >> vj >> w;
        G->Edge[vi - 1][vj - 1] = w;        //
        G->Edge[vj - 1][vi - 1] = w;        //无向图需要多加这一行
    }
}

void dispGraph(AdjMatrix *G){
    cout << "\n输出顶点的信息(字符):" << endl;
    cout << "\t" << endl;
    for(int i = 0;i < G->numV; i++)
        cout << "\t"<< G->Vertex[i];
    cout << "\n输出邻接矩阵:" << endl;
    cout << "\t" << endl;
    
    cout << "\t";
    for(int i = 0;i < G->numV; i++)
        cout << "\t"<< G->Vertex[i];
    cout << endl;
    for(int i = 0;i < G->numV; i++){
        cout << "\t" << G->Vertex[i];
        for(int j = 0; j < G->numV; j++)
        if(G->Edge[i][j]!=INFINITE)             //判断输出
            cout << "\t" << G->Edge[i][j];
        else
            cout << "\t" << "∞";
        cout << endl;
    }

}
/*
    算法思想:
        三层循环： k i j 
        k:控制每次加入中间结点k
        i,j:遍历{i,j}一遍并获得{i,j}的最小距离，更新距离矩阵
        依次加入过全部结点作为中间结点后得到的距离矩阵A_k，其A_k[i][j]为第i+1个结点到第j+1个结点到最短距离
*/

void PrintPath(int path[][MAXSIZE],int vi,int vj){
    if(path[vi][vj]==-1)                    //vi到vj最短路径上没有中间结点，直接输出vj
        cout << vj+1;
    else{
        int mid = path[vi][vj];
        PrintPath(path,vi,mid);
        PrintPath(path,mid,vj);
    }
}


void floyd(AdjMatrix *G,int path[][MAXSIZE]){
    int i,j,k;
    int dist[MAXSIZE][MAXSIZE];
    for(int m = 0; m < G->numV; m++){
        for(int n = 0; n < G->numV; n++){
            dist[m][n] = G->Edge[m][n];         //初始化两点距离
            path[m][n] = -1;                    //初始化路径
        }
    }

    for(k = 0; k < G->numV; k++)
        for(int i = 0; i < G->numV; i++)
            for(int j = 0; j < G->numV; j++)
                if(dist[i][j] > dist[i][k] + dist[k][j]){           //若中间结点能够使结点之间路径更短，则更新权值
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;                                 //存放中间结点位置
                }
    
    for(int i = 0; i < G->numV; i++){
        for(int j = 0; j < G->numV; j++)
            cout << "\t" << dist[i][j];
        cout << endl;
    }
    PrintPath(path,0,5);            //打印1到6的路径
}


int main(){
    AdjMatrix G;
    CreateGraph(&G);
    dispGraph(&G);
    int path[MAXSIZE][MAXSIZE];
    floyd(&G,path);
    return 0;
}

