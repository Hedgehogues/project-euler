#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;

    int lo = 1;
    for (int i = 0; i < N - 1; ++i) lo *= 10;
    int hi = lo * 10 - 1;

    // key: sorted multiset of removed digits (as a small vector) -> list of (original, remaining)
    std::map<std::vector<int>, std::vector<std::pair<int, int>>> groups;

    std::vector<int> masks;
    for (int mask = 0; mask < (1 << N); ++mask) {
        if (__builtin_popcount(mask) == K) masks.push_back(mask);
    }

    for (int num = lo; num <= hi; ++num) {
        int digits[8];
        int tmp = num;
        for (int i = N - 1; i >= 0; --i) { digits[i] = tmp % 10; tmp /= 10; }

        for (int mask : masks) {
            bool hasZero = false;
            std::vector<int> removed;
            long long remaining = 0;
            for (int pos = 0; pos < N; ++pos) {
                bool bit = (mask >> pos) & 1;
                if (bit) {
                    if (digits[pos] == 0) hasZero = true;
                    removed.push_back(digits[pos]);
                } else {
                    remaining = remaining * 10 + digits[pos];
                }
            }
            if (hasZero) continue;
            std::sort(removed.begin(), removed.end());
            groups[removed].push_back({num, static_cast<int>(remaining)});
        }
    }

    std::set<std::pair<int, int>> valid;
    for (auto& [key, list] : groups) {
        for (size_t i = 0; i < list.size(); ++i) {
            for (size_t j = i + 1; j < list.size(); ++j) {
                auto [a, ra] = list[i];
                auto [b, rb] = list[j];
                if (a == b) continue;
                int numerator = std::min(a, b), denominator = std::max(a, b);
                int remNum = (a < b) ? ra : rb;
                int remDen = (a < b) ? rb : ra;
                if (remDen == 0) continue;
                if (static_cast<long long>(numerator) * remDen == static_cast<long long>(denominator) * remNum) {
                    valid.insert({numerator, denominator});
                }
            }
        }
    }

    long long sumNum = 0, sumDen = 0;
    for (auto& [n, d] : valid) { sumNum += n; sumDen += d; }

    std::cout << sumNum << " " << sumDen << "\n";
    return 0;
}
