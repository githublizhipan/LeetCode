/*************************************************************************
	> File Name: 2707.求一元二次方程的根.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Oct 21 11:08:14 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
float a, b, c, delta, part1, part2;
int main() {
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%f %f %f", &a, &b, &c);
        delta = b * b - 4 * a * c;
        if (b == 0) part1 = 0;
        else part1 = -1 * b / (2 * a);
        if (delta > 0) {
            part2 = sqrt(delta) / (2 * a);
            printf("x1=%.5f;x2=%.5f\n", part1 + part2, part1 - part2);
        } else if (fabs(delta) < 1e-8) {
            printf("x1=x2=%.5f\n", part1);
        } else {
            part2 = sqrt(0 - delta) / (2 * a);
            printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n", part1, part2, part1, part2);
        }
    }
    return 0;
} 
