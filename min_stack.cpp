class MinStack {
private:
  stack<int> mainStack;
  stack<int> minStack;

public:
  void push(int x) {

    mainStack.push(x);

    if(minStack.empty() || x <= minStack.top()) {
      minStack.push(x);
    }

  }

  void pop() {

    if(mainStack.empty()) {
      return;
    }

    if(!minStack.empty() && mainStack.top() == minStack.top()){
      minStack.pop();
    }

    mainStack.pop();

  }

  int top() {

    if(!mainStack.empty()){
      return mainStack.top();
    }

    return -1;

  }

  int getMin() {

    if(!minStack.empty()) {
      return minStack.top();
    }

    return -1;

  }
};
