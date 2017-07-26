#include "stdio.h"
#include <iostream>
#include <cstdio>

int main() {

#ifndef ONLINE_JUDGE	
  freopen("10550_b.in", "r", stdin);
  freopen("10550_b.out", "w", stdout);
#endif

  int i, a, b, c, deg = 9, top = 40;
  while (scanf("%d %d %d %d", &i, &a, &b, &c), (i || a || b || c)) { 
    int total = 720 + 360; // guaranteed 3 full turns
    if (i > a) total += (i - a) * 9; // CW
    else total += (i + (top - a)) * 9;
    if (a > b) total += ((top - a) + b) * 9; // CCW, so invert it
    else total += (b - a) * 9;
    if (b > c) total += (b - c) * 9;// CW
    else total += (b + (top - c)) * 9;
    printf("%d\n", total);
  }
}