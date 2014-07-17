int longestConsecutive(vector<int> &num) {
  unordered_map<int, int> hashmap;
  for(int i =0; i < num.size(); i++){
    hashmap[num[i]] = i;
  }
  vector<int> visited(num.size(), 0);
  int maxV = INT_MIN;
  for(int i = 0; i < num.size(); i++){
    if(visited[i] == 1){
      continue;
    }
    visited[i] = 1;
    int len = 1;
    int index = num[i] - 1;
    while(hashmap.find(index) != hashmap.end()){
      visited[hashmap[index]] = 1;
      index--;
      len++;
    }
    index = num[i] + 1;
    while(hashmap.find(index) != hashmap.end()){
      visited[hashmap[index]] = 1;
      index++;
      len++;
    }
    if(len > maxV)
      maxV = len;
  }
  return maxV;
}
