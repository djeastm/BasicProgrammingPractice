#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;
// Unfinished attempt at 599 with UnionFind

typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
      else {
        p[x] = y; setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main() {

#ifndef ONLINE_JUDGE	
  freopen("599.in", "r", stdin);
  freopen("599.out", "w", stdout);
#endif  
  int TC;
  bitset<26> bs;
  UnionFind uf(26);
  vii edges;  
  char a, b;
  scanf("%d", &TC); // number of test cases
  while (TC--) {
    while (scanf(" (%c,%c)", &a, &b), a != '*') { // get edge list
      int x = a - 'A';
      int y = b - 'A';
      edges.push_back(make_pair(x, y)); // store edges
      bs.set(x); bs.set(y); // to get number of vertices that are connected
    }
    int connV = bs.count(); // connected vertices
    int acorns = 0;
    char comma;
    while (scanf("%c", &a), a == '*');
    while (scanf("%c%c", &a, &comma) != EOF) {      
      if (comma == '\n') break;
      if (!bs[a - 'A']) ++acorns; // if it's not in the connected bitset, it's an acorn
    }
  }

 }