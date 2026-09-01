#include <iostream>
#include <vector>

constexpr int MAXN = 1000;

int main() {
    std::vector<long long> digitSum(MAXN + 1);
    std::vector<int> num = {1}; // little-endian digits of the running factorial
    digitSum[0] = 1;            // 0! = 1

    for (int n = 1; n <= MAXN; ++n) {
        int carry = 0;
        for (size_t i = 0; i < num.size(); ++i) {
            int prod = num[i] * n + carry;
            num[i] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            num.push_back(carry % 10);
            carry /= 10;
        }
        long long sum = 0;
        for (int d : num) sum += d;
        digitSum[n] = sum;
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << digitSum[N] << "\n";
    }
    return 0;
}
