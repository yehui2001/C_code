//此程序用动态分配数组实现顺序表及其基本操作
#include<stdio.h>
#include<stdlib.h>
#define Initsize 2

typedef int Elemtype; 
// 动态分配空间
typedef struct{
    Elemtype *data;
    int length,maxsize; //maxsize为当前能最多容纳的元素数
} Seqlist;

// 初始化动态线性表
void Init_List(Seqlist &L){
    // 用malloc函数申请一片连续的存储空间
    L.data = (Elemtype *)malloc(Initsize*sizeof(Elemtype));
    L.length = 0;
    L.maxsize = Initsize; 
}

//增加动态数组的长度
void Increase_List(Seqlist &L,int len){
    int *p = L.data;        //让p指向data
    L.data = (Elemtype *)malloc((L.maxsize+len)*sizeof(Elemtype));  //申请一片更大的内存区域
    for(int i=0; i<L.length; i++){
        L.data[i] = p[i];   //将旧数据复制到新区域
    }
    L.maxsize += len;
    free(p);                //释放p指针，它指向的区域也会自动被系统删除
}

// 打印线性表
void Print_List(Seqlist &L){
    printf("\nThe SeqList is ");
    if(L.length == 0)
        printf("Null");
    for(int i=0; i < L.length; i++){
        printf("%d\t",L.data[i]);
    }
    printf("\n");
}

// 插入数据元素 
bool Insert_List(Seqlist &L,int i,Elemtype e){ //i means the position inserted,e is the element inserted.
    char s;
    if(i<1||i>L.length+1)   //判断插入位置是否合法，即不属于顺序表的逻辑结构
        return false;
    if(L.length == L.maxsize){//当前存储空间已满
        printf("存储空间已满!\n是否扩容？y/n\n");
        scanf("%c",&s);
        if(s=='y'){
            Increase_List(L,1);
        }
        else
            return false;
    }
    for(int j=L.length; j>=i; j--){ //此处的j i 都是指元素的位序，从1开始。
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

// 删除数据元素
bool Delete_List(Seqlist &L,int i,Elemtype &e){ //用e来返回删除的值
    if(i<1||i>L.length+1)   //判断插入位置是否合法
        return false;
    e = L.data[i-1];
    for(int j=i; j<L.length; j++){ //若要删除最后一个元素，只是将表长减1，最后一个元素其实没有被覆盖掉
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;    
}

// 查找数据元素
int Find_List(Seqlist &L,Elemtype e){ //查找值为e的数据元素的下标
    int i;
    for(int i=0; i < L.length; i++){
        if(L.data[i] == e){
            return i+1;
        }
    }
    return 0;
}

int main(){
    Seqlist L;
    Init_List(L);
    Print_List(L);
    Insert_List(L,1,99);
    Insert_List(L,2,999);
    Insert_List(L,3,888);
    Print_List(L);
    Elemtype e = -1,a = 99;
    Delete_List(L,2,e);
    Print_List(L);
    printf("\nThe %d position is%d\n",a,Find_List(L,a));
    return 0;
}