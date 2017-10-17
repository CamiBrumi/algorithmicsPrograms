#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
VE triat, numeros;
int s, n;


void escriu() {
  bool first = true;
  cout << '{';
  for (int i = 0; i < n; ++i) {
    if(triat[i]) {
      if (first) {
        first = false;
        cout << numeros[i];
      } else cout << ',' << numeros[i];
    }
  }
  cout << '}' << endl;
}

// escriu totes les combinacions de n bits
// que comencen amb triat[0..i-1]
void f(int i, int sum) {
  if (i == n) {
    if (sum == s) return escriu();
    return;
  }

  triat[i] = 0;
  f(i + 1, sum);
  triat[i] = 1;
  f(i + 1, sum + numeros[i]);
}


int main() {
  cin >> s >> n;
  triat = VE(n);
  numeros = VE(n);
  for (int i = 0; i < n; ++i) cin >> numeros[i];
  f(0, 0);
}
