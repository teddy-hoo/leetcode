class Solution {
public:
    int trap(int A[], int n) {
        int result=0;  
        int max=0;  
        for(int i=0;i<n;i++)if(A[i]>A[max])max=i;  
        for(int i=0,peak=0;i<max;++i){  
            if(A[i]>peak)peak=A[i];  
            else result+=peak-A[i];  
        }  
        for(int i=n-1,peak=0;i>max;--i){  
            if(A[i]>peak)peak=A[i];  
            else result+=peak-A[i];  
        }  
        return result; 
    }
};
