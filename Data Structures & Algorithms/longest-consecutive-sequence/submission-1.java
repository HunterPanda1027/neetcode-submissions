class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        Set<Integer> numbers = new HashSet<>();
        int max = 1;

        for (int num: nums) {
            numbers.add(num);
        }       

        for (int curr: numbers) {
            int current = 1;
            if (numbers.contains(curr - 1)) continue;
            while(numbers.contains(curr + current)) {
                current++;
            }
            if (current > max) {
                max = current;
            }
        }
        return max;
    }
}
