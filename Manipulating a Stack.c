#include <stdio.h>
#include <stdlib.h>

//A tabela abaixo mostra as opera��es para a manipula��o de uma pilha//

/*PUSH - Coloca um novo elemento no topo da pilha
  
  POP - Retira o elemento do topo da pilha
  
  Opera��o un�ria - Efetua a opera��o sobre o elemento do topo da pilha e substitui o elemento
                    do topo pelo resultado. Opera��es dispon�veis: DEC(subtrai o valor 1 do elemento)
  
  Opera��o bin�ria - Efetua a opera��o sobre os dois elemntos do topo da pilha;
                     retira os dois elementos do topo da pilha e coloca o 
					 resultado da opera��o no topo da pilha. 
					
					Opera��es dispon�veis:
					ADD (adi��o, X + Y), SUB(subtra��o, X - Y),
					MPY(multiplica��o, X * Y) e DIV(divis�o, X/Y), onde Y � o 
					elemento no topo da pilha e X o elemento abaixo de Y.*/

/*Utilizando as defini��es acima, a sequ�ncia de instru��es a seguir foi implementada
para avaliar o resultado de uma express�o, sendo A, B, C, D e E os operandos desta express�o.
O resultado da avalia��o e acumulado em F.

PUSH A
PUSH B
SUB
PUSH C
PUSH D
PUSH E
MPY
ADD
DEC
DIV
POP F

Com base no que foi exposto acima, se A, B, C, D e E apresentarem, respectivamente, 
os valores 9, 3, 2, 1 e 1, qual o valor armazenado em F ap�s a execu��o da instru��o POP F ? */


//Nome: Darlan Freire Mendon�a da Silva - T:146
//Matr�cula: 2017102635

//Defini��o da Lista
typedef struct Estrutura{
	int valor;
	struct Estrutura *prox;
}LISTA;

//Fun��o para iniciar a pilha como vazia
void Inicia(LISTA** Pilha){
	*Pilha=NULL;
}										

//Empty verifica se a pilha est� ou n�o vazia
int Empty(LISTA *Pilha){
	return (Pilha==NULL);
}

//PUSH insere um novo inteiro na pilha
void Push(LISTA** Pilha, int num){
	LISTA *tmp; //Declara��o de um ponteiro tmp do tipo LISTA como auxiliar
	tmp = (LISTA*)malloc(sizeof(LISTA)); //Aloque(tmp)
	if (tmp==NULL) return; //Se tmp estiver vazio, retorne
	tmp->valor = num; //tmp.valor recebe num
	tmp->prox = *Pilha; //tmp.prox recebe o que est� em pilha
	*Pilha = tmp; //Pilha recebe o que est� em tmp;
}

//POP apaga o valor no top da pilha
int Pop(LISTA** Pilha){
	int num;
	LISTA *tmp = *Pilha; //tmp aponta para a pilha
	if(Empty(*Pilha)) //Se n�o existir elementos na pilha
		return;
	num = (*Pilha)->valor;
	*Pilha = (*Pilha)->prox; 
	return num;
	free(tmp);// Libera a mem�ria existente em tmp
	
}

//Imprime TODOS os elementos da pilha
void Print(LISTA *Pilha){
	if (Empty(Pilha))
		return; //N�o existe elementos
	printf("%d\n",Pilha->valor);
	Print(Pilha->prox);//Chamada recursiva para listar o prox
}

//DEC faz um decremento no topo da pilha
int DEC(LISTA *Pilha){
	if(Empty(Pilha))
		return -1; //N�o existe elementos
	return Pilha->valor--;
}
//SUB Subtra��o
int SUB(int a, int b)
{
	int resultado;
	resultado = b - a;
	return resultado;
}
//MPY Multiplica��o
int MPY(int a, int b)
{
	int resultado;
	resultado = a * b;
	return resultado;
}
//DIV Divis�o
int DIV(int a, int b)
{
	int resultado;
	resultado =  b / a;
	return resultado;
}
//ADD Adi��o
int ADD(int a, int b)
{
	int resultado;
	resultado = a + b;
	return resultado;
}
	
//In�cio
int main(void) {
	//Declara��o das vari�veis
	int x,y;
	LISTA *P;
	 
	Inicia(&P);//Inicia a pilha passando como par�metro o endere�o de P
	
	Push(&P,9); //Insere 9 na pilha
	Push(&P,3); //Insere 3 na pilha
	
	/*Antes de chamar a fun��o (SUB), eu retirei da pilha o �ltimo e pen�ltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da fun��o*/
	x = Pop(&P); //Remove 3 da pilha e coloca em x
	y = Pop(&P); //Remove 9 da pilha e coloca em y
	Push(&P, SUB(x,y)); //Insere na pilha o resultado da fun��o (SUB)
	Push(&P,2); //Insere 2 na pilha
	Push(&P,1);	//Insere 1 na pilha
	Push(&P,1);	//Insere 1 na pilha
	
	/*Antes de chamar a fun��o (MPY), eu retirei da pilha o �ltimo e pen�ltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da fun��o*/
	x = Pop(&P); //Remove 1 da pilha e coloca em x
	y = Pop(&P); //Remove 1 da pilha e coloca em y
	Push(&P, MPY(x,y)); //Insere na pilha o resultado da fun��o (MPY)
	
	/*Antes de chamar a fun��o (ADD), eu retirei da pilha o �ltimo e pen�ltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da fun��o*/
	x = Pop(&P); //Remove 1 da pilha e coloca em x
	y = Pop(&P); //Remove 2 da pilha e coloca em y
	Push(&P, ADD(x,y)); //Insere na pilha o resultado da fun��o (ADD)
	DEC(P); // Decremento do elemento no top da pilha
	
	/*Antes de chamar a fun��o (DIV), eu retirei da pilha o �ltimo e pen�ltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da fun��o*/
	x = Pop(&P); //Remove 2 da pilha e coloca em x
	y = Pop(&P); //Remove 6 da pilha e coloca em y
	Push(&P, DIV(x,y)); ////Insere na pilha o resultado da fun��o (DIV)
	
	Print(P); //Chamada a fun��o para imprimir TODOS os elementos da pilha
}//fim

//Resposta: Ao final da execu��o, a pilha ter� somente um elemento com valor 3!
