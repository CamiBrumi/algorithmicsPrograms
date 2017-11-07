#include <iostream>
#include <vector>

using namespace std;
using VC = vectos<char>;
using VCC = vector<VC>;
VCC mapa;
using VE = vector<int>;
using VEE = vector<VE>;
VEE explorat;

int f(int i, int j) {
    char& lloc = mapa[i][j];
    if (lloc == 'X') return false;
    if (lloc == 't') return true;
    return explorat[i][j] = 
}

int main() {
    int n, m;
    mapa = VCC(n, VC(m));
    explorat = VEE(n, VE(m, -1)); // -1 si no s'ha explorat, 0 si no es pot passar, 1 si es pot passar
    char c;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            mapa[i][j] = c;
            if (c == 't') explorat = 1;
            else if (c == 'X') explorat = 0;
        }
    }
}
