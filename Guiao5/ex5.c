#include "pipe.h"

/* Acrescente ao interpretador de comandos proposto nos guiões anteriores a possibilidade de encadear as
entradas e saı́das de programas a executar através de pipes anónimos (operador |). */

/* Esquema com pseudocódigo:
 * for (i=0; i < n_comandos; i++){
 *           if(i=0){
 *           pipe();
 *           switch(fork());
 *
 *           else{ if (i = n_comandos -1 ){
 *
 *                  switch(fork())
 *
 *                  } else{
 *                  pipe();
 *                  switch(fork())
 *                  }
 *                  }
 */

int main (int argc, char const *argv[]) {

    return 0;
}
