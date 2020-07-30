/*************************************************************************
	> File Name: 71.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月22日 星期五 16时47分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000
int n, m;

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int get(int a) {
        return (fa[a] = (fa[a] == a ? a : get(fa[a])));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main() {
    cin >> n >> m;
    u.init(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        switch(a) {
            case 1: u.merge(b, c); break;
            case 2: cout << (u.get(b) == u.get(c) ? "Yes\n" : "No\n"); break;
        }
    }
    return 0;
}
