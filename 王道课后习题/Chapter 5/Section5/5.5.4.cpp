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

void disp(ALGraph *G){
    cout << "邻接表：" << endl;    
    for(int i = 0; i < G->numV; i++){
        cout << G->adjlist[i].info;
        EdgeNode *p = G->adjlist[i].firstEdge;
        while(p){
            cout << "\t" << "->"<< G->adjlist[p->index].info <<"("<< p->weight<<")";
            p = p->next;
        }
        cout << endl;
    }
}

void dispALGraph(ALGraph *G){
    cout << "邻接表：" << endl;    
    for(int i = 0; i < G->numV; i++){
        cout << G->adjlist[i].info;
        EdgeNode *p = G->adjlist[i].firstEdge;
        while(p){
            cout << "\t" << "->"<< G->adjlist[p->index].info <<"("<< p->weight<<")";
            p = p->next;
        }
        cout << endl;
    }
}

void Convert(ALGraph &G2,AdjMatrix &G1){
    for(int i = 0; i < G2.numV; i++){
        EdgeNode * p = G2.adjlist[i].firstEdge;
        while(p!=NULL){
            G1.Edge[i][p->index] = p->weight;
            p = p->next;
        }
    }
}


int main(){
    AdjMatrix G1;
    ALGraph G2;
    CreateGraph(&G2);
    Convert(G2,G1);
    return 0;
}

