#include <iostream>
#include <vector>
#include <cstdint>

static bool isPrimeMR(unsigned long long n) {
    if (n < 2) return false;
    for (unsigned long long p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    unsigned long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) { d /= 2; r++; }
    auto mulmod = [&](unsigned long long a, unsigned long long b, unsigned long long mod) -> unsigned long long {
        return (unsigned long long)((__uint128_t)a * b % mod);
    };
    auto powmod = [&](unsigned long long a, unsigned long long e, unsigned long long mod) -> unsigned long long {
        unsigned long long result = 1;
        a %= mod;
        while (e > 0) {
            if (e & 1) result = mulmod(result, a, mod);
            a = mulmod(a, a, mod);
            e >>= 1;
        }
        return result;
    };
    for (unsigned long long a : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}) {
        if (a % n == 0) continue;
        unsigned long long x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int i = 0; i < r - 1; i++) {
            x = mulmod(x, x, n);
            if (x == n - 1) { composite = false; break; }
        }
        if (composite) return false;
    }
    return true;
}

int main() {
    const long long SIEVE_LIMIT = 6000000;
    std::vector<bool> isComposite(SIEVE_LIMIT + 1, false);
    std::vector<long long> primes;
    for (long long i = 2; i <= SIEVE_LIMIT; i++) {
        if (!isComposite[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= SIEVE_LIMIT; j += i) isComposite[j] = true;
        }
    }

    std::vector<long long> psum(primes.size() + 1, 0);
    for (size_t i = 0; i < primes.size(); i++) psum[i + 1] = psum[i] + primes[i];

    int T;
    std::cin >> T;
    while (T--) {
        long long N;
        std::cin >> N;

        // largest L with psum[L] <= N (psum strictly increasing)
        int lo = 0, hi = (int)primes.size();
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (psum[mid] <= N) lo = mid; else hi = mid - 1;
        }
        int Lmax = lo;

        long long bestSum = -1;
        int bestLen = 0;
        for (int L = Lmax; L >= 1 && bestLen == 0; L--) {
            for (size_t i = 0; i + (size_t)L <= primes.size(); i++) {
                long long sum = psum[i + L] - psum[i];
                if (sum > N) break;
                if (isPrimeMR((unsigned long long)sum)) {
                    bestSum = sum;
                    bestLen = L;
                    break;
                }
            }
        }

        std::cout << bestSum << " " << bestLen << "\n";
    }

    return 0;
}
