#include<iostream>
using namespace std;

//划分
int Partition(int a[],int p,int r){
    int temp = a[p];                        //取基准元素
    while(p < r){                           
        while(a[r] >= temp && p < r)        //必须加上low<high，否则high指针(用来寻找high左侧,low右侧小于枢轴元素值的元素)会找到low的左侧(小于枢轴元素的区域)
            r--;
        a[p] = a[r];
        while(a[p] <= temp && p < r)        //上下两个while至少要有一个等号，否则会陷入死循环，即a[p] = a[r],且p,r不会变
            p++;
        a[r] = a[p];
    }
    a[r] = temp;
    return r;
}

void QuickSort(int a[],int p,int r){   
    if(p < r){
        int q = Partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}

void Print(int a[]){
    cout << "链表序列:" << endl;
    for(int i = 0; i < 10; i++){
        cout << a[i] << "\t";
    }
}



int main(){
    int a[10] = {3,1,5,3,2,9,3,5,4,6};
    Print(a);
    QuickSort(a,0,9);
    Print(a);
    return 0;
}