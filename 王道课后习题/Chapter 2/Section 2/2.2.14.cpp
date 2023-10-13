#include<iostream>
using namespace std;

int Min(int a,int b){
    return a<b?a:b;
}

int Dist(int a,int b,int c){
    return (abs(a-b)+abs(b-c)+abs(c-a));
}

int Min_Dist(int A[],int B[],int C[],int a,int b,int c){
    int i,j,k,min;
    min = Dist(A[0],B[0],C[0]);
    for(i = 0; i < a; i++)
        for(j = 0; j < b; j++)
            for(k = 0; k < c; k++){
                min = Dist(A[i],A[j],A[k]);
                //min = Min(min,Dist(A[i],A[j],A[k]));
                cout << min << endl;
            }
    return min;
}

int main(){
    int S1[] = {-1,0,9},S2[] = {-25,-10,10,11},S3[] = {2,9,17,30,41};
    Min_Dist(S1,S2,S3,sizeof(S1)/sizeof(int),sizeof(S2)/sizeof(int),sizeof(S3)/sizeof(int));
    return 0;
}