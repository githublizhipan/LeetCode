/*************************************************************************
	> File Name: 534.1.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Thu Sep 17 22:50:22 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int n, arr[30], check[5000] = {1, 0}, ans;

void func(int s, int sum) {
    if (check[sum] == 0) {
        ans++;
        check[sum] = 1;
    }
    for (int i = s; i < n; i++) {
        sum += arr[i];
        func(i + 1, sum);
        sum -= arr[i];
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    func(0, 0);
    cout << ans << endl;
    return 0;
}
