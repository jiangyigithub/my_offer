#include "head.hpp"

class Solution
{
public:
    /// priority queue
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty())
            return {};
        priority_queue<pair<int, int>> q; // 优先级队列，默认最大值在堆顶
        for (int i = 0; i < k; ++i)
        {
            q.emplace(nums[i], i);
        }
        vector<int> res = {q.top().first};
        for (int i = k; i < nums.size(); ++i)
        {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
    
    /// monotone deque
    vector<int> maxSlidingWindow(vector<int> &nums, int k, string sol)
    {   
        /// sol=="deque"
        if (nums.empty())
            return {}; // 判空
        deque<int> q; // 双向队列
        // 将第一个滑动窗口中的单调队列对应的坐标构建出来
        // q 中存单调队列中对应的nums坐标
        // 若新元素比 q 结尾坐标的元素值大
        // 从 q 结尾开始移除坐标 （始终保持最大值在头）
        // 否则将新元素的坐标进入队列
        for (int i = 0; i < k; ++i)
        {
            while (!q.empty() && nums[i] > nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans = {nums[q.front()]}; // 存滑动窗口的最大值
        // 滑动窗口右移，继续将新元素与 q 结尾的坐标比较
        for (int i = k; i < nums.size(); ++i)
        {
            while (!q.empty() && nums[i] > nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k)      // 若 q 头坐标在滑动窗口左边界外侧
                q.pop_front();              // 移除 q 头坐标
            ans.push_back(nums[q.front()]); // q 的头坐标的值即滑动窗口的最大值压入vector
        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line = "[1,3,-1,-3,5,3,6,7]";
    vector<int> nums = stringToIntegerVector(line);

    int k = 3;

    // vector<int> ret = Solution().maxSlidingWindow(nums, k);
    vector<int> ret = Solution().maxSlidingWindow(nums, k, "deque");

    string out = integerVectorToString(ret);
    cout << out << endl;

    return 0;
}