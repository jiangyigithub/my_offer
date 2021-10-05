#include "head.hpp"

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp);
    }

private:
    int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp)
    {
        // end
        if (l >= r)
            return 0;
        // recur
        int m = (l + r) / 2;
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
        // merge
        int i = l, j = m + 1;
        for (int k = l; k <= r; k++)
        {
            tmp[k] = nums[k];
        }
        for (int k = l; k <= r; k++)
        {
            // 左子数组已合并完
            if (i == m + 1)
            {
                nums[k] = tmp[j];
                j++;
            }
            // 右子数组已合并完
            else if (j == r + 1)
            {
                nums[k] = tmp[i];
                i++;
            }
            else if (tmp[i] <= tmp[j])
            {
                nums[k] = tmp[i];
                i++;
            }
            else if (tmp[i] > tmp[j])
            {
                nums[k] = tmp[j];
                j++;
                res += (m - i + 1); //reverse pair
            }
            else
            {
                /** do nothing **/
            }
        }
        return res;
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

int main()
{
    string line = "[7,3,2,6]";
    // string line = "[7,3,2,6,0,1,5,4]";

    vector<int> nums = stringToIntegerVector(line);

    int ret = Solution().reversePairs(nums);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}