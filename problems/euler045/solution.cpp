#include <iostream>

long long isqrt(long long x) {
    long long lo = 1, hi = 400000000LL;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mid * mid >= x) hi = mid;
        else lo = mid + 1;
    }
    while (lo * lo < x) ++lo;
    return lo;
}

bool isTriangular(long long x) {
    long long disc = 1 + 8 * x;
    long long s = isqrt(disc);
    if (s * s != disc) return false;
    return (s - 1) % 2 == 0;
}

bool isPentagonal(long long x) {
    long long disc = 1 + 24 * x;
    long long s = isqrt(disc);
    if (s * s != disc) return false;
    return (s + 1) % 6 == 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, a, b;
    std::cin >> N >> a >> b;

    if (a == 3 && b == 6) {
        for (long long n = 1;; ++n) {
            long long h = n * (2 * n - 1);
            if (h >= N) break;
            std::cout << h << "\n";
        }
    } else if (a == 3 && b == 5) {
        for (long long n = 1;; ++n) {
            long long p = n * (3 * n - 1) / 2;
            if (p >= N) break;
            if (isTriangular(p)) std::cout << p << "\n";
        }
    } else if (a == 5 && b == 6) {
        for (long long n = 1;; ++n) {
            long long h = n * (2 * n - 1);
            if (h >= N) break;
            if (isPentagonal(h)) std::cout << h << "\n";
        }
    }

    return 0;
}
