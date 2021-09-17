#include "head.hpp"
class Solution {
private:
vector<vector<int>> res;

void backtrack(vector<int>& nums, vector<int>& paths){
    if(paths.size()==nums.size()){
        res.push_back(paths);
        return;
    }
    
    for(int i =0;i<nums.size();i++){
        if(paths.find(nums[i]) != std::string::npos) continue;
        paths.push_back(nums[i]);
        backtrack(nums,paths);
        paths.pop_back();
    }
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> paths;
        backtrack(nums,paths);
        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line = "[1,2,3]";
    vector<int> nums = stringToIntegerVector(line);
    vector<vector<int>> rets = Solution().permute(nums);
    for(auto ret:rets)
    {
    string out = integerVectorToString(ret);
    cout << out << endl;
    }
    return 0;
}


