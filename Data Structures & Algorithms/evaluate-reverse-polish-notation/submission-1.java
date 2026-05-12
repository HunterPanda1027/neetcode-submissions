class Solution {
    public int evalRPN(String[] tokens) {

        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < tokens.length; i++) {
            String x = tokens[i];
            if (x.equals("+")) {
                stack.push(stack.pop() + stack.pop());
            } else if (x.equals("*")) {
                stack.push(stack.pop() * stack.pop());
            } else if (x.equals("-")) {
                int last = stack.pop();
                int first = stack.pop();
                stack.push(first - last);
            } else if (x.equals("/")) {
                int last = stack.pop();
                int first = stack.pop();
                stack.push(first / last);
            } else {
                stack.push(Integer.parseInt(x));
            }
        }
    return stack.pop();
    }
}
