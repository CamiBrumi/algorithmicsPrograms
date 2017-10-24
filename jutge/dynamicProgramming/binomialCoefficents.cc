#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VE = vector<ll>;
using ME = vector<VE>;

//typedef vector<int> VE;
//typedef vector<VE> VEE;

int const N = 31;
int const K = 31;
ME v;

ll bc(int n, int k) {
    if(v[n][k] != -1) return v[n][k];
    if (k == 0 or k == n) return v[n][k] = 1;
    return v[n][k] = bc(n-1, k) + bc(n-1, k-1);
}

int main() {
  v = ME(N, VE(K, -1));
  int n, k;
  while (cin >> n >> k) cout << bc(n, k) << endl;
}
