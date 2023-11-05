#include<iostream>
#define MAXSIZE 100
#define INFINITE 9999
using namespace std;

typedef struct EdgeNode{
    int index;              //该结点在顶点数组里面的位置信息
    int weight;             //权值
    EdgeNode *next;         //下一个邻接边
}EdgeNode,*EdgeList;

typedef struct VertexNode{
    char info;              //顶点信息
    EdgeNode *firstEdge;    //指向第一条依附该顶点的边的指针，即指向边表的入口
}VertexNode,Adjlist[MAXSIZE];

typedef struct{
    Adjlist adjlist;        //顶点数组
    int numE,numV;          //顶点数，边数
}ALGraph;

void CreateGraph(ALGraph *G){
    int e,v,vi,vj,w;
    cout << "请输入图的边数和顶点数:" << endl;
    cin >> e >> v;
    G->numE = e;
    G->numV = v;

    cout << "请依次输入顶点信息"<< endl;
    for(int i = 0; i < G->numV; i++){
        cout <<"请输入第"<< i+1 << "结点的值" << endl;
        cin >> G->adjlist[i].info;
        G->adjlist[i].firstEdge = NULL;     //初始化
    }

    //建立边表
    for(int i = 0; i < G->numE; i++){
        cout << "请输入边的信息 vi vj w" << endl;
        cin >> vi >> vj >> w;
        EdgeNode * ENode = new EdgeNode;
        ENode->index = vj - 1;
        ENode->weight = w;                              //若是无向图需要重复一遍vj -> vi
        ENode->next = G->adjlist[vi - 1].firstEdge;     //头插法    
        G->adjlist[vi - 1].firstEdge = ENode;
    
    }

}

void DispGraph(ALGraph *G){
    cout << "邻接表：" << endl;    
    for(int i = 0; i < G->numV; i++){
        cout << "\t" << G->adjlist[i].info;
        EdgeNode *p = G->adjlist[i].firstEdge;
        while(p){
            cout << "->"<< G->adjlist[p->index].info <<"("<< p->weight<<")";
            p = p->next;
        }
        cout << endl;
    }
}

/*void OutPut(ALGraph *G,int **weights){
    for(int i = 0; i < G->numV; i++)
        for(int j = 0; j < G->numV; j++){
            if(weights[i][j]!=0)
                cout << i+1 <<"->("<< weights[i][j] <<")"<< j+1 << endl;

        }
}
*/

void Output(ALGraph* G, int** weights) {
    cout << "Kruskal算法最小生成树的边和权值:" << endl;
    for (int i = 0; i < G->numV; i++) {
        for (int j = i + 1; j < G->numV; j++) {
            if (weights[i][j] != 0) {
                cout << G->adjlist[i].info << " ->(" << weights[i][j] << ") " << G->adjlist[j].info << endl;
            }
        }
    }
}

/*
    采用并查集，来判断新加入边的两个顶点是否有公共祖先（即新加入的边加入后是否会构成环）
*/

void Inifather(ALGraph *G,int *fa){
    for(int i = 0; i < G->numV; i++)
        fa[i] = i;                       //最开始将每个结点的祖先设置为自己
}

void Iniweight(ALGraph *G,int **weight){
    for(int i = 0; i < G->numV; i++)    //权值初始化
    for(int j = 0; j < G->numV; j++)
        weight[i][j] = 0;
}

int findAncestor(int *fa,int i){
    if(fa[i]==i)    return i;
    else{
        fa[i] = findAncestor(fa,fa[i]);         //优化，压缩路径，先找到根()结点，再将查找路径上所有结点都挂到根结点下
        return fa[i];                           //未找到继续
    }
}

void Union(int *fa,int i,int j){
    int i_a = findAncestor(fa,i);
    int j_a = findAncestor(fa,j);
    fa[i_a] = j_a;                              //i的祖先指向j的祖先
}

void Kruskal(ALGraph *G){
    int **weights = new int*[G->numV];          //动态分配内存
    for(int i = 0; i < G->numV; i++)
        weights[i] = new int[G->numV];
    Iniweight(G,weights);

    int *fa = new int[G->numV];
    Inifather(G,fa);

    int Edge_Num = 0;
    while(Edge_Num < G->numV-1){
        int weight = INFINITE;
        int start,end;
        for(int i = 0; i < G->numV; i++){       //遍历每一个顶点的所有边
            for(EdgeNode *p = G->adjlist[i].firstEdge;p;p = p->next)
                if(p->weight < weight && findAncestor(fa,i)!=findAncestor(fa,p->index)){
                        weight = p->weight;
                        start  = i;
                        end = p->index;
                }
        }
        Union(fa,start,end);                    //每次加入新边后，让其end顶点成为start顶点的祖先
        weights[start][end] = weight;
        weights[end][start] = weight;
        Edge_Num++;
    }        
    Output(G,weights);
}

int main(){
    ALGraph G;
    CreateGraph(&G);
    DispGraph(&G);
    Kruskal(&G);
    return 0;
}