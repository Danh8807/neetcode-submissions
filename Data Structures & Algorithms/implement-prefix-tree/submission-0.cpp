class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord = false;
};
class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *cur = root;
        for(char c: word){
            if(cur -> children.find(c) == cur->children.end()){
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        Node *cur = root;
        for(char c: word){
            if(cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for(char c: prefix){
            if(cur->children.find(c) == cur->children.end()){
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
