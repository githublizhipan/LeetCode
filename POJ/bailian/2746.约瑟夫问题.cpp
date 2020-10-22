/*************************************************************************
	> File Name: 2746.约瑟夫问题.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Thu Oct 22 14:55:32 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
int n, m, f[310];

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        memset(f, 0, sizeof(f)); 
        for (int i = 1; i <= n; i++) {
            f[i] = (f[i - 1] + (m - 1)) % i + 1;
        }
        cout << f[n] << endl;
    }
    return 0;
}
