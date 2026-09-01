#include <iostream>
#include <vector>

bool isPrime(long long x) {
    if (x < 2) return false;
    if (x < 4) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> primesB;
    for (int b = 2; b <= N; ++b) {
        if (isPrime(b)) primesB.push_back(b);
    }

    int bestLen = -1, bestA = 0, bestB = 0;
    for (int b : primesB) {
        for (int a = -N; a <= N; ++a) {
            long long n = 0;
            while (true) {
                long long val = n * n + a * n + b;
                if (!isPrime(val)) break;
                ++n;
            }
            if (n > bestLen) {
                bestLen = static_cast<int>(n);
                bestA = a;
                bestB = b;
            }
        }
    }

    std::cout << bestA << " " << bestB << "\n";
    return 0;
}
