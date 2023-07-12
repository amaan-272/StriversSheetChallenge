//CodeStudio Code
string serializeTree(TreeNode<int> *root) {
    if(!root) return "#";
    return to_string(root->data)+","+serializeTree(root->left)+serializeTree(root->right);
}

TreeNode<int>* solve(string &serialized, int &index) {
    if(index>=serialized.length() || serialized[index] == '#') {
        index++;
        return NULL;
    }
    int num {};
    while(isdigit(serialized[index])) num = (num*10)+(serialized[index++]-'0');
    TreeNode<int>* root = new TreeNode<int>(num);
    index++;
    root->left = solve(serialized, index);
    root->right = solve(serialized, index);
    return root;
}

TreeNode<int>* deserializeTree(string &serialized) {
    int index {};
    return solve(serialized, index);
}

//LeetCode Code
class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

    void serialize(TreeNode* root, ostringstream& out) {
        if(root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } 
        else out << "# ";
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if(val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
