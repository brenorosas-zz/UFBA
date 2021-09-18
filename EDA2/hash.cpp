#include <iostream>

#define MAXNUMREGS 11

using namespace std;

struct Registro {
  int chave, idade;
  char nome[20];
  bool ocupado, nunca_ocupado;
  Registro() {
    chave = idade = -1;
    ocupado = false;
    nunca_ocupado = true;
  }
};

pair<int, int> consultas_sucesso = {0, 0}, consultas_sem_sucesso = {0, 0};

pair<int, string> buscaHash(int chave, FILE *f) {
  int primeiro_vazio = -1;
  int h1 = chave % MAXNUMREGS;
  int h2 = max((chave / MAXNUMREGS) % MAXNUMREGS, 1);
  Registro r;
  for (int index = 0; index < MAXNUMREGS; index++) {
    fseek(f, h1 * sizeof(Registro), SEEK_SET);
    fread(&r, sizeof(Registro), 1, f);
    if (primeiro_vazio == -1 and !r.ocupado) primeiro_vazio = h1;
    if (r.chave == chave) {
      return {h1, "existe"};
    }
    if (r.nunca_ocupado) return {primeiro_vazio, "nao existe"};
    h1 += h2;
    h1 %= MAXNUMREGS;
  }
  if (primeiro_vazio == -1) return {-1, "cheio"};
  return {primeiro_vazio, "nao existe"};
}

void inserir(Registro &r, FILE *f) {
  pair<int, string> h = buscaHash(r.chave, f);
  if (h.second == "cheio")
    printf("insercao de chave sem sucesso - arquivo cheio: %d\n", r.chave);
  else if (h.second == "existe") {
    printf("chave ja existente %d\n", r.chave);
  } else {
    fseek(f, h.first * sizeof(Registro), SEEK_SET);
    r.ocupado = true;
    r.nunca_ocupado = false;
    fwrite(&r, sizeof(Registro), 1, f);
    printf("insercao com sucesso: %d\n", r.chave);
  }
}

void consultar(int chave, FILE *f) {
  pair<int, string> h = buscaHash(chave, f);
  if (h.second == "existe") {
    Registro r;
    fseek(f, h.first * sizeof(Registro), SEEK_SET);
    fread(&r, sizeof(Registro), 1, f);
    printf("chave: %d\n%s\n%d\n", r.chave, r.nome, r.idade);
  } else {
    printf("chave nao encontrada: %d\n", chave);
  }
}

void remove(int chave, FILE *f) {
  pair<int, string> h = buscaHash(chave, f);
  if (h.second != "existe") {
    printf("chave nao encontrada: %d\n", chave);
  } else {
    Registro r;
    fseek(f, h.first * sizeof(Registro), SEEK_SET);
    fread(&r, sizeof(Registro), 1, f);
    r = Registro();
    r.nunca_ocupado = false;
    fseek(f, h.first * sizeof(Registro), SEEK_SET);
    fwrite(&r, sizeof(Registro), 1, f);
    printf("chave removida com sucesso: %d\n", chave);
  }
}

void imprimir(FILE *f) {
  fseek(f, 0, SEEK_SET);
  Registro r;
  for (int i = 0; i < MAXNUMREGS; i++) {
    printf("%d %s", i, ": ");
    fread(&r, sizeof(Registro), 1, f);
    if (r.nunca_ocupado) {
      printf("vazio\n");
    } else if (r.ocupado == true) {
      printf("%d %s %d\n", r.chave, r.nome, r.idade);
    } else {
      printf("*\n");
    }
  }
}
void makeFile(FILE *f) {
  f = fopen("dados", "w+");

  Registro r;
  for (int i = 0; i < MAXNUMREGS; i++) {
    fwrite(&r, sizeof(Registro), 1, f);
  }
  fclose(f);
}

void calcMedia() {
  printf("%.1f\n", consultas_sucesso.first * 1.0 / consultas_sucesso.second);
  printf("%.1f\n",
         consultas_sem_sucesso.first * 1.0 / consultas_sem_sucesso.second);
}
int main() {
  FILE *f;
  if (!(f = fopen("dados", "r+"))) {
    makeFile(f);
    f = fopen("dados", "r+");
  }

  while (true) {
    Registro r;
    char op;
    cin >> op;
    if (op == 'i') {
      cin >> r.chave;
      cin.ignore();
      scanf("%[^\n]", r.nome);
      cin >> r.idade;
      inserir(r, f);
    } else if (op == 'c') {
      int chave;
      cin >> chave;
      consultar(chave, f);
    } else if (op == 'r') {
      int chave;
      cin >> chave;
      remove(chave, f);
    } else if (op == 'p') {
      imprimir(f);
    } else if (op == 'm') {
      calcMedia();
    } else if (op == 'e') {
      break;
    } else {
      cout << "Operação inválida" << endl;
    }
  }

  fclose(f);
}