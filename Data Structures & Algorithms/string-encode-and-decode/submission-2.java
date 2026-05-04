class Solution {

    public String encode(List<String> strs) {
        StringBuilder str = new StringBuilder();
        for (String word: strs) {
            char temp = (char) word.length();
            str.append(temp);
            str.append(word);
        }
        return str.toString();
    }

    public List<String> decode(String str) {
        int i = 0;
        List<String> res = new ArrayList<>();
        
        while (i < str.length()) {
            int len = str.charAt(i);
            res.add(str.substring(i+1, i+len+1));
            i = i + len + 1;
        }
        return res;
    }
}
