/*************************************************************************
	> File Name: 516.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 20时30分59秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int n;
char str[100005];

long long ans, numc[100005], numw[100005], nc, nw;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        if (str[i] == 'C') nc++;
        numc[i] = nc;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == 'W') nw++;
        numw[i] = nw;
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == 'O') {
            ans += numc[i] * numw[i];
        }
    }
    cout << ans << endl;

    return 0;
}
