class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
            return std::tolower(c);
        });

        s.erase(
            std::remove_if(s.begin(), s.end(), [](unsigned char c) {
                return !std::isalnum(c);
            }),
            s.end()
        );

        for (int i = 0; i < s.length()/2; i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
