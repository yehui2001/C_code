#include<iostream>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //处理两种特殊情况
    if(m==0){           //第一个数组为空，合并后即为第二个数组                  
        nums1 = nums2;
    }
    if(n==0){           //第二个数组为空，合并后即为第一个数组
        return;
    }
    int i,j,k = 0;
    int *b = new int[m+n];   
    for(i = 0,j = 0; i < m && j < n;){
        if(nums1[i]<nums2[j])
            b[k++] = nums1[i++];
        else
            b[k++] = nums2[j++];
    }
    while(i < m)   b[k++] = nums1[i++];
    while(j < n) b[k++] = nums2[j++];
    for(k = 0; k < m+n; k++)
        nums1[k] = b[k];
}
    
int main(){
    vector<int>nums1 = {1,2,7,0,0,0};
    vector<int>nums2 = {2,5,6};    
    int m = 3,n = 3;
    merge(nums1,m,nums2,n);
    return 0;
}