#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if we can produce at least `t` products within `d` seconds
bool check(long long d, const vector<int>& a, int t) {
    long long total_products = 0;
    for (int time : a) {
        total_products += d / time;
        if (total_products >= t) {
            return true;
        }
    }
    return total_products >= t;
}

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Set the binary search range
    long long l = 0;
    long long h = static_cast<long long>(1e18); // A very large number
    long long ans = h;

    while (l <= h) {
        long long mid = l + (h - l) / 2;
        if (check(mid, a, t)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
