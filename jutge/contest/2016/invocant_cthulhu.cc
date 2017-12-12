#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
VI letters;
int n, comptador;


// Explicació per a que serveix el vector perm:
// en la posició i-èssima del vector perm posem el número que correspon a una paraula.
// Exemple: si al vector perm apareix dues vegades el #3 => la tercera paraula del vector words apareixerà dues vegades per pantalla.
void f(int i) { //potser se passarà d'elements
  if (i == n) ++comptador;
  for (int j = 0; j < 26; ++j) {
      if (letters[j] > 0) {
        //perm[i] = j;
        --letters[j];
        f(i+1);
        ++letters[j];
      }
  }
}

int main() {
  string s;
  letters = VI (26, 0);

  while (cin >> s) {
    n = s.size();
    for (int i = 0; i < n; ++i) {
      ++letters[s[i] - 'a'];
    }
    //perm = VI(n);
    comptador = 0;
    f(0);
    letters = VI (26, 0);
    cout << comptador << endl;
  }
}
