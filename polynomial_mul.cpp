#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

// Define complex type for convenience
typedef complex<double> Complex;

// Recursive FFT implementation
void recursiveFFT(Complex a[], int n, Complex y[], bool inverse = false) {
    // Base case: if n = 1, return a
    if (n == 1) {
        y[0] = a[0];
        return;
    }

    // Calculate principal complex nth root of unity
    Complex wn = exp(Complex(0, (inverse ? -1 : 1) * 2 * M_PI / n));
    Complex w = 1;

    // Split the input coefficients into even and odd indices
    Complex A0[n / 2], A1[n / 2];
    for (int i = 0; i < n; i += 2) {
        A0[i / 2] = a[i];
        A1[i / 2] = a[i + 1];
    }

    // Compute FFT recursively for even and odd parts
    Complex y0[n / 2], y1[n / 2];
    recursiveFFT(A0, n / 2, y0, inverse);
    recursiveFFT(A1, n / 2, y1, inverse);

    // Compute FFT for the entire polynomial
    for (int k = 0; k < n / 2; ++k) {
        y[k] = y0[k] + w * y1[k];
        y[k + n / 2] = y0[k] - w * y1[k];
        w *= wn;
    }
}

// Polynomial multiplication using FFT
void multiplyPolynomials(int poly1[], int size1, int poly2[], int size2, int result[]) {
    int n = 1;
    while (n < size1 + size2) {
        n <<= 1; // Find the smallest power of 2 that is greater than or equal to the size of poly1 and poly2
    }

    // Add higher-order zero coefficients to poly1 and poly2
    Complex a[n], b[n];
    fill(a, a + n, 0);
    fill(b, b + n, 0);
    for (int i = 0; i < size1; ++i) {
        a[i] = poly1[i];
    }
    for (int i = 0; i < size2; ++i) {
        b[i] = poly2[i];
    }

    // Compute FFT of poly1 and poly2
    Complex fft_poly1[n], fft_poly2[n];
    recursiveFFT(a, n, fft_poly1);
    recursiveFFT(b, n, fft_poly2);

    // Pointwise multiplication of FFT results
    Complex fft_result[n];
    for (int i = 0; i < n; ++i) {
        fft_result[i] = fft_poly1[i] * fft_poly2[i];
    }
    // Compute inverse FFT of the result
    Complex inv_fft_result[n];
    recursiveFFT(fft_result, n, inv_fft_result, true);

    // Round the real parts to integers and convert to array of integers
    for (int i = 0; i < n; ++i) {
        result[i] = round(inv_fft_result[i].real() / n);
    }
}

int main() {
    // Input polynomials: (1 + 2x + 3x^2) * (2 + x)
    int poly1[] = {9, -10, 7, 6};
    int poly2[] = {-5, 4, 0, -2};
    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    // Resulting polynomial will have size1 + size2 - 1 coefficients
    int result[size1 + size2 - 1];

    // Perform polynomial multiplication using FFT
    multiplyPolynomials(poly1, size1, poly2, size2, result);

    // Print the result
    cout << "Result of polynomial multiplication: ";
    for (int i = 0; i < size1 + size2 - 1; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
