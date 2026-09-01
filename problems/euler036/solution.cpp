#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindromeBase10(long long num) {
    std::string s = std::to_string(num);
    std::string r = s;
    std::reverse(r.begin(), r.end());
    return s == r;
}

bool isPalindromeBaseK(long long num, int K) {
    std::vector<int> digits;
    long long t = num;
    while (t > 0) { digits.push_back(t % K); t /= K; }
    int lo = 0, hi = static_cast<int>(digits.size()) - 1;
    while (lo < hi) {
        if (digits[lo] != digits[hi]) return false;
        ++lo; --hi;
    }
    return true;
}

int main() {
    long long N;
    int K;
    std::cin >> N >> K;

    long long sum = 0;
    for (long long num = 1; num < N; ++num) {
        if (isPalindromeBase10(num) && isPalindromeBaseK(num, K)) sum += num;
    }

    std::cout << sum << "\n";
    return 0;
}
