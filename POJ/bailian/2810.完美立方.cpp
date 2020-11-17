/*************************************************************************
	> File Name: 2810.完美立方.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Oct 27 21:07:56 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int n, Cube[110];
int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        Cube[i] = pow(i, 3);
    }
    for (int a = 6; a <= n; a++) {
        for (int b = 2; b <= n; b++) {
            for (int c = b; c <= n; c++) {
                for (int d = c; d <= n; d++) {
                    if (Cube[a] == Cube[b] + Cube[c] + Cube[d]) {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }

    return 0;
}
