/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
        	return NULL;
        }

        map<UndirectedGraphNode*, UndirectedGraphNode*> created;
        queue<UndirectedGraphNode*> q;
        
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        vector<UndirectedGraphNode*> neighbors(node->neighbors.size());
        newNode->neighbors = neighbors;
        created[node] = newNode;

        q.push(node);
        while(!q.empty()){
        	UndirectedGraphNode* cur = q.front();
        	q.pop();

        	for(int i = 0; i < cur->neighbors.size(); i++){
        		UndirectedGraphNode *neighbor = cur->neighbors[i];
        		if(created.find(neighbor) == created.end()){
        			UndirectedGraphNode *newCur = new UndirectedGraphNode(neighbor->label);
        			vector<UndirectedGraphNode*> neighbors(neighbor->neighbors.size());
        			newCur->neighbors = neighbors;
        			created[neighbor] = newCur;
        			created[cur]->neighbors[i] = newCur;
        			q.push(neighbor);
        		}
        		else{
        			created[cur]->neighbors[i] = created[neighbor];
        		}
        	}
        }

        return newNode;
    }
};