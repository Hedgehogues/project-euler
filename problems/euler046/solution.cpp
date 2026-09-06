#include <iostream>
#include <vector>

constexpr int MAXN = 500000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<bool> isComposite(MAXN + 1, false);
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; (long long)i * i <= MAXN; ++i) {
        if (!isComposite[i]) {
            for (int j = i * i; j <= MAXN; j += i) isComposite[j] = true;
        }
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        int count = 0;
        for (int k = 1; 2 * k * k < N; ++k) {
            int rem = N - 2 * k * k;
            if (rem >= 2 && !isComposite[rem]) ++count;
        }
        std::cout << count << "\n";
    }
    return 0;
}
