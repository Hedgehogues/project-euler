#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> names(n);
    for (auto &s : names) std::cin >> s;

    std::sort(names.begin(), names.end());

    std::unordered_map<std::string, long long> score;
    score.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
        long long value = 0;
        for (char c : names[i]) value += c - 'A' + 1;
        score[names[i]] = value * (i + 1);
    }

    int q;
    std::cin >> q;
    while (q--) {
        std::string word;
        std::cin >> word;
        std::cout << score[word] << "\n";
    }
    return 0;
}
