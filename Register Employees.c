/*	CENTRO UNIVERSITARIO CARIOCA - UNICARIOCA
	ATIVIDADE PRÁTICA SUPERVISIONADA - Programação Estruturada	
	DARLAN FREIRE MENDONÇA DA SILVA			Matrícula.: 2017102635				*/
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEMP 70
#define CARG 20
#define NOM 40

//_________________________________Estrutura Cadastro____________________________//

struct endereco{
	char end[TEMP];
	char numero[TEMP];
	char bairro[TEMP];
	char cidade[TEMP];
	char estado[TEMP];
	char cep[TEMP];
};

struct funcionario{
    int codigo;
    char nome[40];
    char cargo[20];
    float sal;
    char tel[TEMP];
    char status[TEMP];
   	struct endereco casa;
};

float desconto(float sal){
	float INSS=sal*0.11;
	float VT=sal*0.06;
	float salfim=sal-VT-INSS;
	return salfim;
}

int cadastrar(void){
	struct funcionario lista;
 	getchar();
 	system("cls");
    printf("\n----------------------Adicionar Funcionario----------------------------\n\n");
     
   	printf("Nome:"); fgets(lista.nome,NOM,stdin);
    printf("Codigo:"); scanf("%d",&lista.codigo,stdin); getchar();
    printf("Cargo:"); fgets(lista.cargo,CARG,stdin);
    printf("Salario:"); scanf("%f",&lista.sal,stdin); getchar();
    printf("Telefone:"); fgets(lista.tel,TEMP,stdin);
    printf("Endereco:"); fgets(lista.casa.end,TEMP,stdin);
    printf("Numero:"); fgets(lista.casa.numero,TEMP,stdin);  
    printf("Bairro:"); fgets(lista.casa.bairro,TEMP,stdin); 
	printf("Cidade:"); fgets(lista.casa.cidade,TEMP,stdin);
	printf("Estado:"); fgets(lista.casa.estado,TEMP,stdin);
	printf("Cep:"); fgets(lista.casa.cep,TEMP,stdin);
	printf("Status:"); fgets(lista.status,TEMP,stdin);
	
	FILE *file;
    file=fopen("arquivo.dat","a");
    if(buscar(lista.codigo)==1){
    	return 1;
	}
	else{
    	fwrite (&lista, sizeof(struct funcionario), 1, file);
    	fclose (file);
    	return 0;
	}
	
}

int buscar(int codigo){
	int i=0, v[100];
    
	FILE *file;
    file=fopen("arquivo.dat", "r");
    
	if(!file)
        return 1;
    else{
    	struct funcionario l;
        while (fread(&l, sizeof(struct funcionario), 1, file)){
		 	 v[i]=l.codigo;
		 	 i++;
        }
        fclose(file);
    }
		for(i=0;i<100;i++){
			if(v[i]==codigo){
				printf("\nCODIGO JA CADASTRADO!!!\n\n");
				return 1;
			}	
		}	
	return 0;
}

int exibir(void){  
	FILE *file;
    file=fopen ("arquivo.dat", "r");
    if(!file)
    	return 1;
    else{
    	struct funcionario l;
       	system("cls");
		printf("\nFuncionarios Cadastrados\n\n");
        printf("\n----------------------------------------------------------\n\n");
     
     while(fread(&l,sizeof(struct funcionario),1, file)){ 
    	printf("Nome: %s",l.nome);
    	printf("Codigo: %d\n",l.codigo);
    	printf("Cargo: %s",l.cargo);
    	printf("Salario: R$ %.2f\n",l.sal);
    	printf("Telefone: %s",l.tel);
    	printf("Endereco: %s",l.casa.end);
    	printf("Numero: %s",l.casa.numero);   
    	printf("Bairro: %s",l.casa.bairro);   
		printf("Cidade: %s",l.casa.cidade);
		printf("Estado: %s",l.casa.estado);
		printf("Cep: %s",l.casa.cep);
		printf("Status: %s\n",l.status);
		
		float salfin = desconto(l.sal);
     	printf("Salario com Descontos: R$ %.2f\n\n",salfin);
     	printf("\n----------------------------------------------------------\n\n");
     }
     fclose(file);
	}
	return 0;
}

//___________________________________________MAIN_________________________________________//
main(void){
	int opcao;
    
	while (1){
	do{
        	system("cls");
            printf("\nMenu Principal\n");
			printf("\n[1] Cadastrar funcionario");
            printf("\n[2] Exibir lista de funcionarios cadastrados");
            printf("\n[3] Sair");
            printf("\n\nDigite sua opcao: ");
            scanf("%i", &opcao);
            
    }while((opcao<1) && (opcao>3));
    
    switch(opcao){
            case 1:
                if(cadastrar()==0)
                	printf("\nFuncionario cadastrado!\n\n");
                	system("pause");
                	break; 
            case 2:
            	if(exibir()==1)
            		printf("\nErro ao abrir o arquivo!\n");
                	system("pause");
            		break;
            case 3:
            	exit(0);
		}
	}
}
