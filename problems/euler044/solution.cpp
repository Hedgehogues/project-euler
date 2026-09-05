#include <iostream>

long long pentagonal(long long n) {
    return n * (3 * n - 1) / 2;
}

bool isPentagonal(long long x) {
    if (x <= 0) return false;
    long long disc = 1 + 24 * x;

    long long lo = 1, hi = 10000000LL;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mid * mid >= disc) hi = mid;
        else lo = mid + 1;
    }
    while (lo * lo < disc) ++lo;

    if (lo * lo != disc) return false;
    return (1 + lo) % 6 == 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, K;
    std::cin >> N >> K;

    for (long long n = K + 1; n < N; ++n) {
        long long pn = pentagonal(n);
        long long pnk = pentagonal(n - K);
        if (isPentagonal(pn - pnk) || isPentagonal(pn + pnk)) {
            std::cout << pn << "\n";
        }
    }
    return 0;
}
