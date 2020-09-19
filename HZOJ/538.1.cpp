/*************************************************************************
	> File Name: 538.1.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 19 08:46:10 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int n, arr[25][25], check[25], flag;

void func(int s) {
    if (flag) {
        cout << "-";
    }
    flag = 1;
    cout << s;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0 && arr[s][i] == 1) {
            check[i] = 1;
            func(i);
        }
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            func(i);
        }
    }

    return 0;
}
