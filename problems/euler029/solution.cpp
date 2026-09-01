#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<char> isPower(n + 1, 0);

    long long globalMaxK = 1, v2 = 2;
    while (v2 * 2 <= n) { v2 *= 2; ++globalMaxK; }

    std::vector<char> reach(globalMaxK * n + 2, 0);
    std::vector<long long> touched;

    long long count = 0;

    for (long long a = 2; a <= n; ++a) {
        if (isPower[a]) continue;

        for (long long p = a * a; p <= n; p *= a) isPower[p] = 1;

        // k=1 always contributes exactly the full range [2,n] -> n-1 values
        count += (n - 1);

        long long maxK = 1, val = a;
        while (val * a <= n) { val *= a; ++maxK; }

        if (maxK >= 2) {
            touched.clear();
            for (long long k = 2; k <= maxK; ++k) {
                for (long long b = 2; b <= n; ++b) {
                    long long idx = k * b;
                    if (idx > n && !reach[idx]) {
                        reach[idx] = 1;
                        touched.push_back(idx);
                        ++count;
                    }
                }
            }
            for (long long idx : touched) reach[idx] = 0;
        }
    }

    std::cout << count << "\n";
    return 0;
}
