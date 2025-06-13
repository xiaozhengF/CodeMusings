#include <cstdio>
#include <iostream>
using namespace std;
// 时间复杂度为O(n)
int function(int x,int n){
    int result = 1;
    for(int i = 0;i<n;i++){
        result*=x;
    }
    return result;
}
// 时间复杂度为O(n)
int function2(int x,int n){
    if(n==0){
        return 1;
    }else return function2(x,n-1)*x;
}
// 时间复杂度为O(logn)
int function3(int x,int n){
    if(n==0) return 1;
    int t = function3(x,n/2);
    if(n%2==1) return t*t*x;
    return t*t;
}
int main(){
    int x;
    int n;
    cin >> x >> n;
    cout << "Result by function: " << function(x,n) << endl;
    cout << "Result by function2: " << function2(x,n) << endl;
    cout << "Result by function3: " << function3(x,n) << endl;
    return 0;

}