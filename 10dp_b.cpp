#include "head.hpp"
int fib(int n){
    int ret[2]={0,1};
    if(n<2) return ret[n];
    int sum = 0;
    int cur =1;
    int pre =0;
    for(int i=2;i<=n;i++){
        sum = cur + pre;
        pre = cur;
        cur = sum;
    }
    return sum;
}

int main(){
    int result = fib(5);
    cout<<"fib(5): "<<result<<endl;
}