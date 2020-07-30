/*************************************************************************
	> File Name: 396.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 21时45分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n;
int mmap[35][35];
int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};

void func(int x0, int y0) {
    for(int i = 0; i < 4; i++) {
        int x = x0 + dir[i][0];
        int y = y0 + dir[i][1];
        if(x < 0 || y < 0 || x > n + 1 || y > n + 1 || mmap[x][y]) continue;
        if(mmap[x][y] == 0) {
            mmap[x][y] = 3;
            func(x, y);
        }
    }
} 


int main() {
    cin >> n;
    mmap[0][0] = 3;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    func(0, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j > 1) cout << " ";
            if(mmap[i][j] == 3) cout << 0;
            else if(mmap[i][j] == 1) cout << 1;
            else cout << 2;
        }
        cout << endl;
    }
    return 0;
}
