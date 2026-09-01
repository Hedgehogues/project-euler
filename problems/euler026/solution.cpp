#include <iostream>
#include <vector>

constexpr int MAXN = 10000;

int cycleLength(int d) {
    std::vector<int> pos(d, -1);
    int r = 1 % d;
    int step = 0;
    while (r != 0) {
        if (pos[r] != -1) return step - pos[r];
        pos[r] = step;
        r = (r * 10) % d;
        ++step;
    }
    return 0;
}

int main() {
    std::vector<int> upto(MAXN, 0);
    int bestD = 0, bestLen = -1;
    for (int d = 2; d < MAXN; ++d) {
        int len = cycleLength(d);
        if (len > bestLen) {
            bestLen = len;
            bestD = d;
        }
        upto[d] = bestD;
    }

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cout << upto[N - 1] << "\n";
    }
    return 0;
}
