#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*O c�digo descrito abaixo l� uma frase e a imprime na ordem inversa usando uma pilha.*/

//Nome: Darlan Freire Mendon�a da Silva - T:146
//Matr�cula: 2017102635

//Defini��o da Lista
typedef struct Estrutura{
	char string[50];
	struct Estrutura *prox;
}LISTA;

typedef LISTA *PILHA; //PILHA � agora um novo tipo.
					//PILHA � o nome da vari�vel ponteiro do tipo LISTA

//Fun��o Inicia a PILHA vazia
PILHA Inicia(){
	PILHA P = (PILHA)malloc(sizeof(LISTA));
	P->prox = NULL;
	return P;
}

//Fun��o PUSH insere a string de entrada na PILHA
void PUSH(char *s, char *frase){
	int i, slen,fraselen;
	for(i=0,slen=strlen(s),fraselen=strlen(frase); i<fraselen;i++){
		s[i] = frase[i];
	}
}

//Fun��o POP devolve a PILHA invertida
char *POP(char *s){
	int i,len;
	char aux;
	for(i=0,len=strlen(s)-1; i<len ;i++,len--){
		aux=s[i];
		s[i]=s[len];
		s[len]=aux;
	}
	return s;
}

//In�cio
int main(void) {
	//Declara��o das vari�veis
	PILHA p;
	char s[50];
	int n;
	
	printf("Entre com uma frase: ");
	gets(s);//Leia a string (s)
	
	p = Inicia();//Inicia a PILHA vazia com nome (p)
	
	for(n=0;n<strlen(s);n++){
		PUSH(p->string,s);//Chamada da fun��o PUSH
	}
	printf("\n");
	printf("%s",POP(p->string));//Chamada da fun��o POP e imprime a PILHA
}
//fim
