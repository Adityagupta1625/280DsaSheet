// Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:

// Each student gets one packet.
// The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
// Examples:

// Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3
// Output: Minimum Difference is 2
// Explanation:
// We have seven packets of chocolates and
// we need to pick three packets for 3 students
// If we pick 2, 3 and 4, we get the minimum
// difference between maximum and minimum packet
// sizes.

// Brute Force:
// A simple solution is to generate all subsets of size m of arr[0..n-1]. For every subset, find the difference between the maximum and minimum elements in it. Finally, return the minimum difference.

// Optimised Solution:

#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // code
    if (m == 0 || n == 0)
    {

        return 0;
    }
    if (n < m)
    {

        return -1;
    }
    sort(a.begin(), a.end());
    long long int min_diff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++)
    {
        long long int diff = a[i + m - 1] - a[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}