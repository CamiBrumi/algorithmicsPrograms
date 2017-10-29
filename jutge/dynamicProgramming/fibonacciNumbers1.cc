#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using VE = vector<ll>;
int const N = 1000;
//int const MOD = 10e8;



int main(){
  VE F = VE(N, 0);
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < N; ++i) {
    F[i] = F[i-1] + F[i-2];
    cout << "F[" << i << "] = " << F[i] << endl;
  }
  int n, m;
  while (cin >> n >> m) cout << F[n]%m << endl;
}
