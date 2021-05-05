// 1 - Escreva uma rotina que retorne o número de vezes que um determinado elemento ocorre
// numa lista circular simplesmente encadeada.
// #include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
int Mostra_lista (no end) {
	int cont=0;
	if(end==NULL) {
		printf("\nLISTA VAZIA\n");
		return 0;
	}
	no p = end;
	do {
		printf("%d ", p->info);
		p = p->prox;
		cont++;
	} while(p != end);
	return cont;
}
void Insere_inicio (int info, no *end) {
	no p = (no) malloc (sizeof(reg));
	p->info = info;
	if(!*end) {
		p->prox = p;
		*end = p;
		return;
	}
	no q = *end;
	while(q->prox != *end) q = q->prox;
	q->prox = p;
	p->prox = *end;
	*end = p;
}
int main() {
	int info,i=1;
	char resp;
	no end = NULL;
	do {
		printf("[%d] = ",i);
		scanf("%d",&info);
		Insere_inicio(info,&end);
		printf("\nNUMERO DE ELEMENTOS = %d\n",Mostra_lista(end));
		do {
			printf("\ndeseja continuar??(S/N)\n");
			resp = toupper(getch());
		} while(resp!='S'&&resp!='N');
		i++;
	} while(resp!='N');	
}

// 3 - Escreva uma rotina para excluir todos os nós de uma lista circular simplesmente encadeada.
// #include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Mostra_lista (no end) {
	if(end==NULL) {
		printf("\nLISTA VAZIA\n");
		return;
	}
	no p = end;
	do {
		printf("%d ", p->info);
		p = p->prox;
	} while(p != end);
}
void Insere_inicio (int info, no *end) {
	no p = (no) malloc (sizeof(reg));
	p->info = info;
	if(!*end) {
		p->prox = p;
		*end = p;
		return;
	}
	no q = *end;
	while(q->prox != *end) q = q->prox;
	q->prox = p;
	p->prox = *end;
	*end = p;
}
void Excluir_tudo(no *end) {
	no p = *end, r;
	if(*end == NULL) return;
	while(1) {
		r = p;
		p = p->prox;
		r->prox = p->prox;
		free(p);
		p = r;
		if(p->prox == *end) {
			free(p);
			*end = NULL;
			return;			
		} 
	}
}
int main() {
	int info,i=1;
	char resp;
	no end = NULL;
	do {
		printf("[%d] = ",i);
		scanf("%d",&info);
		Insere_inicio(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar??(S/N)\n");
			resp = toupper(getch());
		} while(resp!='S'&&resp!='N');
		i++;
	} while(resp!='N');
	Excluir_tudo(&end);
	Mostra_lista(end);
}

// 5 - Desenvolva uma rotina que remova de uma lista circular ordenada todas as ocorrências de
// um determinado elemento.
// #include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Mostra_lista (no end) {
	if(end==NULL) {
		printf("\nLISTA VAZIA\n");
		return;
	}
	no p = end;
	do {
		printf("%d ", p->info);
		p = p->prox;
	} while(p != end);
}
void Insere_inicio (int info, no *end) {
	no p = (no) malloc (sizeof(reg));
	p->info = info;
	if(!*end) {
		p->prox = p;
		*end = p;
		return;
	}
	no q = *end;
	while(q->prox != *end) q = q->prox;
	q->prox = p;
	p->prox = *end;
	*end = p;
}
void Excluir_todos(int info, no *end) {
	if(*end == NULL) return;
	if((*end)->prox == *end && (*end)->info == info) {
		free(*end);
		*end = NULL;
		return;
	}
	int achou=1;
	while(achou!=0) {
		no p  = *end, r;
		do {
			r = p;
			p = p->prox;
		} while(p->prox != *end && p->info != info);
			if (info==p->info && p->prox!= *end){
				r->prox = p->prox;
				free(p);
				achou=1;
			} else if (info==p->info && p->prox==*end){
				r->prox = p->prox;
				free(p);
				*end = r;
				achou=1;
			} else achou = 0;
		}
	}
int main() {
	int info,i=1;
	char resp;
	no end = NULL;
	do {
		printf("[%d] = ",i);
		scanf("%d",&info);
		Insere_inicio(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar??(S/N)\n");
			resp = toupper(getch());
		} while(resp!='S'&&resp!='N');
		i++;
	} while(resp!='N');
	do {
		printf("\n\t digite elemento a ser excluido: ");
		scanf("%d",&info);
		Excluir_todos(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja excluir??(S/N)\n");
			resp = toupper(getch());
		} while(resp!='S'&&resp!='N');
	} while(resp!='N');	
}

// 7 - Escreva uma rotina que informe se as duas listas circulares encadeadas são idênticas.
// #include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
int Mostra_lista (no end) {
	int cont=0;
	if(end==NULL){
		printf("\nLISTA VAZIA\n");
		return cont;
	}
	no p = end;
	do {
		printf("%d ", p->info);
		p = p->prox;
		cont++;
	} while(p != end);
	return cont;
}
void Insere_inicio (int info, no *end) {
	no p = (no) malloc (sizeof(reg));
	p->info = info;
	if(!*end) {
		p->prox = p;
		*end = p;
		return;
	}
	no q = *end;
	while(q->prox != *end) q = q->prox;
	q->prox = p;
	p->prox = *end;
	*end = p;
}
int Confere_listas(no end1, no end2) {
	no p = end1 , q = end2;
	while(p->prox != end1) {
		if(p->info != q->info) return 1;
		q = q->prox;
		p = p->prox;
	}	
}
int main() {
	int info,i=1,cont1=0,cont2=0;
	char resp;
	no end1 = NULL, end2 = NULL;
	//lista 1
	do {
		printf("lista_1[%d] = ",i);
		scanf("%d",&info);
		Insere_inicio(info,&end1);
		cont1 = Mostra_lista(end1);
		do {
			printf("\ndeseja continuar??(S/N)\n");
			resp = toupper(getch());
		} while(resp!='S'&&resp!='N');
		i++;
	} while(resp!='N');
	i=1;
	//lista 2
	do {
		printf("lista_2[%d] = ",i);
		scanf("%d",&info);
		Insere_inicio(info,&end2);
		cont2 = Mostra_lista(end2);
		do {
			printf("\ndeseja continuar??(S/N)\n");
			resp = toupper(getch());
		} while(resp!='S'&&resp!='N');
		i++;
	} while(resp!='N');	
	if(cont1!=cont2) {
		printf("LISTAS SAO DIFERENTES");
		exit(1);
	}
	if(Confere_listas(end1,end2)==1) printf("LISTAS SAO DIFERENTES");
	else printf("LISTAS SAO IGUAIS");
}

// 9 - Escreva um rotina que faça uma cópia de uma lista circular encadeada, eliminando os ele-
// mentos repetidos.
// #include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Mostra_lista (no end) {
	if(end==NULL) printf("\nLISTA VAZIA\n");
	no p = end;
	do {
		printf("%d ", p->info);
		p = p->prox;
	} while(p != end);
}
void Insere_inicio (int info, no *end) {
	no p = (no) malloc (sizeof(reg));
	p->info = info;
	if(!*end) {
		p->prox = p;
		*end = p;
		return;
	}
	no q = *end;
	while(q->prox != *end) q = q->prox;
	q->prox = p;
	p->prox = *end;
	*end = p;
}
void Copia_lista(no end) {
	no end2 = NULL;
	no p = end, r;
	int achou;
	if(end == end->prox) {
		Insere_inicio(p->info, &end2);	
		Mostra_lista(end2);
		return;
	}	
	while(p->prox != end) {
		achou = 0;
		while(r != end && achou != 1) {
			r = p;
			r = r->prox;
			if(r->info == p->info) achou = 1;
			else r = r->prox;
		}
		if (achou == 0) Insere_inicio(p->info, &end2);	
		p = p->prox;
	}
	Mostra_lista(end2);
}
int main() {
	int info,i=1;
	char resp;
	no end = NULL;
	do {
		printf("[%d] = ",i);
		scanf("%d",&info);
		Insere_inicio(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar??(S/N)\n");
			resp = toupper(getch());
		} while(resp!='S'&&resp!='N');
		i++;
	} while(resp!='N');
	Copia_lista(end);
	printf("\n");	
	Mostra_lista(end);
	getch();
}