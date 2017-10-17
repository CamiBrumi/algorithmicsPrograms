#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VS = vector<string>;
VE triat;
VS paraules;
int n, x, y;


void escriu(const VE& V) {
  cout << '{';
  bool first = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < triat[i]; ++j) {
      if (first) {
        first = false;
        cout << i + 1;
      } else cout << ',' << i + 1;
    }
  }
  cout << '}' << endl;
}

// escriu totes les combinacions de n bits
// que comencen amb triat[0..i-1]
void f(int i) {
  if (i == n) return escriu(triat);

  for (int j = x; j <= y; ++j) {
    triat[i] = j;
    f(i+1);
  }
}

int main() {
  cin >> n >> x >> y;
  triat = VE(n);
  f(0);
}
