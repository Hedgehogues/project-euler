#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isPandigital(const std::string& s, int K) {
    if (static_cast<int>(s.size()) != K) return false;
    std::vector<bool> seen(K + 1, false);
    for (char c : s) {
        int d = c - '0';
        if (d < 1 || d > K || seen[d]) return false;
        seen[d] = true;
    }
    return true;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> results;

    for (int m = 2; m < N; ++m) {
        std::string concat;
        for (long long n = 1; static_cast<int>(concat.size()) < K; ++n) {
            concat += std::to_string(m * n);
        }
        if (isPandigital(concat, K)) results.push_back(m);
    }

    std::sort(results.begin(), results.end());
    for (int m : results) std::cout << m << "\n";

    return 0;
}
