/*************************************************************************
	> File Name: 473.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 13时40分13秒
 ************************************************************************/

#include<iostream>
using namespace std;


double c;

int main() {
    while(cin >> c, c != 0.00) {
        int ans = 2;
        double sum = 0.5;
        if(c < 0.5) {
            cout << 1 << endl;
            continue;
        }
        while(sum + 1.0 / (ans + 1.0) < c) {
            sum += 1.0 / (ans + 1.0);
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
