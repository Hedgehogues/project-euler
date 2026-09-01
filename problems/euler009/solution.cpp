#include <iostream>

// a+b+c=N, a^2+b^2=c^2, c=N-a-b  =>  b = N(N-2a) / (2(N-a)), derived once per a.
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        long long N;
        std::cin >> N;

        long long best = -1;
        for (long long a = 1; 3 * a < N; ++a) {
            long long num = N * (N - 2 * a);
            long long den = 2 * (N - a);
            if (num <= 0 || num % den != 0) continue;
            long long b = num / den;
            if (b <= a) continue;
            long long c = N - a - b;
            if (c <= b) continue;
            long long prod = a * b * c;
            if (prod > best) best = prod;
        }
        std::cout << best << "\n";
    }
    return 0;
}
