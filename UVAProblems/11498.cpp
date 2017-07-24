#include "stdio.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>

int main() {


#ifndef ONLINE_JUDGE	
  freopen("11498.in", "r", stdin);
  freopen("11498.out", "w", stdout);
#endif
  int k, n, m, x, y;
  while (scanf("%d", &k), k) { // number of queries
    scanf("%d %d", &n, &m); // division point
    while (k--) { 
      scanf("%d %d", &x, &y);
      // coordinates of residence
      std::string s = "";
      if (y < m) s += 'S';
      else if (y > m) s += 'N';
      else { printf("divisa\n") ; continue; }

      if (x < n) s += 'O';
      else if (x > n) s += 'E';
      else { s = "divisa"; }
      printf("%s\n", s.c_str());
    }
  }
  
  
}