/*************************************************************************
	> File Name: 571.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 11时16分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, x, y;

typedef struct Node {
    int now, step;
} Node;
int arr[105][105], check[105];

queue<Node> que;


int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    que.push({x, 0});
    check[x] = 1;    
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        if (temp.now == y) {
            cout << temp.step - 1 << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (arr[temp.now][i]) {
                que.push({i, temp.step + 1});
                check[i] = 1;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
