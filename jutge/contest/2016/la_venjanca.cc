#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P; //espai, mala sort
typedef vector<P> VP;
//typedef vector<int> VI;
//VI triat;
VP cem;
int s, n;

int f(int i, int sup, int ms) {
  if (sup > s) return 0;
  if (i == n) return ms;
  return max(f(i+1, sup + cem[i].first, ms + cem[i].second), f(i+1, sup, ms));
}

int main() {
  while (cin >> s >> n) {
    cem = VP(n);
    for (int i = 0; i < n; ++i) {
      cin >> cem[i].first >> cem[i].second;
    }
    cout << f(0, 0, 0) << endl;
  }
}
