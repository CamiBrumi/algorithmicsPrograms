#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VEE = vector<VE>;



int main() {
    int nll = 'Z' - 'A' + 1;
    VE lletres = VE(nll, 0);
    lletres[0] = 1;
    for (int i = 1; i < nll; ++i) lletres[i] = i + 1 + lletres[i-1];

    VE ant = VE(500, 0);
    VE act = VE(500, 0);

    string seq;
    cin >> seq;
    act[0] = lletres[seq[0] - 'A'];
    cout << act[0];
    for (int i = 1; i < seq.size(); ++i) {
      act[i] = act[i-1] + lletres[seq[i] - 'A'];
      cout << ' ' << act[i];
    }
    cout << endl;
    while (cin >> seq) {
      ant = act;
      act[0] = lletres[seq[0] - 'A'] +  ant[0];
      cout << act[0];
      int n = seq.size();
      for (int i = 1; i < n; ++i) {
        act[i] = lletres[seq[i] - 'A'] + act[i-1] +  ant[i] - ant[i-1];
        cout << ' ' << act[i];
      }
      cout << endl;
    }
}
