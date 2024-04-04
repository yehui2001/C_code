#include<iostream>
using namespace std;

//5 6 1 2 3 4 
int Get_Position(int a[],int n,int target){
    int low = 0,high = n-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(a[mid]==target)                   
            return mid;
        else if(a[mid]>=a[low]){            // 4 5 6 7 1 2  
                if(a[low] <= target && target <= a[mid])    //假设查找5
                    high = mid-1;
                else                //假设查找1,说明target>a[mid]或者target<a[low]
                    low = mid+1;
        }
        else if(a[mid]<a[low]){    //a[mid]<a[low]    即 5 6 1 2 3 4   说明mid到high区间部分有序
                if(a[mid] <= target && target <= a[high])
                    low = mid+1;
                else
                    high = mid-1;
        }
    }
    return -1;
}


int main(){
    int n = 6;
    int a[6] = {5,6,1,2,3,4};
    int target  = 4;
    cin >> target;
    cout << "The target_index is " << Get_Position(a,n,target)+1 << endl;;
    return 0;
}