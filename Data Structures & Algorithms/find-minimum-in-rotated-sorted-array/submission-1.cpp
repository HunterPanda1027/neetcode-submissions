class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int minimum = nums[r];

        while (l <= r) {
            int middle = l + ((r - l) / 2);

            if (nums[middle] < minimum) {
                minimum = nums[middle];
                r = middle - 1;
            } else {
                l = middle + 1;
            }
        }

        return minimum;


    }
};
