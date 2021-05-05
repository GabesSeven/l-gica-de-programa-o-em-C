// 1 - Um número complexo é dividido em duas partes na forma z=a+b.i, onde a e b são nú-
// meros reais. Defina um tipo chamado complexo usando struct para contemplar estas
// duas partes. Além disso, faça funções para ler, somar, subtrair e multiplicar números
// complexos.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	float a,b,c,d;
}complexo;
complexo Ler(complexo *NC) {
	system("cls");
	printf("digite os valores de a,b,c e d respectivamente\nonde,x = a + bi e y = c + di\n\n");
	scanf("%f%f%f%f", &(*NC).a,&(*NC).b,&(*NC).c,&(*NC).d);
	system("cls");
}
void adi(complexo NC) {
	printf("o resultado e:\n z = %.1f + %.1fi\n\n", (NC.a+NC.c),(NC.b+NC.d));
}
void sub(complexo NC) {
	printf("o resultado e:\n z = %.1f + %.1fi\n\n", (NC.a-NC.c),(NC.b-NC.d));	
}
void mul(complexo NC) {
	printf("o resultado e:\n z = %.1fi^2 + %.1fi + %.1f\n\n", (NC.b*NC.d),(NC.a*NC.d)+(NC.b*NC.c),(NC.a*NC.c));
}
int main() {
	char n;
	complexo NC;
	do {
		system("cls");
		printf("numeros complexos, tecle...\n1 - adicao\n2 - subtracao\n3 - multiplicacao\n\n");
		scanf("%c", &n);
	} while(n!='1'&&n!='2'&&n!='3');
	switch(n) {
		case '1':
			Ler(&NC);
			adi(NC);
			break;
		case '2':
			Ler(&NC);
			sub(NC);
			break;
		case '3':
			Ler(&NC);
			mul(NC);
			break;
	}
}

// 3 - Suponha um cadastro de alunos onde cada aluno contém os seguintes campos: Nome,
// Data de Nascimento (dia, mês, ano), RG, Sexo, Endereço (Rua, Cidade, Estado, CEP),
// RA (Registro de Aluno) e CR (Coeficiente de Rendimento: número real no intervalo
// [0,1]). Faça um programa que realize o cadastro de alunos em um vetor com 100 posi-
// ções. O programa deve manipular este cadastro com as seguintes opções:
// 1) Inserir um novo aluno no cadastro.
// 2) Ordenar o cadastro por nome em ordem alfabética.
// 3) Ordenar o cadastro por CR, maiores primeiro.
// 4) Imprimir o cadastro na ordem atual
// 5) Ler o valor de um RA e imprimir os dados do aluno no cadastro com mesmo RA.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
struct datanascimento {
	char dia[2],mes[2],ano[4];
};
struct end {
	char rua[20],cidade[20],est[10],cep[10];	
};
typedef struct cadastro {
	char nome[50],rg[10],sexo[10],ra[20];
	float cr;
	struct end endereco;
	struct datanascimento datnas;
}fp;	
fp cadastrese(fp *ficha) {
	fflush(stdin);
	system("cls");
	printf("digite seu nome: ");
	gets((*ficha).nome);
	system("cls");
	printf("digite sua data de nasc, dia/mes/ano:\n ");
	scanf("%d%d%d", (*ficha).datnas.dia,(*ficha).datnas.mes, (*ficha).datnas.ano);
	system("cls");
	printf("digite seu rg: ");
	gets((*ficha).rg);
	system("cls");
	printf("digite seu sexo: feminino ou masculino?\n\n");
	gets((*ficha).sexo);
	system("cls");
	printf("digite seu endereco(rua, cidade, estado, cep):\n");
	printf("RUA: \n\n");
	gets((*ficha).endereco.rua);
	printf("\nCIDADE: \n\n");
	gets((*ficha).endereco.cidade);
	printf("\nESTADO: \n\n");
	gets((*ficha).endereco.est);
	printf("\nCEP: \n\n");
	gets((*ficha).endereco.cep);
	system("cls");
	printf("digite seu RA\n\n");
	gets((*ficha).ra);
	system("cls");
	printf("digite seu CR - VARIANDO DE 0-1\n\n");
	scanf("%f", &(*ficha).cr);
	return *ficha;
}
int main() {
	int i,j,tam; 
	fp ficha[100],aux,aux2;
	
	do {
		system("cls");
		printf("quantidade de cadastros?\n\n");
		scanf("%d", &tam);	
	} while(tam<0&&tam>100);

	for(i=0;i<tam;i++) {
		cadastrese(&ficha[i]);
	}
	
	//ordenando
	for(i=0;i<tam-1;i++) {
		for(j=i;j<tam;j++) {
			if(strcmp(ficha[j].nome,ficha[i].nome)==0)
				if(ficha[j].cr>ficha[i].cr) {
					aux2=ficha[j];
					ficha[j]=ficha[i];
					ficha[i]=aux2;
				}
            if(strcmp(ficha[j].nome,ficha[i].nome)<0) {
					aux=ficha[j];
					ficha[j]=ficha[i];
					ficha[i]=aux;
			}
		}
	}
	system("cls");

	for(i=0;i<tam;i++) 
		printf("NOME: %s\nDATA DE NASCIMENTO: %s/%s/%s\nRG: %s\nSEXO: %s\nENDERECO:\nRUA: %s CIDADE: %s ESTADO: %s CEP: %s\nRA: %s\nCR %.2f\n\n", ficha[i].nome, ficha[i].datnas.dia, ficha[i].datnas.mes, ficha[i].datnas.ano, ficha[i].rg, ficha[i].sexo, ficha[i].endereco.rua, ficha[i].endereco.cidade, ficha[i].endereco.est, ficha[i].endereco.cep, ficha[i].ra, ficha[i].cr);
	char resp,codRA[20];
	int ver;
	getch();
    do {
        system("cls");
        printf("deseja pesquisar algum aluno pelo RA?\nS - sim\nN - nao\n\n");
        scanf("%c", &resp);
    } while(resp!='N'&&resp!='n'&&resp!='S'&&resp!='s');
	system("cls");
	if(resp=='n'||resp=='N') printf("PROFESSORA ANDREIA, A MELHOR!");
	else {
		do {
			system("cls");
			ver=0;
			fflush(stdin);	
			printf("digite o numero do RA\n\n");
			gets(codRA);
			for(i=0;i<tam;i++) {
				if(strcmp(ficha[i].ra,codRA)==0) {
					ver=1;
					break;
				}
			}
            if(ver==1) {
				printf("NOME: %s\nDATA DE NASCIMENTO: %s/%s/%s\nRG: %s\nSEXO: %s\nENDERECO:\nRUA: %s CIDADE: %s ESTADO: %s CEP: %s\nRA: %s\nCR %.2f\n\n", ficha[i].nome, ficha[i].datnas.dia, ficha[i].datnas.mes, ficha[i].datnas.ano, ficha[i].rg, ficha[i].sexo, ficha[i].endereco.rua, ficha[i].endereco.cidade, ficha[i].endereco.est, ficha[i].endereco.cep, ficha[i].ra, ficha[i].cr);
				getch();	
			} else {
				printf("ALUNO NAO ENCONTRADO");
				getch();	
			}
		} while(ver!=1);
	}
	system("cls");
	printf("PROFESSORA ANDREIA, A MELHOR!");
	getch();
}

// A seguir: do execício 4 ao 13;
// 4 - Declare uma estrutura chamada TipoReg contendo os seguintes campos: Nome, RG,
// Salario, Idade, Sexo, DataNascimento; onde Nome e RG são strings, Salario é real, I-
// dade é inteiro, Sexo é char e DataNascimento é uma estrutura contendo três inteiros,
// dia, mês e ano. Declare uma estrutura chamada TipoCadastro que contém dois cam-
// pos: um campo funcionário, contendo um vetor com 100 posições do tipo TipoReg e
// outro campo inteiro, Quant, que indica a quantidade de funcionários no cadastro.
// 5 - Faça uma função, IniciaCadastro, que inicia uma variável do tipo TipoCadastro. A
// função atribui a quantidade de funcionários como zero.
// 6 - Faça uma função, LeFuncionarios, com uma variável do tipo TipoCadastro como pa-
// râmetro de entrada. A função deve ler os dados de vários funcionários e colocar no vetor 
// do cadastro, atualizando a quantidade de elementos não nulos. A função deve retornar 
// com o cadastro atualizado. Lembre que o cadastro não suporta mais funcionários
// que os definidos no vetor de funcionários.
// 7 - Faça uma função, chamada ListaFuncionarios, que imprime os dados de todos os
// funcionário.
// 8 - Faça uma função, chamada ListaFuncionarios, que imprime os dados de todos os
// funcionário.
// 9 - Faça uma função, SalarioIntervalo, que tem como parâmetros: um parâmetro do tipo
// TipoCadastro e dois valores reais v1 e v2 , v1 <= v2. A função lista os funcionários com 
// salário entre v1 e v2. Depois de imprimir os funcionários, imprime a média dos salários dos
// funcionários listados.
// 10 - Faça uma função que dado um cadastro, imprime o nome do funcionário e o imposto
// que é retido na fonte. Um funcionário que recebe até R$1000,00 é isento do imposto.
// Para quem recebe mais de R$1000,00 e até R$2000,00 tem 10% do salário retido na
// fonte. Para quem recebe mais de R$2000,00 e até R$3500,00 tem 15% do salário reti-
// do na fonte. Para quem recebe mais de R$3500,00 tem 25% do salário retido na fonte.
// 11 - Faça uma função, BuscaNome, que tem como entrada o cadastro e mais um parâme-
// tro que é um nome de um funcionário. A função deve retornar uma estrutura (tipo Ti-
// poReg) contendo todas as informações do funcionário que tem o mesmo nome. Caso a
// função não encontre um elemento no vetor contendo o mesmo nome que o dado como
// parâmetro, a estrutura deve retornar com nome igual a vazio.
// 12 - Desenvolva uma função, AtualizaSalario, que tem como parâmetro o cadastro de fun-
// cionários. A função deve ler do teclado o RG do funcionário a atualizar. Em seguida, a
// função lê o novo salário do funcionário. Por fim, a função atualiza no cadastro o salário
// do funcionário com o RG especificado.
// 13 - Faça uma função, chamada ListaMaraja, que tem como parâmetro o cadastro e devol-
// ve uma estrutura contendo os dados de um funcionário que tem o maior salário.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct {
	int dia,mes,ano;
}data;
typedef struct {
	char nome[50],rg[15],sexo[20];
	float salario;
	int idade;
	data datadenasc;
}TipoReg;
typedef struct {
	TipoReg funcionario[100];
	int quant;
}TipoCadastro;
//-----------------------------------------	
TipoCadastro ListaFuncionarios(TipoCadastro cadastro) {
	fflush(stdin);
	int i;
	for(i=0;i<cadastro.quant;i++) printf("NOME: %s\nRG: %s\nSEXO: %s\nIDADE: %d\nDATA DE NASCIMENTO: %d/%d/%d\nSALARIO: %.2f\n\n", cadastro.funcionario[i].nome,cadastro.funcionario[i].rg, cadastro.funcionario[i].sexo, cadastro.funcionario[i].idade,cadastro.funcionario[i].datadenasc.dia,cadastro.funcionario[i].datadenasc.mes,cadastro.funcionario[i].datadenasc.ano,cadastro.funcionario[i].salario);
	printf("\n\n\n----------------------- aperte para continuar");
	getch();
	system("cls");
}
TipoCadastro LeFuncionarios(TipoCadastro *cadastro) {
	int i;
	do {
		system("cls");
		printf("digite a quantidade de cadastro que deseja fazer - OBS: quantidade max e 99 cadastros\n\n");
		scanf("%d", &(*cadastro).quant);
	} while((*cadastro).quant<0&&(*cadastro).quant>99);	
	
	for(i=0;i<(*cadastro).quant;i++) {
		system("cls");
		fflush(stdin);
		printf("digite o nome:\n\n");
		gets((*cadastro).funcionario[i].nome);
		system("cls");
		printf("digite o RG:\n\n");
		gets((*cadastro).funcionario[i].rg);
		system("cls");
		printf("digite o sexo:\n\n");
		gets((*cadastro).funcionario[i].sexo);
		system("cls");
		printf("digite o idade:\n\n");
		scanf("%d", &(*cadastro).funcionario[i].idade);
		system("cls");
		printf("digite sua data de nascimento:\n\n");
		scanf("%d%d%d", &(*cadastro).funcionario[i].datadenasc.dia,&(*cadastro).funcionario[i].datadenasc.mes,&(*cadastro).funcionario[i].datadenasc.ano);
		system("cls");
		printf("digite o valor do salario:\n\n");
		scanf("%f", &(*cadastro).funcionario[i].salario);
		system("cls");
	}
}
TipoCadastro OrdenaNome(TipoCadastro *cadastro) {
	int i,j;
	TipoReg aux;
	for(i=0;i<(*cadastro).quant;i++)
		for(j=i;j<(*cadastro).quant;j++)
			if(strcmp((*cadastro).funcionario[j].nome,(*cadastro).funcionario[i].nome)<0) {
				aux=(*cadastro).funcionario[j];
				(*cadastro).funcionario[j]=(*cadastro).funcionario[i];
				(*cadastro).funcionario[i]=aux;
			}
}
TipoCadastro OrdenaSalario(TipoCadastro *cadastro) {
	int i,j;
	TipoReg aux;
	for(i=0;i<(*cadastro).quant;i++)
		for(j=i;j<(*cadastro).quant;j++)
        		if((*cadastro).funcionario[j].salario<(*cadastro).funcionario[i].salario) {
				aux=(*cadastro).funcionario[j];
				(*cadastro).funcionario[j]=(*cadastro).funcionario[i];
				(*cadastro).funcionario[i]=aux;
			}
}
TipoCadastro IniciaCadastro(TipoCadastro *cadastro) {	
	(*cadastro).quant=0;	
}
TipoCadastro SalarioIntervalo(TipoCadastro cadastro, TipoCadastro *CAD) {
	int aux,i,j,cont=0,cont2=0;
	float soma=0,v1,v2;
	printf("digite o valor do intervalo dos salarios\n\n");
	scanf("%f%f",&v1,&v2);
	system("cls");
	if (v1>v2) {
		aux=v1;
		v1=v2;
		v2=aux;
	}
	for(i=0;i<cadastro.quant;i++)
		if(cadastro.funcionario[i].salario>v1&&cadastro.funcionario[i].salario<v2) {
			(*CAD).funcionario[cont]=cadastro.funcionario[i];
			(*CAD).quant=cadastro.quant;
			cont++;
		}
	for(i=0;i<cadastro.quant;i++) {
		soma = soma + (*CAD).funcionario[i].salario;
		cont2++;
	}
	fflush(stdin);
	printf(" A MEDIA SALARIAL É %.2f\n\n\n", soma/cont2);
}
TipoCadastro Imposto(TipoCadastro cadastro) {
	int i;
	char RG[20];
	printf("digite o valor do RG para acharo cadastro\n\n");
	gets(RG);
	system("cls");
	for(i=0;i<(cadastro).quant;i++) {
		if (strcmp(cadastro.funcionario[i].rg,RG) != 0) printf("-------------------------------\n");
		else {
			printf("NOME: %s\nSALARIO: %f\n",cadastro.funcionario[i].nome,cadastro.funcionario[i].salario);
			if (cadastro.funcionario[i].salario<1000) printf("\nIMPOSTO: %f\n\n", 0*(cadastro.funcionario[i].salario));
			else if(cadastro.funcionario[i].salario>=1000&&cadastro.funcionario[i].salario<=2000) printf("\nIMPOSTO: %f\n\n", (10/100)*(cadastro.funcionario[i].salario));
			else if(cadastro.funcionario[i].salario>2000&&cadastro.funcionario[i].salario<=3500) printf("\nIMPOSTO: %f\n\n", (15/100)*(cadastro.funcionario[i].salario));
			else if(cadastro.funcionario[i].salario>3500) printf("\nIMPOSTO: %f\n\n", (25/100)*(cadastro.funcionario[i].salario));
		}	
	}
}
TipoCadastro BuscaNome(TipoCadastro cadastro, char nome[]) {
	int ver,i,cont=0;
	TipoCadastro cadastro2;
	ver=0;
	for(i=0;i<cadastro.quant;i++) {
		if(strcmp(nome,cadastro.funcionario[i].nome)==0) {
		strcpy(cadastro2.funcionario[cont].nome,cadastro.funcionario[i].nome);
		cont++;	
		ver=1;
		printf("NOME: %s\nRG: %s\nSEXO: %s\nIDADE: %d\nDATA DE NASCIMENTO: %d/%d/%d\nSALARIO: %.2f\n\n", cadastro.funcionario[i].nome,cadastro.funcionario[i].rg, cadastro.funcionario[i].sexo, cadastro.funcionario[i].idade,cadastro.funcionario[i].datadenasc.dia,cadastro.funcionario[i].datadenasc.mes,cadastro.funcionario[i].datadenasc.ano,cadastro.funcionario[i].salario);
		}
	}
	if (ver==1) return cadastro2;
}
TipoCadastro AtualizaSalario(TipoCadastro *cadastro) {
	int i;
	char rg2[20];
	system("cls");
	printf("digite RG dofuncionario para atualizar o salario\n\n");
	gets(rg2);
	system("cls");
	for(i=0;i<(*cadastro).quant;i++) {
		if(strcmp(rg2,(*cadastro).funcionario[i].rg)==0) {
            printf ("digite o valor do novo salario\n\n");
            scanf("%f", &(*cadastro).funcionario[i].salario);
		}
	}
}
int main() {
	char nome[20],cst;
	TipoCadastro cadastro, CAD;
	IniciaCadastro(&cadastro);
	LeFuncionarios(&cadastro);
	ListaFuncionarios(cadastro);
	do {
        system("cls");
        printf("deseja ordenar o nome dos funcionarios de que forma?\n1 - OrdenaNome\n2 - OrdenaSalario\n\n");
        scanf("%c",&cst);
    } while(cst!='1'&&cst!='2');
	if (cst=='1') OrdenaNome(&cadastro);
	else OrdenaSalario(&cadastro);
	ListaFuncionarios(cadastro);
	SalarioIntervalo(cadastro, &CAD);
	ListaFuncionarios(CAD);
	Imposto(cadastro);
	ListaFuncionarios(cadastro);
	printf("\ndigite nome do funcionario que deseja buscar\n\n");
	gets(nome);
	system("cls");
	BuscaNome(cadastro,nome);
	printf("\n\n\n----------------------- aperte para continuar");
	getch();
	system("cls");
	AtualizaSalario(&cadastro);	
	ListaFuncionarios(cadastro);
}