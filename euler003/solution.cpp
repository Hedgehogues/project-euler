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

        long long largest = 1;
        while (n % 2 == 0) {
            largest = 2;
            n /= 2;
        }
        for (long long p = 3; p * p <= n; p += 2) {
            while (n % p == 0) {
                largest = p;
                n /= p;
            }
        }
        if (n > 1) largest = n;

        cout << largest << "\n";
    }

    return 0;
}
