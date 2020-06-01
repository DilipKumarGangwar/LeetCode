/*
 Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

//Solution

class Trie {
    Trie * children[26];
    bool endofWord;

public:
    /** Initialize your data structure here. */
    Trie() {

       // Trie *p= new Trie;

        for(int i=0;i<26;i++)
        {
            children[i]=NULL;

        }
        endofWord=false;

    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        int word_size=word.size();

        Trie *root=this;
        for(int i=0;i<word_size;i++)
        {

            int index=word[i]-'a';
            if(root->children[index]==NULL)
            {
                root->children[index] =  new Trie();
            }
            root=root->children[index];
        }
        root->endofWord=true;

    }


    /* Returns if the word is in the trie. */
    bool search(string word) {

     //   return searchUtil(this,word, 0, word.length());
        Trie *root=this;
        for(char c:word)
        {
            if(root->children[c-'a']==NULL)  //retun false for small and wrong prefix, larger word
                return false;
            root=root->children[c-'a'];
        }

        //can comeout in case of if word=some prefix or if word is fuly present
        if(root->endofWord==true)
           return true;
        return false;
    }


   /* Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root=this;
        for(char c:prefix)
        {
            if(root->children[c-'a']==NULL)  //retun false for small and wrong prefix, larger word
                return false;
            root=root->children[c-'a'];
        }

        //can comeout in case of if word=some prefix or if prefix is fuly present till end

           return true;


      }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

//TC = O(Q * length of largest string)  q is no of queries
//SC = O(size of a node * no of nodes in trie)
