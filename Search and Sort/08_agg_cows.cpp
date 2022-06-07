// AGGRCOW - Aggressive cows

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.

// Example
// Input:
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9

// Output:
// 3
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        int n, c;
        cin >> n >> c;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        int l = 1, h = v[n - 1] - v[0];
        int ans = 0;

        while (l <= h)
        {
            int m = (l + h) / 2;

            int prev = v[0];
            int cnt = 1;
            for (int i = 1; i < n; i++)
            {
                if (v[i] - prev >= m)
                {
                    cnt++;
                    prev = v[i];
                }
            }

            if (cnt >= c)
            {
                l = m + 1;
                ans = m;
            }

            else
                h = m - 1;
        }
        cout << h << endl;
    }
    return 0;
}