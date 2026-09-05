#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        long long t;
        std::cin >> t;

        long long disc = 1 + 8 * t; // fits in int64: 8*1e18+1 < 9.3e18

        long long lo = 1, hi = 3000000000LL; // sqrt(8e18) ~ 2.83e9, safe upper bound
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (mid * mid >= disc) hi = mid;
            else lo = mid + 1;
        }
        // refine in case bound was too tight
        while (lo * lo < disc) ++lo;

        long long s = lo;
        if (s * s == disc && (s - 1) % 2 == 0) {
            std::cout << (s - 1) / 2 << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }
    return 0;
}
