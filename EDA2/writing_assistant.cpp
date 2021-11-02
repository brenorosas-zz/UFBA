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
  return true;
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

void printOut(Trie &root, string s = "", int v = 0) {
  if (root[v].end) {
    cout << s << ' ' << root[v].frequence << endl;
  }
  for (int i = 0; i < 26; i++) {
    if (root[v].children[i] == -1)
      continue;
    printOut(root, s + (char)('a' + i), root[v].children[i]);
  }
}

void addFrequence(string ult, string s) {
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
      string s;
      cin >> s;

      if (Consult(root, s)) {
        vector<WordFrequence> nextWords = Take(s);
        cout << "proximas palavras:";
        for (auto &word : nextWords) {
          cout << ' ' << word.word;
        }
        cout << endl;
        if (ff == false) {
          addFrequence(ult, s);
        }
        ff = false;
        ult = s;
        Insert(root, s, true);
      } else {
        cout << "palavra desconhecida - possiveis correcoes:" << endl;
      }
    } else if (operation == 'f') {
      printOut(root);
    } else if (operation == 'p') {
      string s;
      cin >> s;
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