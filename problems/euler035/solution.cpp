#include <iostream>
#include <vector>

int main() {
    long long N;
    std::cin >> N;

    long long limit = N - 1;

    // rotations can exceed `limit` if N isn't a power-of-10 boundary; sieve
    // up to the max value with the same digit count as `limit` to stay safe.
    long long sieveLimit = 9;
    while (sieveLimit < limit) sieveLimit = sieveLimit * 10 + 9;

    std::vector<bool> isComposite(sieveLimit + 1, false);
    isComposite[0] = true;
    isComposite[1] = true;
    for (long long i = 2; i * i <= sieveLimit; ++i) {
        if (!isComposite[i]) {
            for (long long j = i * i; j <= sieveLimit; j += i) isComposite[j] = true;
        }
    }

    long long sum = 0;
    for (long long p = 2; p <= limit; ++p) {
        if (isComposite[p]) continue;

        // generate all rotations and check primality
        std::string s = std::to_string(p);
        bool allCircular = true;
        for (size_t r = 0; r < s.size(); ++r) {
            std::string rotated = s.substr(r) + s.substr(0, r);
            long long val = std::stoll(rotated);
            if (val < 2 || isComposite[val]) { allCircular = false; break; }
        }
        if (allCircular) sum += p;
    }

    std::cout << sum << "\n";
    return 0;
}
