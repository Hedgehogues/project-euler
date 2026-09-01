#include <iostream>

constexpr long long MOD = 1'000'000'007LL;

long long mulmod(long long a, long long b) {
    return (a % MOD) * (b % MOD) % MOD;
}

long long power(long long base, long long exp) {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = mulmod(result, base);
        base = mulmod(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long inv6 = power(6, MOD - 2);

    int T;
    std::cin >> T;
    while (T--) {
        long long N;
        std::cin >> N;
        long long m = (N - 1) / 2;

        long long mm = m % MOD;
        long long mp1 = (m + 1) % MOD;
        long long tw = (2 * m + 1) % MOD;

        long long sumSq = mulmod(mulmod(mm, mp1), tw);
        long long termA = mulmod(mulmod(16, sumSq), inv6);
        long long termB = mulmod(2, mulmod(mm, mp1));
        long long termC = (4 * mm) % MOD;

        long long ans = (1 + termA + termB + termC) % MOD;
        std::cout << ans << "\n";
    }
    return 0;
}
