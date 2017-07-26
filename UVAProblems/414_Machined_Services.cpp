#include "stdio.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <regex>

int main() {

#ifndef ONLINE_JUDGE	
  freopen("414.in", "r", stdin);
  freopen("414.out", "w", stdout);
#endif  
  int count = 0;
  while (scanf("%d\n", &count), count) {
    int roughness = 0, min = 25;
    int c1 = count, c2 = count;
    char input[28];
    int rows[10000];
    // Get length of shortest stretch of blanks
    while (c1--) {
      int d = 0;
      fgets(input, sizeof input, stdin);      
      for (char& ch : input) {
        if (ch == ' ') ++d;
        else if (ch == '\n') break;
      }
      if (d < min) min = d;
      rows[c1+1] = d;
    }
    // Subtract the min blanks number from each
    // rows' number of blanks and add that to roughness
    while (c2--) {
      roughness += rows[c2+1] - min;
    }
    printf("%d\n", roughness);
  }
}