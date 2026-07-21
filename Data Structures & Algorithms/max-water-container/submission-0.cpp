class Solution {
public:
    int maxArea(vector<int>& heights) {
        int length = heights.size() - 1;
        int left = 0;
        int right = length;
        int max = 0;

        while (left != right) {
            int curr = std::min(heights[left], heights[right]) * length;
            if(curr > max) {
                max = curr;
            } else {
                if (heights[left] >= heights[right]) {
                    right--;
                } else {
                    left++;
                }
                length--;
            }
        }

        return max;
    }
};
