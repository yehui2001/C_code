#include<iostream>
using namespace std;

#define Maxsize 50

typedef int Elemtype;
typedef struct{
    Elemtype data[Maxsize]; //静态数组存放数据元素
    int length;             //当前长度
} Seqlist;                  //顺序表类型定义

void Swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

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
    折半查找
*/
void Find(Seqlist &L,Elemtype x){
    int low = 0,high = L.length-1,mid;
    mid = (low + high)/2;
    while(low <= high){
        if(L.data[mid] > x){
            high = mid - 1;
            mid = (high + low)/2;
        }
        else{
            low = mid + 1;
            mid = (high + low)/2;
        }
    }

    if(L.data[mid]==x && mid!=L.length-1){  //若x元素位于表的末尾，则不交换
        Swap(L.data[mid],L.data[mid+1]);
    }
    if(L.data[mid]!=x){
        for(int i = L.length; i > mid; i--){
            L.data[i] = L.data[i-1];
        }
        L.data[mid+1] = x;                   //L.data[mid] < x <= L.data[low]
        L.length++;
    }
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
    int x = 6;
    Find(L,x);
    Print_List(L);
}