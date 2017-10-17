#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;


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
void f(int i, VE& triat) {
  if (i == (int)triat.size()) escriu(triat);
  else {
    triat[i] = 0;
    f(i + 1, triat);
    triat[i] = 1;
    f(i + 1, triat);
  }
}


int main() {
  int n;
  cin >> n;
  VE triat(n);
  f(0, triat);
}
