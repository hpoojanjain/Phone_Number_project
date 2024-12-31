#include <bits/stdc++.h>
#include <Trie.h>

using namespace std;

class Dictionary
{
public:
  Trie *wordStore;
  unordered_map<string, string> definitions;

public:
  Dictionary()
  {
    wordStore = new Trie();
  }
  void addWordDefinition(string word, string meaning)
  {
    definitions[word] = meaning;
    wordStore->insertString(word);
  }
  vector<pair<string, string>> getWordDefinitions(string word)
  {
    auto words = wordStore->findStringsStartingWith(word);
    sort(words.begin(), words.end());
    vector<pair<string, string>> wordDefs;
    for (auto word : words)
    {
      wordDefs.push_back({word, definitions[word]});
    }
    return wordDefs;
  }
};

int main()
{
  Dictionary dict;
  int choice;

  do
  {
    // Display the menu in color
    cout << "\033[1m\033[34mDictionary Application\033[0m\n";
    cout << "1. Add a word and definition\n";
    cout << "2. Search words by prefix\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      // Add a word and its definition
      string word, definition;
      cout << "Enter the word: ";
      cin >> word;
      cout << "Enter the definition: ";
      cin.ignore(); // Ignore leftover newline character
      getline(cin, definition);
      dict.addWordDefinition(word, definition);
      cout << "\033[32mWord added successfully!\033[0m\n";
      break;
    }
    case 2:
    {
      // Search words by prefix
      string prefix;
      cout << "Enter the prefix to search: ";
      cin >> prefix;
      auto results = dict.getWordDefinitions(prefix);
      if (results.empty())
      {
        cout << "\033[31mNo matching words found!\033[0m\n";
      }
      else
      {
        cout << "\033[1m\033[33mMatching words and definitions:\033[0m\n";
        for (const auto &entry : results)
        {
          // Split the word into prefix and suffix
          string word = entry.first;
          string suff = word.substr(prefix.size());

          // Display with different colors
          cout << "\033[1m\033[32m" << prefix << "\033[35m" << suff << "\033[0m: \033[36m" << entry.second << "\033[0m\n";
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
}
