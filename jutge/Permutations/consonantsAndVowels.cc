#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VE = vector<int>;
using VEE = vector<VE>;
using VC = vector<char>;
using VCC = vector<VC>;

VE permut;
VEE usat;
VCC lletres;
int n;

void escriu() {
  for (int i = 0; i < 2*n; ++i)
    cout << lletres[i%2][permut[i]];
  cout << endl;
}

void f(int i) {
  if (i == 2*n) return escriu();
  for (int j = 0; j < n; ++j) {
    if (!usat[i%2][j]) {
        permut[i] = j;
        usat[i%2][j] = 1;
        f(i+1);
        usat[i%2][j] = 0;
    }
  }
}


int main() {
  cin >> n;
  lletres = VCC(2, VC(n));
  usat = VEE(2, VE(n, 0));
  for(int i = 0; i < 2; ++i) {
    //cout << "i = " << i << endl;
    for(int j = 0; j < n; ++j) {
      //cout << "       j = " << j << endl;
      cin >> lletres[i][j];
    }
  }
  permut = VE(2*n);
  f(0);
}
