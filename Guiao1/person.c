#include "files.h"

/* Considere uma estrutura (struct) com dados de uma pessoa (nome, idade, ...) e um ficheiro binário que contém
 * registos organizados segundo esta estrutura. Não assuma que o ficheiro cabe todos em memória.
 * Escreva um programa que, consoante a opção, permita:
 * -> -i: Acrescentar pessoas a um ficheiro de dados (binario – a idade é um inteiro).
 * -> -u: Actualizar a idade de uma determinada pessoa no ficheiro de dados.
 * -> Exemplos:
 *  -> $ pessoas -i "José Mourinho" 55
 *  -> $ pessoas -u "José Mourinho" 56 */

/*
int search(int fd, char *name){
    int t;
    if (fd <0) return 1;
 //using strung cmp!!
    while ()
}
 */

int main(int argc, char const *argv[]) {

    /* Ideias a desenvolver:
     * -> 2 comandos que permitam inserir e alterar dados de pessoas, num determinado ficheiro.
     * -> Criar um ficheiro de leitura;
     * -> Programar a sua alteração e inserção;
     * -> Não esquecer de utilizar o stdin e stdout, pois é a partir daí que os comandos serão utilizados! */

    if (argc != 4) {
        perror("Modo de inserção desrespeitado!\n");
        return 1;
    }

    int fd;
    Pessoa pessoa;

    if (!strcmp(argv[2], "-i")) {

        fd = open("id.txt", O_WRONLY | O_CREAT | O_APPEND | S_IRUSR | S_IWUSR, 0640);
        if (fd == -1) {
            perror("Erro: não foi possível criar ficheiro de registo");
            return 1;
        }

        system("clear");
        puts("Modo de inserção.");


        strcpy(pessoa.nome, argv[2]);
        pessoa.idade = atoi(argv[3]);

        write(fd, &pessoa, sizeof(struct Pessoa));
        close(fd);
     /*   int pos = lseek(fd, sizeof(struct Pessoa), SEEK_CUR);
        pos = pos / sizeof(struct Pessoa);
        printf("registo nº %d \n", pos);*/
    }
    //if (!strcmp(argv[2],"-u"))
    return 0;
}