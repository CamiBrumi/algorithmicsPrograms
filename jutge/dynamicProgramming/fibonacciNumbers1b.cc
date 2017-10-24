#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using VE = vector<ll>;
int const N = 1001;
VE F;
int m;

ll fib(int n) {
  if (F[n] != -1) {
    return F[n];
  }
  if (n <= 1) {
    return F[n] = n;
  }
  return F[n] = (fib(n-2) + fib(n-1))%m;
}

int main(){
  F = VE(N, -1);
  int n;
  while (cin >> n >> m) {
    cout << fib(n)%m << endl;
    F = VE(N, -1);
  }
}
