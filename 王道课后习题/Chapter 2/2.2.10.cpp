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

void Swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Reverse(Seqlist &L,int left,int right){
    if(left >= right)  return;
    for(int i = 0; i <= (right+left)/2 - left; i++) //除法默认向下取整，等于的情况需要考虑（0+9）/2 = 4,A[4]需要与A[5]交换
        Swap(L.data[left+i],L.data[right-i]);
}

/*算法思想
    先整体倒置，然后分别调整前半部分跟后半部分。
    ab -> (ab)' = b'a' ->(b')'(a')' = ba
*/

void Divert(Seqlist &L,Elemtype p){
    Reverse(L,0,L.length-1);
    Reverse(L,0,L.length-p-1);            
    Reverse(L,L.length-p,L.length-1);      
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
    Divert(L,2);
    Print_List(L);
}