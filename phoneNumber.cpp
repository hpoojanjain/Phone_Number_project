#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Trie
{
  unordered_map<char, Trie *> childs;
  bool flag;

public:
  Trie() {
    this-> flag = false;
  }

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
    node->flag = true;
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
    if (n->childs.size() == 0 || n->flag)
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

void displayMenu()
{
  cout << "\033[1m\033[34mPhone Number Autocomplete System\033[0m\n";
  cout << "1. Insert a phone number\n";
  cout << "2. Search by prefix\n";
  cout << "3. Exit\n";
  cout << "Choose an option: ";
}

int main()
{
  Trie trie;
  int choice;

  do
  {
    displayMenu();
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      string phoneNumber;
      cout << "Enter the phone number to insert: ";
      cin >> phoneNumber;
      trie.insertString(phoneNumber);
      cout << "\033[32mPhone number inserted successfully!\033[0m\n";
      break;
    }
    case 2:
    {
      string prefix;
      cout << "Enter the prefix to search: ";
      cin >> prefix;
      auto results = trie.findStringsStartingWith(prefix);
      if (results.empty())
      {
        cout << "\033[31mNo matching phone numbers found!\033[0m\n";
      }
      else
      {
        cout << "\033[1m\033[33mMatching phone numbers:\033[0m\n";
        for (const auto &num : results)
        {
          string suff = num.substr(prefix.size());
          cout << "\033[1m\033[32m" << prefix << "\033[35m" << suff << "\033[0m" << endl;
        }
      }
      break;
    }
    case 3:
      cout << "\033[1m\033[35mExiting...\033[0m\n";
      break;
    default:
      cout << "\033[31mInvalid option. Please try again.\033[0m\n";
    }

    cout << endl;
  } while (choice != 3);

  return 0;
}
