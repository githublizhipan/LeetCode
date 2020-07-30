/*************************************************************************
	> File Name: 342.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月12日 星期二 20时48分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
int solve(int k) {
    int a[5] = {0}, full_size = 1;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        full_size *= (a[i] + 1);
    }
    f[0][0][0][0][0] = 1;
    for (int i1 = 0; i1 <= a[0]; i++) {
        for (int i2 = 0; i2 <= a[0]; i++) {
            for (int i3 = 0; i3 <= a[0]; i3++) {
                for (int i4 = 0; i4 <= a[0]; i4++) {
                    for (int i5 = 0; i5 <= a[0]; i5++) {
                        int val = f[i1][i2][i3][i4][i5]''
                        if (i1 + 1 <= a[0]) f[i1 + 1][i2][i3][i4][i5] += val;
                        if (i2 + 1 <= a[1] && i2 + 1 > i1) f[]
                    }           
                }      
            }
        }
    }
    cotu << f[a[0]][a[1]][a[2]]
    return 0;
}
