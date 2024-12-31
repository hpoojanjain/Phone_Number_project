#include <bits/stdc++.h>
using namespace std;

class Trie
{
  unordered_map<char, Trie *> childs;
  bool ends;

public:
  Trie() {}

  void addChild(char c)
  {
    childs[c] = new Trie();
  }

  Trie *getChild(char c)
  {
    return childs[c];
  }

  bool hasChild(char c)
  {
    return getChild(c) != nullptr;
  }

  void insertString(string s)
  {
    auto node = this;
    for (int i = 0; i < s.size(); i++)
    {
      if (!node->hasChild(s[i]))
      {
        node->addChild(s[i]);
      }
      node = node->getChild(s[i]);
    }
    node->ends = true;
  }

  vector<string> findStringsStartingWith(string s)
  {
    auto node = this;
    for (int i = 0; i < s.size(); i++)
    {
      if (node->hasChild(s[i]))
      {
        node = node->getChild(s[i]);
      }
      else
      {
        return {};
      }
    }
    vector<string> ans;
    traverse(node, ans, "");
    for (int i = 0; i < ans.size(); i++)
    {
      ans[i] = s + ans[i];
    }
    return ans;
  }

  void traverse(Trie *n, vector<string> &ans, string acc)
  {
    if (n->childs.size() == 0 || n->ends)
    {
      ans.push_back(acc);
    }
    for (auto p : n->childs)
    {
      string nextacc = acc;
      nextacc.push_back(p.first);
      traverse(p.second, ans, nextacc);
    }
  }
};
