class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowPtr = nums[0];
        int fastPtr = nums[nums[0]];

        while(slowPtr != fastPtr) {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        }

        int extraPtr = 0;

        while(slowPtr != extraPtr) {
            slowPtr = nums[slowPtr];
            extraPtr = nums[extraPtr];
        }

        return slowPtr;
    }
};
