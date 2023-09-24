#include<iostream>
using namespace std;
#define N 50

//代码分析：当left = 2，right = 3,mid = 2;
//i = 2,m = 2,j = 3,n = 3;进行最后一次调用，将相邻的两个元素进行对调

//合并两个有序表
void Merge(int a[],int temp[],int left,int mid,int right){
    int i = left,m = mid,j = mid + 1,n = right,k = 0;
    while(i<=m && j<=n){
        if(a[i]<a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=m)
        temp[k++] = a[i++];
    while(j<=n)
        temp[k++] = a[j++];

    for(i = 0; i < k; i++)              // i < k
        a[left + i] = temp[i];          //注意此处是a[left+i]
}

//递归
void MergeSort(int a[],int temp[],int left,int right){
    if(left < right){
        int mid = (left+right)/2;
        MergeSort(a,temp,left,mid);                  //让左半边有序
        MergeSort(a,temp,mid+1,right);               //使右半边有序
        Merge(a,temp,left,mid,right);           //合并到temp[]中
    }
}

void Print(int a[],int n){
    cout << "序列为:" <<endl;
    for(int i = 0; i < n; i++){
        cout <<"\t"<< a[i];
    }
}

int main(){
    int num[N];
    int temp[N];
    int n;
    cout <<"请输入想要插入元素的个数:"<< endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    Print(num,n);
    MergeSort(num,temp,0,n-1);          //n-1为最后一个元素的下标
    Print(num,n);
    return 0;
}