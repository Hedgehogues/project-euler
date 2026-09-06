#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N, K;
    std::cin >> N >> K;

    long long bound = N + K; // a bit of safety margin beyond N+K-1
    std::vector<int> omega(bound + 1, 0);
    for (long long p = 2; p <= bound; ++p) {
        if (omega[p] == 0) { // p is prime (not yet marked by any smaller factor)
            for (long long m = p; m <= bound; m += p) omega[m]++;
        }
    }

    for (long long m = 2; m <= N; ++m) {
        bool ok = true;
        for (long long i = 0; i < K; ++i) {
            if (omega[m + i] != K) { ok = false; break; }
        }
        if (ok) std::cout << m << "\n";
    }

    return 0;
}
