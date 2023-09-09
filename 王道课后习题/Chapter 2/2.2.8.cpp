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

void Reverse_TwoList(Seqlist &L,int m,int n){
    if(m > n){
        for(int i = 0; i < n; i++){
            Swap(L.data[i],L.data[m+i]);
        }
        for(int k = 0; k < n; k++){
            int temp = L.data[m+k];
            for(int j = n+k; j < m+k ; j++){    //此处是向后移位插入
                L.data[j+1] = L.data[j];    
            }
            L.data[n+k] = temp;
        }
    }
    else{
        for(int i = 0; i < m; i++){
            Swap(L.data[i],L.data[m+i]);
        }
        for(int k = 0; k < n-m; k++){
            int temp = L.data[2*m+k];
            for(int j = m+n-1; j > m ; j--){    //此处是向后移位插入
                L.data[j] = L.data[j-1];    
            }
            L.data[m+k] = temp;
        }
    }
}

//改用使用逆置函数实现

//先定义带有左右起点(left、right分别指向首尾元素)的逆置函数
void Reverse(Seqlist &L,int left,int right){
    if(left >= right)  return;
    for(int i = 0; i <= (right+left)/2 - left; i++) //除法默认向下取整，等于的情况需要考虑（0+9）/2 = 4,A[4]需要与A[5]交换
        Swap(L.data[left+i],L.data[right-i]);
}

void Exchange(Seqlist &L,int m,int n){
    Reverse(L,0,L.length-1);
    Reverse(L,0,n-1);
    Reverse(L,n,L.length-1);
}


int main(){
    Seqlist L;
    Init_List(L);
    int m,n;
    cout<<"请输入要插入的两个表的长度分别为:"<<endl;
    cin >> m >> n;
    L.length = m + n;
    cout<<"输入元素:"<<endl;
    for(int i = 0; i < L.length; i++){
        cin >> L.data[i];
    }
    Print_List(L);
    //Reverse_TwoList(L,m,n);
    Exchange(L,m,n);
    Print_List(L);
}