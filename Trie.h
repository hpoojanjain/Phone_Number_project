#ifndef TRIE_H
#define TRIE_H

#include <bits/stdc++.h>
using namespace std;

class Trie
{
  unordered_map<char, Trie *> childs; // Children of the current Trie node
  bool ends; // Indicates if a string ends at this node

public:
  // Constructor
  Trie();

  // Adds a child Trie node for the given character
  void addChild(char c);

  // Returns the child Trie node corresponding to the character
  Trie *getChild(char c);

  // Checks if a child Trie node exists for the given character
  bool hasChild(char c);

  // Inserts a string into the Trie
  void insertString(string s);

  // Finds all strings in the Trie that start with the given prefix
  vector<string> findStringsStartingWith(string s);

  // Traverses the Trie to collect all strings
  void traverse(Trie *n, vector<string> &ans, string acc);
};

#endif // TRIE_H
