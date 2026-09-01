#include <iostream>
#include <vector>

constexpr int MAXN = 5'000'000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> length(MAXN + 1, 0);
    length[1] = 1;

    std::vector<long long> path;
    path.reserve(1200);

    for (int i = 2; i <= MAXN; ++i) {
        if (length[i]) continue;
        long long n = i;
        path.clear();
        while (n != 1 && (n > MAXN || length[n] == 0)) {
            path.push_back(n);
            n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        }
        int base = (n == 1) ? 1 : length[n];
        for (int k = (int)path.size() - 1; k >= 0; --k) {
            ++base;
            if (path[k] <= MAXN) length[(int)path[k]] = base;
        }
    }

    std::vector<int> bestN(MAXN + 1, 0);
    bestN[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        bestN[i] = (length[i] >= length[bestN[i - 1]]) ? i : bestN[i - 1];
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << bestN[N] << "\n";
    }
    return 0;
}
