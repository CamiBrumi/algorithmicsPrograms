#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VE = vector<int>;
using VS = vector<string>;
VE triat, perm;
VS words;
int n;

void escriu() {
  cout << '(';
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (first) {
      cout << words[perm[i]];
      first = false;
    }
    else cout << ',' << words[perm[i]];
  }
  cout << ')' << endl;
}

void f(int i) {
  //cout << "i =" << i << endl;
  if (i == n) return escriu();

  for (int j = 0; j < n; ++j) {
    perm[i] = j;
    f(i + 1);
  }
}


int main() {
  cin >> n;
  triat = perm = VE(n);
  words = VS(n);
  for (int i = 0; i < n; ++i) cin >> words[i];
  f(0);
}
