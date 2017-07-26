// C++ProgrammingApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
//inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace std;
using namespace my_code;


int main()
{
  
  read_file_for_me();
  
  return 0;
}

void my_code::read_file_for_me() {
  printf("\nINPUT\n");
  // Option 1 Scanf with simple regex
  printf("\n######\n");
#ifndef ONLINE_JUDGE	
  freopen("10550.in", "r", stdin);
  freopen("10550.out", "w", stdout);
#endif
  int N;
  char x[110];  // array size a bit larger than needed
  scanf("%d\n", &N);
  while (N--) {                  // we simply loop from N, N-1, N-2, ..., 0
    scanf("0.%[0-9]...\n", &x);   // `&' is optional when x is a char array
                                       // note: if you are surprised with the trick above,
                                       // please check scanf details in www.cppreference.com
    printf("the digits are 0.%s\n", x);
  }

  printf("\n######\n");
  // Option 2: number of test cases given in first line of input
  
  int TC, a, b;
  scanf("%d", &TC); // number of test cases | 1 2 | 12
  while (TC--) { // shortcut to repeat until 0 | 5 7 | 9
    scanf("%d %d", &a, &b); // compute answer | 6 3 |--------------
    printf("%d\n", a + b); // on the fly |--------------|
  }
  
  printf("\n######\n");
  // Option 3: multiple test cases terminated by special values
  // in this case, zeros
  
  while (scanf("%d %d", &a, &b), (a || b)) // because 0 means false in C++
    printf("%d\n", a + b);
  printf("\n######\n");

  // Option 4: multiple test cases terminated by EOF signal
  while (scanf("%d %d", &a, &b) != EOF)
    printf("%d\n", a + b);

  printf("\n######\n");

  // Option 5: multiple test cases terminated when you reach
  // a predetermined number of items in each test case (e.g. 3)
  // scanf returns the number of items read 
  
  int c;
  while (scanf("%d %d %d", &a, &b, &c) == 3)
    printf("%d\n", a + b + c);
  printf("\n######\n");

  // OUTPUT OPTIONS
  printf("\nOUTPUT\n");
  printf("\n######\n");
  // Option 1: output numbered sequentially
  // using same text file as last example, the print statement
  // in the loop is the important thing to look at
  
  int d = 1; // keeping count
  while (scanf("%d %d %d", &a, &b, &c) == 3)
    printf("Case %d: %d\n\n", d++, a + b + c); //adding extra space, if needed
  
  printf("\n######\n");

  // Option 2 - only print lines between test cases and not 
  // on last line
  
  d = 1;
  while (scanf("%d %d", &a, &b) == 2) {
    if (d > 1) printf("\n"); // print the extra line beforehand if on 2nd or later
    printf("Case %d: %d\n", d++, a + b); // won't print extra at end
  }
  printf("\n######\n");

  // Option 3: each test case includes a count integer before values
  
  int k, ans, v;
  while (scanf("%d", &k) != EOF) {
    ans = 0;
    while (k--) { scanf("%d", &v); ans += v; }
    printf("%d\n", ans);
  }
  printf("\n######\n");

  // Option 4: sum unknown number of values in each test case
  /*fp = fopen("outputCountIntegerBeforeValues.txt", "r");
  if (!fp) {
  perror("File opening failed");
  return;
  }
  char ch;
  while (fscanf(fp, "%d", &k) != EOF) {
  ans = 0;
  while (fscanf(fp, "%c", &ch), ch != '\n') {
  fscanf(fp, "%d", &v);
  ans += v;
  }
  printf("%d\n", ans);
  }
  fclose(fp);
  printf("\n######\n");*/
}

