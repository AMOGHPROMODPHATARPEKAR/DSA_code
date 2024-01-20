#include <iostream>
using namespace std;

    class TrieNode
    {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char d)
        {
            data = d;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
        }
    };

class Trie{

    public:

    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // TC:O(L)
    void insertUtil(TrieNode* root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //assume word will be in caps

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursion

        insertUtil(child,word.substr(1));

    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    }

    // TC:O(L)
    bool searchUtil(TrieNode *root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        //recursion

        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word)
    {
       return searchUtil(root,word);
    }


    //removal
    void removeUtil(TrieNode* root,string word)
    {
        if(word.length() == 0)
        {
            if(root->isTerminal)
            {
                root->isTerminal = false;
            }
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }

        //recursion

        return removeUtil(child,word.substr(1));
    }

    void removeWord(string word)
    {
        removeUtil(root,word);
    }

    bool prefixUtil(TrieNode *root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        //recursion

        return prefixUtil(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return  prefixUtil(root,prefix);
    }

};


int main()
{

    Trie *t = new Trie() ;

    t->insertWord("AMOGH");
    t->insertWord("AMO");
    t->insertWord("BAR");

    cout<<"present or NOt : "<<t->searchWord("AMOGH")<<endl;

    t->removeWord("AMO");
    cout<<"present or NOt : "<<t->searchWord("AMO")<<endl;

    cout<<"Prefix: present or NOt : "<<t->startsWith("AMO")<<endl;
    cout<<"Prefix: present or NOt : "<<t->startsWith("B")<<endl;



}

