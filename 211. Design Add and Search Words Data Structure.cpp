class Node{
public:
    Node* childs[26];
    bool valid;
    
    Node(){
        for(int i=0;i<26;i++) childs[i] = NULL;
        valid = false;
    }
};
class WordDictionary {
public:
    
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        int n = word.size();
        Node* t = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(t->childs[c-'a'] == NULL) t->childs[c-'a'] = new Node();
            t = t->childs[c-'a']; 
        }
        t->valid = true;
    }
    
    
    bool charSearch(Node* root,string& word,int idx){
        if(!root) return false;
        if(idx == word.size() && root->valid) return true;
        if(idx == word.size() && !root->valid) return false;
        char c = word[idx];
        if(c=='.'){
            bool ex = false;
            for(Node* n:root->childs) ex = ex || charSearch(n,word,idx+1);
            return ex;
        }
        else return charSearch(root->childs[c-'a'],word,idx+1);
    }
    bool search(string word) {
        return charSearch(root,word,0);
    }
};