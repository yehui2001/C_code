#include<iostream>
using namespace std;
#define maxsize 10
#define ElemType int

void swap(int &a,int &b){
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

/*
    折半插入排序:
        链表无法使用，仅限顺序表
        先折半查找有序表，找到应该插入的位置，然后移动后面元素，进行插入
    空间复杂度:O(1)
    时间复杂度:O(n^2)
*/

void Bionary_Sort(int A[],int n){
    int i,j,low,high,mid,temp;      //low有序表的起点下标,high代表有序表的终点下标
    for(int i = 1; i < n; i++){
        temp = A[i];                //获得待插元素的值
        low = 0;                    //每次要查找位置时候，有序表的始点下标重新赋值为0
        high = i-1;                 //要插入第i+1个元素，当前的有序表的长度显然为i（下标从0开始）
        
        //查找操作
        while(low <= high){
            mid = (low+high)/2;     //取有序序列中的中间元素的值
            if(A[mid] > temp)       
                high = mid-1;
            else                    //若出现A[mid] = temp;则继续查找右半子表，保证其稳定性，出现相同的元素向后插
                low = mid + 1;
        }
        //解释:循环终止前，low = mid = high,若此时指向的元素A[high]<temp,low = mid + 1，插入位置一定在该high后一位,A[high]< A[i]<=A[low],因为high后两位的位置一定比temp大(之前已经检查过了）。  
        //插入操作          插入位置low(两者相同)
        for(int j = i;j > low;j--)  //最后一次进入j=low+1 A[low+1] = A[low]
            A[j] = A[j-1];
        A[low] = temp;
    }
    Print(A);
}

/*
    直接插入算法:
        每次将一个待排序的记录按其关键字大小插入前面已排好的子序列，直到全部记录插入完成。
    空间复杂度:O(1)
    时间复杂度:最好情况O(n),最坏情况O(n^2)

*/       
void InsertSort(int A[],int n){
    int i,j,temp;
    for(i = 1; i < n; i++){                      //默认第一个元素是已排好的序列
        if(A[i] < A[i-1]){                       //若A[i]的值小于其前驱，将A[i]插入
            temp = A[i];                         //j>0用来结束查找完成，如temp为最小值
            for(j = i; A[j-1]>temp&& j>0; j--)  //若有序表中该结点的前一个结点值比temp值大，后移
                A[j] = A[j-1];                   //直到某个结点的前一个结点<=temp，则该结点的位置即插入位置  
            A[j] = temp;                         //复制到插入位置
        }
    }
    Print(A);
}

/*
    希尔排序:
        用一个增量将待排序表分割成若干子表
    空间复杂度:O(1)
    时间复杂度:最好情况(O^1.3),最坏情况(O^2)
*/

void ShellSort(int A[],int n){
    int d,i,j,temp;                            //d代表查找增量
    for(d = n/2;d >= 1; d/=2)                  //默认增量为长度的一半
        for(i = d; i < n; i++){                //后续代码采用直接插入排序的逻辑
            if(A[i]<A[i-d]){                   //若A[i]值小于其子表的前驱结点的值
                temp = A[i];
                for(j = i; j >0 && temp < A[j-d];j-=d)  //向前找该结点在所在子表的位置
                    A[j] = A[j-d];
            A[j] = temp;
            }
        }
    Print(A);
}


/*
    快速排序:
        采用分治的思想
        1.每次选取待排序列的首个元素为枢轴元素，将序列分为左右子表
        2.然后递归进行，直到子表长度为0
    空间复杂度:最差情况O(n),最好情况O(nlogn)
    时间复杂度:最差情况O(n^2),最好(平均)情况O(nlogn)
*/

int Partition(int A[],int low,int high){
    int temp = A[low];                               //取第一个元素为枢轴元素
    while(low < high){                               //low(包括low)左侧的值都是小于等于temp的值，high(包括high)右侧的值都是大于等于temp的值，若二者相同，则是temp的位置
        while(temp<=A[high]&&low<high)               //必须加上low<high，否则high指针(用来寻找high左侧,low右侧小于枢轴元素值的元素)会找到low的左侧(小于枢轴元素的区域)
            high--;
        A[low] = A[high];
        while(temp>=A[low]&&low<high)                //上下两个while至少要有一个等号，否则会陷入死循环，即a[low] = a[high],且low,high不会变
            low++;
        A[high] = A[low];
    }
    A[low] = temp;                                   //此处的high跟low相同
    return low;
}

void QuickSort(int A[],int low,int high){
    if(low < high){                                   //子表元素个数大于等于1个
        int pivotpos = Partition(A,low,high);         //获得枢轴元素位置 
        QuickSort(A,low,pivotpos-1);                  //左子表
        QuickSort(A,pivotpos+1,high);                 //右子表
    }    
}

/*
    简单选择排序:
        每趟从未排序[i,n]的序列中选出最小的元素与L[i]交换，依此循环n-1趟
    空间复杂度:O(1)
    时间复杂度:O(n^2)
*/

void SelectSort(int A[],int n){
    int i,j;
    for(i = 0; i < n-1; i++){           //总共进行n-1趟比较
        int min = i;
        for(j = i+1; j < n; j++)
            if(A[min]>A[j])
                min = j;
        swap(A[min],A[i]);
    }
}

/*
    归并排序：
        二路归并，两个相邻的有序表两两合并
    空间复杂度:O(n);
    时间复杂度:O(nlogn);
*/
void Merge(int A[],int low,int mid,int high){
    int i,l,m;
    int *B = new int[high+1];
    for(i = low; i <= high; i++)
        B[i] = A[i];
    for(l = low,m = mid+1,i = l; l <= mid && m <= high; i++){       //low是左表的起点，mid+1是右表的起点，每次循环选取一个值i++
        if(B[l]<=B[m])                              //从前往后依此比较两表的值
            A[i] = B[l++];                          //比较若左表中元素更小，则取出赋值
        else
            A[i] = B[m++];
    }
    while(l<=mid)                                   //处理表中剩余元素
        A[i++] = B[l++];
    while(m<=high)
        A[i++] = B[m++];
}

void MergeSort(int A[],int low,int high){
    if(low < high){                                 //直到有序表中只有一个元素
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

void HeadAdjust(int *A,int k,int len){          //k为子树根结点下标
    A[0] = A[k];                                //A[0]作为哨兵用来记录子树根结点的值
    for(int i = 2*k; i <=len; i*=2){            //从最后一个子树的左孩子结点开始
        if(i < len && A[i]<A[i+1])              //选择更大的叶子结点
            i++;
        if(A[0] > A[i])     break;              //比较叶子结点值与根结点A[0]的值，若小于根结点，则子树满足大根堆
        else{                                   
            A[k] = A[i];                        //否则，将孩子结点的值放到根结点上
            k = i;                              //更新根结点的下标k = i,继续向下查找A[0]的位置
        }
    }
    A[k] = A[0];
}

void BuildMaxHeap(int *A,int len){
    for(int i = len/2; i > 0; i--)              //从最后一个父亲结点(子树)开始调整，因为一共有len个结点
        HeadAdjust(A,i,len);                    //最后一个叶子结点的下标为len，求父亲结点为len/2向下取整
}

void HeapSort(int *B,int len){
    int *A = new int[len+1];
    for(int i = 1; i <= len; i++)
        A[i] = B[i-1];
    cout << "堆排序序列:" << endl;
    BuildMaxHeap(A,len);        
    for(int i = len; i >= 1; i--){
        cout << A[1] << "\t";
        swap(A[i],A[1]);                        //交换堆底堆定
        HeadAdjust(A,1,i-1);                    //调整剩下i-1个结点
    }
}



int main(){
    int A[maxsize] = {2,4,5,6,1,7,6,8,9,0};
    int n = sizeof(A)/sizeof(int);
    cout << "原序列为:" << endl;
    Print(A);
    ///Bionary_Sort(A,n);
    //InsertSort(A,n);
    //ShellSort(A,n);
    //BubbleSort(A,n);
    //QuickSort(A,0,n-1);
    //SelectSort(A,n);
    //MergeSort(A,0,n-1);
    HeapSort(A,10);
    //Print(A);
    return 0;
}