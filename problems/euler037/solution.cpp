#include <iostream>
#include <vector>
#include <string>

int main() {
    long long N;
    std::cin >> N;

    long long limit = N - 1;
    std::vector<bool> isComposite(limit + 1, false);
    isComposite[0] = true;
    if (limit >= 1) isComposite[1] = true;
    for (long long i = 2; i * i <= limit; ++i) {
        if (!isComposite[i]) {
            for (long long j = i * i; j <= limit; j += i) isComposite[j] = true;
        }
    }

    auto isPrime = [&](long long x) {
        if (x < 2 || x > limit) return false;
        return !isComposite[x];
    };

    long long sum = 0;
    for (long long p = 10; p <= limit; ++p) {
        if (isComposite[p]) continue;

        std::string s = std::to_string(p);
        bool truncatable = true;

        // right-to-left truncation (remove leftmost digit each time)
        for (size_t i = 1; i < s.size() && truncatable; ++i) {
            long long val = std::stoll(s.substr(i));
            if (!isPrime(val)) truncatable = false;
        }
        // left-to-right truncation (remove rightmost digit each time)
        for (size_t len = s.size() - 1; len >= 1 && truncatable; --len) {
            long long val = std::stoll(s.substr(0, len));
            if (!isPrime(val)) truncatable = false;
            if (len == 1) break;
        }

        if (truncatable) sum += p;
    }

    std::cout << sum << "\n";
    return 0;
}
