#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[64];
    char tel[64];
    char curso[64];
    float nota1;
    float nota2;
};

int lerAluno(struct Aluno *aluno, FILE *entrada);
float calcularMedia(float nota1, float nota2);
const char* definirSituacao(float media);

int main() {
    FILE* entrada;
    FILE* saida;
    struct Aluno aluno;

    entrada = fopen("../DadosEntrada.csv", "r");
    saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos!");
        exit(1);
    }

    fprintf(saida, "NOME, NOTA, SITUACAO\n");

    while (lerAluno(&aluno, entrada) != EOF) {
        float media = calcularMedia(aluno.nota1, aluno.nota2);
        const char* situacao = definirSituacao(media);
        fprintf(saida, "%s, %.2f, %s\n", aluno.nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}

int lerAluno(struct Aluno *aluno, FILE *entrada) {
    char linha[256];
    if (fgets(linha, sizeof(linha), entrada) == NULL)
        return EOF;

    sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", aluno->nome, aluno->tel, aluno->curso, &aluno->nota1, &aluno->nota2);
    
    return 1;
}

float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

const char* definirSituacao(float media) {
    return (media >= 7) ? "APROVADO" : "REPROVADO";
}
