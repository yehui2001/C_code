#include<iostream>
using namespace std;

int main(){
    int n,N,count = 0;
    cin >> N;
    for(n = 1; n <= N; n++){
        int t = n;
        while(t){              //判断最小分位
            if(t%10==1)        //例如111 110%10==1
                count++;         
            t/=10;             //判断下一个分位   11即原来百分位十分位
        }
    }
    cout << "共有" << count << "个1" << endl;
    return 0;
}