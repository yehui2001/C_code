#include<iostream>
using namespace std;
#define maxSize 20

void Pack(int n,int m,int v[],int w[],int s[][maxSize]){
    for(int i = 1; i <= n; i++)  s[i][0] = 0;
    for(int j = 0; j <= m; j++)  s[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){                //w[]下标从0开始
            if(w[i-1]>j)  s[i][j] = s[i-1][j];
            else    s[i][j] = max(s[i-1][j],s[i-1][j-w[i-1]]+v[i-1]);
        }
}

void Traceback(int n,int m,int w[],int s[][maxSize],vector<bool> x){   //x[n]用来标识第i个物品的拿取情况，1代表拿，0代表没拿
    for(int i = n; i >= 1; --i)
        if(s[i][m]==s[i-1][m]) x[i] = 0;
        else{
            x[i] = 1;m-=w[i];
        }
}

void Print(int n,int m,int s[][maxSize]){
    for(int j = 0; j <= m; j++)  cout << "\t"<< "容量:"<< j;
    cout << endl;
    for(int i = 0; i <= n; i++){
        cout << "第" << i << "件";
        for(int j = 0; j <= m; j++){
            cout << "\t" << s[i][j];
        }
        cout << endl;
    }
}

int main(){
    int n = 5,m = 10;
    int w[5] = {2,2,6,5,4},v[5] = {6,3,5,4,6};
    vector<bool>x(11,0);
    int s[maxSize][maxSize];
    Pack(n,m,v,w,s);
    Traceback(n,m,w,s,x);
    Print(n,m,s);
    return 0;
}