#include "head.hpp"
class Solution {
public:
    int movingCount(int m, int n, int k) {
        return 0;
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().movingCount(m, n, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}