#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

int linha(){
	printf("\n------------------------------");
}

bool mundo(int p){
	if (p<0)
			return true;
	
	else (p>0)
		return false;
			
}

int main(){
	struct tpessoa{
		char nome[50], mundo[50];
		int posicao[1], posicaoEspelho;
	}; struct tpessoa pessoa[50];
	
	int i=0;
	char escolha;
	FILE *arq;
	
	arq = fopen("Histórico.txt", "a+");
	setlocale(LC_ALL, "Portuguese");
	printf("::::::::::Localizador do Mundo Invertido::::::::::");
	for(i=0;i<50;i++){
		printf("\nDigite o nome da pessoa:");
		scanf("%s", &pessoa[i].nome);
		
		printf("\nDigite a posição X:");
		scanf("%d", &pessoa[i].posicao[0]);
		
		printf("\nDigite a posição Y:");
		scanf("%d", &pessoa[i].posicao[1]);
		
		printf("\nDeseja continuar? S/N");
		escolha = toupper(getche());
		if (escolha == 'N') break;
	}
	system("cls");
	
	for(int resultado=0;resultado<=i;resultado++){
		printf("\nPessoa:%s", pessoa[resultado].nome);
		printf("\nPosição X:%d", pessoa[resultado].posicao[0]);
		printf("\nPosição Y:%d", pessoa[resultado].posicao[1]);
		if (pessoa[resultado].posicao[1]==0)
			strcpy (pessoa[resultado].mundo, "Em ambos dos Mundos");
		
		else{
			if  (mundo(pessoa[resultado].posicao[1])==true)
				strcpy (pessoa[resultado].mundo, "Mundo invertido");
			
			else
				strcpy (pessoa[resultado].mundo, "Mundo normal");
		}
		
			
		
		pessoa[resultado].posicaoEspelho=pessoa[resultado].posicao[1]*-1;
		printf("\n::::::::::Ponto Espelhado::::::::::\n");
		printf("Posição X:%d", pessoa[resultado].posicao[0]);
		printf("\nPosição Y:%d", pessoa[resultado].posicaoEspelho);
		linha();
		
//		fprintf(arq, "\nPessoa:%s\nPosição X:%d\nPosição Y:%d\nPosição Invertida\nMundo:", variavél);
	}
	fclose(arq);
		
	getch();
	return(0);
}


