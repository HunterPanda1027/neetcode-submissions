class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int stuff : nums) {
            freq.put(stuff, freq.getOrDefault(stuff, 0) + 1);
        }
        int divider = nums.length; 
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            int key = -1;
            int max = -1;
            for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
                if (entry.getValue() > max) {
                    max = entry.getValue();
                    key = entry.getKey();
                }
            }
            res[i] = key;
            freq.remove(key);
        }
        return res;
    }
}
