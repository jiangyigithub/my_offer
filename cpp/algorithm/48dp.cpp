#include "head.hpp"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int i = -1, res = 0, len = s.size();
        for(int j = 0; j < len; j++) {
            if(dic.find(s[j]) != dic.end())
                i = max(i, dic.find(s[j])->second); // 更新左指针
            dic[s[j]] = j; // 哈希表记录
            res = max(res, j - i); // 更新结果
        }
        return res;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line = "abcabcbb";
 
    string s = stringToString(line);
    
    int ret = Solution().lengthOfLongestSubstring(s);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}