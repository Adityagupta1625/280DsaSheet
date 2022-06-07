// Given an array which contains integer values, we need to make all values of this array equal to some integer value with minimum cost where the cost of changing an array value x to y is abs(x-y)

// Examples : 

// Input  : arr[] = [1, 100, 101]
// Output : 100
// We can change all its values to 100 with minimum cost,
// |1 - 100| + |100 - 100| + |101 - 100| = 100

// Ternary Search
int computeCost(int arr[], int N, int X)
{
    int cost = 0;
    for (int i = 0; i < N; i++)
        cost += abs(arr[i] - X);
    return cost;
}

int minCostToMakeElementEqual(int arr[], int N)
{
    int low, high;
    low = high = arr[0];
 
    // setting limits for ternary search by
    // smallest and largest element
    for (int i = 0; i < N; i++) {
        if (low > arr[i])
            low = arr[i];
        if (high < arr[i])
            high = arr[i];
    }
 
    /* loop until difference between low and high
       become less than 3, because after that
       mid1 and mid2 will start repeating
    */
    while ((high - low) > 2) {
 
        // mid1 and mid2 are representative array
        // equal values of search space
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
 
        int cost1 = computeCost(arr, N, mid1);
        int cost2 = computeCost(arr, N, mid2);
 
        // if mid2 point gives more total cost,
        // skip third part
        if (cost1 < cost2)
            high = mid2;
 
        // if mid1 point gives more total cost,
        // skip first part
        else
            low = mid1;            
    }
 
    // computeCost gets optimum cost by sending
    // average of low and high as X
    return computeCost(arr, N, (low + high) / 2);
}

// Maths approach
int minCostToMakeElementEqual(int a[], int n)
{
 
    // If there are odd elements, we choose
    // middle element
    int y;
    if (n % 2 == 1)
        y = a[n / 2];
 
    // If there are even elements, then we choose
    // the average of middle two.
    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;
 
    // After deciding the final value, find the
    // result.
    int s = 0;
    for(int i = 0; i < n; i++)
        s += abs(a[i] - y);
         
    return s;
}