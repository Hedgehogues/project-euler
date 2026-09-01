#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Rosser's theorem: p_n < n * (ln n + ln ln n) for n >= 6.
static long long nthPrimeUpperBound(long long n) {
    if (n < 6) return 15;
    double dn = static_cast<double>(n);
    double bound = dn * (log(dn) + log(log(dn)));
    return static_cast<long long>(bound) + 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> queries(t);
    long long maxN = 1;
    for (auto &n : queries) {
        cin >> n;
        maxN = max(maxN, n);
    }

    long long limit = max<long long>(20, nthPrimeUpperBound(maxN));

    vector<bool> isComposite(limit + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= limit; ++i) {
        if (!isComposite[i]) {
            primes.push_back(i);
            if (i <= limit / i) {
                for (long long j = i * i; j <= limit; j += i) {
                    isComposite[j] = true;
                }
            }
        }
    }

    for (long long n : queries) {
        cout << primes[n - 1] << "\n";
    }

    return 0;
}
