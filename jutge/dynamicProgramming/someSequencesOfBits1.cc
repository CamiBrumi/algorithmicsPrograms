#include <iostream>
#include <vector>
using namespace std;
using VE = vector<int>;

int f1(int n);
int f2(int n);
int f3(int n);

// f1 que acaba amb 0
int f1(int n) {
  if (n <= 2) return 1;
  return f2(n-1) + f3(n-1);
}

// f2 que acaba amb 01
int f2(int n) {
  //if (n == 1) return 0;
  if (n <= 3) return 1; // ja no podrà ser n = 1.
  return f2(n-2) + f3(n-2);
}

// f3 que acaba amb 11
int f3(int n) {
  if (n == 1) return 0;
  if (n <= 2) return 1; // ja no podrà ser n = 1.
  return f1(n-2);
}


int main() {
  //cout << "-1-" << endl;
  int n;
  //cout << "-2-" << endl;
  while (cin >> n) {
    if (n == 0) cout << 1 << endl;
    else if (n == 1) cout << 2 << endl;
    else cout << f1(n) + f2(n) + f3(n) << endl;
  }
}
