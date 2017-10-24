#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
VE triat;
int n, z, o;


void escriu(const VE& V) {
  bool first = true;
  for (int x : V) {
    if (first) {
      first = false;
      cout << x;
    } else cout << ' ' << x;
  }
  cout << endl;
}

// escriu totes les combinacions de n bits
// que comencen amb triat[0..i-1]
void f(int i, int zeros, int ones) {
  if (zeros > z or ones > o) return;

  if (i == n) escriu(triat);
  else {
    triat[i] = 0;
    f(i + 1, zeros + 1, ones);
    triat[i] = 1;
    f(i + 1, zeros, ones + 1);
  }
}


int main() {
  cin >> n >> o;
  z = n - o;
  triat = VE(n);
  f(0, 0, 0);
}
