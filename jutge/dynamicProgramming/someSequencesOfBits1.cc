#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using VE = vector<ll>;

ll f1(int n);
ll f2(int n);
ll f3(int n);

VE F1, F2, F3;

// f1 retorna el número de seqüències que acaben amb 0
ll f1(int n) {
  ll& res = F1[n];
  if (res != -1) return res;
  if (n == 1) return res = 1;
  return res = f2(n-1) + f3(n-1);
}

// f2 retorna el número de seqüències que acaben amb 01
ll f2(int n) {
  ll& res = F2[n];
  if (res != -1) return res;
  if (n == 1) return res = 0;
  if(n <= 2) return res = 1;
  return res = f2(n-2) + f3(n-2);
}

// f3 retorna el número de seqüències que acaben amb 11
ll f3(int n) {
  ll& res = F3[n];
  if (res != -1) return res;
  if (n == 1) return res = 0;
  if(n <= 2) return res = 1;
  return res = f1(n-2);
}


int main() {
  F1 = F2 = F3 = VE(151, -1);
  //cout << "-1-" << endl;
  int n;
  //cout << "-2-" << endl;
  while (cin >> n) {
    if (n == 0) cout << 1 << endl;
    else if (n == 1) cout << 2 << endl;
    else cout << f1(n) + f2(n) + f3(n) << endl;
  }
}
