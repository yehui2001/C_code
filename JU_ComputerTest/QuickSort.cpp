#include<iostream>
#include<vector>
using namespace std;

int QuickSort(vector<int>&A,int low,int high){
    int i = low, j = high;
    if(i < j){
        int temp = A[i];
        while(i!=j){
            while(A[j]>=temp&&i < j)   j--;
            A[i] = A[j];
            while(A[i]<=temp &&i < j)   i++;
            A[j] = A[i];
        }
        A[i] = temp;
        int pivotpos = i;
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}



int main(){
    int n;
    cout << "请输入序列的长度" << endl;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    QuickSort(nums,0,n-1);
    cout << "排序后的序列为：" << endl;
    for(int i = 0; i < n; i++)
        cout << "\t" << nums[i];
    cout << endl;
    return 0;
}