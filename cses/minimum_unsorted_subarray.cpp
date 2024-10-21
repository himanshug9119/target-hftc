#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum length subarray
int findMinimumSubarrayLength(vector<int> &a)
{
    int n = a.size();

    // Step 1: Find the first element out of order from the left
    int start = 0;
    while (start < n - 1 && a[start] <= a[start + 1])
    {
        start++;
    }

    // If the entire array is sorted
    if (start == n - 1)
    {
        return 0;
    }

    // Step 2: Find the first element out of order from the right
    int end = n - 1;
    while (end > 0 && a[end] >= a[end - 1])
    {
        end--;
    }

    // Step 3: Find the minimum and maximum in the subarray [start, end]
    int subarray_min = a[start];
    int subarray_max = a[start];
    for (int i = start; i <= end; i++)
    {
        if (a[i] < subarray_min)
        {
            subarray_min = a[i];
        }
        if (a[i] > subarray_max)
        {
            subarray_max = a[i];
        }
    }

    // Step 4: Expand the subarray to include any numbers greater than subarray_min to the left
    while (start > 0 && a[start - 1] > subarray_min)
    {
        start--;
    }

    // Step 5: Expand the subarray to include any numbers less than subarray_max to the right
    while (end < n - 1 && a[end + 1] < subarray_max)
    {
        end++;
    }

    // The length of the subarray is end - start + 1
    return end - start + 1;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int min_length = findMinimumSubarrayLength(a);
    cout << "Minimum length subarray to sort: " << min_length << endl;

    return 0;
}
