/*************************************************************************
	> File Name: 387.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 17时16分44秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
using namespace std;

struct GUA {
    long long num;
    int index;
};

int cmp(GUA a, GUA b) {
    return a.num < b.num;
}


int main() {
    GUA gua[100000];
    int M, N;
    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        cin >> gua[i].num;
        gua[i].index = i;
    }

    sort(gua + 1, gua + M + 1, cmp);
    
    long long y;
    for(int i = 1; i <= N; i++) {
        cin >> y;
        if(gua[M].num < y) {
            cout << 0 << endl;
            continue;
        }
        int l = 0, r = M, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if(gua[mid].num >= y) {
                r = mid;
            } else l = mid + 1;
        }
        cout << gua[l].index << endl;
    }

    return 0;
}
