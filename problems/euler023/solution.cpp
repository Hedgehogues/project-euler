#include <iostream>
#include <vector>

constexpr int LIMIT = 28123;
constexpr int MAXN = 100000;

int main() {
    std::vector<int> divSum(LIMIT + 1, 0);
    for (int d = 1; d <= LIMIT; ++d) {
        for (int multiple = 2 * d; multiple <= LIMIT; multiple += d) {
            divSum[multiple] += d;
        }
    }

    std::vector<int> abundant;
    for (int n = 12; n <= LIMIT; ++n) {
        if (divSum[n] > n) abundant.push_back(n);
    }

    std::vector<bool> isSum(LIMIT + 1, false);
    for (size_t i = 0; i < abundant.size(); ++i) {
        for (size_t j = i; j < abundant.size(); ++j) {
            int s = abundant[i] + abundant[j];
            if (s > LIMIT) break;
            isSum[s] = true;
        }
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        bool result = (N > LIMIT) || (N >= 0 && N <= LIMIT && isSum[N]);
        std::cout << (result ? "YES" : "NO") << "\n";
    }
    return 0;
}
