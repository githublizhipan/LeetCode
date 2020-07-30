/*************************************************************************
	> File Name: 528.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月03日 星期五 18时24分27秒
 ************************************************************************/

#include<iostream>
#include <queue>

using namespace std;
struct node {
    int x, step;
};

int n, x, y;
int mmap[105][105], check[105][105];
int main() {
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    queue<node> que;
    que.push({x, 0});
    check[x][x] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i = 1; i <= n; i++) {
            if(i == temp.x || !mmap[temp.x][i]) continue;
            if(mmap[temp.x][i] && !check[temp.x][i]) {
                if(i == y) {
                    cout << temp.step << endl;
                    return 0;
                }
                check[temp.x][i] = 1;
                check[i][temp.x] = 1;
                que.push({i, temp.step + 1});
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
