#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> ONES = {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
const std::vector<std::string> TENS = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

std::string underThousand(int n) {
    std::string res;
    if (n >= 100) {
        res += ONES[n / 100] + " Hundred";
        n %= 100;
        if (n) res += " ";
    }
    if (n >= 20) {
        res += TENS[n / 10];
        if (n % 10) res += " " + ONES[n % 10];
    } else if (n > 0) {
        res += ONES[n];
    }
    return res;
}

std::string numberToWords(long long n) {
    if (n == 0) return "Zero";

    const long long SCALES[] = {1000000000000LL, 1000000000LL, 1000000LL, 1000LL};
    const std::string NAMES[] = {"Trillion", "Billion", "Million", "Thousand"};

    std::string result;
    for (int i = 0; i < 4; ++i) {
        long long group = n / SCALES[i];
        n %= SCALES[i];
        if (group > 0) {
            if (!result.empty()) result += " ";
            result += underThousand((int)group) + " " + NAMES[i];
        }
    }
    if (n > 0) {
        if (!result.empty()) result += " ";
        result += underThousand((int)n);
    }
    return result;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        long long N;
        std::cin >> N;
        std::cout << numberToWords(N) << "\n";
    }
    return 0;
}
