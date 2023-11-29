#include<iostream>
using namespace std;

int main(){
    const int v[6] = {1,5,10,50,100,500};       //钱币的单价
    int a[6] = {0},money,sum = 0;     
    cout << "请输入各种面值的数量:" << endl;
    for(int i = 0; i < 6; i++){
        cout << "面值" << v[i] << "数量:";
        cin >> a[i];
    }
    cout << "请输入商品价格:" << endl;
        cin >> money;
    for(int i = 5; i >=0; i--){
        int t =  min(money/v[i],a[i]);  //选择当前能用的最大面值钱币数
        money -= t*v[i];                //总金额减少
        sum += t;   
    }

    if(money==0)
        cout << "恰好需要" << sum << "张" << endl;
    else
        cout << "No Way!" << endl;
    return 0;
}