#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;
using VS = vector<string>;
VE triat;
VS paraules;
int n, p;


void escriu(const VE& V) {
  for (int i = 0; i < p; ++i) {
    cout << "subset " << i + 1 << ": {";
    bool first = true;
    for (int j = 0; j < n; ++j) {
      if(triat[j] == i) {
        if (first) {
          first = false;
          cout << paraules[j];
        } else {
          cout << "," << paraules[j];
        }
      }
    }
    cout << '}' << endl;
  }
  cout << endl;

  /*
  int part = 0;
  for (int i = 0; i < n; ++i) {
    cout << "subset " << part + 1 << ": {";
    bool first = true;
    for (int j = 0; j < n; ++j) {
      if (V[j] == part) {
        if (first) {
          first = false;
          cout << paraules[j];
        } else cout << "," << paraules[j];
      }
    }
    cout << "}" << endl;
    ++part;
  }
  cout << endl; */
}

// escriu totes les combinacions de n bits
// que comencen amb triat[0..i-1]
void f(int i) {
  if (i == n) return escriu(triat);

  for (int j = 0; j < p; ++j) {
    triat[i] = j;
    f(i+1);
  }
}

int main() {
  cin >> n;
  paraules = VS(n);
  for (int i = 0; i < n; ++i) {
    cin >> paraules[i];
  }
  cin >> p;
  triat = VE(n);
  f(0);
}
