#include "files.h"

/* Considere uma estrutura (struct) com dados de uma pessoa (nome, idade, ...) e um ficheiro binário que contém
 * registos organizados segundo esta estrutura. Não assuma que o ficheiro cabe todos em memória.
 * Escreva um programa que, consoante a opção, permita:
 * -> -i: Acrescentar pessoas a um ficheiro de dados (binario – a idade é um inteiro).
 * -> -u: Actualizar a idade de uma determinada pessoa no ficheiro de dados.
 * -> Exemplos:
 *  -> $ pessoas -i "José Mourinho" 55
 *  -> $ pessoas -u "José Mourinho" 56 */


int novaPessoa(int fd, const char *nome, int idade){
    int index;
    if (fd == -1) {
        perror("Não foi possível abrir o ficheiro! ");
        return 1;
    }

    puts("Modo de inserção. ");

    PESSOA p1;
    p1.idade = idade;
    strcpy(p1.nome,nome);
    lseek(fd, 0, SEEK_END); //move o offset para o final do ficheiro
    write(fd,&p1, sizeof(struct Pessoa));
}

int atualizaPessoa(int fd, const char *nome, int idade) {
    if (fd == -1) {
        perror("ERROR - open file");
        return 1;
    }

    puts("Modo de atualização 1. Pessoa + idade ");

    PESSOA p1;
    int bytes_read;
    lseek(fd, 0, SEEK_SET);
    while ((bytes_read = read(fd, &p1, sizeof(struct Pessoa))) > 0) {
        if (!bytes_read) return -1;
        if (!strcmp(p1.nome, nome)) {
            p1.idade = idade;
            strcpy(p1.nome, nome);
            lseek(fd, -sizeof(struct Pessoa), SEEK_CUR);
            write(fd, &p1, sizeof(struct Pessoa));
        }
    }
}

int atualizaRegisto(int fd, const char *nome, int idade){

}
void verFicheiro(int fd, const char *nome, int idade){
    PESSOA p1; //Cria pessoa
    lseek(fd,0,SEEK_SET);
    int byte_read;
    while((byte_read = read(fd,&p1,sizeof(struct Pessoa))) > 0){
        printf("\tidade: %d\n\tnome: %s\n",p1.idade,p1.nome);
        printf("\t--------------------\n");
    }
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

    int fd = open("registo", O_RDWR | O_CREAT | O_APPEND, 0640);

    const char *nome = argv[2];
    int idade = atoi(argv[3]);

    switch (*(argv[1] + 1)) {
        case 'i':
            novaPessoa(fd, nome, idade);
            break;
        case 'u':
            atualizaPessoa(fd, nome, idade);
            break;
        case 'r':
            atualizaRegisto(fd, nome, idade);
        default:
            puts("Erro: modo inválido");
            break;
    }
    verFicheiro(fd, nome, idade);
    close(fd);
    return 0;
}
