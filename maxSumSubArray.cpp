#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarrayOfSizeK(const vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) return 0; // or handle as needed

    long long windowSum = 0;
    for (int i = 0; i < k; ++i)
        windowSum += nums[i];

    long long maxSum = windowSum;

    for (int end = k; end < n; ++end) {
        windowSum += nums[end];         // add new element
        windowSum -= nums[end - k];     // remove old element
        maxSum = max(maxSum, windowSum);
    }
    return (int)maxSum;
}
