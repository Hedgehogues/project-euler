#include <iostream>
#include <string>
#include <algorithm>

static std::string sortedDigits(long long v) {
    std::string s = std::to_string(v);
    std::sort(s.begin(), s.end());
    return s;
}

int main() {
    long long N;
    int K;
    std::cin >> N >> K;

    for (long long x = 1; x <= N; x++) {
        std::string sig = sortedDigits(x);
        bool ok = true;
        for (int m = 2; m <= K; m++) {
            if (sortedDigits(x * m) != sig) { ok = false; break; }
        }
        if (ok) {
            std::cout << x;
            for (int m = 2; m <= K; m++) std::cout << " " << (x * m);
            std::cout << "\n";
        }
    }

    return 0;
}
