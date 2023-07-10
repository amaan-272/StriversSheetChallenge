//CodeStudio Code
unordered_map<graphNode*, graphNode*> nodes;

graphNode* dfs(graphNode* node) {
    if(nodes.find(node) != end(nodes)) return nodes[node];
    graphNode* clone = new graphNode(node->data);
    nodes[node] = clone; 
    for(auto i:node->neighbours) clone->neighbours.push_back(dfs(i));
    return clone;
}

graphNode *cloneGraph(graphNode *node) {
    if(!node) return NULL;
    return dfs(node);    
}

//LeetCode Code
class Solution {
public:
    unordered_map<Node*, Node*> store;
   
    Node* dfs(Node* node) {
        if(store.count(node)) return store[node];
        Node* clone = new Node(node->val);
        store[node] = clone; 
        for(Node* i:node->neighbors) clone->neighbors.push_back(dfs(i));
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return dfs(node);    
    }
};
