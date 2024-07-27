#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // Handle base % mod

    while (exp > 0) {
        // If exp is odd, multiply the result with the base
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        // Square the base and reduce the exponent by half
        exp = exp >> 1;  // Divide exponent by 2
        base = (base * base) % mod;
    }
    
    return result;
}

int main() {
    long long n;
    cin >> n;
    
    // Compute 2^n % mod
    cout << modExp(2, n, mod) << endl;
    
    return 0;
}
