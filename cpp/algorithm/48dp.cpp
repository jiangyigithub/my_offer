#include "head.hpp"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> dic;
        int i = -1, res = 0, len = s.size();
        for (int j = 0; j < len; j++)
        {   
            // 什么时候更新左指针
            if (dic.find(s[j]) != dic.end())
                i = max(i, dic.find(s[j])->second); // 更新左指针
            dic[s[j]] = j;                          // 哈希表记录
            // j-i 为不含重复字符串的首尾指针
            res = max(res, j - i);                  // 更新结果
        }
        return res;
    }
};

int main()
{
    string line = "abcabcbb";

    int ret = Solution().lengthOfLongestSubstring(line);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}