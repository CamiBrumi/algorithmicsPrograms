#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VEE = vector<VE>;

int main() {
  int w, h, c;
  cin >> w >> h >> c;
  VEE M(w + 1, VE(h + 1, 0));
  for (int i = 1; i <= w; ++i)
    for (int j = 1; j <= h; ++j) cin >> M[i][j];

  for (int i = 1; i <= w; ++i)
    for (int j = 1; j <= h; ++j) M[i][j] += M[i][j-1] + M[i-1][j] - M[i-1][j-1];
  
  int maxi, maxj;
  int max = -1;
  for (int i = c; i <= w; ++i) {
    for (int j = c; j <= h; ++j) {
      int restUp = M[i-c][j];
      int restLeft = M[i][j-c];
      int sumUpLeft = M[i-c][j-c];
      
      //cout << "pixSum[" << i << "][" << j << "] - restUp - restLeft + sumUpLeft = " << pixSum[i][j] << " - " << restUp << " - " << restLeft << " + " << sumUpLeft << endl;
      int redRec = M[i][j] - restUp - restLeft + sumUpLeft;
      //cout << "redRec = " << redRec << endl;
      if (redRec > max) {
          
        max = redRec;
        maxi = i - c;
        maxj = j - c;
        //cout << maxi << ' ' << maxj << endl;
      }
    }
  }

  cout << maxi << ' ' << maxj << endl;  
}
