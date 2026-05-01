class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        HashMap<Character, Integer> res = new HashMap<>();
        for (int i = 0; i < s.length(); i++){
            res.put(s.charAt(i), res.getOrDefault(s.charAt(i),0) + 1);
            res.put(t.charAt(i), res.getOrDefault(t.charAt(i),0) - 1);
        }
        Set<Integer> x = new HashSet<>(res.values());
        return x.size() == 1;
    }
}
