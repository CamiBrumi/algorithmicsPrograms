#include <iostream>
#include <vector>

using namespace std;
using VC = vectos<char>;
using VCC = vector<VC>;
VCC mapa;

int main() {
    int n, m;
    mapa = VCC(n, VC(m));
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mapa[i][j];
    }
}
