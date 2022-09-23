#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int linha(){
	printf("\n------------------------------");
}

int main(){
	struct tpessoa{
		char nome[50];
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
		if (pessoa[resultado].posicao[1]<0)
			printf("\n--Mundo Invertido--");
		else if (pessoa[resultado].posicao[1]==0)
			printf("Ponto de interceção (Está em ambas as partes)");
			
		pessoa[resultado].posicaoEspelho=pessoa[resultado].posicao[1]*-1;
		printf("\n::::::::::Ponto Espelhado::::::::::\n");
		printf("Posição X:%d", pessoa[resultado].posicao[0]);
		printf("\nPosição Y:%d", pessoa[resultado].posicaoEspelho);
		linha();
		fprintf(arq, "\nNome:%s\nPosição X:%d\nPosição Y:%d\nPosição Y espelhada:%d\n", pessoa[resultado].nome, pessoa[resultado].posicao[0], pessoa[resultado].posicao[1], pessoa[resultado].posicaoEspelho);
	}
	fclose(arq);
		
	getch();
	return(0);
}
