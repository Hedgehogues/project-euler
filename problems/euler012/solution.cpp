#include <iostream>
#include <vector>

using namespace std;

// Triangular number T_n = n*(n+1)/2. Since gcd(n, n+1) = 1, splitting into the
// even half (n/2 or (n+1)/2) and the odd counterpart lets divisor counts of
// the two coprime factors multiply: d(T_n) = d(a) * d(b).
static const long long SIEVE_LIMIT = 60000;
static const int MAX_N = 1000;

static vector<int> buildSmallestPrimeFactor(long long limit) {
    vector<int> spf(limit + 1, 0);
    for (long long i = 2; i <= limit; ++i) {
        if (spf[i] == 0) {
            for (long long j = i; j <= limit; j += i) {
                if (spf[j] == 0) spf[j] = static_cast<int>(i);
            }
        }
    }
    return spf;
}

static long long divisorCount(long long x, const vector<int>& spf) {
    long long count = 1;
    while (x > 1) {
        int p = spf[x];
        int exponent = 0;
        while (x % p == 0) {
            x /= p;
            ++exponent;
        }
        count *= (exponent + 1);
    }
    return count;
}

static vector<long long> computeAnswers() {
    vector<int> spf = buildSmallestPrimeFactor(SIEVE_LIMIT);
    vector<long long> answer(MAX_N + 1, -1);

    int filled = 0;
    for (long long n = 1; filled < MAX_N; ++n) {
        long long a, b;
        if (n % 2 == 0) {
            a = n / 2;
            b = n + 1;
        } else {
            a = n;
            b = (n + 1) / 2;
        }
        long long divisors = divisorCount(a, spf) * divisorCount(b, spf);
        long long triangular = n * (n + 1) / 2;

        for (int threshold = 1; threshold <= MAX_N; ++threshold) {
            if (answer[threshold] == -1 && divisors > threshold) {
                answer[threshold] = triangular;
                ++filled;
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> answer = computeAnswers();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << answer[n] << "\n";
    }

    return 0;
}
