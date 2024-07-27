#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// This function generates all unique permutations of the string `s` starting from index `i`
void solve(int i, int n, string s, set<string> &ans) {
    if (i == n) {
        ans.insert(s);
        return;
    }

    for (int idx = i; idx < n; idx++) {
        swap(s[i], s[idx]);  // Swap characters at index i and idx
        solve(i + 1, n, s, ans);  // Recursive call for the next index
        swap(s[i], s[idx]);  // Swap back to restore original string
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    set<string> ans;  // To store unique permutations

    solve(0, n, s, ans);

    cout << ans.size() << endl;
    vector<string> sorted_ans(ans.begin(), ans.end());  // Convert set to vector for sorting and printing
    sort(sorted_ans.begin(), sorted_ans.end());

    for (const auto &str : sorted_ans) {
        cout << str << endl;
    }

    return 0;
}
