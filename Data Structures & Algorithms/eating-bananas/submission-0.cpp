class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper = std::ranges::max(piles);
        int lower = 1;
        int ans = upper;

        while (upper >= lower) {
            int k = lower + (upper - lower) / 2;
            int sum = 0;
            for (int num : piles) {
                sum += (num + k - 1) / k;
            }
             if (sum > h) {
                lower = k+1;
            } else {
                upper = k-1;
                ans = k;
            }
        }
        return ans;
    }
};
