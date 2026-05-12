class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<Integer> stack = new ArrayDeque<>();
        int[] res = new int[temperatures.length];
        for(int i = 0; i < temperatures.length; i++) {
            int x = temperatures[i];
            while (!stack.isEmpty() && x > temperatures[stack.peek()]) {
                int indice = stack.pop();
                res[indice] = i - indice;
            }
            stack.push(i);

        }
        return res;
    }
}
