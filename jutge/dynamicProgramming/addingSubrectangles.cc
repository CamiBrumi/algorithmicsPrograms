#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VEE = vector<VE>;



int main() {
    string s;
    while (cin >> s)
  
    
    int fila = 0;
    VEE V = VEE(500, VE(500, 0));
    while (cin >> s) {
        for (int i = 0; s.size(); ++i) {
            V[fila][i] = s[i];
        }
        ++fila;
    }
    
  
}
