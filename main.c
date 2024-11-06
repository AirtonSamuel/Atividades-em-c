#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 1000000

int indices(int numero, int vetor[tam]);
void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho);
void buscador(int numero, int inicio, int vetor[tam]);

int main() {
    int vetor[tam], desejado=0, buscan;
    carrega_vetor_ordenado(vetor, 1, tam);
    printf ("Insira o valor que deseja buscar no vetor: ");
    scanf ("%d", &desejado);
    buscan = indices(desejado, vetor);
    buscador(desejado, buscan, vetor);
    
    
    return 0;
}

int indices(int numero, int vetor[tam]){
  int indice = 0;
    if (numero > vetor[tam/4*3]) {
        indice = tam/4*3;
    } else {
        if (numero > vetor[tam/4*2]) {
         indice = tam/4*2;
        } else {
            if (indice > vetor[tam/4]) {
               indice = tam/4;
            }
        }
    }
    return indice;
}

void buscador(int numero, int inicio, int vetor[tam]){
 int nencontrado = 0;
  for(int i = inicio; i < tam; i++){
        if (numero == vetor[i]) {
            printf ("Número encontrado! Se encontra na posição: %d", i);
            nencontrado = 1;
            break;
      }
    }
    if (nencontrado == 0) {
        printf ("Número não encontrado no vetor.");
    }
}

void carrega_vetor_ordenado(int colecao[], int valor_inicial, int tamanho){
	int i;
	srand( (unsigned) time(NULL) );
	for(colecao[0] = valor_inicial, i=1; i<tamanho; i++){
		colecao[i] = colecao[i-1] + (rand() % 10);
		printf ("%d, \n", colecao[i]);
	}
}
