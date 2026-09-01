#include <iostream>

using namespace std;

// Sakamoto's algorithm, returns 0=Sunday..6=Saturday.
// The Gregorian calendar repeats every 400 years = 146097 days = exactly
// 20871 weeks, and every term of the formula (y, y/4, y/100, y/400) shifts
// by an exact multiple of 7 when y shifts by lcm(400, 7) = 2800. So reducing
// `year` mod 2800 first keeps every intermediate value small no matter how
// large the input year is (constraints here allow Y up to 10^16).
static int dayOfWeek(long long year, int month, int day) {
    static const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    long long y = year;
    if (month < 3) y -= 1;
    y = ((y % 2800) + 2800) % 2800;
    long long sum = y + y / 4 - y / 100 + y / 400 + t[month - 1] + day;
    return static_cast<int>(((sum % 7) + 7) % 7);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long y1, y2;
        int m1, d1, m2, d2;
        cin >> y1 >> m1 >> d1;
        cin >> y2 >> m2 >> d2;

        long long count = 0;
        long long y = y1;
        int m = m1;
        while (y < y2 || (y == y2 && m <= m2)) {
            bool include = !(y == y1 && m == m1 && d1 > 1);
            if (include && dayOfWeek(y, m, 1) == 0) ++count;
            ++m;
            if (m > 12) {
                m = 1;
                ++y;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
