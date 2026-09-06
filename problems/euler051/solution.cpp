#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K, L;
    std::cin >> N >> K >> L;

    long long lo = 1;
    for (int i = 1; i < N; i++) lo *= 10;
    long long hi = lo * 10 - 1;

    std::vector<bool> isComposite(hi + 1, false);
    isComposite[0] = true;
    if (hi >= 1) isComposite[1] = true;
    for (long long i = 2; i * i <= hi; i++) {
        if (!isComposite[i]) {
            for (long long j = i * i; j <= hi; j += i) isComposite[j] = true;
        }
    }
    auto isPrime = [&](long long v) {
        return v >= 2 && v <= hi && !isComposite[v];
    };

    // place value of digit position pos (0 = most significant)
    std::vector<long long> pow10(N);
    pow10[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) pow10[i] = pow10[i + 1] * 10;

    std::vector<int> masks;
    std::vector<long long> maskPow; // sum of pow10[pos] for pos in mask, aligned with masks[]
    for (int m = 0; m < (1 << N); m++) {
        if (__builtin_popcount((unsigned)m) == K) {
            masks.push_back(m);
            long long s = 0;
            for (int pos = 0; pos < N; pos++) if (m & (1 << pos)) s += pow10[pos];
            maskPow.push_back(s);
        }
    }

    std::vector<long long> bestFamily;
    bool found = false;
    std::vector<int> digitOf(N);
    long long family[10];

    for (long long P = lo; P <= hi && !found; P++) {
        if (isComposite[P]) continue;

        long long rem = P;
        for (int pos = N - 1; pos >= 0; pos--) { digitOf[pos] = (int)(rem % 10); rem /= 10; }

        for (size_t mi = 0; mi < masks.size(); mi++) {
            int mask = masks[mi];
            int sharedDigit = -1;
            bool uniform = true;
            for (int pos = 0; pos < N && uniform; pos++) {
                if (mask & (1 << pos)) {
                    if (sharedDigit == -1) sharedDigit = digitOf[pos];
                    else if (digitOf[pos] != sharedDigit) uniform = false;
                }
            }
            if (!uniform) continue;

            int famCount = 0;
            long long mp = maskPow[mi];
            for (int d = 0; d <= 9; d++) {
                if ((mask & 1) && d == 0) continue; // position 0 is the most-significant digit
                long long val = P + (long long)(d - sharedDigit) * mp;
                if (isPrime(val)) family[famCount++] = val;
            }
            if (famCount < L) continue;

            std::sort(family, family + famCount);
            std::vector<long long> candidateOutput(family, family + L);

            if (!found || candidateOutput < bestFamily) {
                bestFamily = candidateOutput;
                found = true;
            }
        }
    }

    for (size_t i = 0; i < bestFamily.size(); i++) {
        if (i) std::cout << " ";
        std::cout << bestFamily[i];
    }
    std::cout << "\n";

    return 0;
}
