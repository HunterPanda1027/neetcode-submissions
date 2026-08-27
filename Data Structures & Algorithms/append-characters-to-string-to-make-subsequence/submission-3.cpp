class Solution {
public:
    int appendCharacters(string s, string t) {
        int pt1 = 0; 
        int pt2 = 0;

        while (pt1 < s.size() && pt2 < t.size()) {
            if (s[pt1] == t[pt2]) {
                pt2++;
            }
            pt1++;
        }

        return t.size() - pt2;
    }
};