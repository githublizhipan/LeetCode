/*************************************************************************
	> File Name: 240.图形打印四.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Sep 12 15:33:28 2020
	> Source: 
 ************************************************************************/

#include<iostream>
using namespace std;
int n, arr[2200][2200];
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};
void draw(int x, int y, int n) {
    if (n == 1) {
        arr[x][y] = 1;
        return ;
    }
    draw(x, y, n - 1);
    draw(x + num[n] / 3 * 2, y, n - 1);
    draw(x + num[n] / 3, y + num[n] / 3, n - 1);
    draw(x, y + num[n] / 3 * 2, n - 1);
    draw(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
    return ;
}

int main() {
    draw(1, 1, 7);
    while (cin >> n, n != -1) {
        for (int i = 1; i <= num[n]; i++) {
            for (int j = 1; j <= num[n]; j++) {
                if (arr[i][j]) cout << "X";
                else cout << " ";
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    return 0;
}
