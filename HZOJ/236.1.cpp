/*************************************************************************
	> File Name: 236.1.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Fri Sep 18 22:05:01 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, cnt, arr[15];

void func(int s, int left) {
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
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
