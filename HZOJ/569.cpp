/*************************************************************************
	> File Name: 569.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 14时09分09秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include <stack>
using namespace std;
int main() {
    int v, n;
    double c;
    char s;

    stack<int> V;
    stack<double> C;
    
    cin >> v >> c >> n;
    V.push(v);
    C.push(c);

    for(int i = 1; i <= n; ++i) {

        cin >> s;
        if(s == 'P') {
            cin >> v >> c;
            double temp = (V.top() * (0.01 * C.top()) + v * (0.01 * c)) / (V.top() + v);
            C.push(temp * 100.0);
            V.push(V.top() + v);
            printf("%d %.5lf\n", V.top(), C.top());
        } else if(s == 'Z') {
            if(V.size() == 1) {
                printf("%d %.5lf\n", V.top(), C.top());
                continue;
            }
            V.pop();
            C.pop();
            printf("%d %.5lf\n", V.top(), C.top());
        }
    }
    return 0;
}
