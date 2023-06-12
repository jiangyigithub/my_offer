#include "head.hpp"
#include "PrintUtil.hpp"

class MinStack
{
public:
    stack<int> A, B;
    MinStack() {}
    void push(int x)
    {
        A.push(x);
        if (B.empty() || B.top() >= x)
            B.push(x);
    }
    void pop()
    {
        if (A.top() == B.top())
            B.pop();
        A.pop();
    }
    int top()
    {
        return A.top();
    }
    int min()
    {
        return B.top();
    }
};

int main()
{
    MinStack *minStack = new MinStack();
    vector<int> res;
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    res.push_back(minStack->min());
    minStack->pop();
    res.push_back(minStack->top());
    res.push_back(minStack->min());
    PrintUtil::printVector(res);
}