#include <iostream>
#include <vector>

constexpr long long BASE = 1'000'000'000LL;
constexpr int MAXD = 5000;

int digitCount(const std::vector<long long>& v) {
    int lead = static_cast<int>(v.back());
    int leadDigits = 0;
    while (lead > 0) { ++leadDigits; lead /= 10; }
    if (leadDigits == 0) leadDigits = 1;
    return leadDigits + 9 * static_cast<int>(v.size() - 1);
}

std::vector<long long> add(const std::vector<long long>& a, const std::vector<long long>& b) {
    std::vector<long long> result;
    result.reserve(std::max(a.size(), b.size()) + 1);
    long long carry = 0;
    for (size_t i = 0; i < a.size() || i < b.size() || carry; ++i) {
        long long sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(sum % BASE);
        carry = sum / BASE;
    }
    return result;
}

int main() {
    std::vector<long long> firstIndex(MAXD + 1, 0);

    std::vector<long long> prev = {1}; // F1
    std::vector<long long> curr = {1}; // F2
    firstIndex[1] = 1;

    long long idx = 2;
    int filled = 1;
    while (filled < MAXD) {
        std::vector<long long> next = add(prev, curr);
        ++idx;
        prev = curr;
        curr = next;
        int d = digitCount(curr);
        if (d > filled) {
            for (int k = filled + 1; k <= d && k <= MAXD; ++k) firstIndex[k] = idx;
            filled = d;
        }
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << firstIndex[N] << "\n";
    }
    return 0;
}
