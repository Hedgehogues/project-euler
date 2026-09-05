#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int M = N + 1; // digits 0..N, M digits total
    int primes[7] = {2, 3, 5, 7, 11, 13, 17};
    int numRules = M - 3;
    if (numRules < 0) numRules = 0;
    if (numRules > 7) numRules = 7;

    std::string digits;
    for (int d = 0; d <= N; ++d) digits += static_cast<char>('0' + d);

    long long sum = 0;
    do {
        bool ok = true;
        for (int k = 1; k <= numRules; ++k) {
            int sub = (digits[k] - '0') * 100 + (digits[k + 1] - '0') * 10 + (digits[k + 2] - '0');
            if (sub % primes[k - 1] != 0) { ok = false; break; }
        }
        if (ok) {
            sum += std::stoll(digits);
        }
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << sum << "\n";
    return 0;
}
