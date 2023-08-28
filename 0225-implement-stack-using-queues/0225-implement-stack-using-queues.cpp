class MyStack {
public:
    queue<int>Q1, Q2;
    int top_elem=-1;
    MyStack() {
    }
    
    void push(int x) {
        Q1.push(x);
        top_elem=x;
    }
    
    int pop() {
        while(Q1.size()>1){
            int front = Q1.front(); Q1.pop();
            Q2.push(front);
            top_elem = front;
        }
        int num = Q1.front();
        Q1.pop();
        
        while(!Q2.empty()){
            int front = Q2.front(); Q2.pop();
            Q1.push(front);
        }

        return num;
    }
    
    int top() {
        return top_elem;   
    }
    
    bool empty() {
        if(Q1.size()==0 and Q2.size()==0)return true;
        return false;
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