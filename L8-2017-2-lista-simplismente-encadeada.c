// 7 - Escreva uma rotina que retorne o número de elementos de uma lista linear simplesmente
// encadeada.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Insere(int info, no *end) {
	no p = (no) malloc(sizeof(reg));
	p->info = info;
	p->prox = *end;
	*end = p;
}
int Conta_lista(no end) {
	int cont=0;
	no p = end;
	while(p) {
		cont++;
		p = p->prox;
	}
	return cont;
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		system("cls");
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		do {
			system("cls");
			printf("deseja continuar(S/N)?\n\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	system("cls");
	printf("------ %d elementos nesta lista",Conta_lista(end));
}


// 9 - Escreva uma rotina que retorne o conteúdo do último nó de uma lista linear simplesmente
// encadeada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
int final_lista(no end) {
	no p = end; 
	while(p->prox){
		p = p->prox;
	}
	return p->info;
};
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	p->info = info;
	p->prox = *end;
	*end = p;
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		system("cls");
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		do {
			system("cls");
			printf("deseja continuar(S/N)?\n\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	system("cls");
	printf("------ %d e o ultimo elementos nesta lista",final_lista(end));
}

// 11 - Escreva uma rotina que retorne o número de vezes que um determinado elemento ocorre
// numa lista linear simplesmente encadeada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Cont(no end) {
	no p = end;
	no q = end;
	int cont=0; 
	while(p) {
		while(q) {
			if(p->info == q->info){
				cont++;
			}	
			q = q->prox;
		}
		printf("%d aparece %d vezes\n",p->info,cont);
		cont=0;
		p = p->prox;
		q = end;
	}
}
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	p->info = info;
	p->prox = *end;
	*end = p;
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		system("cls");
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		do {
			system("cls");
			printf("deseja continuar(S/N)?\n\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	system("cls");
	Cont(end);
}

// 13 - Escreva uma rotina para inserir um elemento no final de uma lista linear simplesmente encadeada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
//
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	if((*end)==NULL){
		p->info = info;
		p->prox = NULL;
		(*end) = p;
	} else {
		  no q = *end;
		  while(q->prox) 
		  	q = q->prox;
		  p->info = info;
		  p->prox = NULL;
		  q->prox = p;
	}
}
void Mostra_lista(no end) {
	no p = end;
	while(p) {
		printf("%d\t",p->info);
		p = p->prox;
	}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		system("cls");
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		do {
			system("cls");
			printf("deseja continuar(S/N)?\n\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	system("cls");
	Mostra_lista(end);
}

// 15 - Escreva uma rotina para inserir um elemento antes do n-ésimo elemento de uma lista linear
// simplesmente encadeada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	p->info = info;
	p->prox = *end;
	*end = p;	
}
int Mostra_lista(no end) {
	int cont=0;
	no p = end;
	while(p) {
		cont++;
		printf("%d\t",p->info);
		p = p->prox;
	}
	return cont;
}
void Nv_elemnt(int info, no *end) {
	no p = (no) malloc(sizeof(reg));
	if((*end)->prox==NULL) {
		p->info = info;
		p->prox = *end;
		*end = p;
	} else {
		no q = *end,r = *end;
		q = q->prox;
		while(q->prox) {
			r = q;
			q = q->prox;
		}
		p->info = info;
		p->prox = q;
		r->prox = p;
	}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		system("cls");
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		do {
			system("cls");
			printf("deseja continuar(S/N)?\n\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	system("cls");
	printf("\n\nexistem %d elementos",Mostra_lista(end));
	printf("insira o novo elemento\n");
	scanf("%d", &info);
	Nv_elemnt(info,&end);
	printf("\n\nexistem %d elementos",Mostra_lista(end));
}

// 17 - Escreva uma rotina para remover o último elemento de uma lista linear simplesmente encadeada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	p->info = info;
	p->prox = *end;
	*end = p;	
}
void Mostra_lista(no end) {
	no p = end;
		while(p) {
			printf("%d\t",p->info);
			p = p->prox;
		}
}
void exclui(no *end) {
	no p = *end, q = *end;
	if(end==NULL) printf("\n\nnao existe mais lista");
	else if(p->prox == NULL) {
		free(p);
		*end = NULL;
	} else {
		p = p->prox;
		while(p->prox) {
			q = p;
			p = p->prox;
		}
		free(p);
		q->prox=NULL;
	}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		system("cls");
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		do {
			system("cls");
			printf("deseja continuar(S/N)?\n\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	do {
		system("cls");
		Mostra_lista(end);	
		do {
			printf("\ndeseja excluir(S/N)?\n\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		if(resp=='S') exclui(&end);
		if(end==NULL) {
			printf("\n\nnao existe mais lista");
			resp='N';	
		}
	} while(resp!='N');
}

// 21 - Desenvolva uma rotina que permita a inserção ordenada (crescente) de elementos em uma
// lista linear simplesmente encadeada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	if(*end==NULL){
		p->info = info;
		p->prox = NULL;
		*end = p;	
	} else {
		no q = *end, r;
		if(q->info >= info) {
			p->info = info;
			p->prox = *end;
			*end = p;
		}
		while(q->prox && q->info < info) {
			r = q;
			q = q->prox;	
		}
		if(info > q->info) {	
			q->prox = p;
			p->info = info;
			p->prox = NULL;
		} else {
			p->info = info;
			p->prox = q;
			r->prox = p;
		}
	}	
}
void Mostra_lista(no end) {
	no p = end;
		while(p) {
			printf("%d\t",p->info);
			p = p->prox;
		}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
}

// 19 - Dada uma lista linear simplesmente encadeada e um elemento, escreva uma rotina que remova da lista todas as ocorrências do elemento.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void Insere(int info, no *end) {
	no p = (no) malloc(sizeof(reg));
	p->info = info;
	p->prox = *end;
	*end = p;
}
void exclui(int info, no *end) {
	no p = *end, r;
	if((*end) -> prox == NULL && (*end)->info==info){
		free(p);
		printf("não há lista para excluir");
		getch();
		exit(1);	
	} else {
		if(p->info==info){
			*end = p->prox;
			free(p);
			p = *end; 
		}
		while(p->prox) {
			r = p;
			p = p->prox;
			if(p->info == info) {
				r->prox = p->prox;
				free(p);
				p = r;
			}
		}
		if(p->prox==NULL && info == p->info) {
			free(p);
			printf("não há lista para excluir");
			getch();
			exit(1);
		}	
	}	
}
void Mostra_lista(no end) {
	no p = end;
		while(p) {
			printf("%d\t",p->info);
			p = p->prox;
		}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	do {
		printf("\n\ndigite o elemento que deseja excluir: ");
		scanf("%d",&info);
		exclui(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
	} while(resp!='N');
}

// 23 - Desenvolva uma rotina que remova de uma lista linear ordenada todas as ocorrências de um determinado elemento.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg{
	int info;
	reg *prox;
};
void exclui(int info, no *end) {
	no p = *end, r;
	if((*end) -> prox == NULL && (*end)->info==info){
		free(p);
		printf("não há lista para excluir");
		getch();
		exit(1);	
	} else {
		if(p->info==info) {
			*end = p->prox;
			free(p);
			p = *end; 
		}
		while(p->prox) {
			r = p;
			p = p->prox;
			if(p->info == info) {
				r->prox = p->prox;
				free(p);
				p = r;
			}
		}
		if(p->prox==NULL && info == p->info) {
			free(p);
			printf("não há lista para excluir");
			getch();
			exit(1);
		}
	}	
}
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	if(*end==NULL) {
		p->info = info;
		p->prox = NULL;
		*end = p;	
	}
	else {
		no q = *end, r;
		if(q->info >= info) {
			p->info = info;
			p->prox = *end;
			*end = p;
		}
		while(q->prox && q->info < info) {
			r = q;
			q = q->prox;	
		}
		if(info > q->info) {	
			q->prox = p;
			p->info = info;
			p->prox = NULL;
		}
		else {
			p->info = info;
			p->prox = q;
			r->prox = p;
		}
	}	
}
void Mostra_lista(no end) {
	no p = end;
		while(p) {
			printf("%d\t",p->info);
			p = p->prox;
		}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	do {
		printf("\n\ndigite o elemento que deseja excluir: ");
		scanf("%d",&info);
		exclui(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
	} while(resp!='N');
}

// 25 - Faça uma rotina para concatenar duas listas encadeadas, dando origem a uma única lista.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void uniao(no end1, no end2, no *end) {
	no p = end1,q1;
	*end = end1;
	while(p->prox) {
		no r = (no) malloc(sizeof (reg));
		r->info = p->info;
		r->prox = p->prox;
		p = p->prox;
		if(p->prox == NULL) q1 = p;
	}
	p = end2;
	while(p->prox) {
		no r = (no) malloc(sizeof (reg));
		r->info = p->info;
		r->prox = p->prox;
		p = p->prox;
		if(p->prox == NULL) r->prox = NULL;
	}
	q1->prox = end2;
}
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	if(*end==NULL) {
		p->info = info;
		p->prox = NULL;
		*end = p;	
	} else {
		no q = *end, r;
		if(q->info >= info) {
			p->info = info;
			p->prox = *end;
			*end = p;
		}
		while(q->prox && q->info < info) {
			r = q;
			q = q->prox;	
		}
		if(info > q->info) {	
			q->prox = p;
			p->info = info;
			p->prox = NULL;
		}
		else {
			p->info = info;
			p->prox = q;
			r->prox = p;
		}
	}	
}
void Mostra_lista(no end) {
	no p = end;
		while(p) {
			printf("%d\t",p->info);
			p = p->prox;
		}
}
int main() {
	no end3 = NULL, end2 = NULL, end1 = NULL;
	int info, i = 1;
	char resp;
	// list 1
	do {
		printf("lista 1 = [%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end1);
		Mostra_lista(end1);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	// list 2
	i = 1;
	do {
		printf("lista 2 = [%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end2);
		Mostra_lista(end2);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	system("cls");
	printf("lista 1 = ");
	Mostra_lista(end1);
	printf("\nlista 2 = ");
	Mostra_lista(end2);
	uniao(end1,end2,&end3);
	printf("\nuniao = ");
	Mostra_lista(end3);
	getch();
}

// 27 - Escreva uma rotina que retorne a soma dos números de uma lista linear simplesmente enca-
// deada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
int soma(no end) {
	int soma=0;
	while(end) {
		soma = soma + end->info;
		end = end->prox;
	}
	return soma;
}
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	if(*end==NULL) {
		p->info = info;
		p->prox = NULL;
		*end = p;	
	} else {
		no q = *end, r;
		if(q->info >= info) {
			p->info = info;
			p->prox = *end;
			*end = p;
		}
		while(q->prox && q->info < info) {
			r = q;
			q = q->prox;	
		}
		if(info > q->info) {	
			q->prox = p;
			p->info = info;
			p->prox = NULL;
		}
		else {
			p->info = info;
			p->prox = q;
			r->prox = p;
		}
	}	
}
void Mostra_lista(no end) {
	no p = end;
		while(p) {
			printf("%d\t",p->info);
			p = p->prox;
		}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	printf("\n\no valor da soma e = %d", soma(end));
	getch();
}

// 29 - Escreva uma rotina para criar uma cópia de uma lista linear simplesmente encadeada.
#include<stdlib.h>
#include<ctype.h>
// #include<conio.h>
#include<stdio.h>
typedef struct reg *no;
typedef struct reg {
	int info;
	reg *prox;
};
void verifica(no end) {
	no p = end, q;
	int info, cont1, cont2=0;
	while(p) {
		cont1=0;
		q = end;
		while(q) if(p->info == q->info) cont1++;			
		if(cont1 > cont2) {
			p->info = info;
			cont2 = cont1;
		}
		p = p->prox;
	}
	printf("o numero que aparece mais vezes e o %d, aparecendo %d vezes\n",info,cont2);
}
void Insere(int info, no *end) {
	no p = (no)malloc(sizeof(reg));
	if(*end==NULL) {
		p->info = info;
		p->prox = NULL;
		*end = p;	
	}
	else {
		no q = *end, r;
		if(q->info >= info) {
			p->info = info;
			p->prox = *end;
			*end = p;
		}
		while(q->prox && q->info < info) {
			r = q;
			q = q->prox;	
		}
		if(info > q->info) {	
			q->prox = p;
			p->info = info;
			p->prox = NULL;
		} else {
			p->info = info;
			p->prox = q;
			r->prox = p;
		}
	}	
}
void Mostra_lista(no end) {
	no p = end;
		while(p) {
			printf("%d\t",p->info);
			p = p->prox;
		}
}
int main() {
	no end = NULL;
	int info, i = 1;
	char resp;
	do {
		printf("[%d] = ",i);
		scanf("%d", &info);
		Insere(info,&end);
		Mostra_lista(end);
		do {
			printf("\ndeseja continuar(S/N)?\n");
			resp = toupper(getch());	
		} while(resp!='N'&&resp!='S');
		i++;
	} while(resp!='N');
	verifica(end);
	getch();
}