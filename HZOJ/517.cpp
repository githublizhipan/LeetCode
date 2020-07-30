/*************************************************************************
	> File Name: 517.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 17时50分23秒
 ************************************************************************/

#include<iostream>
using namespace std;


int is_val(int i, int j, int k) {
    if(i + j > k && i + k > j && j + k > i) return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = i; i + j < n; j++) {
            int k = n - i - j;
            if(k < i || k < j) continue; 
            if(is_val(i, j, k)) {
                cnt++;
                //cout << i << " " << j << " " << k << endl;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
