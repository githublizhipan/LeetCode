/*************************************************************************
	> File Name: 375.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月10日 星期五 18时16分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct p{
    int index;
    int c;
    int m;
    int e;
    int sum;
}P;

int cmp1(P a, P b) {
    if(a.sum > b.sum) return 1;
    else if(a.sum == b.sum) {
        if(a.c > b.c) return 1;
        else if(a.c == b.c) {
            if(a.index < b.index) return 1;
        }
    }
    return 0;
}

int main() {

    int n;
    P a[500];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        a[i].index = i;
        cin >> a[i].c >> a[i].m >> a[i].e;
        a[i].sum = a[i].c + a[i].m + a[i].e;
    }
    sort(a + 1, a + n + 1, cmp1);
    for(int i = 1; i <= 5; ++i) {
        cout << a[i].index << " " << a[i].sum << endl;
    }
    return 0;
}
