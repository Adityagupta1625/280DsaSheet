#include <bits/stdc++.h>
using namespace std;
// O(n) Solution:

int ceilSearch(int arr[], int low, int high, int x)
{
    if (x <= arr[low])
        return low;
    for (int i = low; i < high; i++)
    {
        if (arr[i] == x)
            return i;

        if (arr[i] < x && arr[i + 1] >= x)
            return i + 1;
    }
    return -1;
}

// O(logn) Solution:
int ceilSearch(int arr[], int low, int high, int x)
{
    if (x <= arr[low])
        return low;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int index = ceilSearch(arr, 0, n - 1, x);
    if (index == -1)
        cout << "Ceiling of " << x << " doesn't exist in array ";
    else
        cout << "ceiling of " << x << " is " << arr[index];

    return 0;
}
