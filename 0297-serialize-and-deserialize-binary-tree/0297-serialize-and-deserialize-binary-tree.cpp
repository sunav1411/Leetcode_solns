/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
string serialize(TreeNode* root){
    if(root==NULL) return "";

    string data="";
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();

        if(node==NULL){
            data+="NULL,";
            continue;
        }

        data+=to_string(node->val)+",";
        q.push(node->left);
        q.push(node->right);
    }
    return data;
}

TreeNode* deserialize(string data){
    if(data.empty()) return NULL;

    vector<string> value;
    string curr="";
    stringstream ss(data);

    while(getline(ss,curr,','))
        value.push_back(curr);

    if(value[0]=="NULL") return NULL;

    TreeNode* root=new TreeNode(stoi(value[0]));
    queue<TreeNode*> q;
    q.push(root);

    int index=1;

    while(!q.empty()&&index<value.size()){
        TreeNode* node=q.front();
        q.pop();

        if(index<value.size()&&value[index]!="NULL"&&!value[index].empty()){
            node->left=new TreeNode(stoi(value[index]));
            q.push(node->left);
        }
        index++;

        if(index<value.size()&&value[index]!="NULL"&&!value[index].empty()){
            node->right=new TreeNode(stoi(value[index]));
            q.push(node->right);
        }
        index++;
    }
    return root;
}
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));