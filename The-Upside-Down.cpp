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
		int posicao[1], posicaoEspelho,mundo=-1;
	}; struct tpessoa pessoa[50];
	
	int i=0, menu=0;
	int resultado=0;
	char escolha;
	FILE *arq;
	
	while(1){
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	arq = fopen("Histórico.txt", "a+");
	
	printf("::::::::::Localizador do Mundo Invertido::::::::::");
	printf("\nLocalizar(1)\nLista dos cadastros (2)\nVer histórico(3)\nImprimir no cartesiano(4)\nSair(0)\n");
	scanf("%d", &menu);
	
	switch (menu){
		case 0:{
			return(0);
		break;}
		case 1:{
			for(i=0;i<50;i++){
				printf("\nDigite o nome da pessoa:");
				scanf("%s", &pessoa[i].nome);
				
				printf("\nDigite a posição X:");
				scanf("%d", &pessoa[i].posicao[0]);
				
				printf("\nDigite a posição Y:");
				scanf("%d", &pessoa[i].posicao[1]);
				
				if (pessoa[i].posicao[1]<0)
					pessoa[i].mundo=-1;
				
				else if (pessoa[i].posicao[1]==0)
					pessoa[i].mundo=0;
				
				else
					pessoa[i].mundo=1;
					
				pessoa[i].posicaoEspelho=pessoa[i].posicao[1];
				pessoa[i].posicaoEspelho*=-1;
					
				printf("\nDeseja continuar? S/N");
				escolha = toupper(getche());
				if (escolha == 'N') break;
			}
		break;}
		
		case 2:{
			for(resultado=i;resultado>=i;resultado--){
				printf("\nPessoa:%s", pessoa[resultado].nome);
				printf("\nPosição X:%d", pessoa[resultado].posicao[0]);
				printf("\nPosição Y:%d", pessoa[resultado].posicao[1]);
				if (pessoa[resultado].mundo == -1)
					printf("\n--Mundo Invertido--");
				
				else if (pessoa[resultado].mundo == 0)
					printf("\n--Ponto de interceção (Está em ambas as partes)--");
				
				else
					printf("\n--Mundo Normal--");
				
				printf("\n::::::::::Ponto Espelhado::::::::::\n");
				printf("Posição X:%d", pessoa[resultado].posicao[0]);
				printf("\nPosição Y:%d", pessoa[resultado].posicaoEspelho);
				linha();
				system("pause");
			}
		break;}
		
		case 3:{
			arq = fopen("Histórico.txt", "r");
			while(1){
				i++;
				fread(&pessoa,sizeof(struct tpessoa),1,arq);
				printf("\nPessoa:%s", pessoa[i].nome);
				printf("\nPosição X:%d", pessoa[i].posicao[0]);
				printf("\nPosição Y:%d", pessoa[i].posicao[1]);
				if (pessoa[i].posicao[1]<0){
					printf("\n--Mundo Invertido--");
				}
				
				else if (pessoa[i].posicao[1]==0){
					printf("\n--Ponto de interceção (Está em ambas as partes)--");
				}
				
				else{
					printf("\n--Mundo Normal--");
					
				}				
				printf("\n::::::::::Ponto Espelhado::::::::::\n");
				printf("Posição X:%d", pessoa[i].posicao[0]);
				printf("\nPosição Y:%d", pessoa[i].posicaoEspelho);
				system("pause");
			}
		break;}
	}
	
	}
	fclose(arq);
		
	getch();
}


