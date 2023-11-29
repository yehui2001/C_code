#include<iostream>
using namespace std;


void BubbleSort(int *A,int n){
		for(int i = 0; i < n-1; i++)                //共进行n-1趟排序
			for(int j = n-1; j > i; j--)            //向前查找
				if(A[j] < A[j-1])                   //若前一个元素值比该元素大，则交换值
					swap(A[j],A[j-1]);
}

/*
    算法思想:
        贪心算法
        1.首先对人的体重排序，然后将最大体重的人与最小体重人的重量之和与最大载重Max比较
        2.如果没有超过Max则可以乘船，否则体重大的单独一搜船
        3.然后再比较体重第二大的人与最小体重加和与Max的关系，以此类推
*/

int main(){
    int Max = 86;                                   //最大载重量
    int n = 6;
    int count = 0;
    int Weight[] = {10,84,82,80,85,81};
    BubbleSort(Weight,n);
    for(int i = 0,j = n-1; i <= j;){
        if(Weight[i]+Weight[j] < Max){
            i++;
            j--;
            count++;
        }
        else{
            j--;
            count++;
        }
    }
    cout << "需要的最少船只数:" << count << endl;
    return 0;
}