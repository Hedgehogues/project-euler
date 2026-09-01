#include <iostream>

int main() {
    long long N;
    std::cin >> N;

    long long fact[10];
    fact[0] = 1;
    for (int i = 1; i <= 9; ++i) fact[i] = fact[i - 1] * i;

    long long limit = N - 1;
    const long long SAFE_CAP = 3'000'000;
    if (limit > SAFE_CAP) limit = SAFE_CAP;

    long long sum = 0;
    for (long long num = 10; num <= limit; ++num) {
        long long s = 0;
        long long t = num;
        while (t > 0) {
            s += fact[t % 10];
            t /= 10;
        }
        if (s % num == 0) sum += num;
    }

    std::cout << sum << "\n";
    return 0;
}
