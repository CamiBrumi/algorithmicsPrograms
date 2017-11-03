#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using VE = vector<ll>;
using VEE = vector<VE>;

ll f1(int n, int z);
ll f2(int n, int z);
ll f3(int n, int z);

VEE F1, F2, F3;

// f1 retorna el número de seqüències que acaben amb 0
ll f1(int n, int z) {
  ll& res = F1[n][z];
  if (res != -1) return res;
  //if (n <= 1) return res = 1;
  if (n == 1 and z == 1) return res = 1;
  if (n == 1 and z != 1) return res = 0;
  if (z > n or z <= 0) return res = 0;
  return res = f2(n-1, z-1) + f3(n-1, z-1);
}

// f2 retorna el número de seqüències que acaben amb 01
ll f2(int n, int z) {
  ll& res = F2[n][z];
  if (res != -1) return res;
  if ((n-z) < 1 or z <= 0) return res = 0;
  //if (n == 1) return res = 0;
  //if(n <= 3) return res = 1;
  return res = f2(n-2, z-1) + f3(n-2, z-1);
}

// f3 retorna el número de seqüències que acaben amb 11
ll f3(int n, int z) {
  ll& res = F3[n][z];
  if (res != -1) return res;
  if (z > n) return res = 0;
  if ((n-z) < 2 or z <= 0) return res = 0;
  if (n == 1) return res = 0;
  if(n <= 2) return res = 1;
  return res = f1(n-2, z);
}


int main() {
  F1 = F2 = F3 = VEE(181, VE(91, -1));
  //cout << "-1-" << endl;

  //cout << "-2-" << endl;
  int z, u;
  while (cin >> z >> u) {
    int n = z + u;
    if (n == 0) cout << 1 << endl;
    else if (n == 1) cout << 2 << endl;
    else cout << f1(n, z) + f2(n, z) + f3(n, z) << endl;
  }
}
