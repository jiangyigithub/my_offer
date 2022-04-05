#include <vector>
#include <iostream>
using namespace std;

vector<int> vec = { 4, 2, 5, 1, 3, 9};   
vector<int>::iterator itr = min_element(vec.begin(), vec.end()); // itr -> 1

// Note 1: Algorithm always process ranges in a half-open way: [begin, end)
sort(vec.begin(), itr);  // vec: { 2, 4, 5, 1, 3, 9}

reverse(itr, vec.end());  // vec: { 2, 4, 5, 9, 3, 1}   itr => 9


// Note 2: more than one range loop case
vector<int> vec2(3);
copy(itr, vec.end(),  // Source
     vec2.begin());   // Destination
     //vec2 needs to have at least space for 3 elements.



// Note 3:
vector<int> vec3;
copy(itr, vec.end(), back_inserter(vec3));  // Inserting instead of overwriting 
                  // back_insert_iterator      Not efficient

vec3.insert(vec3.end(), itr, vec.end());  // Efficient and safe