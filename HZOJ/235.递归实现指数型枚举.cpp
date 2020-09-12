/*************************************************************************
	> File Name: 235.递归实现指数型枚举.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 12 18:18:02 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;
int n, arr[1000];
int cnt;
void output() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        arr[cnt++] = i;
        output();
        func(i + 1);
        cnt--;
    }
    return ;
}

int main() {
    cin >> n;
    func(1);    
    return 0;
}
