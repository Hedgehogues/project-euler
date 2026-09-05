#include <iostream>
#include <vector>
#include <numeric>

constexpr int MAXP = 5'000'000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> count(MAXP + 1, 0);

    for (long long m = 2; 2 * m * (m + 1) <= MAXP; ++m) {
        for (long long n = 1; n < m; ++n) {
            if ((m - n) % 2 == 0) continue;
            if (std::gcd(m, n) != 1) continue;
            long long perimeter = 2 * m * (m + n);
            if (perimeter > MAXP) break;
            for (long long p = perimeter; p <= MAXP; p += perimeter) {
                count[p]++;
            }
        }
    }

    std::vector<int> bestP(MAXP + 1, 0);
    int curBestP = 0, curBestCount = 0;
    for (int p = 1; p <= MAXP; ++p) {
        if (count[p] > curBestCount) {
            curBestCount = count[p];
            curBestP = p;
        }
        bestP[p] = curBestP;
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << bestP[N] << "\n";
    }
    return 0;
}
