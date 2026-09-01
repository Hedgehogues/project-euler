#include <iostream>
#include <vector>

using namespace std;

static const int MAX_N = 10000;

// digitSum[n] = sum of decimal digits of 2^n, computed once via repeated
// doubling of a base-10 digit array (least-significant digit first).
static vector<int> computeDigitSums() {
    vector<int> digitSum(MAX_N + 1);
    vector<int> digits = {1}; // 2^0
    digitSum[0] = 1;

    for (int n = 1; n <= MAX_N; ++n) {
        int carry = 0;
        for (int& d : digits) {
            int v = d * 2 + carry;
            d = v % 10;
            carry = v / 10;
        }
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }

        int sum = 0;
        for (int d : digits) sum += d;
        digitSum[n] = sum;
    }

    return digitSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> digitSum = computeDigitSums();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << digitSum[n] << "\n";
    }

    return 0;
}
