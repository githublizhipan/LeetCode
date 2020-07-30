/*************************************************************************
	> File Name: 386.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月08日 星期三 19时41分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int num, val;
};

node wm[100005];

bool cmp(node a, node b) {
    return a.val < b.val;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> wm[i].val;
        wm[i].num = i + 1;
    }
    sort(wm, wm + n, cmp);
    
    for(int i = 0; i < m; i++) {
        int l = 0,r = n - 1, t, f = 0;
        cin >> t;
        while(l <= r) {
            int mid = (r + l) >> 1;
            if(wm[mid].val == t) {
                cout << wm[mid].num << endl;
                f = 1;
                break;
            }
            if(wm[mid].val < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(f == 0) cout << 0 << endl;
    }
    return 0;
}
