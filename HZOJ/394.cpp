/*************************************************************************
	> File Name: 394.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月15日 星期五 22时39分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
int L, N, M, num[50005], last, cnt;


int main() {
    cin >> L >> N >> M;
    for (int i = 1; i <=  N; i++) {
        cin >> num[i];
    }
    num[N + 1] = L;

    int l = 0, r = L;
    while (l != r) {
        cnt = 0, last = 0;
        int mid = (l + r + 1) / 2;
        for (int i = 1; i <= N + 1; i++) {
            if (num[i] - last < mid) {
                cnt++;
            } else {
                last = num[i];
            }
        }
        if (cnt <= M) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
