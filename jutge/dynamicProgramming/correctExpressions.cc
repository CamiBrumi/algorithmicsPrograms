#include <iostream>
#include <vector>
using namespace std;
using VE = vector<int>;
VE F;
int N = 26;
int m;

int f(int n) {
  //int& res = F[n];
  if (F[n] != -1) return F[n];
  if (n%2 == 0) return F[n] = 0;
  if (n == 1) {
    return F[n] = m;
  }
  int sum = f(n-2);
  for (int i = 1; i < n-5; ++i) {
    sum += f(i)*f(n-5-i);
  }
  return F[n] = sum;
}

int main() {
  int n;
  F = VE(N, -1);
  while (cin >> n >> m) {
    cout << f(n) << endl;
    F = VE(N, -1);
  }
}
