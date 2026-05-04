class Solution {
    public int[] productExceptSelf(int[] nums) {
        int zero = 0;
        int index = -1;
        int product = 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                zero++;
                index = i;
            } else {
                product *= nums[i];
            }
        }

        int[] res = new int[nums.length];
        for (int j = 0; j < nums.length; j++) {
            if (zero > 1) {
                res[j] = 0;
            } else if (zero == 1) {
                if (j == index) {
                    res[j] = product;
                } else {
                    res[j] = 0;
                }
            } else {
                res[j] = product / nums[j];
            }
        }
        return res;
    }
}  
