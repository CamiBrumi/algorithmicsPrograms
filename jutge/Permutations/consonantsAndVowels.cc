#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// el vector perm és la permutació en si, o sigui, el que sortirà per la pantalla.
// el vector triat ens diu si el numero corresponent la posició j ha sortit en el vector perm o no.
// triat[j] = 1 si el numero j ha sortit al vector perm, triat[j] = 0 altrament. 

using VE = vector<int>;
VE triat, perm;
int n;

void escriu() {
  cout << '(';
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (first) {
      cout << perm[i] + 1;
      first = false;
    }
    else cout << ',' << perm[i] + 1;
  }
  cout << ')' << endl;
}

void f(int i) {
  if (i == n) return escriu();

  for (int j = 0; j < n; ++j) {
    if (!triat[j]) {
      perm[i] = j;
      triat[j] = 1;
      f(i + 1);
      triat[j] = 0;
    }
  }

}


int main() {
  cin >> n;
  triat = perm = VE(n);
  f(0);
}
