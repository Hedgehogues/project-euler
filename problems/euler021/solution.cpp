#include <iostream>
#include <vector>

constexpr int MAXN = 100000;

int main() {
    std::vector<int> divSum(MAXN, 0);
    for (int d = 1; d < MAXN; ++d) {
        for (int multiple = 2 * d; multiple < MAXN; multiple += d) {
            divSum[multiple] += d;
        }
    }

    std::vector<long long> prefix(MAXN, 0);
    for (int a = 1; a < MAXN; ++a) {
        int b = divSum[a];
        bool amicable = (b != a) && (b > 0) && (b < MAXN) && (divSum[b] == a);
        prefix[a] = prefix[a - 1] + (amicable ? a : 0);
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << prefix[N - 1] << "\n";
    }
    return 0;
}
