#include "stdio.h"
#include <iostream>
#include <cstdio>

int main() {

#ifndef ONLINE_JUDGE	
  freopen("11364.in", "r", stdin);
  freopen("11364.out", "w", stdout);
#endif  
  int TC, n;
  scanf("%d", &TC);
  while (TC--) {
    int x[110], ans = 0, first = 99, last = 0, count, i = 0;
    scanf("%d", &n);
    count = n;
    while (n--) {
      scanf("%d ", &x[i++]);  
    }  
    for (i = 0; i < count; i++) {
      if (x[i] < first) first = x[i];
      if (x[i] > last) last = x[i];
    }
    ans = 2 * (last - first);
    
    printf("%d\n", ans);
  }

}