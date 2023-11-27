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

//类似于Prim
void Dijkstra(AdjMatrix *G,int start){
    start--;
    int flag[MAXSIZE];                              //访问标记数组
    int dist[MAXSIZE];                              //其他顶点到start结点到距离
    int prevs[MAXSIZE];                             //存放枢轴元素(当前离源最短结点)
    int k = start;
    for(int i = 0; i < G->numV; i++){
        dist[i] = G->Edge[start][i];                //初始化start到各顶点距离
        prevs[i] = 0;
        flag[i] = 0;
    }
    flag[0] = 1;                                    

    for(int i = 0; i < G->numV; i++){
        if(start==i)
            continue;
        int min  = INFINITE;
        for(int j = 0 ;j < G->numV; j++){           //找目前能到达的权值最小顶点
            if(!flag[j]&&dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        flag[k] = 1;                                //加入新顶点
        for(int m = 0; m < G->numV; m++){           //更新dist数组 看新加入的k结点到各个顶点的距离是否比原来的连通区域到各个顶点距离还要小
            if(!flag[m]&&dist[m] > G->Edge[k][m]+dist[k]){
                dist[m] = G->Edge[k][m]+dist[k];
                prevs[m] = k;
            }
        }  
    }

    //打印
    for(int i = 0; i < G->numV; i++)
        i == start?cout <<'\t'<<0:cout <<'\t'<< G->Vertex[prevs[i]];
    cout << endl;
    for(int i = 0; i < G->numV; i++)
        cout <<"\t"<< dist[i];

}
            



//Input: 10 6 123456 145 462 656 523 216 311 345 364 356 325
int main(){
    AdjMatrix G;
    CreateGraph(&G);
    dispGraph(&G);
    Dijkstra(&G,1);
    return 0;
}