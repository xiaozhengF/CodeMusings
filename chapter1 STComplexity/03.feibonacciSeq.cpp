#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

int feibonacci_1(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return feibonacci_1(n - 1) + feibonacci_1(n - 2);
}
int feibonacci_2(int first, int second, int n)
{
    if (n <= 0)
        return 0;
    if (n < 3)
        return 1;
    else if (n == 3)
        return first + second;
    return feibonacci_2(second, first + second, n - 1);
}

void time_consumption(){
    int n;
    while(cin>>n){
        milliseconds start_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        cout << feibonacci_2(1,1,n) << endl;
        milliseconds end_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        cout << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
    }
}
int main(){
    time_consumption();
    return 0;
}