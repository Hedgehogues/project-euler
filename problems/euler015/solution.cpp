#include <iostream>
#include <vector>

constexpr long long MOD = 1'000'000'007LL;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (__int128)result * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    const int MAXN = 1001;
    std::vector<long long> fact(MAXN), invFact(MAXN);
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i % MOD;
    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 1; i > 0; --i) invFact[i - 1] = invFact[i] * i % MOD;

    int T;
    std::cin >> T;
    while (T--) {
        int N, M;
        std::cin >> N >> M;
        long long ans = fact[N + M] * invFact[N] % MOD * invFact[M] % MOD;
        std::cout << ans << "\n";
    }
    return 0;
}
