#pragma GCC target("avx2")

#include <immintrin.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

#define N 100000

int main() {
    alignas(32) int a[N], b[N], c[N];

    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i * 2;
    }

    auto start = high_resolution_clock::now(); 

    for (int i = 0; i < N; i += 8) {
        __m256i x = _mm256_loadu_si256((__m256i*)&a[i]);
        __m256i y = _mm256_loadu_si256((__m256i*)&b[i]);
        __m256i z = _mm256_add_epi32(x, y);
        _mm256_storeu_si256((__m256i*)&c[i], z);
    }

    auto end = high_resolution_clock::now(); 

    double duration = duration_cast<nanoseconds>(end - start).count(); 
    cout << "Execution time: " << duration << " ms\n";

    int d[N];
    start = high_resolution_clock::now();  

    for (int i = 0; i < N; i++) {
        d[i] = a[i] + b[i];
    }

    end = high_resolution_clock::now(); 

    duration = duration_cast<nanoseconds>(end - start).count(); 
    cout << "Execution time: " << duration << " ms\n";
    return 0;
}
