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

void Find_midpos(Seqlist &L){
    int step = 0,pos = 0;
    for (int i = 0,j = L.length/2; i < L.length/2 && j < L.length;){
        if(L.data[i] < L.data[j]){
            step++;                     //
            if(step==L.length/2){
                pos = i;
                break;
            }
            i++;
        }
        else{
            step++;
            if(step==L.length/2){
                pos = j;
                break;
            }
            j++;
        }
    }
    cout <<"中位数:"<< L.data[pos] <<endl;
}

int main(){
    Seqlist L;
    Init_List(L);
    cout<<"请输入要插入的元素个数(偶数):"<<endl;
    cin >>L.length;
    for(int i = 0; i < L.length; i++){
        cin >> L.data[i];
    }
    Print_List(L);
    Find_midpos(L);
}