class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> brackets = new HashMap<>(Map.of('(', ')', '[',']','{','}'));
        Deque<Character> stack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);
            if (brackets.containsKey(curr)) {
                stack.push(curr);
            } else if (stack.isEmpty()){
                return false;
            } else {
                if (brackets.get(stack.pop()) != curr) return false;
            }
        }
        if (stack.isEmpty()) {
            return true;
        } else {
            return false;
        }
    }
}
