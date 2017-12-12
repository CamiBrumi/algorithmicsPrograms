#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
VVI mazmorra;
int n;

int f(int i, int j, int trAnt) {
  if (i == n) return 0;
  cout << 2;
  return min(f(i+1, j, mazmorra[i][j]) + (mazmorra[i+1][j] > trAnt), f(i+1, j+1, mazmorra[i][j]) + (mazmorra[i+1][j] > trAnt));
}

int main () {
  while (cin >> n) {
    mazmorra = VVI(n, VI(n, 0));
    for (int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        cin >> mazmorra[i][j];
      }
    }
    /*
    for (int i = 0; i < n; ++i) {
      for(int j = 0; j <= i; ++j) {
        cin >> t;
        cout << 1 << endl;
        mazmorra[i].push_back(t);
      }
    } */
    cout << f(0, 0, 1e9) << endl;
  }
}
