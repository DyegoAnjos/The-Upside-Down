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
		printf("Posi��o X:%d", pessoa[resultado].posicao[0]);
		printf("\nPosi��o Y:%d", pessoa[resultado].posicaoEspelho);
		linha();
		
//		fprintf(arq, "\nPessoa:%s\nPosi��o X:%d\nPosi��o Y:%d\nPosi��o Invertida\nMundo:", variav�l);
	}
	fclose(arq);
		
	getch();
	return(0);
}


