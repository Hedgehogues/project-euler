#include <iostream>

int main() {
    long long N;
    std::cin >> N;

    long long powOf9 = 1;
    for (int i = 0; i < N; ++i) powOf9 *= 9;

    long long limit = powOf9;
    long long digits = 1;
    while (true) {
        long long candidateLimit = (digits + 1) * powOf9;
        long long minWithDigitsPlus1 = 1;
        for (int i = 0; i < digits; ++i) minWithDigitsPlus1 *= 10;
        if (candidateLimit < minWithDigitsPlus1) break;
        ++digits;
        limit = candidateLimit;
    }

    long long digitPow[10];
    for (int d = 0; d <= 9; ++d) {
        long long p = 1;
        for (int i = 0; i < N; ++i) p *= d;
        digitPow[d] = p;
    }

    long long total = 0;
    for (long long i = 10; i <= limit; ++i) {
        long long sum = 0;
        long long x = i;
        while (x > 0) {
            sum += digitPow[x % 10];
            x /= 10;
        }
        if (sum == i) total += i;
    }

    std::cout << total << "\n";
    return 0;
}
