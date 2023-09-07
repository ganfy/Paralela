#include <iostream>
#include <chrono>
#define n 1000
using namespace std;

int A[n][n], B[n][n], C[n][n];

int main(){

    //filling matrices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }
    
    //normal multiplication

    std::chrono::seconds s (1);             // 1 second
    std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds> (s);
    auto start = chrono::steady_clock::now();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start); 

    std::cout << "ns: " << ns.count() << std::endl;

    //filling matrices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }

    //block multiplication

    start = chrono::steady_clock::now();

    int blockSize = 4; 
    
    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int ii = i; ii < min(i + blockSize, n); ++ii) {
                    for (int jj = j; jj < min(j + blockSize, n); ++jj) {
                        C[ii][jj] = 0;
                        for (int kk = k; kk < min(k + blockSize, n); ++kk) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }

    end = chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout << "ns: " << ns.count() << std::endl;
}

