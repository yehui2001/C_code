#include<iostream>
#include<vector>
using namespace std;



int main(){
    int m,n,p;
    cin >> n >> m >> p;
    vector<int>table(n,-1);
    vector<int>nums(m);
    for(int i = 0; i < m; i++)
        cin >> nums[i];

    for(int i = 0; i < n; i++){
        int pos = nums[i]%p;
        while(table[pos++]!=-1)
            table[pos] = nums[i];
    }

    for(int i = 0; i < n; i++)
        cout << table[i] << '\t';

    return 0;
}