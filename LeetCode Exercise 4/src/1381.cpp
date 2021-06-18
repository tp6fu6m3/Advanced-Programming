class CustomStack {
public:
    vector<int> myStack;
    int size;
    
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(myStack.size() < size){
            myStack.push_back(x);
        }
    }
    
    int pop() {
        if(myStack.empty()){
            return -1;
        }
        else{
            int top = myStack.back();
            myStack.pop_back();
            return top;
        }
    }
    
    void increment(int k, int val) {
        if(k > myStack.size()){
            k = myStack.size();
        }
        for(int i=0;i<k;i++){
            myStack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */