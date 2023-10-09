//基于链式存储构造哈夫曼树
#include<iostream>
#define Maxsize 20
using namespace std;

typedef struct HuffmanNode{
    char id;                        //存放的信息
    int weight;                      //权值(使用频率)
    struct HuffmanNode *left;
    struct HuffmanNode *right;
}HuffmanNode;

//采用快排对每个结点数据(从HT[f]到HT[r])升序排列
void QuickSort(HuffmanNode *HT[],int low,int high){     //f为开始结点下标，r为结尾结点下标
    HuffmanNode *s; 
    int i = low,j = high;                                        
    if(i < j){
        s = HT[i];
        while(i < j){
            while(i < j && HT[j]->weight >= s->weight)    j--;
            HT[i] = HT[j];
            while(i < j && HT[i]->weight <= s->weight)    i++;
            HT[j] = HT[i];
        }
        HT[i] = s;
        QuickSort(HT,low,i-1);
        QuickSort(HT,i+1,high);
    }
} 

HuffmanNode *HuffmanTree(int Weight[],char ID[],int n){
    HuffmanNode *HT[Maxsize],*p,*q,*s;      //使用循环队列存放排放之前的结点
    int front = 0,rear = 0;                            
    for(int i = 0; i < n; i++){
        s = new HuffmanNode;
        s->weight = Weight[i];
        s->id = ID[i];
        s->left = NULL;
        s->right = NULL;
        HT[rear] = s;
        rear = rear+1;
    }

    QuickSort(HT,front,rear-1);             //尾结点下标从rear-1开始

    while(rear!=front+1){                   //结束时，rear指向表尾的后一个结点，front指向第一个结点
        p = HT[front++];
        q = HT[front++];

        s = new HuffmanNode;                //拿两个最小的结点出来合成为一个结点
        s->left = p;
        s->right = q;
        s->weight = p->weight + q->weight;  //权值等于两者加和
        HT[rear] = s;
        rear = (rear+1);
        QuickSort(HT,front,rear-1);         //尾结点下标从rear-1开始
    }
        return HT[rear-1];          
}

void InOrder(HuffmanNode *HT){
    if(HT!=NULL){
        InOrder(HT->left);
        InOrder(HT->right);
        cout << HT->weight<<"\t";
    }
}

int main(){
    HuffmanNode *HT;
    int Weight[6] = {45,13,12,16,9,5};
    char ID[6] = {'a','b','c','d','e'};
    HT = HuffmanTree(Weight,ID,6);
    InOrder(HT);
    return 0;
}