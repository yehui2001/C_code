#include<iostream>
#include<vector>
using namespace std;

int Bag_01(vector<int>&v,vector<int>&w,int N,int V){
    int maxsize = max(N,V);
    int **s = new int*[maxsize];
    for(int i = 0; i < maxsize; i++)
        s[i] = new int[maxsize];
    for(int i = 1; i <= N; i++)  s[i][0] = 0;       //The edge point need to be initialize
    for(int j = 0; j <= V; j++)  s[0][j] = 0;
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= V; j++){
            if(v[i-1] > j)
                s[i][j] = s[i-1][j];
            else
                s[i][j] = max(s[i-1][j],s[i-1][j-v[i-1]]+w[i-1]);
        }
    return s[N][V];
    for (int i = 0; i < maxsize; i++) {
        delete[] s[i];
    }
    delete[] s;
}


int main(){
    int N,V;
    cin >> N >> V;      //N means the nums , V means the volume
    vector<int>v(N);
    vector<int>w(N);
    for(int i = 0; i < N; i++)
        cin >> v[i] >> w[i];
    cout << Bag_01(v,w,N,V);
    return 0;
}