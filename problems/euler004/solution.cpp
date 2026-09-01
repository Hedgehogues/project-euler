#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool isPalindrome(int x) {
    int rev = 0, y = x;
    while (y > 0) {
        rev = rev * 10 + y % 10;
        y /= 10;
    }
    return rev == x;
}

static const vector<int>& palindromeProducts() {
    static vector<int> pals = [] {
        vector<int> v;
        for (int i = 100; i <= 999; ++i) {
            for (int j = i; j <= 999; ++j) {
                int p = i * j;
                if (isPalindrome(p)) v.push_back(p);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }();
    return pals;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int>& pals = palindromeProducts();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto it = lower_bound(pals.begin(), pals.end(), n);
        cout << *prev(it) << "\n";
    }

    return 0;
}
