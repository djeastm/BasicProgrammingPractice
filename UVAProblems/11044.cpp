#include "stdio.h"
#include <iostream>
#include <cstdio>

int main() {

#ifndef ONLINE_JUDGE	
  freopen("11044.in", "r", stdin);
  freopen("11044.out", "w", stdout);
#endif  
  int TC, n, m;
  scanf("%d", &TC); 
  while (TC--) { 
    scanf("%d %d", &n, &m); 
    printf("%d\n", (n/3) * (m/3)); 
  }
}