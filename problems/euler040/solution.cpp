#include <iostream>

int digitAt(unsigned long long idx) {
    // idx is 1-indexed position in the fractional part of Champernowne's constant
    __int128 remaining = idx;
    __int128 d = 1;
    __int128 count9 = 9;      // 9 * 10^(d-1)
    __int128 blockStart = 1;  // 10^(d-1)

    while (true) {
        __int128 blockDigits = count9 * d;
        if (remaining > blockDigits) {
            remaining -= blockDigits;
            count9 *= 10;
            blockStart *= 10;
            d += 1;
        } else {
            break;
        }
    }

    __int128 numberIndex = (remaining - 1) / d;
    __int128 number = blockStart + numberIndex;
    __int128 digitPos = (remaining - 1) % d; // 0-indexed from left within `number`

    __int128 divisor = 1;
    for (__int128 k = 0; k < d - 1 - digitPos; ++k) divisor *= 10;

    __int128 digit = (number / divisor) % 10;
    return static_cast<int>(digit);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        long long product = 1;
        for (int k = 0; k < 7; ++k) {
            unsigned long long idx;
            std::cin >> idx;
            product *= digitAt(idx);
        }
        std::cout << product << "\n";
    }
    return 0;
}
