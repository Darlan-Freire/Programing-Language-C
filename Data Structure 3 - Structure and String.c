#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Nome: Darlan Freire Mendonça da Silva - T:146
//Matrícula: 2017102635

typedef struct Registro{
	int chave;
	char nome[3][3];
	struct Registro *prox;
}ELEMENTO; //ELEMENTO é agora um novo tipo

//Definição do tipo FILA//
typedef ELEMENTO *FILA; //FILA é agora um novo tipo.
						//FILA é o nome da variável ponteiro do tipo ELEMENTO

//Início
int main(void) {
	FILA p, h, prim, q; //Declaração das variáveies do tipo FILA//
	int l,c;
	
	prim = NULL;//(prim) não faz nada
	
	p = (FILA)malloc(sizeof(ELEMENTO));// Aloque(p)
	
	h = p; //(h) agora aponta para (p)
	
	p->chave = 1; //inserindo o valor 1 no campo p.chave
	
	//inserindo nome "ANA"
	p->nome[0][0] = 'A';
	p->nome[0][1] = 'n';
	p->nome[0][2] = 'a';
	//inserindo nome "BIA"
	p->nome[1][0] = 'B';
	p->nome[1][1] = 'i';
	p->nome[1][2] = 'a';
	//inserindo nome "LIA"
	p->nome[2][0] = 'L';
	p->nome[2][1] = 'i';
	p->nome[2][2] = 'a';
	
	//Imprime os nomes em p.nome
	printf("p.nome[0]: ");
	for(c=0;c<3;c++){
		printf("%c", p->nome[0][c]);
	}
	printf("\np.nome[1]: ");
	for(c=0;c<3;c++){
		printf("%c", p->nome[1][c]);
	}
	printf("\np.nome[2]: ");
	for(c=0;c<3;c++){
		printf("%c", p->nome[2][c]);
	}
	
	printf("\n--------------------------------");
	
	q = (FILA)malloc(sizeof(ELEMENTO));// Aloque(q)
	
	//q.nome recebe a string inversa de p.nome
	for(l=0;l<3;l++){	
		for(c=0;c<3;c++){
			q->nome[l][2-c] = p->nome[l][c];
		}
	}
	
	//imprime as string de q.nome inversa
	for(l=0;l<3;l++){
		printf("\nq.nome[%d]: ",l);
		for(c=0;c<3;c++){
			printf("%c", q->nome[l][c]);
		}
	}
}//fim

