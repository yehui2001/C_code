#include<stdio.h>
#include<stdlib.h>
#define maxsize 10


void Swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Print(int A[]){
    for(int i = 0;i < maxsize;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}

//直接插入排序
void InsertSort(int A[],int n){                           //数组传参时，实际上传的是地址
    printf("直接插入排序\n");
    printf("------------------------------------------------------------------------------------------\n");
    int temp,i,j;
    for(i = 1; i < n; i++){
        if(A[i]<A[i-1]){
            temp = A[i];                            //保留当前元素
            for(j = i; A[j-1]>temp && j>0; j--){    //寻找当前元素在已排序序列中的位置，j>0，保证找到序列头部的时候停止，认为当前元素是已排序序列中的最小元素
                A[j] = A[j-1];                      //若前一个元素的值大于当前元素，后移，将前面的元素后移                 
            }
            A[j] = temp;                            //复制到对应位置j处
        }
        printf("第%2d躺的结果为:",i+1);
        Print(A);
    }
}

//带哨兵的直接插入排序
void InsertSort_Sentry(int A[],int n){
    int i,j;
    for(i = 2; i < n; i++){
        if(A[i]<A[i-1]){
                A[0] = A[i];                         //存放当前元素;
            for(j = i; A[j-1]>A[0]; j--){            //无需判断j>0,因为当j=1时，A[j-1] = A[0]不大于A[0]自动跳出循环
                A[j] = A[j-1];
            }
            A[j] = A[0];
        }
    }
}

//折半插入排序
void Half_InsertSort(int A[],int n){
    int i,j,low,mid,high,temp;
    for(i = 1; i < n; i++){
        temp = A[i];
        low = 0;
        high = i-1;
        while(low<=high){                       //循环结束时找到A[i] 元素在已排序序列中的位置high               
            mid = (low+high)/2;                 //取中间点，向下取整
            if(A[mid]>temp)
                high = mid - 1;                 //查找左半子表
            else                                //若出现A[mid] = temp;则继续查找右半子表，保证其稳定性
                low = mid + 1;                  //查找右半子表
        }
        for(j = i; j>low;j--){                  //默认low所指位置是待插位置
            A[j] = A[j-1];                      //解释:循环终止前，low = mid = high,若此时指向的元素A[high]<temp,low = mid + 1，插入位置一定在该high后一位,A[high]< A[i]<=A[low],因为high后两位的位置一定比temp大(之前已经检查过了）。
        }                                       
        A[low] = temp;
    }
}

//希尔排序
void ShellSort(int A[],int n){
    int d,i,j,temp;
    for(d = n/2;d >= 1; d/=2)  //最大步长d设为总长度一半
        for(i=d;i<n;i++)       //访问各个子表是交替的
            if(A[i]<A[i-d]){
                temp = A[i];
                for(j = i-d; j>=0&& temp<A[j];j -= d)       //在以d为间距的子表中向前进行直接插入排序
                    A[j+d] = A[j];                          
                A[j+d] = temp;
            }
}

//冒泡排序
void BubbleSort(int A[],int n){
    printf("冒泡排序\n");
    printf("------------------------------------------------------------------------------------------\n");
    int i,j;
    bool flag;
    for(i = 0; i < n; i++){
        for(j = 0;j < n-i-1; j++){            //向后冒泡
            flag = false;               //定义每躺初始的交换状态为false
            if(A[j]>A[j+1]){
                Swap(A[j],A[j+1]);
                flag = true;
            }
        }
        printf("第%2d躺的结果为:",i+1);   //便于查看，可注释
        Print(A);
        if(!flag){                      //若某躺排序中，并未发生元素交换，则认为序列有序。
            printf("------------------------------------------------------------------------------------------\n");
            printf("该序列已有序，提前停止排序");
            return;    
        }
    }
}

void BubbleSort_front(int A[],int n){
    printf("冒泡排序\n");
    printf("------------------------------------------------------------------------------------------\n");
    int i,j;
    bool flag;
    for(i = 0; i < n-1; i++){           //i所指位置之前的元素已排序，当i = n - 1时，其前n-1元素已排序。
        for(j = n - 1;j > i; j--){      //向前冒泡
            flag = false;               //定义每躺初始的交换状态为false
            if(A[j]<A[j-1]){
                Swap(A[j],A[j-1]);
                flag = true;
            }
        }
        printf("第%2d躺的结果为:",i+1);   //便于查看，可注释
        Print(A);
        if(!flag){                      //若某躺排序中，并未发生元素交换，则认为序列有序。
            printf("------------------------------------------------------------------------------------------\n");
            printf("该序列已有序，提前停止排序");
            return;    
        }
    }   
}

//快速插入排序
void QuickSort(){

}

int main(){
    int num[maxsize] = {9,8,7,8,6,5,4,3,2,1};
    int lens = sizeof(num)/sizeof(int);
    //输入序列
    printf("请输入序列:");
    /*
    for(int i=0;i<maxsize;i++){
        scanf("%d",&num[i]);
    }
    */
    printf("原序列:\n");
    Print(num);
    printf("------------------------------------------------------------------------------------------\n");
    //InsertSort(num,lens);
    //printf("直接插入排序:\n");
    //Print(num);
    //Half_InsertSort(num,lens);
    //printf("折半插入排序:\n");
    //ShellSort(num,lens);
    //printf("希尔排序:\n");
    BubbleSort_front(num,lens);
    //Print(num);
    return 0;
}