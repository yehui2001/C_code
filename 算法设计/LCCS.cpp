//最长连续公共子序列
#include<iostream>
using namespace std;
#define maxSize 10

//m:X序列长度
//n:Y序列长度
//c[i][j]:记录序列Xi和Yj的最长公共子序列的长度
//b[i][j]:用来记录c[i][j]是由那种子问题得到的，用来递归输出,b[i][j] = 1代表当前的两个值相同且是公共子序列的一部分 b[i][j] = 2代表c[i][j]是由左序列(X)得到的
void LCSLength(int m,int n,char x[],char y[],int c[][maxSize],int b[][maxSize]){
    int i,j;
    for(i = 1; i<=m; i++) c[i][0] = 0;  //若任一条序列长度为0，则最长公共子序列也为0
    for(i = 1; i<=n; i++) c[0][i] = 0;  

        for(i = 1; i <= m; i++){
            for(j = 1; j <=n; j++){
                if(x[i]==y[j])  {c[i][j] = c[i-1][j-1]+1; b[i][j] = 1;}                 //若当前值相同，则最长公共子序列长度等于除去此二值以外的最长公共子序列长度+1
                else {c[i][j] = 0; b[i][j] = 2;}    
            }                                                                           
        }
}


void Print_C(int c[][maxSize],int m,int n){
    cout << "C_matrix:"<< endl;
    for(int i=0;i<=m;++i)
        for(int j=0;j<=n;++j){
                cout<<c[i][j]<<"\t";
            if(j==n) cout<<endl;
        }
}

void Print_B(int b[][maxSize],int m,int n){
    cout << "B_matrix:"<< endl;
    for(int i=0;i<=m;++i)
        for(int j=0;j<=n;++j){
                cout<<b[i][j]<<"\t";
            if(j==n) cout<<endl;
        }
}

void Print(char a[],int m){
    for(int i = 1; i <= m; i++)
        cout <<"\t"<< a[i];
    cout << endl;
}

int main(){
    char X[]={' ','A','B','C'},Y[]={' ','A','B','E','C','D'};     //为了保证X[i],Y[j]下标从1开始，X[0],Y[0]设空
    int c[maxSize][maxSize],b[maxSize][maxSize];
    int m = sizeof(X)-1,n = sizeof(Y)-1;
    cout << "X序列为:" << endl;
    Print(X,m);
    cout << "Y序列为:" << endl;
    Print(Y,n);
    LCSLength(m,n,X,Y,c,b);
    cout <<"最长连续公共子序列为:"<< endl;
    cout << endl;
    Print_C(c,m,n);
    Print_B(b,m,n);
    return 0;
}