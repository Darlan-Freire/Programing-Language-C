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

//In�cio//
int main(void) {
	FILA p, h, prim, q; //Declara��o das vari�veies do tipo FILA//
	
	prim = NULL;//Isso aqui (prim) CONTINUA n�o fazendo nada.
	
	p = (FILA)malloc(sizeof(ELEMENTO));// Aloque(p)

	h = p; //(h) agora aponta para (p)
	
	p->chave = 1; //inserindo o valor 1 no campo p.chave
	
	//la�o i de 1 at� 3 fa�a
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
