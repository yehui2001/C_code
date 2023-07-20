#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define N 101

void Print(int dp[N][N],int n){
    int i,j;
    for(i = 1;i <= n;i++){
	    for(j =1;j <= i;j++){
		printf("%d\t",dp[i][j]);
    }
    printf("\n");
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

int main(int argc, char *argv[])
{
    //n代表三角形行数
	int n;
    scanf("%d",&n);

    //将数据填入数字三角形
    //为了让数组中的下标与三角形的行列对齐，我们让数组从i = 1, j = 1开始
    int dp[N][N],i,j;
	for(i = 1;i <= n;i++)
		for(j = 1; j <= i; j++)
			scanf("%d",&dp[i][j]);

    //打印检测
    //Print(dp,n);

    int p,q;
        for(p = 2; p <= n; p++){
            for(q = 1;q <= p; q++){
                dp[p][q] += max(dp[p-1][q-1],dp[p-1][q]);
            }
        }
    
    //由于三角形具有类似平衡二叉树的性质(向左走次数与向右走次数相差不能超过1）,
    //边界为: n - 1 = 2k + 1 , k+1 -> 可以连续向左(右)走的最大次数 k -> 可以连续向右(左)走的最小次数
    //故极值点只能出现在以下两个位置

    //printf("最大和为:");
    printf("%d\n",max(dp[n][(n+1)/2],dp[n][(n+2)/2])); //n为奇数的时候，位置只有一个是[n][(n+2)/2]
    
    return 0;
}