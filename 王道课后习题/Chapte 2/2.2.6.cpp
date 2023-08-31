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

void Delete(Seqlist &L,Elemtype s,Elemtype t){
    if(s >= t || L.length==0)
        return;
    int k = 0;                              
    for(int i = 0; i < L.length; i++){      //删除x元素相当于,把每个非x元素向前移动的步数 = 其前面总共的x元素的个数
        if(L.data[i] >= s&&L.data[i] <= t)
            k++;
        else
            L.data[i-k] = L.data[i];
    }
    L.length -= k;
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
    Delete(L,2,8);
    Print_List(L);
}