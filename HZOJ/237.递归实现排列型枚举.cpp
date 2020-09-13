/*************************************************************************
	> File Name: 237.递归实现排列型枚举.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 12 23:12:53 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;

int n, arr[1000], cnt, mark[1000];

void func(int left) {
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            arr[cnt++] = i;
            func(left - 1);
            mark[i] = 0;
            cnt--;
        }
    }
    return ;
}

int main() {
    cin >> n;
    func(n);
    return 0;
}
