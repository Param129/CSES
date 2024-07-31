#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

signed main() {
    ordered_set<pair<int, int>> st;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insert the first k elements into the ordered_set
    for (int i = 0; i < k; i++) {
        st.insert({a[i], i});
    }

    // Output the median of the first window
    cout << st.find_by_order((k - 1) / 2)->first << " ";

    int j = 0;
    for (int i = k; i < n; i++) {
        // Erase the element that is leaving the window
        st.erase({a[j], j});
        // Insert the new element that is entering the window
        st.insert({a[i], i});
        // Output the median of the current window
        cout << st.find_by_order((k - 1) / 2)->first << " ";
        j++;
    }
    return 0;
}
