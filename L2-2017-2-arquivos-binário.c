// 1 - Declare um arquivo com registros que contém os seguintes campos: NÚMERO DA CONTA,
// NOME DO CLIENTE, SALDO e DATA DA ÚLTIMA OPERAÇÃO. Faça um programa que ca-
// dastre e consulte os registros deste arquivo.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
struct DATA {
	int dia,mes,ano;
};
typedef struct {
	char Nome[20], Nconta[10];
	float saldo;
	struct DATA datOp;
}cadastro;
cadastro LeCadastro (cadastro *cad) {
		fflush(stdin);
		printf("nome:\n");
		gets((*cad).Nome);
		system("cls");
		printf("numero da conta:\n");
		gets((*cad).Nconta);
		system("cls");
		printf("saldo:\n");
		scanf("%f", &(*cad).saldo);
		system("cls");
		printf("data da ultima operacao(dd/mm/aaaa):\n");
		scanf("%d%d%d", &(*cad).datOp.dia, &(*cad).datOp.mes, &(*cad).datOp.ano);
		system("cls");
}
int main() {
	cadastro cad;
	int tam,i,soma=0,x;
	FILE *arq;
	arq = fopen("cadastros.dat", "w+b");	
	do {
		system("cls");
		printf("digite a quantidade de cadastros a ser feito, no max 100 cadastros\n\n");
		scanf("%d", &tam);
	} while(tam<0&&tam>100);
	system("cls");
	for(i=0;i<tam;i++) {
		LeCadastro(&cad);
		fwrite(&cad, sizeof(cad),1,arq);
	}	
	fclose(arq);
	arq = fopen("cadastros.dat","rb");
	while(fread(&cad,sizeof(cad),1,arq)==1) {	
		printf("nome: %s\n", cad.Nome);
		printf("numero da conta: %s\n",cad.Nconta);
		printf("saldo: %f\n", cad.saldo);
		printf("data da ultima operacao(dd/mm/aaaa): %d/%d/%d\n\n\n", cad.datOp.dia, cad.datOp.mes, cad.datOp.ano);
	}
	system("pause");
	fclose(arq);
}


// 3 - Supondo-se a existência de um arquivo A, com registros em que os campos são NOME e
// SALÁRIO, faça um programa que crie um arquivo B, através da cópia dos registros de A.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
struct DATA {
	int dia,mes,ano;
};
typedef struct {
	char Nome[20], Nconta[10];
	float saldo;
	struct DATA datOp;
}cadastro;
cadastro LeCadastro (cadastro *cad) {
		fflush(stdin);
		printf("nome:\n");
		gets((*cad).Nome);
		system("cls");
		printf("numero da conta:\n");
		gets((*cad).Nconta);
		system("cls");
		printf("saldo:\n");
		scanf("%f", &(*cad).saldo);
		system("cls");
		printf("data da ultima operacao(dd/mm/aaaa):\n");
		scanf("%d%d%d", &(*cad).datOp.dia, &(*cad).datOp.mes, &(*cad).datOp.ano);
		system("cls");
}
int main() {
	cadastro cad;
	int tam,i,soma=0,x;
	FILE *arq;
	arq = fopen("cadastros.dat", "w+b");	
	do {
		system("cls");
		printf("digite a quantidade de cadastros a ser feito, no max 100 cadastros\n\n");
		scanf("%d", &tam);
	} while(tam<0&&tam>100);
	system("cls");
	for(i=0;i<tam;i++) {
		LeCadastro(&cad);
		fwrite(&cad, sizeof(cad),1,arq);
	}	
	fclose(arq);
	arq = fopen("cadastros.dat","rb");
	while(fread(&cad,sizeof(cad),1,arq)==1) {	
		printf("nome: %s\n", cad.Nome);
		printf("numero da conta: %s\n",cad.Nconta);
		printf("saldo: %f\n", cad.saldo);
		printf("data da ultima operacao(dd/mm/aaaa): %d/%d/%d\n\n\n", cad.datOp.dia, cad.datOp.mes, cad.datOp.ano);
	}	
	system("pause");
	fclose(arq);
}

// 5 - A seção de controle de produção de uma fábrica mantém um arquivo de registros de produ-
// ção por máquinas. Cada registro contém o número da máquina e o número de peças produ-
// zidas em um dia. Supondo que a fábrica possua três máquinas, escreva um programa que
// separe o arquivo em três arquivos, um para cada máquina.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	char NumMaq;
	int Quant;
}MAQ;
int main() {
	FILE *arq,*arq1,*arq2,*arq3;
	arq = fopen("maq.dat","w+b");
	arq1 = fopen("maq1.dat","w+b");
	arq2 = fopen("maq2.dat","w+b");
	arq3 = fopen("maq3.dat","w+b");
	char resp;
	MAQ maq; 
	do {
		do {
			system("cls");
			printf("digite o numero da maquina: 1, 2 ou 3\n");
			scanf("%c", &maq.NumMaq);
		} while(maq.NumMaq!='1'&&maq.NumMaq!='2'&&maq.NumMaq!='3');
		system("cls");
		printf("digite a quantidade de pecas pruduzidas\n");
		scanf("%d",&maq.Quant);
		fwrite(&maq, sizeof(maq), 1, arq);
		do {
			system("cls");
			printf("deseja fazer outro registro??\nS-sim\nN - nao\n");
			scanf("%c",&resp);
		} while(resp!='N'&&resp!='n'&&resp!='s'&&resp!='S');
	} while(resp!='N'&&resp!='n');
	system("cls");	
	rewind(arq);
	while(fread(&maq, sizeof(maq), 1, arq)==1) {	
		if(maq.NumMaq=='1') fwrite(&maq, sizeof(maq), 1, arq1);
		else if(maq.NumMaq=='2') fwrite(&maq, sizeof(maq), 1, arq2);
		else fwrite(&maq, sizeof(maq), 1, arq3);
		printf("maquina: %c\n", maq.NumMaq);
		printf("pecas: %d\n\n", maq.Quant);		
	}
	rewind(arq1);
	rewind(arq2);
	rewind(arq3);
	printf("----------------------------------arquivo 1--------------------------------------------\n\n");
	while(fread(&maq, sizeof(maq), 1, arq1)==1) {	
		printf("maquina: %c\n", maq.NumMaq);
		printf("pecas: %d\n\n", maq.Quant);		
	}
	printf("----------------------------------arquivo 2--------------------------------------------\n\n");
	while(fread(&maq, sizeof(maq), 1, arq2)==1) {	
		printf("maquina: %c\n", maq.NumMaq);
		printf("pecas: %d\n\n", maq.Quant);		
	}
	printf("----------------------------------arquivo 3--------------------------------------------\n\n");
	while(fread(&maq, sizeof(maq), 1, arq3)==1) {	
		printf("maquina: %c\n", maq.NumMaq);
		printf("pecas: %d\n\n", maq.Quant);		
	}
	fclose(arq);
	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
}

// 7 - Faça um programa que simule um controle de estoque de uma loja, onde cada produto, re-
// presentado por meio de um registro, possui um IDENTIFICADOR INTEIRO, NOME, QUAN-
// TIDADE e CUSTO UNITÁRIO. O programa deve permitir a inclusão e remoção de novos
// produtos, consulta de produtos por nome, alteração de registros, geração de relatórios (e-
// xemplo: qual vendeu mais, qual tem maior estoque, produtos cujo estoque esteja abaixo de X
// unidades, etc.). Todos os registros devem ser armazenados sequencialmente em um arquivo
// binário. O programa deve disponibilizar um menu de opções ao usuário. Exemplo: 1 – Incluir
// Produto, 2 – consultar, etc.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	char nome[20],CodProd[20];
	int Quant,existe;
	float preco;
}produto;
produto busca (produto *cadastro) {
	FILE *arq;
	int ver=0;
	char nome[20];
	printf("digite o nome do produto para fazer a busca\n\n");
	gets(nome);
	arq = fopen("produto.dat","rb");
	while(fread(cadastro, sizeof(*cadastro), 1, arq)==1) {
		if(strcmp(nome,(*cadastro).nome)==0&&(*cadastro).existe==0) {
			printf("nome: %s\n",(*cadastro).nome);
			printf("codigo: %s\n",(*cadastro).CodProd);
			printf("preco: %.2f\n",(*cadastro).preco);
			printf("quantidade no estoque: %d\n",(*cadastro).Quant);
			ver=1;
			getch();
			break;
		}
	}
	if(ver==0) {
		printf("nao foi possivel achar o poduto\n\n");
		getch();
	}
}
produto Cadastro (produto *cadastro) {
	fflush(stdin);
	(*cadastro).existe=0;
	system("cls");
	printf("digite o nome do produto:\n");
	gets((*cadastro).nome);
	system("cls");
	printf("digite o codigo identificador do produto:\n");
	gets((*cadastro).CodProd);
	system("cls");
	printf("digite o preco do produto:\n");
	scanf("%f",&(*cadastro).preco);
	system("cls");
	printf("digite a quantidade no estoque\n");
	scanf("%d",&(*cadastro).Quant);
	system("cls");
}
produto inclusao(produto *cadastro) {
	FILE *arq;
	system("cls");
	fflush(stdin);
	arq = fopen("produto.dat", "r+b");
	Cadastro(cadastro);
	fseek (arq, 0, SEEK_END);
	fwrite (cadastro, sizeof(*cadastro), 1, arq);
	rewind(arq);
	system("cls");
	while(fread(cadastro, sizeof(*cadastro), 1, arq)==1) {	
		if((*cadastro).existe==0) {
		printf("\n\nnome: %s\n", (*cadastro).nome);
		printf("codigo: %s\n",(*cadastro).CodProd);
		printf("preco: %.2f\n", (*cadastro).preco);
		printf("quantidade no estoque: %d\n\n",(*cadastro).Quant);
		}
	}
	getch();
	fclose(arq);
}
produto remocao (produto *cadastro) {
	fflush(stdin);
	char nomecomp[20],resp;
	int verificacao;
	FILE *arq;
	verificacao=0;
	system("cls");
	if ((arq = fopen("produto.dat", "r+b"))==NULL) {
		printf("erro ao ler arquivo\n\n");
		exit(1);
	}
	printf("digite o nome do produto a ser removido\n");
	gets(nomecomp);
	rewind(arq);
	while(fread(cadastro, sizeof(*cadastro),1,arq)==1) {
		if(strcmp(nomecomp,(*cadastro).nome)==0&&(*cadastro).existe==0) {	
			printf("\n\nnome: %s\n", (*cadastro).nome);
			printf("codigo: %s\n",(*cadastro).CodProd);
			printf("preco: %.2f\n", (*cadastro).preco);
			printf("quantidade no estoque: %d\n\n",(*cadastro).Quant);
			getch();
			do {
				printf("deseja mesmo remover?\nS - sim\nN - nao\n");
				scanf("%c",&resp);
			} while (resp!='s'&&resp!='n'&&resp!='S'&&resp!='N');
			if(resp=='N'||resp=='n') return *cadastro;
			else {
				(*cadastro).existe=1;
				fseek (arq, -sizeof(*cadastro), 1);
				fwrite(cadastro,sizeof(*cadastro),1,arq);
				verificacao=1;
				break;
			} 		
		}
	}
	system("cls");
	if(verificacao==0) {
		system("cls");
		printf("\nnao existe esse produto na lista\n\n");
		getch();
		return *cadastro;
	}
	rewind(arq);
	fflush(stdin);
	while(fread(cadastro, sizeof(*cadastro),1,arq)==1) {	
			if((*cadastro).existe==0) {
				printf("\n\nnome: %s\n", (*cadastro).nome);
				printf("codigo: %s\n",(*cadastro).CodProd);
				printf("preco: %.2f\n", (*cadastro).preco);
				printf("quantidade no estoque: %d\n\n",(*cadastro).Quant);
			}
	}
	getch();
	fclose(arq);	
}
void deletar() {
	FILE *arq,*arq2;
	produto cad;
	arq = fopen("produto.dat","r+b");
	arq2 = fopen("produto2.dat","w+b");
	while(fread(&cad,sizeof(cad),1,arq)==1) {
		if(cad.existe!=1) fwrite(&cad,sizeof(cad),1,arq2);
	}
	rewind(arq);
	rewind(arq2);
	// nome do arquivo a ser excluído
	char *arquivo = "c:\\produto.dat";
	// exclusão do arquivo
	if (remove(arquivo) == 0) printf ("Arquivo foi excluido com sucesso.\n\n");
	getch();
	rename("produto2.dat","produto.dat");
	fclose(arq2);
}
int main() {
	FILE *arq,*arq2;
	char num,num2,resp,resp2,resp3;
	produto cadastro,cadastro2;
	arq = fopen("produto.dat","w+b");
	do {		
		Cadastro(&cadastro);
		fwrite(&cadastro, sizeof(cadastro), 1, arq);	
		do {
			system("cls");
			printf("deseja fazer outro registro??\nS-sim\nN - nao\n");
			scanf("%c",&resp);
		} while(resp!='N'&&resp!='n'&&resp!='s'&&resp!='S');
	} while(resp!='N'&&resp!='n');
	rewind(arq);
	system("cls");
	while(fread(&cadastro, sizeof(cadastro), 1, arq)==1) {	
		printf("\n\nnome: %s\n", cadastro.nome);
		printf("codigo: %s\n",cadastro.CodProd);
		printf("preco: %.2f\n", cadastro.preco);
		printf("quantidade no estoque: %d\n\n",cadastro.Quant);
	}
	getch();
	rewind(arq);
	do {
		system("cls");
		printf("\n\ndeseja fazer alguma alteracao na lista??\nS - sim\nN - nao\n\n");
		scanf("%c", &resp2);
	} while(resp2!='N'&&resp2!='n'&&resp2!='s'&&resp2!='S');
	if(resp2=='S'||resp2=='s') {
		do {
			do {
				system("cls");
				printf("digite uma das opcoes:\n1- consutar por nome algum produto\n2 - inclusao de algum produto\n3 - remocao de algum produto\n4 - geracao de relatorios\n");
				scanf("%c", &num);
			} while(num!='1'&&num!='2'&&num!='3'&&num!='4');
			system("cls");
			fflush(stdin);
			switch(num) {
				case '1':
					busca(&cadastro);
					break;
				case '2':
					inclusao(&cadastro);
					break;
				case '3':
					remocao(&cadastro);
					deletar();
					break;
				case '4':
					arq = fopen("produto.dat","r+b");
					arq2 = fopen("produto3.dat","w+b");
					do {
						system("cls");
						printf("digite uma das opcoes:\n1- maior preco\n2 - maior estoque\n\n");
						scanf("%c", &num2);
					} while(num2!='1'&&num2!='2');
					cadastro2.Quant=cadastro.preco=0;
					system("cls");
					switch(num2) {
						case '1':
							while(fread(&cadastro, sizeof(cadastro),1,arq)==1) {
								if(cadastro2.preco<cadastro.preco&&cadastro.existe==0) {
									cadastro2.preco = cadastro.preco;
									strcpy(cadastro2.nome,cadastro.nome);
									strcpy(cadastro2.CodProd,cadastro.CodProd);
									cadastro2.Quant = cadastro.Quant;
								}
							}
							fwrite(&cadastro2, sizeof(cadastro2),1,arq2);
							rewind(arq2);
							while(fread(&cadastro, sizeof(cadastro),1,arq2)==1) {
								printf("nome: %s\n", cadastro2.nome);
								printf("codigo: %s\n",cadastro2.CodProd);
								printf("preco: %.2f\n", cadastro2.preco);
								printf("quantidade no estoque: %d\n\n",cadastro2.Quant);		
								getch();
							}
							fclose(arq);
							fclose(arq2);
							break;	
						case '2':
							while(fread(&cadastro, sizeof(cadastro),1,arq)==1) {
								if(cadastro2.Quant<cadastro.Quant&&cadastro.existe==0) {
									cadastro2.preco = cadastro.preco;
									strcpy(cadastro2.nome,cadastro.nome);
									strcpy(cadastro2.CodProd,cadastro.CodProd);
									cadastro2.Quant = cadastro.Quant;
								}
							}
							fwrite(&cadastro2, sizeof(cadastro2),1,arq2);
							rewind(arq2);
							while(fread(&cadastro, sizeof(cadastro),1,arq2)==1) {
								printf("nome: %s\n", cadastro2.nome);
								printf("codigo: %s\n",cadastro2.CodProd);
								printf("preco: %.2f\n", cadastro2.preco);
								printf("quantidade no estoque: %d\n\n",cadastro2.Quant);		
								getch();
							}
							fclose(arq);
							fclose(arq2);
							break;
					}
					break;
				}
				do {
					system("cls");
					printf("\n\ndeseja fazer alguma alteracao na lista??\nS - sim\nN - nao\n\n");
					scanf("%c", &resp3);
				} while(resp3!='N'&&resp3!='n'&&resp3!='s'&&resp3!='S');		
			} while(resp3!='N'&&resp3!='n');
		}
		else exit(1);
}


// 9 - Supondo-se que em um sistema computacional bancário exista um arquivo de acesso direto
// e que cada registro gravado use como chave o número da conta do cliente, escreva um pro-
// grama que, lendo um número da conta de um cliente, escreva o número da conta, o nome e
// o saldo deste cliente.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	char nome[20],Nconta[20];
	float saldo;
}banco;
banco cadastro(banco *cad) {
	fflush(stdin);
	system("cls");
	printf("nome:\n");
	gets((*cad).nome);
	system("cls");
	printf("numero da conta:\n");
	gets((*cad).Nconta);
	system("cls");
	printf("saldo bancario:\n");
	scanf("%f",&(*cad).saldo);
	system("cls");
}
void busca(banco cad) {
	fflush(stdin);
	char cont[20];
	system("cls");
	printf("digite o numero da conta\n");
	gets(cont);
	FILE *arq;
	arq = fopen("dados.dat", "rb");
	while( fread(&cad,sizeof(cad),1,arq)==1) {
		if(strcmp(cont,cad.Nconta)==0) {
			printf("nome: %s\n",cad.nome);
			printf("numero da conta: %s\n",cad.Nconta);
			printf("saldo bancario: %f\n\n",cad.saldo);
		}
	}
	getch();
	fclose(arq);
}
int main() {
	FILE *arq;
	arq = fopen("dados.dat","w+b");
	int resp,n;
	banco cad;
	n=1;
	do {
		system("cls");
		printf("cadastro %d\n\n",n);
		getch();
		cadastro(&cad);
		fwrite(&cad,sizeof(cad),1,arq);
		do {
			system("cls");
			printf("deseja continuar??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp);
		} while(resp!='S'&&resp!='s'&&resp!='N'&&resp!='n');
		n++;	
	} while(resp!='N'&&resp!='n');	
	system("cls");
	rewind(arq);
	while(fread(&cad,sizeof(cad),1,arq)==1) {
		printf("nome: %s\n",cad.nome);
		printf("numero da conta: %s\n",cad.Nconta);
		printf("saldo bancario: %f\n\n",cad.saldo);
	}
	getch();
	system("cls");
	rewind(arq);
	char cont[20],resp2;
	do {
		busca(cad);
		do {
			system("cls");
			printf("deseja continuar??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp2);
		} while(resp2!='S'&&resp2!='s'&&resp2!='N'&&resp2!='n');	
	} while(resp2!='N'&&resp2!='n');	
}

// 11 - Faça um programa que liste um arquivo sequencial denominado DADOS que possui registros
// com os campos de NOME, ENDEREÇO, CEP e TELEFONE.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	char nome[20],end[20],cep[20],tel[20];
}dados;
dados cadastro(dados *cad) {
	fflush(stdin);
	system("cls");
	printf("nome:\n");
	gets((*cad).nome);
	system("cls");
	printf("endereco:\n");
	gets((*cad).end);
	system("cls");
	printf("CEP:\n");
	gets((*cad).cep);
	system("cls");
	printf("telefone:\n");
	gets((*cad).tel);
	system("cls");
}
int main() {
	FILE *arq;
	arq = fopen("dados.dat","w+b");
	int resp,n;
	dados cad;
	n=1;
	do {
		system("cls");
		printf("cadastro %d\n\n",n);
		getch();
		cadastro(&cad);
		fwrite(&cad,sizeof(cad),1,arq);
		do {
			system("cls");
			printf("deseja continuar??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp);
		} while(resp!='S'&&resp!='s'&&resp!='N'&&resp!='n');
		n++;	
	} while(resp!='N'&&resp!='n');	
	system("cls");
	rewind(arq);
	while(fread(&cad,sizeof(cad),1,arq)==1) {
		printf("nome: %s\n",cad.nome);
		printf("endereco: %s\n",cad.end);
		printf("CEP: %s\n",cad.cep);
		printf("telefone: %s\n\n",cad.tel);
	}
	getch();
}

// 13 - O arquivo “bolsa.dat” contém registros das operações de um cliente na Bolsa de Valores.
// Cada operação de compra ou venda que um cliente realiza na bolsa gera um registro com o
// NÚMERO do cliente, o CÓDIGO da operação (V para Venda e C para Compra), a DESCRI-
// ÇÃO do título comercializado, a QUANTIDADE de títulos comercializados e o VALOR UNI-
// TÁRIO de cada título. Estes registros estão seqüencialmente organizados no arquivo BOLSA
// de tal modo que todos os registros de um mesmo cliente estão juntos. Escreva um programa
// para gerar o arquivo seqüencial RESULTADO, onde para cada cliente apareça um registro
// da forma: NÚMERO DO CLIENTE, SALDO APURADO e TIPO DE SALDO. O TIPO DE SAL-
// DO será igual a C (de Credor) se o valor comprado for maior que o vendido. Caso contrário, o
// saldo será D (de Devedor).
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	char ncliente[20],tipodesaldo[20],desc[100];
	float saldoap;
}dados;
dados cadastro(dados *cad) {
	int quant,i;
	char cod;
	float soma=0,valor;
	fflush(stdin);
	system("cls");
	printf("numero do cliente:\n");
	gets((*cad).ncliente);
	do {
		system("cls");
		printf("digite a quantidade de titulos comercializado:\n");
		scanf("%d", &quant);
	} while(quant<0);
	for(i=0;i<quant;i++) {
		fflush(stdin);
		do {
			system("cls");
			printf("titulo %d", i+1);
			printf("codigo da operaca\nV - venda\nC - compra:\n");
			scanf("%c", &cod);
		} while(cod!='V'&&cod!='v'&&cod!='C'&&cod!='c');
		if(cod=='c'||cod=='C') {
			system("cls");
			printf("digite o valor\n");
			scanf("%f",&valor);
			soma = soma - valor;
		} else if (cod=='V'||cod=='v') {
			system("cls");
			printf("digite o valor\n");
			scanf("%f",&valor);
			soma = soma + valor;
		}
		fflush(stdin);
	}
	(*cad).saldoap = soma;
	if(soma<0) strcpy((*cad).tipodesaldo,"devedor");
	else strcpy((*cad).tipodesaldo,"credor");
	system("cls");
	printf("descricao do titulo comercializado:\n");
	gets((*cad).desc);
	system("cls");
}
int main() {
	FILE *arq;
	arq = fopen("bolsa.dat","w+b");
	char resp;
	dados cad;
	do {
		system("cls");
		cadastro(&cad);
		fwrite(&cad,sizeof(cad),1,arq);
		do {
			system("cls");
			printf("deseja continuar a cadastrar??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp);
		} while(resp!='S'&&resp!='s'&&resp!='N'&&resp!='n');	
	} while(resp!='N'&&resp!='n');	
	system("cls");
	rewind(arq);
	while(fread(&cad,sizeof(cad),1,arq)==1) {	
		printf("numero do cliente: %s\n", cad.ncliente);
		printf("saldo apurado: %.2f\n", cad.saldoap);
		printf("tipo de saldo: %s\n\n", cad.tipodesaldo);	
	}	
	getch();
	fclose(arq);
}

// 15 - Escreva um programa para gerenciar atendimentos em uma clínica. O menu de opções deve
// conter:
// 1 - Marcar a consulta
// 2 - Desmarcar a consulta
// 3 - Escrever mapa de horários para um determinado dia
// 4 - Escrever o nome e as datas em que um paciente foi consulado
// 5 - Escrever o nome e o telefone de todos os pacientes cuja última consulta ocorreu há mais
// de 6 meses e que tem idade superior a 50 anos
// 6 - Fim
// Os dados de cada cliente estão dispostos em um arquivo, onde cada registro tem a seguinte
// estrutura: código do cliente, nome do cliente, idade, endereço, telefone, patologia.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	int dia,mes,ano;
}data2;
typedef struct   {
	int hor,min;
}hora2;
typedef struct {
	char nome[20];
	hora2 hora ;
	data2 data;
	int exist;
}dados;
typedef struct {
	char nome2[20];
	data2 dat;
}dados3;
typedef struct {
	char nome3[20],tel[15];
}dados4;
dados escrever1(dados *cad) {
	FILE *arq;
	char resp;
	arq = fopen("dados.dat","w+b");
	do {
		(*cad).exist=0;
		fflush(stdin);
		system("cls");
		printf("nome:\n");
		gets((*cad).nome);
		system("cls");
		/*printf("data(dia,mes,ano):\n");
		scanf("%d%d%d", &(*cad).data.dia,&(*cad).data.mes,&(*cad).data.ano);
		system("cls");
		printf("horario(horas,min):\n");
		scanf("%d%d", &(*cad).hora.hor,&(*cad).hora.min);
		system("cls");*/
		fwrite(cad,sizeof(*cad),1,arq);
		fflush(stdin);
		do {
			system("cls");
			printf("deseja continuar a cadastrar??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp);
		} while(resp!='S'&&resp!='s'&&resp!='N'&&resp!='n');	
	} while(resp!='N'&&resp!='n');
	system("cls");
	rewind(arq);
	while(fread(cad, sizeof(*cad),1,arq)==1) {
		if((*cad).exist!=1) {
		printf("nome: %s\n",(*cad).nome);
		printf("data: %d/%d/%d\n",(*cad).data.dia,(*cad).data.mes,(*cad).data.ano);
		printf("horario(horas,min): %d : %d\n\n\n", (*cad).hora.hor,(*cad).hora.min);
		}
	}
	fclose(arq);
	getch();
}
void escrever2() {
	dados3 d;
	FILE *arq;
	char resp;
	arq = fopen("dados3.dat","w+b");
	fflush(stdin);
	system("cls");
	printf("nome:\n");
	gets(d.nome2);
	fwrite(&d,sizeof(d.nome2),1,arq);
	system("cls");
	do {
		system("cls");
		printf("data(dia,mes,ano):\n");
		scanf("%d%d%d", &d.dat.dia,&d.dat.mes,&d.dat.ano);
		fwrite(&d.dat.dia,sizeof(d.dat.dia),1,arq);
		fwrite(&d.dat.mes,sizeof(d.dat.mes),1,arq);
		fwrite(&d.dat.ano,sizeof(d.dat.ano),1,arq);
		do {
			system("cls");
			printf("deseja continuar a cadastrar alguma data??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp);
		} while(resp!='S'&&resp!='s'&&resp!='N'&&resp!='n');	
	} while(resp!='N'&&resp!='n');
	fflush(stdin);
	system("cls");
	rewind(arq);
	fread(&d.nome2,sizeof(d.nome2),1,arq);
	printf("nome: %s\n\n",d.nome2);
	while(fread(&d.dat,sizeof(d.dat),1,arq)==1) printf("data: %d/%d/%d\n",d.dat.dia,d.dat.mes,d.dat.ano);
	fclose(arq);
	getch();
}
void escrever3() {
	FILE *arq;
	char resp;
	dados4 x;
	arq = fopen("dados4.dat","w+b");
	do {
		fflush(stdin);
		system("cls");
		printf("nome:\n");
		gets(x.nome3);
		system("cls");
		printf("telefone:\n");
		gets(x.tel);
		system("cls");
		fwrite(&x,sizeof(x),1,arq);
		fflush(stdin);
		do {
			system("cls");
			printf("deseja continuar a cadastrar??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp);
		} while(resp!='S'&&resp!='s'&&resp!='N'&&resp!='n');	
	} while(resp!='N'&&resp!='n');
	system("cls");
	rewind(arq);
	while(fread(&x, sizeof(x),1,arq)==1) {
		printf("nome: %s\n",x.nome3);
		printf("telefone: %s\n\n",x.tel);
	}
	fclose(arq);
	getch();
}
dados desmarcar(dados *cad) {
	fflush(stdin);
	char nomecomp[20],resp;
	int verificacao;
	FILE *arq;
	verificacao=0;
	system("cls");
	if ((arq = fopen("dados.dat", "r+b"))==NULL) {
		printf("erro ao ler arquivo\n\n");
		exit(1);
	}
	printf("digite o nome do paciente a ser desmarcado\n");
	gets(nomecomp);
	rewind(arq);
	while(fread(cad, sizeof(*cad),1,arq)==1) {
		if(strcmp(nomecomp,(*cad).nome)==0&&(*cad).exist==0) {
			printf("\n\nnome: %s\n",(*cad).nome);
			printf("data: %d/%d/%d\n",(*cad).data.dia,(*cad).data.mes,(*cad).data.ano);
			printf("horario(horas,min): %d : %d\n\n\n", (*cad).hora.hor,(*cad).hora.min);
			getch();
			do {
				printf("deseja mesmo desmarcar?\nS - sim\nN - nao\n");
				scanf("%c",&resp);
			} while (resp!='s'&&resp!='n'&&resp!='S'&&resp!='N');
			if(resp=='N'||resp=='n') return *cad;
			else {
				(*cad).exist=1;
				fseek (arq, -sizeof(*cad), 1);
				fwrite(cad,sizeof(*cad),1,arq);
				verificacao=1;
				break;
			} 		
		}
	}
	if(verificacao==0) {
		system("cls");
		printf("\nnao existe esse paciente na lista\n\n");
		getch();
		return *cad;
	}
	rewind(arq);
	fflush(stdin);
	while(fread(cad, sizeof(*cad),1,arq)==1) {	
			if((*cad).exist==0) {
			printf("nome: %s\n",(*cad).nome);
			printf("data: %d/%d/%d\n",(*cad).data.dia,(*cad).data.mes,(*cad).data.ano);
			printf("horario(horas,min): %d : %d\n", (*cad).hora.hor,(*cad).hora.min);
			printf("---------------%d\n\n",(*cad).exist);
			}
	}
	getch();
	fclose(arq);	
}
dados marcar(dados *cad) {
	FILE *arq;
	system("cls");
	fflush(stdin);
	arq = fopen("dados.dat","r+b");
	(*cad).exist=0;
	printf("nome:\n");
	gets((*cad).nome);
	system("cls");
	printf("data(dia,mes,ano):\n");
	scanf("%d%d%d", &(*cad).data.dia,&(*cad).data.mes,&(*cad).data.ano);
	system("cls");
	printf("horario(horas,min):\n");
	scanf("%d%d", &(*cad).hora.hor,&(*cad).hora.min);
	system("cls");
	fseek(arq,0,2);
	fwrite(cad,sizeof(*cad),1,arq);
	fflush(stdin);
	rewind(arq);
	fflush(stdin);
	while(fread(cad, sizeof(*cad),1,arq)==1) {	
			if((*cad).exist==0) {
			printf("nome: %s\n",(*cad).nome);
			printf("data: %d/%d/%d\n",(*cad).data.dia,(*cad).data.mes,(*cad).data.ano);
			printf("horario(horas,min): %d : %d\n", (*cad).hora.hor,(*cad).hora.min);
			printf("---------------%d\n\n",(*cad).exist);
			}
	}
	getch();
	fclose(arq);	
}
void deletar() {
	FILE *arq,*arq2;
	dados cad;
	arq = fopen("dados.dat","r+b");
	arq2 = fopen("dados2.dat","w+b");
	while(fread(&cad,sizeof(cad),1,arq)==1) {
		if(cad.exist!=1) fwrite(&cad,sizeof(cad),1,arq2);
	}
	rewind(arq);
	rewind(arq2);
	// nome do arquivo a ser excluído
	char *arquivo = "c:\\dados.dat";
	// exclusão do arquivo
	if (remove(arquivo) == 0) printf ("Arquivo foi excluido com sucesso.\n\n");
	getch();
	rename("dados2.dat","dados.dat");
	fclose(arq2);
}
int main() {
	char resp,resp2;
	dados cad;	
	do {
		do {
		system("cls");
		printf("1 - marcar consulta\n2 - Desmarcar a consulta\n3 - escrever mapa de horarios de um dia\n4 - escrever nome e datas em que um paciente foi consultado\n5 - escrever nome e telefone de todos pacientes que consultarama mais de 50 anos\n6 - sair\n\n");
		scanf("%c", &resp2);
		} while(resp2!='1'&&resp2!='2'&&resp2!='3'&&resp2!='4'&&resp2!='5'&&resp2!='6'); 
		switch(resp2) {
			case '1':
				marcar(&cad);
				break;
			case '2':
				desmarcar(&cad);
				deletar();
				break;
			case '3':
				escrever1(&cad);
				break;
			case '4':
				escrever2();
				break;
			case '5':
				escrever3();
				break;
			case '6':
				exit(1);
		}
	} while(resp2!='6');
}