#include <iostream>
#include <vector>
using namespace std;
using VE = vector<int>;
int m;

int f(int n) {
  if (n%2 == 0) return 0;
  if (n == 1) return m;
  f(n-2); //Aquet és el problema, el de parentitzar les expressions...
  int sum = 0;
  for (int i = 1; i < n-5; ++i) {
    sum += f(i)*f(n-5-i);
  }
  return sum;
}

int main() {
  int n;
  while (cin >> n >> m) {
    cout << f(n) << endl;
  }
}
