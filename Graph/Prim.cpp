#include<iostream>
using namespace std;
#define MAXSIZE 10
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

//求最小生成树的权值
int Getsum(AdjMatrix *G,int *prims){
    int sum = 0;
    for(int i = 1; i < G->numV; i++){             //i从1开始，以防把INFINITE加入
        int min = INFINITE;
        for(int j = 0; j < i; j++){                 //从连通区域（0 i-1 已加入的结点中）找到与下一个结点i的最小权值，依此循环
            if(G->Edge[prims[j]][prims[i]] < min){
                min = G->Edge[prims[j]][prims[i]];
            }
        }
        sum += min;
    }
    return sum;
}

void Prim(AdjMatrix *G,int start){
    int prims[MAXSIZE];         //存储最小生成树结果数组    例如 1 4 2 3 元素代表顶点的值
    int lowCost[MAXSIZE];       //start结点到各个顶点的边的权值
    int min,k,index = 0;        //index辅助下标
    lowCost[--start] = 0;         //自己到自己距离为0
    prims[index++] = start;
    for(int i = 0; i < G->numV; i++)
        lowCost[i] = G->Edge[start][i];                 //1.把以start为始点的边的权值传入

    for(int i = 0; i < G->numV; i++){                   //遍历一次加一个结点
        if(start == i)
            continue;
        min = INFINITE;
        for(int j = 0; j < G->numV; j++){
            if(lowCost[j]!=0 && lowCost[j] < min){      //2.从连通边的权值中找最小权值,且未被访问过
                min = lowCost[j];
                k = j;                                  //记录位置
            }
        }

        //3.已找到最小值，更新prims数组
        prims[index++] = k;             
        lowCost[k] = 0;                 //将找到的第k个结点置为已访问（0代表与连通区域距离为0），即代表它已加入最小生成树

        //4.更新lowCost数组 看新加入的k结点到各个顶点的距离是否比原来的连通区域到各个顶点距离还要小
        for(int j = 0; j < G->numV; j++){
            if(lowCost[j] && G->Edge[k][j] < lowCost[j])    //lowCost[j]排除已经加入的结点
                lowCost[j] = G->Edge[k][j];
        }
    }
    cout << "最小生成树为：" << endl;
    for(int i = 0; i < G->numV; i++)
        cout << "\t" << prims[i]+1;

    Getsum(G,prims);
}


//Input: 6 10 123456 145 462 656 523 216 311 345 364 356 325
int main(){
    AdjMatrix G;
    CreateGraph(&G);
    dispGraph(&G);
    Prim(&G,1);
    return 0;
}