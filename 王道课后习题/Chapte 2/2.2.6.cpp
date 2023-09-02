#include<iostream>
using namespace std;

#define Maxsize 50

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
    类似于直接插入思想，将第一个元素视为有序表，然后判断后面插入的元素是否与前面序列的最后一个元素相同
若相同，则向后查找

*/
void Delete_SameElem(Seqlist &L){
    if(L.length == 0)
        return;
    int i = 0;
    for(int j = 1; j < L.length; j++){
        if(L.data[j] != L.data[i]){
            L.data[++i] = L.data[j];
        }
    }
    L.length  = i+1;
}

int main(){
    Seqlist L;
    Init_List(L);
    cout<<"请输入要插入的元素个数:"<<endl;
    cin >>L.length;
    for(int i = 0; i < L.length; i++){
        cin >> L.data[i];
    }
    Print_List(L);
    Delete_SameElem(L);
    Print_List(L);
}