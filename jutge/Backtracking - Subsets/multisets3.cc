#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VS = vector<string>;
VE triat;
VS paraules;
int n, t;


void escriu(const VE& V) {
  cout << '{';
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (triat[i]) {
      for (int j = 0; j < triat[i]; ++j) {
        if (first) {
          first = false;
          cout << i + 1;
        } else cout << ',' << i + 1;
      }
    }
  }
  cout << '}' << endl;
}

// escriu totes les combinacions de n bits
// que comencen amb triat[0..i-1]
void f(int i, int tc) {
  if (tc > t) return;
  if (i == n) {
    if (tc == t) return escriu(triat);
    return;
  }

  for (int j = 0; j <= t; ++j) {
    triat[i] = j;
    f(i+1, tc + j);
  }
}

int main() {
  cin >> n >> t;
  triat = VE(n, 0);
  f(0, 0);
}
