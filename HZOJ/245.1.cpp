/*************************************************************************
	> File Name: 245.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 19时26分37秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int pos = a[n / 2];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i] - pos);
    }
    cout << sum << endl;

    return 0;
}
