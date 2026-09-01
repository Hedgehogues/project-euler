#include <iostream>
#include <vector>

constexpr long long MOD = 1'000'000'007LL;
constexpr int MAXN = 1'000'000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    std::vector<long long> dp(MAXN + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        for (int i = c; i <= MAXN; ++i) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << dp[N] << "\n";
    }
    return 0;
}
