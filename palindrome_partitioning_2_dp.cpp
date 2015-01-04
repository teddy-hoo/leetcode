class Solution {
public:
    int minCut(string s) {
        
        int len = s.size();
        
        if(len <= 0){
            return 0;
        }

        bool mp[len][len];
        vector<int>res(s.size(),0);

        for (int i=len-1;i>=0;i--){
            for (int j=i;j<len;j++){
                if ((s[i]==s[j]) && (j-i<2 || mp[i+1][j-1])){
                    mp[i][j]=true;
                }else{
                    mp[i][j]=false;
                }
            }
        }

        for (int i=0;i<s.size();i++){
            if (mp[0][i] == true){
                res[i]=0;
            }else{  
                int ms = s.size();
                for (int j=0; j<i; j++){
                    if (mp[j+1][i] && ms>res[j]+1 ) {
                        ms=res[j]+1;
                    } 
                }
                res[i]=ms;
            }
        }

        return res[len - 1];
    }
};
