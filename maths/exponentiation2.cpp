#include <iostream>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int PHI_MOD = MOD - 1; // 10^9 + 6

// Modular multiplication
int mul(int a, int b, int mod) {
    return ((a % mod) * (b % mod)) % mod;
}

// Modular exponentiation
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply base with result
            result = mul(result, base, mod);
        }
        exp = exp >> 1;  // Divide exp by 2
        base = mul(base, base, mod);  // Square the base
    }
    return result;
}

// Solve function to compute a^(b^c) % MOD
void solve(int a, int b, int c) {
    // Compute b^c % PHI_MOD
    int exponent = mod_pow(b, c, PHI_MOD);
    // Compute a^exponent % MOD
    int result = mod_pow(a, exponent, MOD);
    cout << result << endl;
}

signed main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
    return 0;
}
