class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<Map, ArrayList<String>> groups = new HashMap<>(); 
        for (String word : strs) {
            Map<Character, Integer> letters = new HashMap<>(); 
            for (int i = 0; i < word.length(); i++){
                letters.put(word.charAt(i), letters.getOrDefault(word.charAt(i), 0) + 1);
            }
            if (groups.containsKey(letters)) {
                groups.get(letters).add(word);
            } else {
                groups.put(letters, new ArrayList<>(List.of(word)));
            }
        }
        return new ArrayList<>(groups.values());
    }
}
