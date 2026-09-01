#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N, K;
        std::cin >> N >> K;
        std::string digits;
        std::cin >> digits;

        long long best = 0;
        for (int i = 0; i + K <= N; ++i) {
            long long prod = 1;
            for (int j = 0; j < K; ++j) {
                prod *= (digits[i + j] - '0');
            }
            if (prod > best) best = prod;
        }
        std::cout << best << "\n";
    }
    return 0;
}
