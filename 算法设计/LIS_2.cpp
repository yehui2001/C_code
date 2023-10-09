//基于贪心及二分搜索实现的LIS
#include<iostream>
using namespace std;
#define maxSize 10

int main(){
    int a[] = {1,5,3,4,2,8,9,4};
    int n = sizeof(a)/sizeof(int);               //例如tail[1] = 1,tail[2] = 2,tail[3] = 4
    //int tail[n];                               //用来存放长度为i的最长公共上升子序列的最小尾值
    vector<int>tail(n+1,0);
    int len = 0;                                 //记录最长长度
    int mid;
    for(int i = 0; i < n; i++){
        int x = a[i];
        int l = 0, r = len;                      //l为返回的x的下标
        while(l <= r){                           //按升序需要插入位置,若tail中存在某个数比x大，会覆盖，若x比tail中所有数大，会插在末尾
            mid = (l+r)/2;
            if(tail[mid]==x) return mid;
            if(tail[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        tail[mid+1] = x;                            //更新tail[l+1]的值，原来tail[l+1] >= x
        len = max(len,mid+1);
    }
    cout << "len = " << len << endl;
    return 0;
}