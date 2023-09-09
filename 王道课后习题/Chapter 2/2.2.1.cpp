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

bool Insert_List(Seqlist &L,int i,Elemtype e){ //i means the position inserted,e is the element inserted.
    if(i<1||i>L.length+1)   //判断插入位置是否合法，即不属于顺序表的逻辑结构
        return false;
    if(L.length == Maxsize) //当前存储空间已满
        return false;       
    for(int j=L.length; j>=i; j--){ //此处的j i 都是指元素的位序，从1开始。
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

void Print_List(Seqlist &L){
    cout <<"The SeqList is"<<endl;
    if(L.length == 0)
        cout << "NULL"<<endl;
    for(int i=0; i < L.length; i++){
        cout <<"\t"<<L.data[i];
    }
}

Elemtype Delete_List(Seqlist &L,int i){ //i 为要删除元素的位序,e来返回删除元素的值
    if(i<1||i>L.length+1)   //判断删除位置是否合法
        return false;
    int e = L.data[i-1];
    L.data[i-1] = L.data[L.length-1];
    L.length--;
    return e;    
}

bool Delete_Min(Seqlist &L,Elemtype &Min){
    int min = 0;
    if(L.length==0)
        return false;
    for(int i = 1; i < L.length; i++){
        if(L.data[i]<L.data[min]){
            min = i;
        }
    }
    Min = Delete_List(L,min+1);
    return true;
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
    int Min;
    Delete_Min(L,Min);
    cout<<"\n"<<"最小被删元素:"<<Min<<endl;
    Print_List(L);
    cout<<endl;
}