#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
using namespace std;

#define MAXNSIMBOLOS 1

struct Node {
  int children[26];
  int frequence;
  bool end;
  Node() {
    memset(children, -1, sizeof(children));
    frequence = 0;
    end = false;
  }
};

struct WordFrequence {
  char word[40];
  int frequence;
  WordFrequence(string s = "") {
    for (int i = 0; i < s.size(); i++) {
      word[i] = s[i];
    }
    word[s.size()] = '\0';
    frequence = 1;
  }
};

struct Trie {
  FILE *trie;

  Trie() {
    if (trie = fopen("trie.dat", "r+")) {
      return;
    }
    trie = fopen("trie.dat", "w+");
    fclose(trie);
    trie = fopen("trie.dat", "r+");
    this->create_node();
  }

  void create_node() {
    fseek(trie, 0, SEEK_END);
    Node aux;
    fwrite(&aux, sizeof(Node), 1, trie);
  }

  void create_node(Node aux) {
    fseek(trie, 0, SEEK_END);
    fwrite(&aux, sizeof(Node), 1, trie);
  }

  int size() {
    fseek(trie, 0, SEEK_END);
    return ftell(trie) / sizeof(Node);
  }

  Node operator[](int pos) {
    Node aux;
    fseek(trie, pos * sizeof(Node), SEEK_SET);
    fread(&aux, sizeof(Node), 1, trie);
    return aux;
  }

  void write(int pos, Node aux) {
    fseek(trie, pos * sizeof(Node), SEEK_SET);
    fwrite(&aux, sizeof(Node), 1, trie);
  }

  int root() { return 0; }

  void close() { fclose(trie); }
};

void Insert(Trie &root, string s, bool typing) {
  int v = 0;
  char fileName[40] = "map/";
  for (int i = 0; i < s.size(); i++) {
    fileName[i + 4] = s[i];
    int x = s[i] - 'a';
    Node newNode = root[v];
    if (newNode.children[x] == -1) {
      root.create_node();
      newNode.children[x] = root.size() - 1;
      root.write(v, newNode);
    }
    v = newNode.children[x];
  }
  for (int i = 0; i < 4; i++) {
    fileName[s.size() + 4 + i] = ".dat"[i];
  }
  fileName[s.size() + 8] = '\0';
  Node newNode = root[v];
  newNode.end = true;
  newNode.frequence += typing;
  root.write(v, newNode);
  FILE *newWord;
  if (newWord = fopen(fileName, "r+")) {
    return;
  }
  newWord = fopen(fileName, "w+");
  fclose(newWord);
}

bool Consult(Trie &root, string s) {
  int v = 0;
  for (int i = 0; i < s.size(); i++) {
    int x = s[i] - 'a';
    if (root[v].children[x] == -1) {
      return false;
    }
    v = root[v].children[x];
  }
  return root[v].end;
}

void Insert(vector<WordFrequence> &ans, WordFrequence r) {
  for (auto &i : ans) {
    if (r.frequence > i.frequence) {
      swap(r, i);
    }
  }
  if (ans.size() < 3) {
    ans.push_back(r);
  }
}

vector<WordFrequence> Take(string s) {
  FILE *fileWord;
  s = s + ".dat";
  vector<WordFrequence> ans;
  char fileName[40] = "map/";
  for (int i = 0; i < s.size(); i++) {
    fileName[i + 4] = s[i];
  }
  fileName[s.size() + 4] = '\0';
  fileWord = fopen(fileName, "r+");
  fseek(fileWord, 0, SEEK_END);
  int n = ftell(fileWord) / sizeof(WordFrequence);
  WordFrequence r;
  fseek(fileWord, 0, SEEK_SET);
  for (int i = 0; i < n; i++) {
    fread(&r, sizeof(WordFrequence), 1, fileWord);
    Insert(ans, r);
  }
  fclose(fileWord);
  return ans;
}

void PrintOut(Trie &root, string s = "", int v = 0) {
  if (root[v].end) {
    cout << s << ' ' << root[v].frequence << endl;
  }
  for (int i = 0; i < 26; i++) {
    if (root[v].children[i] == -1)
      continue;
    PrintOut(root, s + (char)('a' + i), root[v].children[i]);
  }
}

void AddFrequence(string ult, string s) {
  FILE *fileWord;
  char fileName[40] = "map/";
  for (int i = 0; i < ult.size(); i++) {
    fileName[i + 4] = ult[i];
  }
  for (int i = 0; i < 4; i++) {
    fileName[ult.size() + 4 + i] = ".dat"[i];
  }
  fileName[ult.size() + 8] = '\0';
  fileWord = fopen(fileName, "r+");
  fseek(fileWord, 0, SEEK_END);
  int n = ftell(fileWord) / sizeof(WordFrequence);
  WordFrequence r;
  fseek(fileWord, 0, SEEK_SET);
  for (int i = 0; i < n; i++) {
    fread(&r, sizeof(WordFrequence), 1, fileWord);
    if (r.word == s) {
      r.frequence++;
      fseek(fileWord, i * sizeof(WordFrequence), SEEK_SET);
      fwrite(&r, sizeof(WordFrequence), 1, fileWord);
      fclose(fileWord);
      return;
    }
  }
  WordFrequence newWord(s);
  fseek(fileWord, 0, SEEK_END);
  fwrite(&newWord, sizeof(WordFrequence), 1, fileWord);
  fclose(fileWord);
}

struct stat st = {0};

void Merge(vector<pair<string, int>> &vet, pair<string, int> si) {
  for (auto &i : vet) {
    if (si.second > i.second) {
      swap(si, i);
    }
  }
  if (vet.size() < 3) {
    vet.push_back(si);
  }
}

void Correction(Trie &root, vector<pair<string, int>> &ans, string s, int v = 0,
                int vs = 0, bool fail = false, string t = "") {
  if (vs == s.size()) {
    if (root[v].end) {
      Merge(ans, make_pair(t, root[v].frequence));
    }
    return;
  }
  int x = s[vs] - 'a';
  if (!fail) {
    for (int i = 0; i < 26; i++) {
      if (root[v].children[i] != -1) {
        Correction(root, ans, s, root[v].children[i], vs + 1, (i != x),
                   t + (char)('a' + i));
      }
    }
  } else {
    if (root[v].children[x] != -1) {
      Correction(root, ans, s, root[v].children[x], vs + 1, fail, t + s[vs]);
    }
  }
}

int main() {
  Trie root;

  if (stat("map/", &st) == -1) {
    mkdir("map/", 0700);
  }

  string ult;
  bool ff = true;

  while (true) {
    char operation;
    cin >> operation;

    if (operation == 'i') {
      int n;
      cin >> n;
      for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        Insert(root, s, false);
      }
    } else if (operation == 'd') {
      string s, t;
      cin >> s;

      if (Consult(root, s)) {
        vector<WordFrequence> nextWords = Take(s);
        cout << "proximas palavras:";
        for (auto &word : nextWords) {
          cout << ' ' << word.word;
        }
        cout << endl;
        if (ff == false) {
          AddFrequence(ult, s);
        }
        ff = false;
        ult = s;
        Insert(root, s, true);
      } else {
        cout << "here" << endl;
        vector<pair<string, int>> ans;
        Correction(root, ans, s);
        cout << "palavra desconhecida - possiveis correcoes:";
        for (auto &i : ans) {
          cout << ' ' << i.first;
        }
        cout << endl;
        cin >> t;
        Insert(root, t, true);
        if (ff == false) {
          AddFrequence(ult, t);
        }
        ff = false;
        ult = t;
      }
    } else if (operation == 'f') {
      PrintOut(root);
    } else if (operation == 'p') {
      string s;
      cin >> s;
      if (!Consult(root, s))
        continue;
      vector<WordFrequence> nextWords = Take(s);
      for (auto &word : nextWords) {
        cout << word.word << ' ' << word.frequence << endl;
      }
    } else if (operation == 'e') {
      break;
    }
  }
  root.close();
}