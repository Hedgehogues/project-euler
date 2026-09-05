#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isPrime(long long x) {
    if (x < 2) return false;
    if (x < 4) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<long long> candidates;

    for (int n : {4, 7}) {
        std::string digits;
        for (int d = 1; d <= n; ++d) digits += static_cast<char>('0' + d);
        do {
            long long val = std::stoll(digits);
            if (isPrime(val)) candidates.push_back(val);
        } while (std::next_permutation(digits.begin(), digits.end()));
    }

    std::sort(candidates.begin(), candidates.end());

    int T;
    std::cin >> T;
    while (T--) {
        long long N;
        std::cin >> N;
        auto it = std::upper_bound(candidates.begin(), candidates.end(), N);
        if (it == candidates.begin()) {
            std::cout << -1 << "\n";
        } else {
            std::cout << *(it - 1) << "\n";
        }
    }
    return 0;
}
