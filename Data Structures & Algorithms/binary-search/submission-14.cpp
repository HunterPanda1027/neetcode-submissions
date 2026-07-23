class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (nums[middle] == target) {
                return middle; // Target found
            } else if (nums[middle] < target) {
                low = middle + 1; // Target must be in the right half
            } else {
                high = middle - 1; // Target must be in the left half
            }
        }

        return -1; // Target not found
    }
};
