// Bucket
struct Bucket {
    int min;
    int max;
    Bucket() : min(-1), max(-1) {}
};

class Solution {
private:
	void getMinAndMax(vector<int> num, int &min, int &max){
		int len = num.size();
		
		if(len <= 0){
			return;
		}

		min = num[0];
		max = num[0];

		for(int i = 1; i < len; i++){
			max = max < num[i] ? num[i] : max;
			min = min < num[i] ? min : num[i];
		}

	}
	vector<Bucket *> genBuckets(int size){
		vector<Bucket *> buckets;
		for(int i = 0; i < size; i++){
			Bucket *b = new Bucket();
			buckets.push_back(b);
		}
		return buckets;
	}
public:
    int maximumGap(vector<int> &num) {
        
        int len = num.size();
        if(len < 2){
        	return 0;
        }

        int min = num[0];
        int max = num[0];

        getMinAndMax(num, min, max);

        int bucketNum = max - min + 1 > len ? len : max - min + 1;
        vector<Bucket *> buckets = genBuckets(bucketNum + 1);
        int bucketSize = (max - min + 1) / bucketNum + 1;

        for(int i = 0; i < len; i++){
        	int b = (num[i] - min) / bucketSize;
        	if(buckets[b]->min == -1 || buckets[b]->min > num[i]){
        		buckets[b]->min = num[i];
        	}
        	if(buckets[b]->max == -1 || buckets[b]->max < num[i]){
        		buckets[b]->max = num[i];
        	}
        }

        int gap = 0;
        int begin = 0;
        for(int i = 1; i < buckets.size(); i++){
        	if(buckets[i]->min != -1){
        		int g = buckets[i]->min - buckets[begin]->max;
        		gap = g > gap ? g : gap;
        		begin = i;
        	}
        }

        return gap;
    }
};
