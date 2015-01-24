class Solution {
private:
	void swap(int &a, int &b){
		int tmp = a;
		a = b;
		b = tmp;
	}
public:
    void sortColors(int A[], int n) {

    	int zero = 0;
    	int two = n - 1;
    	int cursor = 0;

    	while(cursor <= two){
    		if(A[cursor] == 0){
    			swap(A[cursor], A[zero]);
    			zero++;
    			cursor++;
    		}
    		else if(A[cursor] == 2){
    			swap(A[cursor], A[two]);
    			two--;
    		}
    		else{
    		    cursor++;
    		}
    	}
        
    }
};
