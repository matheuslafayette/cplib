struct TrieNode {
    int count;
    bool isEnd;
    TrieNode* children[26];

    TrieNode(){
        count = 0;
        isEnd = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};
struct TrieNode {
    int count;
    bool isEnd;
    TrieNode* children[26];

    TrieNode(){
        count = 0;
        isEnd = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(const string& word){
        TrieNode* cur = root;
        for(char c:word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
            cur->count++;
        }
        cur->isEnd = true;
    }

    int search(const string &word){
        TrieNode* cur = root;
        for(char c:word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->count;
    }
};
class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(const string& word){
        TrieNode* cur = root;
        for(char c:word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
            cur->count++;
        }
        cur->isEnd = true;
    }

    int search(const string &word){
        TrieNode* cur = root;
        for(char c:word){
            int idx = c - 'a';
            if(!cur->children[idx]){
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->count;
    }
};