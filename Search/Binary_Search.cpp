#include<iostream>
using namespace std;
typedef int Elemtype;

typedef struct{
    Elemtype *elem;
    int Tablelen;
}SSHTable;

int Bionary_Search(SSHTable s,Elemtype key){
    int low = 0, high = s.Tablelen-1,mid;
    while(low<=high){
        int mid = (low+high)/2;
        int temp = s.elem[mid];
        if(temp == key)h                        //若直接找到则直接输出
            return mid;
        else if(temp > key)                     //查找左半边    注意与二分排序区别
            high = mid-1;
        else 
            low = mid+1;                        //查找右半边
    }
    return -1;                                  //失败返回-1
}

int main(){

    return 0;
}
