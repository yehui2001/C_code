#include <iostream>
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

typedef struct {
    int *data;
    int front,rear;             //定义队头指针和队尾指针
}SqQueue;

void CreateQueue(SqQueue &Q,int n){      //初始化队空 
    Q.data = new int[n];
    Q.front = Q.rear = 0;        //默认队尾指针指向队尾元素后一个位置
}

bool EmptyQueue(SqQueue &Q){
    if(Q.rear == Q.front)
        return true;
    return false;
}

bool FullQueue(SqQueue &Q){
    if(Q.front==(Q.rear+1)%MAXSIZE)
        return true;
    return false;
}

bool EnQueue(SqQueue &Q,int x){
    if(FullQueue(Q))     //判断队满
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MAXSIZE;        //通过取余运算，达到循环队列的目的。
    return true;
}

bool DeQueue(SqQueue &Q,int &x){
    if(EmptyQueue(Q))
        return false;
    x = Q.data[Q.front];
    Q.front =(Q.front+1)%MAXSIZE;
    return true;
}

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
        EdgeNode * ENode1 = new EdgeNode;                //vi -> vj
        ENode1->index = vj - 1;                          //index从0开始
        ENode1->weight = w;                              //赋值
        ENode1->next = G->adjlist[vi - 1].firstEdge;     //在vi的边表中使用头插法插入vj结点
        G->adjlist[vi - 1].firstEdge = ENode1;
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

void visit(ALGraph *G,int v){
    cout <<"\t"<< G->adjlist[v].info << endl;
}


void BFS(ALGraph *G,int *visited,int v){ //类似于二叉树的层次遍历
    SqQueue Q;
    CreateQueue(Q,G->numV);
    visit(G,v);
    visited[v] = true;
    EnQueue(Q,v);
    while(!EmptyQueue(Q)){
        DeQueue(Q,v);
        for(EdgeNode *w = G->adjlist[v].firstEdge; w ; w = w->next)  //遍历第v个结点的边表
            if(!visited[w->index]){                                  //边表中有元素，则访问后入队
                visit(G,w->index);
                visited[w->index] = true;
                EnQueue(Q,w->index);
            }
    }
}


//采用BFS算法求结点u到i的最短路径
void BFS_MIN_Distance(ALGraph *G,int u){
    num = u--;
    SqQueue Q;
    CreateQueue(Q,G->numV);
    //d[i]表示从u到i结点的最短路径
    int *d = new int[G->numV];                  //定义最短路径数组
    for(int i = 0; i < G->numV; i++)
        d[i] = INFINITY;
    d[u] = 0;
    int *visited = new int[G->numV];            //定义访问标记数组
    for(int i = 0;i < G->numV; i++)
        visited[i] = false;                     //访问标记数组初始化
    visited[u] = true;
    EnQueue(Q,u);
    while(!EmptyQueue(Q)){
        DeQueue(Q,u);
        for(EdgeNode *w = G->adjlist[u].firstEdge;w;w = w->next)
            if(!visited[w->index]){                    //w为u的尚未访问的邻接顶点
                visited[w->index] = true;              //设置标记
                d[w->index] = d[u] + 1;                //路径长度+1
                EnQueue(Q,w->index);            //w顶点入队
            }
    }
    for(int i = 0; i < G->numV;i++)
        cout << "\t" << "第" << num <<"个结点到值" <<G->adjlist[i].info<<"的最短路径长度为:"<< d[i] << endl;
}


//Input: 
int main(){
    ALGraph G;
    CreateGraph(&G);
    DispGraph(&G);
    cout << "单源最短路径为:" << endl;
    BFS_MIN_Distance(&G,1);
    return 0;
}