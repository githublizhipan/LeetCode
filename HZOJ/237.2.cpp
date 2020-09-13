/*************************************************************************
	> File Name: 237.2.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sun Sep 13 10:40:02 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;

int n, arr[30], cnt, mark[30];

void func(int left) {
    if (left == 0) {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            arr[cnt++] = i;
            mark[i] = 1;
            func(left - 1);
            cnt--;
            mark[i] = 0;
        }
    }
    return ;
}

int main() {
    cin >> n;
    func(n);
    return 0;
}
