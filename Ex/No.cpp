#include<iostream>
using namespace std;


void Move(int *a,int p,int q,int n){
    int temp,t;
    for(int i = 1; i <= n; i++)
    if(a[i]==p){
        temp = i;
        break;
    }

    //确定最终位置
    if(temp+q <= 1)
        t = 1;
    else if(temp + q >= n)
        t = n;
    else
        t = temp + q;

    int c = a[temp];
    if(q>0){
        int i;
        for(i = temp; i <= t-1; i++)
            a[i] = a[i+1];
        a[i] = c;
    }
    else {
        int i;
        for(i = temp; i >= t+1; i--)
            a[i] = a[i-1];
        a[i] = c;
    }

    for(int i = 1; i <= n; i++)
        cout <<'\t'<< a[i];
    cout << endl;
}

void Print(int *a,int n){
    for(int i = 1; i <= n; i++)
        cout << a[i];
}

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    int a[n+1],b[m+1][2];
    for(int i = 1; i <=n ;i++)
        a[i] = i;
    for(int i = 1; i <=m; i++){
        cin >> b[i][0] >> b[i][1];
    }
    for(int i = 1; i <=m; i++)
        Move(a,b[i][0],b[i][1],n);

    Print(a,n);
    return 0;
}