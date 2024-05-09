#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
#define PI 3.14159265358979323846
void fft(complex<double> x[], int n, complex<double> A[]) {
    if (n == 1) {
        A[0] = x[0];
    } else {
        complex<double> even[n / 2];
        complex<double> odd[n / 2];
        complex<double> even_fft[n / 2];
        complex<double> odd_fft[n / 2];
        complex<double> Wn = exp(-2.0 * PI * complex<double>(0, 1) / static_cast<double>(n));
        complex<double> w = 1;
        int k;
        for (k = 0; k < n / 2; k++) {
            even[k] = x[2 * k];
            odd[k] = x[2 * k + 1];
        }

        fft(even, n / 2, even_fft);
        fft(odd, n / 2, odd_fft);
        for (k = 0; k < n / 2; k++) {
            A[k] = even_fft[k] + w * odd_fft[k];
            A[k + n / 2] = even_fft[k] - w * odd_fft[k];
            w *= Wn;
        }
    }
}
int main() {
    int n = 4; // Change n to your desired sequence length
    complex<double> x[n]; // Input sequence
    complex<double> A[n]; // Fourier coefficients
    int i;

    // Populate input sequence (can be changed according to requirements)
    for (i = 0; i < n; i++) {
        cout << "Enter f" << i << ": ";
        cin >> x[i]; // Just a simple example, you can replace with your input sequence
    }
    // Perform FFT
    fft(x, n, A);
    // Display the Fourier coefficients
    cout << "Fourier coefficients:\n";
    for (i = 0; i < n; i++) {
        cout << "A" << i << " = " << A[i].real() << " + " << A[i].imag() << "i\n";
    }
    return 0;
}
