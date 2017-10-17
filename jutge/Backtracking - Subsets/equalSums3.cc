#include <iostream>
#include <vector>
#include <algorithm>
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

void f(int i, int sum, int presuma) {
  if (sum > s or presuma < 0) return;
  if (i == n) {
    if (sum == s) return escriu();
    return;
  }

  triat[i] = 0;
  f(i + 1, sum, presuma);

  triat[i] = 1;
  f(i + 1, sum + numeros[i], presuma - numeros[i]);
}


int main() {
  cin >> s >> n;
  triat = numeros = VE(n);
  int presuma = 0;
  for (int i = 0; i < n; ++i) {
    cin >> numeros[i];
    presuma += numeros[i];
  }

  f(0, 0, presuma);
}
