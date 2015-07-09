/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ImplementTrie.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/09 09:12:40
 * @brief 
 *  
 **/
#include <iostream>
using namespace std;

class TrieNode{
public:
    bool iskey;
    TrieNode *children[26];
    int count;
    TrieNode(){
        iskey = false;
        count = 1;
        for (int i = 0; i<26; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for (int i = 0; i<word.size(); i++){
            if (node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new TrieNode();
            }else{
                node = node->children[word[i]-'a'];
                node->count++;
            }
        }
        node->iskey = true;    
    }

    bool search(string word){
        TrieNode* node = root;
        for (int i = 0; i<word.size(); i++){
            if (node != NULL)
                node = node->children[word[i]-'a'];
            else
                break;
        }
        if (node == NULL)
           return false;
        else
           return node->iskey; 
    }

    int searchCount(string word){
        TrieNode* node = root;
        for (int i = 0; i<word.size(); i++){
            if (node != NULL)
                node = node->children[word[i]-'a'];
            else
                break;
        }
        if (node == NULL)
            return -1;
        else 
            return node->count;
    }

    bool startsWith(string prefix){
        TrieNode* node = root;
        for (int i=0; i<prefix.size();i++){
            if(node != NULL)
                node = node->children[prefix[i]-'a'];
            else
                break;
        }

        if (node == NULL)
            return false;
        return true;
    }
private:
    TrieNode* root;
};


int main(){
    Trie t;
    t.insert("helloworld");
    t.insert("hello");
   // t.insert("hello");
    cout << t.searchCount("h") << endl;
    //cout << t.search("ui") << endl;

}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
