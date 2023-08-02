#include <iostream>

class Solution {
public:
    static std::string minRemoveToMakeValid(std::string s) {
        int stack = 0;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '(')
                stack++;
            else if (s[i] == ')') {
                if (stack > 0)
                    stack--;
                else
                    s[i] = '1';
            }
        }
        int index = s.size() - 1;
        while (stack > 0) {
            if (s[index] == '(') {
                s[index] = '1';
                stack--;
            }
            index--;
        }
        s.erase(remove(s.begin(), s.end(), '1'), s.end());
        return s;
    }
};

int main()
{
    std::string s = "lee(t(c)o)de)";
    std::cout << Solution::minRemoveToMakeValid(s);
}
