#include "head.hpp"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int low=1;
        int high=2;
        vector<vector<int>> res;
        while (high<target){
            long curSum=(low+high)*(high-low+1)/2;
            if(curSum<target){
                high++;
            }
            else if(curSum>target){
                low++;
            }
            else{
                vector<int> ans;
                for(int i=low;i<high+1;++i){
                    ans.push_back(i);
                }
                res.push_back(ans);
                low++;
            }
        }
        return res;

    }
};

int main(){
    vector<vector<int>> res = Solution().findContinuousSequence(9);
    for(auto e:res){
        for(auto i:e){
            cout<<i;
        }
        cout<<endl;
    }
    
}