#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VE = vector<int>;
VE triat, perm;
int r, c;

void escriu() {
  for (int i = 0; i < r; ++i) {
    int pos_rook = perm[i];
    for (int j = 0; j < c; ++j) {
      if (j == pos_rook) cout << 'R';
      else cout << '.';
    }
    cout << endl;
  }
  cout << endl;
}

void f(int i) {
  if (i == r) return escriu();

  for (int j = 0; j < c; ++j) {
    if (!triat[j]) {
      perm[i] = j;
      triat[j] = 1;
      f(i + 1);
      triat[j] = 0;
    }
  }
}


int main() {
  cin >> r >> c;
  perm = VE(r);
  triat = VE(c); // perquè la torre pot estar en una de les c columnes
  f(0);
}
