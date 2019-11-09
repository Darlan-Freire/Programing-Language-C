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

//Início
int main(void) {
	FILA p, h, prim, q; //Declaração das variáveies do tipo FILA//
	int i;
	
	prim = NULL; // AGORA SIM, (prim) vai fazer alguma coisa
	
	p = (FILA)malloc(sizeof(ELEMENTO));//Aloque(p)

	h = p; //(h) agora aponta para (p). 
	
	prim = p;
	
	p->chave = 1; //inserindo o valor 1 no campo p.chave
	
	//laço de 1 até 3
	for(i=1;i<=3;i++){
		q = (FILA)malloc(sizeof(ELEMENTO));//Aloque(q)
		q->chave = p->chave + i; // q.chave <= p.chave + valor de i
		printf("h: %d, p: %d, q: %d\n",(*h).chave,(*p).chave,(*q).chave);
		p->prox = q; // p.prox aponta para (q)
		p = q; // (p) aponta para (q)
	}
	printf("\n");
	printf("h: %d, p: %d, q: %d\n\n",(*h).chave,(*p).chave,(*q).chave);
	
	p = prim; //(p) aponta para (prim)
	
	//imprime os valores da FILA encadeada
	for(i=1;i<=3;i++){
		printf("p: %d\n",(*p).chave);
		p = p->prox; // (p) aponta para p.prox, que é o valor do próximo elemento da fila
	}
}//fim
