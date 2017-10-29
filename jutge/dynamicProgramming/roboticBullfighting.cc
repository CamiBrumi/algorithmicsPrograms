#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VEE = vector<VE>;



int main() {
  int w, h, c;
  cin >> w >> h >> c;
  VEE pixSum = VEE(w, VE(h, 0));
  //tractem amb la primera fila:
  cin >> pixSum[0][0];
  int pixel;
  for (int j = 1; j < h; ++j) {
    cin >> pixel;
    pixSum[0][j] = pixel + pixSum[0][j-1];
  }

  for (int i = 1; i < w; ++i) {
    cin >> pixel;
    pixSum[i][0] = pixel + pixSum[i-1][0];
    //cout << "pixSum[i][0] = pixel + pixSum[i-1][0] = " << pixSum[i][0] << " = "  << pixel << "+" << pixSum[i-1][0] << endl;
    for (int j = 1; j < h; ++j) {
      cin >> pixel;
      pixSum[i][j] = pixel + pixSum[i-1][j] + pixSum[i][j-1] - pixSum[i-1][j-1];
      cout << "pixSum[" << i << "][" << j << "] = pixel + pixSum[i-1][j] + pixSum[i][j-1] - pixSum[i-1][j-1] = " << pixSum[i][j] << " = " << pixel << " + " << pixSum[i-1][j] << " + " << pixSum[i][j-1] << " - " << pixSum[i-1][j-1] << endl;
      //cout << ' ' << pixSum[i][j];
    }
    //cout << endl;
  }
  for (int i = 0; i < w; ++i){
    for (int j = 0; j < h; ++j) {
      cout << ' ' << pixSum[i][j];
    }
    cout << endl;
  }

  int maxi, maxj;
  int max = -1;
  for (int i = c - 1; i < w; ++i) {
    for (int j = c - 1; j < h; ++j) {
      int restUp = 0;
      int restLeft = 0;
      int sumUpLeft = 0;

      if ((j - c) != -1) restUp = pixSum[i][j-c];
      if ((i - c) != -1) restUp = pixSum[i-c][j];
      if (((j - c) != -1) and ((i - c) != -1)) sumUpLeft = pixSum[i-c][j-c];
      cout << "pixSum[" << i << "][" << j << "] - restUp - restLeft + sumUpLeft = " << pixSum[i][j] << " - " << restUp << " - " << restLeft << " + " << sumUpLeft << endl;
      int redRec = (pixSum[i][j] - restUp - restLeft + sumUpLeft);
      //cout << "redRec = " << redRec << endl;
      if (redRec > max) {
        max = redRec;
        maxi = i - c + 1;
        maxj = j - c + 1;
        //cout << maxi << ' ' << maxj << endl;
      }
    }
  }

  cout << maxi << ' ' << maxj << endl;
}
