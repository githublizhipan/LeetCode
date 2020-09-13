/*************************************************************************
	> File Name: 236.递归实现组合型枚举.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 12 21:44:09 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;
int n, m, arr[1000], cnt;

void func(int s, int left) {
    if (left == 0) {
        for (int i = 0; i < m; i++) {
            if (i) cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }
    for (int i = s; i <= n; i++) {
        arr[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
    return ;
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
