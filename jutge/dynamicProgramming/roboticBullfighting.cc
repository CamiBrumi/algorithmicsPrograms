#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VEE = vector<VE>;
VEE v;
int w, h, c;

int main() {
  cin >> w >> h >> c;
  v = VEE(h, VE(w));
  for (int i = 0; i < h; ++i) {
    cin >> v[i][0];
    for (int j = 1; j < w; ++j) {
      cin >> v[i][j];
      v[i][j] += v[i][j-1];
    }
  }
}
