/*************************************************************************
	> File Name: 56.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月29日 星期三 21时04分38秒
 ************************************************************************/
#include<iostream>
using namespace std;

#define STATUS 1000000
#define MAX_N  15
int fac[MAX_N] = {0}; //存10个数的阶乘；
int num[MAX_N]; //存这些数字有没有输出过(用过)，有的话标记为0，求阶乘时会初始化为1

//求阶乘
void init(int x) {
    fac[0] = 1;
    for(int i = 1; i <= x; ++i) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }
    return ;
}

//返回两个数，一个是引用变量temp表示当前位要输出几temp就想法跳到几
//另一个返回还需跳几个状态n
int get_num(int n, int fac, int &temp) {
    int step = n / fac;

    //让x从第一个没用过的数(从最小的往后判段)开始跳
    int j = 1;
    while(!num[j]) j++;
    temp = j;

    //跳step步
    while(step) {
        if(num[temp + 1]) {
            temp++;
            step--;
        } else { //下一个数输出过就再看下下个，这一步不算step不减
            temp++;
        }
    }

    //最后temp跳到了该跳到数，标记一下这个数，下次不能用了
    num[temp] = 0;
    //求出还需要跳跃的状态次数
    n %= fac;
    return n;
}

int main() {
    int x, y;
    cin >> x >> y;
    init(x);

    int n = y - 1; //当前需要跳跃得次数(状态数)
    
    //共x个数，输出x次
    for(int i = x; i >= 1; i--) {
        int temp;
        //传入需要跳跃的次数，剩下几个数的阶乘，一个引用返回当前位是几下面输出他
        n = get_num(n, fac[i - 1], temp);
        cout << temp;
    }
    cout << endl;
    return 0;
}

