#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& tails, int left, int right, int key) {
    while (right > left + 1) {
        int mid = left + (right - left) / 2;
        if (tails[mid] >= key) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int longestIncreasingSubsequence(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> tails;
    tails.push_back(nums[0]);

    for (int i = 1; i < n; ++i) {
        if (nums[i] < tails[0]) {
            tails[0] = nums[i];
        } else if (nums[i] > tails.back()) {
            tails.push_back(nums[i]);
        } else {
            int pos = binarySearch(tails, -1, tails.size() - 1, nums[i]);
            tails[pos] = nums[i];
        }
    }

    return tails.size();
}

int main() {
    std::vector<int> nums = {2, 6, 3, 4, 1, 2, 9, 5, 8};
    int result = longestIncreasingSubsequence(nums);
    std::cout << "Longest increasing subsequence length: " << result << std::endl;
    return 0;
}

