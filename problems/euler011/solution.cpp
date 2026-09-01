#include <iostream>

int main() {
    const int N = 20;
    const int K = 4;
    long long a[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> a[i][j];

    long long best = 0;
    const int dr[4] = {0, 1, 1, 1};
    const int dc[4] = {1, 0, 1, -1};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int d = 0; d < 4; ++d) {
                int ri = i + dr[d] * (K - 1);
                int ci = j + dc[d] * (K - 1);
                if (ri < 0 || ri >= N || ci < 0 || ci >= N) continue;

                long long prod = 1;
                for (int k = 0; k < K; ++k) {
                    prod *= a[i + dr[d] * k][j + dc[d] * k];
                }
                if (prod > best) best = prod;
            }
        }
    }

    std::cout << best << "\n";
    return 0;
}
