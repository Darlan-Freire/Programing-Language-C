#include <stdio.h>
#include <stdlib.h>

int main()
{
    
	float x,y,p_compra,p_venda,lucro=0,lucro_total=0,total_compra=0,total_venda=0,lucro_custo,lucro_venda;
    char nome_merc[20],opcao;
		printf("\n\t   BEM-VINDO!");
	do{printf("\n\tMENU DO CLIENTE\n\nAdicionar Mercadoria:[A]\n\nSair/Lucro Total:[S] ");
	scanf("%c",&opcao);
	fflush(stdin);
		switch(opcao){
			case 'A':
			case 'a':
			
			printf("\nNome da mercadoria: ");
    		scanf("%s",&nome_merc);
    		printf("Preco de compra: ");
    		scanf("%f",&p_compra);
    		printf("Preco de venda: ");
    		scanf("%f",&p_venda);
			system("cls");
			
			total_compra+= p_compra;
			total_venda+= p_venda;
			lucro=p_venda-p_compra;
			x=(lucro*100)/p_compra;
			lucro_total+= lucro;
			
			
			
			fflush(stdin);
			
			if(x<=10){
				printf("Nome da Mercadoria: %s\nLucro de venda: %2.1f\nObteve um lucro de %2.1f%%\n",nome_merc,lucro,x);
				printf("LUCRO MENOR OU IGUAL A 10%%\n");
			}else
			if(x<=20){
				printf("Nome da Mercadoria: %s\nLucro de venda: %2.1f\nObteve um lucro de %2.1f%%\n",nome_merc,lucro,x);
				printf("LUCRO MENOR OU IGUAL A 20%%\n");
			}else{
				printf("Nome da Mercadoria: %s\nLucro de venda: %2.1f\nObteve um lucro de %2.1f%%\n",nome_merc,lucro,x);
				printf("LUCRO MAIOR QUE 20%%\n");}
				break;
			case 'S':
			case 's':
				printf("\nTotal de compra: %2.1f\nTotal de Vendas: %2.1f\nLucro Total: %2.1f\n\n\tVolte Sempre!\n\n",total_compra,total_venda,lucro_total); break;
			default:puts("\nOpcao Invalida. Tente novamente!\n");}
}while(opcao!= 'S' && opcao!= 's');		
	system ("pause");
}
