#include <stdio.h>
#include <stdlib.h>


//Nome: Darlan Freire Mendonça da Silva - T:146
//Matrícula: 2017102635


//Definição da Estrutura//
typedef struct Registro{
	int chave;
	struct Registro *prox;
}ELEMENTO; //ELEMENTO é agora um novo tipo

//Definição do tipo FILA//
typedef ELEMENTO *FILA; //FILA é agora um novo tipo.
						//FILA é o nome da variável ponteiro do tipo ELEMENTO

//Início//
int main(void) {
	FILA p, h, prim, q; //Declaração das variáveies do tipo FILA//
	
	prim = NULL;//Isso aqui (prim) CONTINUA não fazendo nada.
	
	p = (FILA)malloc(sizeof(ELEMENTO));// Aloque(p)

	h = p; //(h) agora aponta para (p)
	
	p->chave = 1; //inserindo o valor 1 no campo p.chave
	
	//laço i de 1 até 3 faça
	int i = 0;
	while(i<3){
		q = (FILA)malloc(sizeof(ELEMENTO)); // Aloque(q)
		q->chave = p->chave + 2; // q.chave <= recebe o valor do campo p.chave + 2
		printf("h: %d, p: %d, q: %d\n",(*h).chave,(*p).chave,(*q).chave);
		p->prox = q; // Agora o campo p.prox aponta para (q)
		i++;
	}
	
	printf("\nh: %d, p: %d, q: %d\n",(*h).chave,(*p).chave,(*q).chave);
}
//fim
