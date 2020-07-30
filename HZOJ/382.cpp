/*************************************************************************
	> File Name: 382.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月12日 星期日 23时20分34秒
 ************************************************************************/
#include<iostream>
using namespace std;

#define MAX 10000
int j[MAX] = {1,0};



int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n; ++i) {
        j[i] = (j[i - 1] + m) % i;
    }
    cout << j[n] + 1 << endl;
    return 0;
}
