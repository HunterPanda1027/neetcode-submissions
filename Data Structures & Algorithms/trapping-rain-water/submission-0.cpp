class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        std::vector<int> prefix(n);
        std::vector<int> suffix(n);

        // 1. Build prefix max array (left to right)
        int premax = 0;
        for (int i = 0; i < n; i++) {
            premax = std::max(premax, height[i]);
            prefix[i] = premax;
        }

        // 2. Build suffix max array (right to left)
        int sufmax = 0;
        for (int i = n - 1; i >= 0; i--) {
            sufmax = std::max(sufmax, height[i]);
            suffix[i] = sufmax;
        }

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += min(prefix[i], suffix[i]) - height[i];
        }

        return res;
    }
};
