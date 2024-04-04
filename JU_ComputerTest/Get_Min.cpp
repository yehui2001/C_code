#include<iostream>
using namespace std;

//要求时间复杂度logn，故采用二分查找        
int Get_Min(int a[],int n){
    int low = 0,high = n-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(a[mid]>a[high])              //3 4 5 1 2 说明最小值在右半部分
            low = mid+1;
        else if(a[mid]<a[high])         //1 2 3 4 5 说明最小值在左半部分
            high = mid;
        else
            high--;                     //2 2 2 1 2 说明a[high]值没有意义
    }
    return a[mid];
}

int main(){
    int n = 5; 
    int a[5] = {1,2,3,4,5};
    cout << "The Min is " << Get_Min(a,5) << endl;
    return 0;
}