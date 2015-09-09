#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <complex>
using namespace std;
typedef complex<double> cmpd;

// フーリエ逆変換した後はfの各要素をFFT_Nで割ること
const int FFT_N = 262144; // 2^18
enum fft_direction { fft_forward, fft_backward };

void dft(vector<cmpd>& f, int n, fft_direction fftd){
  if(n == 1) return;

  vector<cmpd> f0(n / 2);
  vector<cmpd> f1(n / 2);
  for(int i = 0; i < n / 2; i++){
    f0[i] = f[2 * i + 0];
    f1[i] = f[2 * i + 1];
  }
  dft(f0, n / 2, fftd);
  dft(f1, n / 2, fftd);
  cmpd zeta = polar(1.0, (fftd == fft_forward ? 1 : -1) * 2 * M_PI / n);
  cmpd pow_zeta = 1;
  for(int i = 0; i < n; i++){
    f[i] = f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)];
    pow_zeta *= zeta;
  }
}

