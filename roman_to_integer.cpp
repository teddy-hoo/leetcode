class Solution {
public:
	int c2n(char c) {  
      	switch(c) {  
        	case 'I': return 1;  
        	case 'V': return 5;  
        	case 'X': return 10;  
        	case 'L': return 50;  
        	case 'C': return 100;  
        	case 'D': return 500;  
        	case 'M': return 1000;  
        	default: return 0;  
      	}  
    }  
    int romanToInt(string s) {
      	int result = 0;
      	int pre = 0;
      	int aft = 0;
      	for(int i = 0; i < s.size(); i++)  
      	{
      		if(i > 0){
      			pre = c2n(s[i]);
      			aft = c2n(s[i - 1]);
      		}
        	if(pre > aft)  
        	{  
          		result += (pre - 2 * aft);
        	}  
        	else  
        	{  
          		result += pre;
        	}  
      	}
      	return result;
    }  
};