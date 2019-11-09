#include <stdio.h>
#include <stdlib.h>

//A tabela abaixo mostra as operações para a manipulação de uma pilha//

/*PUSH - Coloca um novo elemento no topo da pilha
  
  POP - Retira o elemento do topo da pilha
  
  Operação unária - Efetua a operação sobre o elemento do topo da pilha e substitui o elemento
                    do topo pelo resultado. Operações disponíveis: DEC(subtrai o valor 1 do elemento)
  
  Operação binária - Efetua a operação sobre os dois elemntos do topo da pilha;
                     retira os dois elementos do topo da pilha e coloca o 
					 resultado da operação no topo da pilha. 
					
					Operações disponíveis:
					ADD (adição, X + Y), SUB(subtração, X - Y),
					MPY(multiplicação, X * Y) e DIV(divisão, X/Y), onde Y é o 
					elemento no topo da pilha e X o elemento abaixo de Y.*/

/*Utilizando as definições acima, a sequência de instruções a seguir foi implementada
para avaliar o resultado de uma expressão, sendo A, B, C, D e E os operandos desta expressão.
O resultado da avaliação e acumulado em F.

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
os valores 9, 3, 2, 1 e 1, qual o valor armazenado em F após a execução da instrução POP F ? */


//Nome: Darlan Freire Mendonça da Silva - T:146
//Matrícula: 2017102635

//Definição da Lista
typedef struct Estrutura{
	int valor;
	struct Estrutura *prox;
}LISTA;

//Função para iniciar a pilha como vazia
void Inicia(LISTA** Pilha){
	*Pilha=NULL;
}										

//Empty verifica se a pilha está ou não vazia
int Empty(LISTA *Pilha){
	return (Pilha==NULL);
}

//PUSH insere um novo inteiro na pilha
void Push(LISTA** Pilha, int num){
	LISTA *tmp; //Declaração de um ponteiro tmp do tipo LISTA como auxiliar
	tmp = (LISTA*)malloc(sizeof(LISTA)); //Aloque(tmp)
	if (tmp==NULL) return; //Se tmp estiver vazio, retorne
	tmp->valor = num; //tmp.valor recebe num
	tmp->prox = *Pilha; //tmp.prox recebe o que está em pilha
	*Pilha = tmp; //Pilha recebe o que está em tmp;
}

//POP apaga o valor no top da pilha
int Pop(LISTA** Pilha){
	int num;
	LISTA *tmp = *Pilha; //tmp aponta para a pilha
	if(Empty(*Pilha)) //Se não existir elementos na pilha
		return;
	num = (*Pilha)->valor;
	*Pilha = (*Pilha)->prox; 
	return num;
	free(tmp);// Libera a memória existente em tmp
	
}

//Imprime TODOS os elementos da pilha
void Print(LISTA *Pilha){
	if (Empty(Pilha))
		return; //Não existe elementos
	printf("%d\n",Pilha->valor);
	Print(Pilha->prox);//Chamada recursiva para listar o prox
}

//DEC faz um decremento no topo da pilha
int DEC(LISTA *Pilha){
	if(Empty(Pilha))
		return -1; //Não existe elementos
	return Pilha->valor--;
}
//SUB Subtração
int SUB(int a, int b)
{
	int resultado;
	resultado = b - a;
	return resultado;
}
//MPY Multiplicação
int MPY(int a, int b)
{
	int resultado;
	resultado = a * b;
	return resultado;
}
//DIV Divisão
int DIV(int a, int b)
{
	int resultado;
	resultado =  b / a;
	return resultado;
}
//ADD Adição
int ADD(int a, int b)
{
	int resultado;
	resultado = a + b;
	return resultado;
}
	
//Início
int main(void) {
	//Declaração das variáveis
	int x,y;
	LISTA *P;
	 
	Inicia(&P);//Inicia a pilha passando como parâmetro o endereço de P
	
	Push(&P,9); //Insere 9 na pilha
	Push(&P,3); //Insere 3 na pilha
	
	/*Antes de chamar a função (SUB), eu retirei da pilha o último e penúltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da função*/
	x = Pop(&P); //Remove 3 da pilha e coloca em x
	y = Pop(&P); //Remove 9 da pilha e coloca em y
	Push(&P, SUB(x,y)); //Insere na pilha o resultado da função (SUB)
	Push(&P,2); //Insere 2 na pilha
	Push(&P,1);	//Insere 1 na pilha
	Push(&P,1);	//Insere 1 na pilha
	
	/*Antes de chamar a função (MPY), eu retirei da pilha o último e penúltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da função*/
	x = Pop(&P); //Remove 1 da pilha e coloca em x
	y = Pop(&P); //Remove 1 da pilha e coloca em y
	Push(&P, MPY(x,y)); //Insere na pilha o resultado da função (MPY)
	
	/*Antes de chamar a função (ADD), eu retirei da pilha o último e penúltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da função*/
	x = Pop(&P); //Remove 1 da pilha e coloca em x
	y = Pop(&P); //Remove 2 da pilha e coloca em y
	Push(&P, ADD(x,y)); //Insere na pilha o resultado da função (ADD)
	DEC(P); // Decremento do elemento no top da pilha
	
	/*Antes de chamar a função (DIV), eu retirei da pilha o último e penúltimo elemento, 
	para DEPOIS inserir no topo da pilha o resultado da função*/
	x = Pop(&P); //Remove 2 da pilha e coloca em x
	y = Pop(&P); //Remove 6 da pilha e coloca em y
	Push(&P, DIV(x,y)); ////Insere na pilha o resultado da função (DIV)
	
	Print(P); //Chamada a função para imprimir TODOS os elementos da pilha
}//fim

//Resposta: Ao final da execução, a pilha terá somente um elemento com valor 3!
