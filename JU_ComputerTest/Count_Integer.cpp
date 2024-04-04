#include<iostream>
#define MAX 10
using namespace std;


typedef struct{
    int posi;
    int count;
}data;

int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    cout << "请输入序列：" << endl;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    data t[MAX];
    for(int i = 0; i < MAX; i++){       //初始化
        t[i].count = 0;
        t[i].posi = i;
    }

    for(int i = 0; i < n; i++){
        t[a[i]].count++;
    }

    //冒泡排序
		for(int i = 0; i < MAX-1; i++)                 //共进行n-1趟排序
			for(int j = MAX-1; j > i; j--)             //向前查找
				if(t[j].count > t[j-1].count){         //若前一个元素值比该元素小，则交换值
                    swap(t[j].count,t[j-1].count);
                    swap(t[j].posi,t[j-1].posi);
            }

    for(int i = 0; i < MAX ; i++)
        if(t[i].count)
            cout << t[i]. posi << "\t" << t[i].count << endl;
        else
            continue;

    return 0;
}