#include <iostream>
#include <queue>

using namespace std;
#define int long long
int find(int n,
                                int k)
{
    // Base case: if there's only one child left, it's the
    // one to be removed
    if (n == 1)
        return 1;
    // If k is less than or equal to half the total number
    // of children
    if (k <= (n + 1) / 2)
    {
        // If 2*k is greater than the total number of
        // children, return the remainder of 2*k divided by
        // the total number of children
        if (2 * k > n)
            return (2 * k) % n;
        else
            // Otherwise, return 2*k
            return 2 * k;
    }
    // Calculate the kth child to be removed for half the
    // total number of children
    int temp = find(
        n / 2,
        k - (n + 1) / 2);
    // If the total number of children is odd, return 2*temp
    // + 1
    if (n % 2 == 1)
        return 2 * temp + 1;
    // Otherwise, return 2*temp - 1
    return 2 * temp - 1;
}

signed main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n,k;
        cin>>n>>k;

        cout<<find(n,k)<<endl;

    }

    return 0;
}
