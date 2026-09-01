#include <iostream>
#include <string>
#include <algorithm>
#include <set>

int main() {
    int N;
    std::cin >> N;

    std::string digits;
    for (int d = 1; d <= N; ++d) digits += static_cast<char>('0' + d);

    std::set<long long> products;

    do {
        for (int i = 1; i <= N - 2; ++i) {
            for (int j = 1; i + j <= N - 1; ++j) {
                int k = N - i - j;
                if (k <= 0) continue;
                long long a = std::stoll(digits.substr(0, i));
                long long b = std::stoll(digits.substr(i, j));
                long long c = std::stoll(digits.substr(i + j, k));
                if (a * b == c) products.insert(c);
            }
        }
    } while (std::next_permutation(digits.begin(), digits.end()));

    long long sum = 0;
    for (long long p : products) sum += p;
    std::cout << sum << "\n";
    return 0;
}
