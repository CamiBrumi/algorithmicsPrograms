//operació dona'm una línia de l'entrada

int main() {
  string s;
  while (getline(cin, s)) { //llegir línia a línia
    stringstream ss(s); // canal construit a partir d'un string
    int suma = 0;
    int x;
    while (ss >> x) suma += x;
    cout << suma << endl;
  }
}
