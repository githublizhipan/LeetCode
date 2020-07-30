/*************************************************************************
	> File Name: 383.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 20时38分08秒
 ************************************************************************/
#include <queue>
#include<iostream>
using namespace std;
int main() {
    queue<int> man, woman;
    int x, y, n;
    cin >> x >> y >> n;
    
    for(int i = 1; i <= x; i++) {
        man.push(i);
    }
    for(int j = 1; j <= y; j++) {
        woman.push(j);
    }
    while(n--) {
        int m = man.front();
        int w = woman.front();
        cout << m << " " << w << endl;
        man.pop();
        woman.pop();
        man.push(m);
        woman.push(w);
    }

    return 0;
}
