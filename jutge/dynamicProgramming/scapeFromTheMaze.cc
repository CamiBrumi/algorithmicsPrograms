#include <iostream>
#include <vector>
using namespace std;
using VC = vector<char>;
using VCC = vector<VC>;
using ll = long long;
using VE = vector<ll>;
using VEE = vector<VE>;
VEE V;
int n, m;
VCC lab;
long INF = 1e6;

ll paths(int i, int j) {
  if (V[i][j] != -1) return V[i][j];
  if (lab[i][j] == 'X') return 0;
  int res = 0;
  if (i) res += paths(i-1, j);
  if (j) res += paths(i, j-1);
  if (res > INF) res = INF;
  return (V[i][j] = res);
}

int main() {
  cin >> n >> m;
  while ((n + m) != 0) {
    lab = VCC(n, VC(m));
    for(int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        cin >> lab[i][j];
      }
    V = VEE(n, VE(m, -1));
    V[0][0] = 1;
    ll correctPaths = paths(n-1, m-1);
    if (correctPaths >= INF) cout << "!!!" << endl;
    else cout << correctPaths << endl;
    cin >> n >> m;
  }
}
