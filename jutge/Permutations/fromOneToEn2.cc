#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VE = vector<int>;
VE triat, perm;
int n;

void escriu() {
    VE v = VE(n);
    for (int i = 0; i < n-1; ++i) {
        //cout << "perm[i+1] = " << perm[i+1] << endl;
        v[perm[i]] = perm[i+1];
    }
    v[perm[n-1]] = perm[0];

  cout << '(';
  /*
  for (int i = 1; i < n; ++i) {
    cout << ',' << perm[] + 2;
  }
  cout << ')' << endl;*/
  cout << v[0] + 1;
  for (int i = 1; i < n; ++i) {
        cout << "," << v[i] + 1;
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
  perm[0] = 0;
  triat[0] = true;
  f(1);
}
