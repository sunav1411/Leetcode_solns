struct Node {
    int len;
    int suffix;
    int prefix;
    int maxi;
    char leftChar;
    char rightChar;
};
class SegmentTree{
public:
    vector<Node> seg;
    SegmentTree (int n) {
        seg.resize(4*n);
    }
    void build(int ind, int start, int end, string& s){
        if(start==end){
            seg[ind]=createNewNode(s[start]);
            return ;
        }
        int mid=(start+end)/2;
        build(2*ind+1, start, mid, s);
        build(2*ind+2, mid+1, end, s);
        seg[ind]=merge(seg[2*ind+1], seg[2*ind+2]);
        return ;
    }
    Node query(){
        return seg[0];
    }
    void update (int ind, int start, int end, string& s, int pos){
        if(start==end){
            seg[ind]=createNewNode(s[start]);
            return ;
        }
        int mid=(start+end)/2;
        if(pos<=mid){
            update(2*ind+1, start, mid, s, pos);
        }
        else {
            update(2*ind+2, mid+1, end, s, pos);
        }
        seg[ind]=merge(seg[2*ind+1], seg[2*ind+2]);
        return ;
    }
    Node merge(Node left, Node right){
        Node node;
        node.len=left.len+right.len;
        node.maxi=max(left.maxi, right.maxi);
        node.leftChar=left.leftChar;
        node.rightChar=right.rightChar;
        node.prefix=left.prefix;
        node.suffix=right.suffix;
        if(left.rightChar==right.leftChar){
            node.maxi=max(node.maxi, left.suffix+right.prefix);
            if(left.prefix==left.len){
                node.prefix=left.prefix+right.prefix;
            }
            if(right.suffix==right.len){
                node.suffix=right.suffix+left.suffix;
            }
        }
        return node;
    }
    Node createNewNode(char ch){
        Node node;
        node.len=1;
        node.suffix=1;
        node.prefix=1;
        node.leftChar=ch;
        node.rightChar=ch;
        node.maxi=1;
        return node;
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.length();
        vector<int> ans;
        SegmentTree* segTree = new SegmentTree(n);
        segTree->build(0, 0, n-1, s);
        for(int i=0;i<queryCharacters.size();i++){
            s[queryIndices[i]]=queryCharacters[i];
            segTree->update(0, 0, n-1, s, queryIndices[i]);
            Node node = segTree->query();
            ans.push_back(node.maxi);
        }
        return ans;
    }
};