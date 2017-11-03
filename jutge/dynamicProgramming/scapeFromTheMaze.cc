#include <iostream>
#include <vector>
using namespace std;
using VC = vector<char>;
using VCC = vector<VC>;
int n, m;
VCC lab;
long INF = 1e6;

long long paths(int i, int j) {
  if (i == 0 and j == 0) return 1;
  if (lab[i][j] == '.') {
    if (i == 0) return paths(i, j - 1);
    if (j == 0) return paths(i - 1, j);
    return paths(i-1, j) + paths(i, j-1);
  }
  return 0;
}

int main() {
  cin >> n >> m;
  while ((n + m) != 0) {
    lab = VCC(n, VC(m));
    for(int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        cin >> lab[i][j];
      }
      long long correctPaths = paths(n-1, m-1);
      else cout << correctPaths << endl;
      cin >> n >> m;
  }
}
