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

int main(){
    AdjMatrix G;
    CreateGraph(&G);
    dispGraph(&G);
    return 0;
}

