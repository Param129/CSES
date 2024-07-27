#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;
#define int long long

signed main() {
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (char it : s) {
        mp[it]++;
    }

    int odd_count = 0;
    char odd_char;
    for (auto it : mp) {
        if (it.second % 2 != 0) {
            odd_count++;
            odd_char = it.first;
        }
        if (odd_count > 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    string a = "";
    string b = "";

    for (auto it : mp) {
        char ch = it.first;
        int x = it.second;
        if (x % 2 != 0) {
            continue; // Skip the odd character as it's handled separately
        }
        int half_count = x / 2;
        a += string(half_count, ch);
        b += string(half_count, ch);
    }

    reverse(b.begin(), b.end());

    string result = a;
    if (odd_count == 1) {
        int cnt=mp[odd_char];
        while(cnt--){
            result+=odd_char;
        }
    }
    result += b;

    cout << result << endl;

    return 0;
}
