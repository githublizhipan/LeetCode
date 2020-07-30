/*************************************************************************
	> File Name: 599.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月21日 星期四 17时35分16秒
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;
int n, t, num[1000005];
int main() {
    unordered_map<int, int> h;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        if (h.find(t - num[i]) == h.end()) {
            h[num[i]] = i;
        } else {
            printf("%d %d\n", h[t - num[i]], i);
        }
    }


    return 0;
}
