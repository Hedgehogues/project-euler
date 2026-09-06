#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

int main() {
    long long N, K;
    std::cin >> N >> K;

    const int MAXV = 999999;
    std::vector<bool> isComposite(MAXV + 1, false);
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; (long long)i * i <= MAXV; ++i) {
        if (!isComposite[i]) {
            for (int j = i * i; j <= MAXV; j += i) isComposite[j] = true;
        }
    }

    // group primes by (digit count, sorted digit signature)
    std::map<std::string, std::vector<int>> groups;
    for (int p = 2; p <= MAXV; ++p) {
        if (isComposite[p]) continue;
        std::string s = std::to_string(p);
        std::string key = s;
        std::sort(key.begin(), key.end());
        key += "#" + std::to_string(s.size());
        groups[key].push_back(p);
    }

    struct Result {
        long long firstTerm;
        std::string concat;
    };
    std::vector<Result> results;

    for (auto& [key, arr] : groups) {
        if (static_cast<long long>(arr.size()) < K) continue;
        std::set<int> present(arr.begin(), arr.end());

        for (size_t i = 0; i < arr.size(); ++i) {
            for (size_t j = i + 1; j < arr.size(); ++j) {
                long long d = arr[j] - arr[i];
                if (d <= 0) continue;

                bool ok = true;
                std::vector<long long> seq = {arr[i], arr[j]};
                for (long long t = 2; t < K; ++t) {
                    long long val = arr[j] + (t - 1) * d;
                    if (val > MAXV || present.find(static_cast<int>(val)) == present.end()) {
                        ok = false;
                        break;
                    }
                    seq.push_back(val);
                }
                if (!ok) continue;

                if (arr[i] < N) {
                    std::string concat;
                    for (long long v : seq) concat += std::to_string(v);
                    results.push_back({arr[i], concat});
                }
            }
        }
    }

    std::sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
        if (a.firstTerm != b.firstTerm) return a.firstTerm < b.firstTerm;
        return a.concat < b.concat;
    });

    for (auto& r : results) std::cout << r.concat << "\n";

    return 0;
}
