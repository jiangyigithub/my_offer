#include "head.hpp"

int fib(int n);


int main(){
    int n = 5;
    fib(n);
}

int fib(int n){
    static int t = 0;
    t++;
    cout<<"n ="<<n<<"; time = "<<t<<endl;
    if(n==0) return 0;
    else if(n==1) return 1;
    else  return fib(n-1)+fib(n-2);
}