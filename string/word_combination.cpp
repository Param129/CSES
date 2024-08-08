#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

#define int long long

const int MOD = 1e9 + 7;

using namespace std;

// Memoization map
unordered_map<int, int> memo;

// Recursive function with memoization
int countWays(const string& s, int idx, const unordered_set<string>& dictionary) {
    if (idx == s.size()) return 1;  // Base case: reached the end of the string
    if (memo.find(idx) != memo.end()) return memo[idx];  // Return memoized result

    int ways = 0;
    string current;
    
    for (int i = idx; i < s.size(); ++i) {
        current += s[i];
        if (dictionary.find(current) != dictionary.end()) {
            ways = (ways + countWays(s, i + 1, dictionary)) % MOD;
        }
    }
    
    memo[idx] = ways;  // Memoize the result
    return ways;
}

signed main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    unordered_set<string> dictionary;
    for (int i = 0; i < k; ++i) {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    cout << countWays(s, 0, dictionary) << endl;
    
    return 0;
}
