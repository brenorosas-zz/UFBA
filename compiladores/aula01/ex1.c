#include <stdio.h>

int main() {
    // gcc exercicio1.c -E : Para o programa após o preprocessamento, não chega a compilar, retorna o código preprocessado.
    // gcc exercicio1.c -c : Após compilação e geração do código assembly, retorna um object code.
    // gcc exercicio1.c -S : Para o programa após a compilação, retornando o código em assembly;

    // change name file
    // receiving source code: gcc exercicio1.c
    // dont process source code: gcc exercicio1.i
    // Objjective-C source code: gcc exercicio1.m

    int a = 30 + 10;
    int b = 10 * a;
    return 0;
}