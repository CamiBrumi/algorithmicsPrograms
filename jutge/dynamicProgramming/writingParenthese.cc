#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using VE = vector<ll>;
VE catalan;

ll parentheses(int n) {
  if (catalan[n] != -1) return catalan[n];
  if (n <= 1) return catalan[n] = 1;
  return catalan[n] = (2 * (2*n - 1) * parentheses(n-1)) / (n+1);
}

int main() {
  catalan = VE(67, -1);
  int n;
  while(cin >> n) {
    if((n%2) == 1) cout << 0 << endl;
    else cout << parentheses(n/2) << endl;
  }

}
