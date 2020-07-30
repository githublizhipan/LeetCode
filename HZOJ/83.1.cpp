/*************************************************************************
	> File Name: 83.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月14日 星期六 09时22分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};
char s[1000][1000];

void init(int x, int y, int n) {
    if(n == 1) {
        s[x][y] = 'X';
        return ;
    }
    init(x, y, n - 1);
    init(x + num[n] / 3 * 2, y, n - 1);
    init(x + num[n] / 3, y + num[n] / 3, n - 1);
    init(x, y + num[n] / 3 * 2, n - 1);
    init(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);
}



int main() {
    init(1, 1, 7);
    int n;
    while(cin >> n, n != -1) {
        for(int i = 1; i <= num[n]; i++) {
            for(int j = 1; j <= num[n]; j++) {
                if(s[i][j] == 'X') cout << 'X';
                else cout << ' ';
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}
