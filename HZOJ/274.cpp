/*************************************************************************
	> File Name: 274.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月17日 星期五 21时39分07秒
 ************************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

#define MAX 1000000

ull h[MAX + 5],sumh[MAX + 5];
const int base = 13331;
int main() {
    int N;
    int len[7];
    cin >> N;
    for(int j = 1; j <= N; ++j) {
        for(int i = 1; i <= 6; i++) {
            cin >> len[i];
            if(!h[len[i]]) h[len[i]] = h[len[i] - 1] * base + len[i];
            sumh[j] += h[len[i]];
        }
    }
    sort(sumh + 1, sumh + N + 1);
    for(int i = 1; i < N; ++i) {
        if(sumh[i] != sumh[i + 1]) continue;
        cout << "Twin snowflakes found." << endl;
        return 0;
    }
    cout << "Twin snowflakes found." << endl;
    return 0;
}
