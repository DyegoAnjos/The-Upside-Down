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
	
	arq = fopen("Hist�rico.txt", "a+");
	setlocale(LC_ALL, "Portuguese");
	printf("::::::::::Localizador do Mundo Invertido::::::::::");
	for(i=0;i<50;i++){
		printf("\nDigite o nome da pessoa:");
		scanf("%s", &pessoa[i].nome);
		
		printf("\nDigite a posi��o X:");
		scanf("%d", &pessoa[i].posicao[0]);
		
		printf("\nDigite a posi��o Y:");
		scanf("%d", &pessoa[i].posicao[1]);
		
		printf("\nDeseja continuar? S/N");
		escolha = toupper(getche());
		if (escolha == 'N') break;
	}
	system("cls");
	
	for(int resultado=0;resultado<=i;resultado++){
		printf("\nPessoa:%s", pessoa[resultado].nome);
		printf("\nPosi��o X:%d", pessoa[resultado].posicao[0]);
		printf("\nPosi��o Y:%d", pessoa[resultado].posicao[1]);
		if (pessoa[resultado].posicao[1]<0)
			printf("\n--Mundo Invertido--");
		else if (pessoa[resultado].posicao[1]==0)
			printf("Ponto de interce��o (Est� em ambas as partes)");
			
		pessoa[resultado].posicaoEspelho=pessoa[resultado].posicao[1]*-1;
		printf("\n::::::::::Ponto Espelhado::::::::::\n");
		printf("Posi��o X:%d", pessoa[resultado].posicao[0]);
		printf("\nPosi��o Y:%d", pessoa[resultado].posicaoEspelho);
		linha();
		fprintf(arq, "\nNome:%s\nPosi��o X:%d\nPosi��o Y:%d\nPosi��o Y espelhada:%d\n", pessoa[resultado].nome, pessoa[resultado].posicao[0], pessoa[resultado].posicao[1], pessoa[resultado].posicaoEspelho);
	}
	fclose(arq);
		
	getch();
	return(0);
}
