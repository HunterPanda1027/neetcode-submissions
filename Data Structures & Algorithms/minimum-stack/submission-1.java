class MinStack {

    Deque<Integer> stack;
    Deque<Integer> min;

    public MinStack() {
        stack = new ArrayDeque<>();
        min = new ArrayDeque<>();
    }
    
    public void push(int val) {
        if(min.peek() == null || val <= min.peek()) {
            min.push(val);
        }
        stack.push(val);
    }
    
    public void pop() {
        int res = stack.pop();
        if (res == min.peek()){
            min.pop();
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return min.peek();
    }
}
