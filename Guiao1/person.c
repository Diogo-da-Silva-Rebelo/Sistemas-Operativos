#include "files.h"

/* Considere uma estrutura (struct) com dados de uma pessoa (nome, idade, ...) e um ficheiro binário que contém
 * registos organizados segundo esta estrutura. Não assuma que o ficheiro cabe todos em memória.
 * Escreva um programa que, consoante a opção, permita:
 * -> -i: Acrescentar pessoas a um ficheiro de dados (binario – a idade é um inteiro).
 * -> -u: Actualizar a idade de uma determinada pessoa no ficheiro de dados.
 * -> Exemplos:
 *  -> $ pessoas -i "José Mourinho" 55
 *  -> $ pessoas -u "José Mourinho" 56 */

/* Implmentação de procura num ficheiro:
int search(int fd, char *name){
    int t;
    if (fd <0) return 1;
 //using strung cmp!!
    while ()
} */

int novaPessoa(int fd, const char *nome, int idade){
    if (fd == -1) {
        perror("Não foi possível abrir o ficheiro! ");
        return 1;
    }

    PESSOA p1;
    p1.idade = idade;
    strcpy(p1.nome,nome);
    lseek(fd, 0, SEEK_END); //move o offset para o final do ficheiro
    write(fd,&p1, sizeof(struct pessoa));
}

int atualizaPessoa(int fd, const char *nome, int idade){

}

int novaIdade(int fd, const char *nome, int idade){

}

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

    int fd = open("registo", O_RDWR | O_CREAT | O_APPEND, 600);

    const char *nome = argv[1];
    int idade = atoi(argv[3]);

    switch (*(argv[1])) {
        case "-i":
            novaPessoa(fd,nome,idade));
            break;
        case "-u":
            atualizaPessoa(fd,nome,idade);
            break;
        case "-k":
            novaIdade(fd,nome,idade);
            break;
        default:
            puts("Erro: modo inválido");
            break;
    }

    close(fd);
    return 0;
}


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