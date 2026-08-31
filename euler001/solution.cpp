#include <iostream>
using namespace std;

static long long sumMultiplesBelow(long long n, long long k) {
    long long m = (n - 1) / k;
    return k * m * (m + 1) / 2;
}

static long long solve(long long n) {
    return sumMultiplesBelow(n, 3) + sumMultiplesBelow(n, 5) - sumMultiplesBelow(n, 15);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}
