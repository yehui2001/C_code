#include<iostream>
using namespace std;
#define maxSize 10
//

void MatrixChain(int p[],int n,int m[][maxSize],int s[][maxSize]){          //p用来存放A[1;n]的行列数(其中共有n+1个元素，A1的列等于A2的行)，n是矩阵总个数，m是从第i个矩阵连乘到第j个矩阵的计算量，s是最优解下标
    for(int i = 1; i <= n; i++) m[i][i] = 0;            //序列中只有一个元素的时候，无需连乘
    for(int r = 2; r <= n; r++)                         //r为规模数，记主对角线标号为r = 1，依次向上标号为r = 2......
        for(int i = 1; i <= n-r+1; i++){                //n-r+1是需要计算计算量的矩阵组合个数
            int j = i+r-1;                              //保证计算在斜边上进行
            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];     //在第i个矩阵处分开，获得初始计算量
            s[i][j] = i;                                //分割位置默认为i

            for(int k = i+1; k < j; k++){               //查找从第i个矩阵到第j个矩阵最小计算量的最佳分割位置
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(t < m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
//输出m表格
    cout << "从第i个矩阵连乘到第j个矩阵的最小计算量:" <<endl;
	for(int i=1;i<=n;++i){
        for(int t=1;t<i;t++) cout<<"\t";
		for(int j=i;j<=n;++j)
			{
				cout<<m[i][j]<<"\t";
				if(j==n) cout<<endl;
			}
    }
}
void Traceback(int i,int j,int s[][maxSize]){
    if(i == j)  return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout<<"A"<<i<<","<<s[i][j]<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}

int main(){
    int p[7]={30,35,15,5,10,20,25},n=6;
    int m[maxSize][maxSize],s[maxSize][maxSize];
	MatrixChain(p,6,m,s);
	Traceback(1,6,s);
    return 0;
}