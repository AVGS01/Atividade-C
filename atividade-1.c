#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[64];
    char tel[64];
    char curso[64];
    float nota1;
    float nota2;
};

int main() {
    FILE* entrada;
    FILE* saida;
    struct Aluno aluno;
    entrada = fopen("../DadosEntrada.csv", "r");
    saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Arquivos não encontrados!");
        exit(1);
    }

    fprintf(saida, "NOME, NOTA, SITUACAO\n");

    while (fscanf(entrada, "%[^,],%[^,],%[^,],%f,%f\n", aluno.nome, aluno.tel, aluno.curso, &aluno.nota1, &aluno.nota2) != EOF) {
        float media = (aluno.nota1 + aluno.nota2) / 2.0;
        const char* situacao = (media >= 7) ? "APROVADO" : "REPROVADO";
        fprintf(saida, "%s, %.2f, %s\n", aluno.nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
