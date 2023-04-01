#include<iostream>
#include<cmath>
using namespace std;

int sum_digit(int n){
    int sum = 0,i = 0,j = 0,num = n,temp;
    while(n > 0){
        n = n / 10;
        i++;
    }
    while(i-j >= 0){
        temp = pow(10,i-j);
        sum += num / temp;
        num = num % temp;
        j++;
    }
    return sum;
}

int digit(int n){
    int sum = 0,i = 0,j = 0,num = n,temp;
    while(n > 0){
        n = n / 10;
        i++;
    }
    return i;
}

int main(){
    int n,m,i,j,l,k = 1;
	cin>>n>>endl;
	int sort[n];
	cin>>m>>endl; 
    for(j = 1; j <= 54; j++){
        for(i = 1; i <= n; i++){
            if(sum_digit(i) == j){
                sort[k++] = i;
            }
        }
    }
    cout<<sort[m]<<endl;
    return 0;
}


