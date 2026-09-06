#include <iostream>

constexpr long long MOD = 10000000000LL;

long long mulmod(long long a, long long b) {
    return static_cast<long long>((__int128)a * b % MOD);
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
    long long N;
    std::cin >> N;

    long long sum = 0;
    for (long long i = 1; i <= N; ++i) {
        sum = (sum + power(i, i)) % MOD;
    }

    std::cout << sum << "\n";
    return 0;
}
