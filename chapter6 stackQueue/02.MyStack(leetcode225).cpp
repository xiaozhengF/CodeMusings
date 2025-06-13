#include <queue>
using namespace std;
class MyStack {
public:
    queue<int> Que1;
    queue<int> Que2;
    MyStack() {
        
    }
    
    void push(int x) {
        Que1.push(x);
    }
    
    int pop() {
        if(!empty()){
            while(Que1.size()>1){
                Que2.push(Que1.front());
                Que1.pop();
            }
        }
        int res = Que1.front();
        Que1.pop();
        while(Que2.size()){
                Que1.push(Que2.front());
                Que2.pop();
        }
        return res;
    }
    
    int top() {
        return Que1.back();
    }
    
    bool empty() {
        return Que1.empty();
    }

};
class MyStack2 {
public:
    queue<int> Que;
    MyStack2() {
        
    }
    
    void push(int x) {
        Que.push(x);
    }
    
    int pop() {
        int topVal = this->top();
        int size = Que.size();
        size--;
        while(size--){
            Que.push(Que.front());
            Que.pop();
        }
        Que.pop();
        return topVal;
    }
    
    int top() {
        return Que.back();
    }
    
    bool empty() {
        return Que.empty();
    }
    
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */