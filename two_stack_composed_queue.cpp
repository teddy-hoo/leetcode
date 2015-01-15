class MyQueue{
private:
	stack<int> popStack;
	stack<int> pushStack;
	int size;
public:

	MyQueue(){
		size = 0;
	}
	
	int size(){
		return size;
	}

	int front(){
		return size > 0 ? popStack.top() : -1;
	}

	void pop(){
		if(size > 0){
			popStack.pop();
			stack<int> tmp;
			while(pushStack.size() > 0){
				tmp.push(pushStack.top());
				pushStack.pop();
			}
			tmp.pop();
			while(tmp.size() > 0){
				pushStack.push(tmp.top());
				tmp.pop();
			}
		}
	}

	void push(int value){
		pushStack.push(value);
		stack<int> tmp;
		while(popStack.size() > 0){
			tmp.push(popStack.top());
			popStack.pop();
		}
		tmp.push(value);
		while(tmp.size() > 0){
			popStack.push(tmp.top());
			tmp.pop();
		}
	}

}