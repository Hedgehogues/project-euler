#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sum(1, 0); // little-endian digits
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        if ((int)sum.size() < (int)s.size()) sum.resize(s.size(), 0);

        int carry = 0;
        for (int j = 0; j < (int)s.size(); ++j) {
            int total = sum[j] + (s[s.size() - 1 - j] - '0') + carry;
            sum[j] = total % 10;
            carry = total / 10;
        }
        for (int j = (int)s.size(); carry; ++j) {
            if (j == (int)sum.size()) sum.push_back(0);
            int total = sum[j] + carry;
            sum[j] = total % 10;
            carry = total / 10;
        }
    }

    int len = (int)sum.size();
    while (len > 1 && sum[len - 1] == 0) --len;

    std::string result;
    for (int i = len - 1; i >= 0; --i) result += char('0' + sum[i]);
    std::cout << result.substr(0, 10) << "\n";
    return 0;
}
