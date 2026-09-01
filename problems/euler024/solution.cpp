#include <iostream>
#include <vector>
#include <string>

int main() {
    long long fact[14];
    fact[0] = 1;
    for (int i = 1; i < 14; ++i) fact[i] = fact[i - 1] * i;

    int T;
    std::cin >> T;
    while (T--) {
        long long N;
        std::cin >> N;
        long long idx = N - 1;

        std::string digits = "abcdefghijklm";
        std::vector<char> pool(digits.begin(), digits.end());
        std::string result;

        for (int pos = 13; pos >= 1; --pos) {
            long long f = fact[pos - 1];
            int i = static_cast<int>(idx / f);
            idx %= f;
            result += pool[i];
            pool.erase(pool.begin() + i);
        }

        std::cout << result << "\n";
    }
    return 0;
}
