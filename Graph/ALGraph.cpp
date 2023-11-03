#include<iostream>
#define MAXSIZE 100
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
        cout << G->adjlist[i].info;
        EdgeNode *p = G->adjlist[i].firstEdge;
        while(p){
            cout << "\t" << "->"<< G->adjlist[p->index].info <<"("<< p->weight<<")";
            p = p->next;
        }
        cout << endl;
    }
}

int main(){
    ALGraph G;
    CreateGraph(&G);
    DispGraph(&G);
    return 0;
}