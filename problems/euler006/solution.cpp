#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long sum = n * (n + 1) / 2;
        long long sumSquares = n * (n + 1) * (2 * n + 1) / 6;

        cout << (sum * sum - sumSquares) << "\n";
    }

    return 0;
}
