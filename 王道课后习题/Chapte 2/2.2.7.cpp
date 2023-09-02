#include<iostream>
using namespace std;

#define Maxsize 10

typedef int Elemtype;
typedef struct{
    Elemtype data[Maxsize]; //静态数组存放数据元素
    int length;             //当前长度
} Seqlist;                  //顺序表类型定义

void Init_List(Seqlist &L){
    for(int i=0; i < Maxsize; i++){
        L.data[i] = 0;
    }
    L.length = 0;
}

void Print_List(Seqlist &L){
    cout <<"The SeqList is"<<endl;
    if(L.length == 0)
        cout << "NULL"<<endl;
    for(int i=0; i < L.length; i++)
        cout <<"\t"<<L.data[i];
    cout << endl;
}

/*
算法思想:

*/
void Merge_List(Seqlist &L1,Seqlist &L2,Seqlist &L3){
    int i,j,k;
    for(i = 0,j = 0,k = 0; i < L1.length && j < L2.length;k++){
        if(L1.data[i]>L2.data[j]){
            L3.data[k] = L2.data[j];
            j++;
        }
        else{
            L3.data[k] = L1.data[i];
            i++;
        }
    }
    if(j < L2.length)                   //将有剩余的有序表其他元素加入
        for(;j < L2.length;j++)
            L3.data[k++] = L2.data[j];
    if(i < L1.length)
        for(;i < L1.length;i++)
            L3.data[k++] = L1.data[i];
    L3.length  = L1.length + L2.length;
}

int main(){
    Seqlist L1,L2,L3;
    Init_List(L1);
    Init_List(L2);
    Init_List(L3);
    cout<<"请输入第一个顺序表中要插入的元素个数:"<<endl;
    cin >>L1.length;
    int i;
    for(i = 0; i < L1.length; i++){
        cin >> L1.data[i];
    }
    Print_List(L1);
        cout<<"请输入第二个顺序表中要插入的元素个数:"<<endl;
    cin >>L2.length;
    for(i = 0; i < L2.length; i++){
        cin >> L2.data[i];
    }
    Print_List(L2);

    Merge_List(L1,L2,L3);
    Print_List(L3);
}