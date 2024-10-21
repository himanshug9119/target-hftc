#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Optimize I/O operations
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    // Use a string to buffer the output
    string output;
    output.reserve(100); // Reserve some initial space to avoid frequent reallocations

    // Simulate the Collatz sequence
    while (n > 1)
    {
        output += to_string(n) + ' ';
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
    }
    output += "1\n"; // Append the final 1

    // Output the entire sequence at once
    cout << output;

    return 0;
}
