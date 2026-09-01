#include <iostream>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unsigned long long lcm = 1;
        for (int i = 2; i <= n; ++i) {
            lcm = lcm / gcd(lcm, (unsigned long long)i) * i;
        }
        cout << lcm << "\n";
    }

    return 0;
}
