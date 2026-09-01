#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const long long N_MAX = 40000000000000000LL; // 4e16

    vector<long long> evenFib;
    vector<long long> prefixSum;
    long long a = 1, b = 2;
    while (a <= N_MAX) {
        if (a % 2 == 0) {
            long long sum = (prefixSum.empty() ? 0 : prefixSum.back()) + a;
            evenFib.push_back(a);
            prefixSum.push_back(sum);
        }
        long long next = a + b;
        a = b;
        b = next;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int idx = int(upper_bound(evenFib.begin(), evenFib.end(), n) - evenFib.begin()) - 1;
        cout << (idx >= 0 ? prefixSum[idx] : 0LL) << "\n";
    }

    return 0;
}
