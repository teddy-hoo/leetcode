class Solution {
private:
	void updatePath(vector<string> &pathes, string path, int begin, int end){
		
		if(end < begin){
			return;
		}

		string newPath = path.substr(begin, end - begin + 1);
		if(newPath == ".."){
			if(pathes.size() > 1){
				pathes.pop_back();
			}
		}
		else if(newPath != "." && newPath.size() > 0){
			pathes.push_back(newPath);
		}

	}
	string pathToString(vector<string> pathes){
		string result = pathes[0];

		for(int i = 1; i < pathes.size(); i++){
			result += pathes[i];
			result += "/";
		}

		return result.size() > 1 ? result.substr(0, result.size() - 1) : result;
	}
public:
    string simplifyPath(string path) {
        
        vector<string> pathes;
        string result;
        int len = path.size();

        if(len <= 0){
        	return result;
        }

        int begin = 0;
        int end = 0;
        int i;
        pathes.push_back("/");
        for(i = 0; i < len; i++){
        	if(path[i] == '/'){
        		end = i - 1;
        		updatePath(pathes, path, begin, end);
        		begin = i + 1;
        	}
        }

        updatePath(pathes, path, begin, i - 1);

        result = pathToString(pathes);
        return result;

    }
};