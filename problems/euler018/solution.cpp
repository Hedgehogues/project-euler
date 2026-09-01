#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<std::vector<int>> tri(N);
        for (int i = 0; i < N; ++i) {
            tri[i].resize(i + 1);
            for (int j = 0; j <= i; ++j) std::cin >> tri[i][j];
        }

        for (int i = N - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                tri[i][j] += std::max(tri[i + 1][j], tri[i + 1][j + 1]);
            }
        }

        std::cout << tri[0][0] << "\n";
    }
    return 0;
}
