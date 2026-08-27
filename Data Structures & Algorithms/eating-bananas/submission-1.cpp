class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = std::ranges::max(piles);
        int l = 1;
        int res = r;
        
        while (l <= r) {
            int k = l + (r - l)/2;
            int sum = 0;
            for (int num : piles) {
                sum += (num + k - 1)/k;
            }

            if (sum <= h ) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
