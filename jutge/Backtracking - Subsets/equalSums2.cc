#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VE = vector<int>;
VE triat, numeros;
int s, n;
bool hay_solu;

bool wayToSort(int i, int j) { return i > j; }

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
/*
void greatest(){
  hay_solu = true;
  if (greatest_vector[0] == -1) {
    greatest_vector = triat;
    return;
  }
  if (greatest_vector[0] < triat[0]) {
    greatest_vector = triat;
  }
}
*/
void f(int i, int sum) {
  if (hay_solu) return;
  if (i == n) {
    if (sum == s) {
      hay_solu = true;
      return escriu();
    }
    return;
  }

  triat[i] = 1;
  f(i + 1, sum + numeros[i]);
  triat[i] = 0;
  f(i + 1, sum);
}


int main() {
  cin >> s >> n;
  triat = numeros = VE(n);
  for (int i = 0; i < n; ++i) cin >> numeros[i];
  sort(numeros.begin(), numeros.end(), wayToSort);
  hay_solu = false;
  f(0, 0);
  if (!hay_solu) cout << "no solution" << endl;
}
