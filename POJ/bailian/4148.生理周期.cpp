/*************************************************************************
	> File Name: 4148.生理周期.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Oct 28 09:21:47 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;
int p, e, i, d, cnt;
int main() {
    while(cin >> p >> e >> i >> d) {
        if (p == -1) break;
        int day = d + 1;
        for ( ;day <= 21252; day++) {
            if ((day - p) % 23 == 0) break;
        }
        for ( ;day <= 21252; day += 23) {
            if ((day - e) % 28 == 0) break;
        }
        for ( ;day <= 21252; day += 23 * 28) {
            if ((day - i) % 33 == 0) break;
        }
        cnt++;
        cout << "Case " << cnt << ": the next triple peak occurs in " << day - d << " days." << endl;
    }

    return 0;
}
