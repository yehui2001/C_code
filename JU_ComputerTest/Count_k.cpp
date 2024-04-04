#include<iostream>
#include<vector>
using namespace std;


//  要求时间复杂度为logn,故需要采用二分查找

int Count_K(vector<int> &a,int n, int k){
    int ans = 0;
    int low = 0,high = n-1,i,j;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==k){
            ans++;
            i = mid-1;
            j = mid+1;
            while(a[i]==k && i>=0){ //若第i个位置仍然是K，则继续向左查找
                ans++;
                i--;
            }
            while(a[j]==k && j< n){
                ans++;
                j++;
            }
            break;
        }
        else if(a[mid] > k)
            high = mid-1;
        else if(a[mid] < k)
            low = mid+1;
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << Count_K(a,n,k) << endl;
    return 0;
}