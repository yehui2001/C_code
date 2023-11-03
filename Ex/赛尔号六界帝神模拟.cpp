#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void visit(int (*num)[3],int i,int j){
    num[i][j] = (num[i][j]==1)?0:1;
}

bool Success(int num[3][3]){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(num[i][j]==0)
                return false;
    return true;
}

void Print(int num[3][3]){
    for(int i = 0; i < 3; i++){
        cout << endl;
        for(int j = 0; j < 3; j++)
            cout << "\t"<< num[i][j];
    }
}


int main(){
    int num[3][3] = {0,0,0,0,0,0,0,0,0};   
    int step = 0;
    srand((unsigned)time(NULL));
    int sum = 0;
    while(!Success(num)){
        int i = rand()%3+ 1;
        for(int j = 1; j <= i; j++){
            int a = rand()%3;
            int b = rand()%3;
            visit(num,a,b);
        }
        step++;
        cout <<"\n第"<<step<<"次结果为:"<< endl;
        Print(num);
    }
    cout << endl;
    return 0;
}