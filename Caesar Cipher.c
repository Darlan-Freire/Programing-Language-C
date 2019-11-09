#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000

void decifraCesar(char arqout[], int k){
	
	int i, ch, aux;
	char texto[TAM];
	FILE *file;
	
	file = fopen(arqout, "r");		if (file == NULL){ printf ("\nArquivo nao encontrado\n"); } 
	
	fread(&texto, TAM, 1, file);		fclose(file);
	
	for(i=0; texto[i] != '\0'; i++){
		ch = texto[i];
		
		if(ch >= 'a' && ch <= 'z'){
   	    	ch = ch - k;
   	    	
   	        while(ch < 'a'){
		       	ch = ch + 26;
			}
			
			texto[i] = ch;
    	    }
		if(ch >= 'A' && ch <= 'Z'){
            ch = ch - k;
				        
			while(ch < 'A'){
           		ch = ch + 26;
			}
			
			texto[i] = ch;
		}
		texto[i] = ch;	
	}
	printf ("Texto decriptografado (Key - %i): \n\n%s\n", k, texto);
}

void cifraCesar(char arqin[], char arqout[], int k){
	
	int ch, i, aux;
	char texto[TAM];
	FILE *file;
	
	printf ("\nDigite a frase que deseja criptografar\nFrase: ");		gets(texto);			fflush(stdin);
	printf ("\n\n----Dados----\nFrase normal: %s | Frase cifrada: %s \nKey: %i | Frase: %s\n", arqin, arqout, k, texto);
	
	file = fopen (arqin, "w+");	if (file == NULL) { printf ("Erro na criação do arquivo"); }
	fprintf (file, "%s", texto);	fclose(file);	
	
	for(i=0; texto[i] != '\0'; i++){
		ch = texto[i];
		
		if(ch >= 'a' && ch <= 'z'){
            ch = ch + k;
            
            while(ch > 'z'){
            	ch = ch - 26;
			}
			
            texto[i] = ch;
        }
		if(ch >= 'A' && ch <= 'Z'){
            ch = ch + k;
            
            while(ch > 'Z'){
            	ch = ch - 26;
			}
			
            texto[i] = ch;
        }
        texto[i] = ch;
	}
	
	printf ("\nTexto cifrado: %s", texto);
	file = fopen(arqout, "w+");	if (file == NULL) { printf ("Erro na criação do arquivo"); }
	fprintf (file, "%s", texto);	fclose(file);
	
}

main(){
	
	char arqin[TAM], arqout[TAM];
	int key, opcao;
	
	do {
		printf ("-- MENU --\n\n");
		printf ("1 - Cifrar\n");
		printf ("2 - Decifrar\n");
		printf ("0 - Sair\n");
		printf ("\nDigite sua opcao: ");
       	scanf ("%i", &opcao);		fflush(stdin);

   		switch (opcao){
    		case 1:
    			printf ("-------------------------------------------------\n");
    			printf ("Digite o nome e extensao do arquivo onde sera escrito o texto normal\nExemplo 'Arquivo.txt'\nNome: ");
    			gets(arqin);			fflush(stdin);
    			printf ("\nDigite o nome do arquivo onde sera escrito o texto cifrado\nExemplo 'Arquivo.txt'\nNome: ");
    			gets(arqout);			fflush(stdin);
    			printf ("\nDigite um valor para a chave da criptografia\nKey: ");
				scanf ("%i", &key);		fflush(stdin);
				
				cifraCesar(arqin, arqout, key);
				
				printf ("\n\n\n\tTexto criptografado com sucesso!\n");
				printf ("-------------------------------------------------\n");
				
				break;
				
			case 2:
				printf ("-------------------------------------------------\n");
				printf ("Digite o nome do arquivo onde se encontra texto cifrado: ");
    			gets(arqout);			fflush(stdin);
				printf ("Digite o valor da chave para a descriptografia: ");
				scanf ("%i", &key);		fflush(stdin);
				
				decifraCesar(arqout, key);
				
				printf ("-------------------------------------------------\n");
				break;
				
			case 0:
				printf ("\nObrigado pela preferencia. Ate mais.\n");
				printf ("------------------------------------\n\n");
				system("pause");
				exit(0);
				
			default:
				printf ("\nOpcao invalida, tente novamente\n\n");		
		}
	} while(opcao);
}
