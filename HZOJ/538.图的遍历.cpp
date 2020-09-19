/*************************************************************************
	> File Name: 538.图的遍历.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Fri Sep 18 22:48:08 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int n, arr[100][100], check[100], flag;

void func(int s) {
    if (flag == 1) {
        cout << "-";
    }
    flag = 1;
    cout << s;
    for (int i = 1; i <= n; i++) {
        if (arr[s][i] == 1 && check[i] == 0) {
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
    cout << endl;
    return 0;
}
