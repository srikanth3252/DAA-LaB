#include <stdio.h>
#include <limits.h>


struct Subarray {
    int left, right, sum;
};


struct Subarray findMaxCrossingSubarray(int arr[], int low, int mid, int high) {
    int left_sum = INT_MIN, sum = 0, max_left = mid;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid + 1;
    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    struct Subarray result = {max_left, max_right, left_sum + right_sum};
    return result;
}

struct Subarray findMaximumSubarray(int arr[], int low, int high) {
    if (low == high) {  
        struct Subarray base = {low, high, arr[low]};
        return base;
    }

    int mid = (low + high) / 2;
    struct Subarray left = findMaximumSubarray(arr, low, mid);
    struct Subarray right = findMaximumSubarray(arr, mid + 1, high);
    struct Subarray cross = findMaxCrossingSubarray(arr, low, mid, high);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
    	printf("Enter array elements: ");
        scanf("%d", &arr[i]);
    }
    struct Subarray result = findMaximumSubarray(arr, 0, n - 1);

    printf("Maximum subarray found from index %d to %d with sum = %d\n",
           result.left, result.right, result.sum);

    return 0;
}