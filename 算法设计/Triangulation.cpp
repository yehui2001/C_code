#include<iostream>
using namespace std;
#define maxSize 10

int p[6][6] = {{0,2,2,3,1,4},{2,0,1,5,2,3},{2,1,0,2,1,4},{3,5,2,0,6,2},{1,2,1,6,0,1},{4,3,4,2,1,0}};//凸多边形的权

int w(int i,int j,int k){
	return p[i][j]+p[k][j]+p[i][k];
}

void triangleDivide(int n,int t[maxSize][maxSize],int s[maxSize][maxSize]){          //p用来存放A[1;n]的行列数(其中共有n+1个元素，A1的列等于A2的行)，n是矩阵总个数，t是从第i个矩阵连乘到第j个矩阵的计算量，s是最优解下标
    for(int i = 1; i <= n; i++) t[i][i] = 0;            //序列中只有一个元素的时候，无需连乘
    for(int r = 2; r <= n; r++)                         //r为规模数，记主对角线标号为r = 1，依次向上标号为r = 2......
        for(int i = 1; i <= n-r+1; i++){                //n-r+1是需要计算计算量的矩阵组合个数
            int j = i+r-1;                              
            t[i][j] = t[i][i] + t[i+1][j] + w(i-1,i,j);     
            s[i][j] = i;                                

            for(int k = i+1; k < j; k++){               
                int m = t[i][k] + t[k+1][j] + w(i-1,j,k);
                if(m < t[i][j]){
                    t[i][j] = m;
                    s[i][j] = k;
                }
            }
        }
//输出t表格
    cout << "t:" <<endl;
	for(int i=1;i<=n;++i){
        for(int t=1;t<i;t++) cout<<"\t";
		for(int j=i;j<=n;++j)
			{
				cout<<t[i][j]<<"\t";
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
    int t[maxSize][maxSize],s[maxSize][maxSize];
    triangleDivide(6,t,s);
    Traceback(1,6,s);
    return 0;
}