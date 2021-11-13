#include "head.hpp"

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> res ;
//         for(int i = 0;i<nums.size()-1;i++){
//             for(int j = i+1;j< nums.size();j++){
//                 if(nums[j]==(target - nums[i])){
//                     res.push_back(nums[i]);
//                     res.push_back(nums[j]);
//                     return res;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int pre =0, inv = nums.size()-1;
        while(pre<inv){
            if(nums[pre]+nums[inv]>target){inv--;}
            else if(nums[pre]+nums[inv]<target){pre++;}
            else if(nums[pre] + nums[inv] == target){return {nums[pre],nums[inv]};}
        }
        return {};
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line = "[2,7,11,15]";
        vector<int> nums = stringToIntegerVector(line);
        line = "9";
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    
    return 0;
}