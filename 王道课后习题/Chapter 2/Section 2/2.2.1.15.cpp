#include<iostream>
using namespace std;

int dis(int a,int b,int c){
    return abs(b-a)+abs(c-b)+abs(c-a);
}

int min(int a,int b,int c){
    if(a<b&&a<c)    return a;
    else if(b<a&&b<c)   return b;
    else return c;
}

int Find_Minoftrip(int *S1,int *S2,int *S3,int len1,int len2,int len3){
    int i = 0,j = 0,k = 0;
    int Min = 1000;
    int NowD = 0;
    while(i<len1 && j<len2 && k<len3){
        NowD = dis(S1[i],S2[j],S3[k]);
        Min = NowD<Min?NowD:Min;
        if(min(S1[i],S2[j],S3[k])==S1[i])  i++;
        else if(min(S1[i],S2[j],S3[k])==S2[j])  j++;
        else k++;
    }
    return Min;
}


int main(){
    int S1[] = {-1,0,9},S2[] = {-25,-10,10,11},S3[] = {2,9,17,30,41};
    cout << Find_Minoftrip(S1,S2,S3,3,4,5) << endl;
    return 0;
}