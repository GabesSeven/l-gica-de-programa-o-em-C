#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
//---------------
typedef struct reg *no;
typedef struct reg{
 	char info[31];
	reg *prox, *ant;
};
//
void Mostra_lista (no end){
	no p = end;
	int quant = 1;
	if(!end) return;
	while(p){
		printf("%d: %s\n", quant, p->info);
		p = p->prox;
		quant++;
	}
	//
}
//
void Insere_linha (char info[], no *end){
	no p = (no) malloc(sizeof(reg));
	strcpy(p->info , info);
	if(!*end){
		p->prox = p->ant = NULL;
		*end = p;
		return;
	}
	no q = *end;
	while(q->prox) q = q->prox;
	q->prox = p;
	p->prox = NULL;
	p->ant = q;
}
//
void Exclui_linha(int num, no *end){
	no p = *end;
	int achou=0, num2=1;
	if(!*end){
		printf("\nNAO HA LINHA PARA EXCLUIR\naperte qualquer tecla para continuar");
		getch();
		return;
	}
	//
	while(p->prox && num2 != num){
		p = p->prox;
		num2++;
	}
	if(num==num2) achou=1;
	//
	if(achou==0){
		printf("\nNAO FOI POSSIVEL ENCONTRAR LINHA\naperte qualquer tecla para continuar");
		getch();
		return;
	}
	else {
		if((*end)->prox == NULL){
			free(p);
			(*end) = NULL;
			return;
		}
		if(p->ant == NULL && p == *end){
			(*end) = p->prox;
			p->prox->ant = *end;
			free(p);
			(*end)->ant = NULL;
		} else if(p->prox != NULL && p != *end){
			p->ant->prox = p->prox;
			p->prox->ant = p->ant;
			free(p);
		} else if(p->prox == NULL && p != *end){
			p->ant->prox = NULL;
			free(p);
		}
	}
}
//
void Altera_linha (int num,char info[], no *end){
	no p = *end;
	int achou=0, num2=1;
	if(!*end){
		printf("\nNAO HA LINHA PARA ALTERAR\naperte qualquer tecla para continuar");
		getch();
		return;
	}
	//
	while(p->prox && num2 != num){
		p = p->prox;
		num2++;
	}
	if(num==num2) achou=1;
	//
	if(achou==0){
		printf("\nNAO FOI POSSIVEL ENCONTRAR LINHA\naperte qualquer tecla para continuar");
		getch();
		return;
	}
	else strcpy(p->info,info);
}
//
int main(){
	int num, ver;
	char resp, info[31];
	no end = NULL;
	//
	printf("BEM VINDO AO EDITOR DE TEXTO\n\naperte qualquer tecla para continuar...\n");
	getch();
	while(1){
		system("cls");
		Mostra_lista(end);
		printf("\n\nTECLE...\n(1) - para inserir linha\n(2) - para excluir linha\n(3) - para alterar linha\n(4) - para sair\n\n\nOBS: LIMITE DE CARACTERES POR LINHA SAO DE 100 CARACTERES");
		resp = getch();
		system("cls");
		//
		if(resp=='1'){
			Mostra_lista(end);
			fflush(stdin);
			printf("\n\ndigite a frase da linha:\n");
			gets(info);
			ver = strlen(info);
			if(ver>30){
				printf("\n\nlimite de caracteres excedido\n\n...aperte qualquer tecla para continuar");
				getch();
			}else Insere_linha (info, &end);				
		}else if(resp=='2'){
			Mostra_lista(end);
			printf("\n\ndigite a linha que deseja ser removida:\n");
			scanf("%d", &num);
			Exclui_linha (num, &end);
		}else if(resp=='3'){
			Mostra_lista(end);
			printf("\n\ndigite o numero da linha que deseja ser alterada:\n");
			scanf("%d",&num);
			fflush(stdin);
			printf("\ndigite a frase da linha:\n");
			gets(info);
			Altera_linha (num,info,&end);
		}else if(resp=='4') exit(1);
	}
}