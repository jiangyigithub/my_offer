# include <vector>
using namespace std;

vector<int> vec;
vec.push_back(4);
vec.push_back(1);
vec.push_back(8);

vector<int>::iterator itr1 = vec.begin();
vector<int>::iterator itr2 = vec.end();

for(vector<int>::iterator itr = itr1;itr!=itr2;++itr)
    cout<<*itr<<" ";
sort(itr1,itr2)