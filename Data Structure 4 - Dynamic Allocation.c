#include <stdio.h>
#include <stdlib.h>


//Nome: Darlan Freire Mendon�a da Silva - T:146
//Matr�cula: 2017102635

//Defini��o da Estrutura//
typedef struct Registro{
	int chave;
	struct Registro *prox;
}ELEMENTO; //ELEMENTO � agora um novo tipo

//Defini��o do tipo FILA//
typedef ELEMENTO *FILA; //FILA � agora um novo tipo.
						//FILA � o nome da vari�vel ponteiro do tipo ELEMENTO

//In�cio
int main(void) {
	FILA p, h, prim, q; //Declara��o das vari�veies do tipo FILA//
	int i;
	
	prim = NULL; // AGORA SIM, (prim) vai fazer alguma coisa
	
	p = (FILA)malloc(sizeof(ELEMENTO));//Aloque(p)

	h = p; //(h) agora aponta para (p). 
	
	prim = p;
	
	p->chave = 1; //inserindo o valor 1 no campo p.chave
	
	//la�o de 1 at� 3
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
		p = p->prox; // (p) aponta para p.prox, que � o valor do pr�ximo elemento da fila
	}
}//fim
