#include <iostream>
#include <vector>

using namespace std;

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

    vector<bool> isComposite(maxN + 1, false);
    vector<long long> prefixSum(maxN + 1, 0);
    for (long long i = 2; i <= maxN; ++i) {
        if (!isComposite[i] && i <= maxN / i) {
            for (long long j = i * i; j <= maxN; j += i) {
                isComposite[j] = true;
            }
        }
        prefixSum[i] = prefixSum[i - 1] + (isComposite[i] ? 0 : i);
    }

    for (long long n : queries) {
        cout << prefixSum[n] << "\n";
    }

    return 0;
}
