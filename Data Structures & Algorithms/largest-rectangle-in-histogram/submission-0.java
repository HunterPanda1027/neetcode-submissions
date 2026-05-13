class Solution {
    public int largestRectangleArea(int[] heights) {
        Deque<Integer> stack = new ArrayDeque<>();
        int[] left = new int[heights.length];
        int[] right = new int[heights.length];

        for (int i = 0; i < heights.length; i++) {
            left[i] = -1;
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                left[i] = stack.peek();
            }
            stack.push(i);
        }
        
        stack.clear();
        for (int i = heights.length - 1; i >= 0; i--) {
            right[i] = heights.length;
            while(!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                right[i] = stack.peek();
            }
            stack.push(i);
        }

    int max = 0;
    for (int i =0; i < heights.length; i++){
        left[i] += 1;
        right[i] -= 1;
        max = Math.max(max, heights[i] * (right[i] - left[i] + 1));
    }
    return max;

    }
}
