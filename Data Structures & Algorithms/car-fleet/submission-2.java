class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        Deque<Double> stack = new ArrayDeque<>();
        Map<Integer, Integer> pairs = new HashMap<>();

        for (int i = 0; i < position.length; i++) {
            pairs.put(position[i], speed[i]);
        }

        Arrays.sort(position);

        for (int i = position.length - 1; i >= 0; i--) {
            double eta = ((double) target - position[i]) / pairs.get(position[i]);
            if (stack.isEmpty() || eta > stack.peek()) {
                stack.push(eta);
            }
        }
        return stack.size();
    }
}
