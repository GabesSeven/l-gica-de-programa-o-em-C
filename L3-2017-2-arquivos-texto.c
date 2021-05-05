// 1 - Escreva um programa que mostre um arquivo texto no vídeo. O nome do arquivo deve ser
// fornecido pelo teclado. 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
int main() {
	char nome[25],c;
	FILE *arq;
	fflush(stdin);
	printf("digite o nome do arquivo que deseja ser aberto\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"rt"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	while(!feof(arq)) {
		fread(&c,sizeof(c),1,arq);
		printf("%c",c);
	}
	getch();
	fclose(arq);
}

// 3 - Faça um programa que processe um texto convertendo as letras maiúsculas em minúsculas.
// A inicial de cada frase deve ficar maiúscula.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	char nome[25],c;
	FILE *arq,*arq2;
	fflush(stdin);
	printf("digite o nome do arquivo que deseja ser aberto\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	arq2 = fopen("troca.txt","a+t");
	system("cls");
	c = getc(arq);
	c = toupper(c);
	putc(c,arq2);
	while(!feof(arq)) {
		c = getc(arq);
		if(c==' ') {
			putc(c,arq2);
			c = getc(arq);
			c = toupper(c);
			putc(c,arq2);
		}
		else if(c>64&&c<91) {
			c = tolower(c);
			putc(c,arq2);
		}
		else if(c>96&&c<123) {
			c = toupper(c);
			putc(c,arq2);
		}
	}
	rewind(arq2);
	fflush(stdin);
	while(!feof(arq2)) {
		fread(&c,sizeof(c),1,arq2);
		printf("%c",c);
	}
	getch();
	fclose(arq);
	fclose(arq2);
	//char *arquivo = "c:\\a.txt";
	//remove(arquivo);
	//rename("troca.txt",nome);
}

// 5 - Faça um programa no qual o usuário informa o nome do arquivo texto e uma palavra, e retor-
// ne o número de vezes que aquela palavra aparece no arquivo.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	fflush(stdin);
	char nome[25],texto[30],nome2[20],c;
	int cont=0;
	FILE *arq;
	printf("digite o nome do arquivo que deseja ser aberto\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	system("cls");
	printf("digite a palavra que deseja procurar\n\n");
	gets(nome2);
	system("cls");
	while(!feof(arq)) {
		fscanf(arq,"%s",texto);
		if(strstr(texto,nome2)!=0) cont++;
	}
	rewind(arq);
	fflush(stdin);
	while(!feof(arq)) {
		fread(&c,sizeof(c),1,arq);
		printf("%c",c);
	}
	printf("\n\n===========a palavra aparece %d vezes", cont);
	getch();
	fclose(arq);
}

// 7 - Faça um programa que copie um arquivo texto em outro arquivo mantendo a estrutura de
// linhas.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	fflush(stdin);
	char nome[25],c;
	FILE *arq,*arq2;
	printf("digite o nome do arquivo que deseja ser aberto\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	arq2 = fopen("copia.txt","w+");
	system("cls");
	//===============================
	while(!feof(arq)) {
		c = getc(arq);
		putc(c,arq2);
	}
	fclose(arq);
	rewind(arq2);
	fflush(stdin);
	while(!feof(arq2)) {
		fread(&c,sizeof(c),1,arq2);
		printf("%c",c);
	}
	getch();
	fclose(arq2);
}

// 9 - Faça um programa que leia o arquivo texto “texto.txt” e grave todas as palavras iniciadas
// com vogais no arquivo texto “vogais.txt”. O programa deve também mostrar na tela o ar-
// quivo “texto.txt”, durante a procura das palavras, e o número de palavras gravadas em
// “vogais.txt”.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	fflush(stdin);
	char texto[30],c,ch='\n';
	FILE *arq,*arq2;
	if((arq = fopen("texto.txt","r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	system("cls");
	arq2 = fopen("vogais.txt","a+t");
	//========================
	while(!feof(arq)) {	
		fscanf(arq,"%s",texto);
		printf("%s\t",texto);
		if(toupper(texto[0])=='A'||toupper(texto[0])=='U'||toupper(texto[0])=='O'||toupper(texto[0])=='I'||toupper(texto[0])=='E') {
		fputs(texto,arq2);
		putc(ch,arq2);	
		}
	}
	fclose(arq);
	rewind(arq2);
	fflush(stdin);
}

// 11 - Faça um programa que recebe um vetor de n números, converta cada um desses números
// para binário e grave a sequência de 0s e 1s em um arquivo texto. Cada número deve ser
// gravado em uma linha.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	fflush(stdin);
	char nome[25];
	int i;
	FILE *arq;
	printf("digite o nome do arquivo que deseja ser gravado\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	int v[11] = {0,1,2,3,4,5,6,7,8,9,10}; 
	char str[30],c='\0';
	for(i=0;i<11;i++) {
		char bin[20];
		itoa(v[i],bin,2); 	
		fputs(bin,arq);
		putc(c,arq);
	}
	rewind(arq);
	fflush(stdin);
	while(!feof(arq)) {
		c = getc(arq);
		printf("%c",c);
	}
	getch();
	fclose(arq);
}

// 13 - Faça um programa que formate um texto qualquer, imprimindo 60 caracteres por linha com
// margens direita e esquerda alinhadas, páginas numeradas e com no máximo 60 linhas por
// página. O arquivo é composto por linhas de texto e linhas de controle, onde as linhas de con-
// trole podem ser do tipo: .pp (a próxima linha começa com parágrafo) e, .dS e .dE (o texto
// entre essas duas linhas não deve ser formatado).
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	fflush(stdin);
	char str[4],texto[60],nome[25],c;
	int i,ver=0;
	FILE *arq;
	printf("digite o nome do arquivo que deseja ser lido\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	int pag=1,linha=1;
	while(!feof(arq)) {
		if(strcmp(str,".dS")==0) {
			ver=1;
			c = getc(arq);
			printf("%c",c);
			str[0]=str[1];
			str[1]=str[2];
			str[3]=c;
			str[4]='\0';
			if(strcmp(str,".dE")==0&&ver==1)ver=0;
		}
		else {
		if(linha==1)printf("//============================================================================================================== pag. %d\n", pag);
		if(linha==1)printf("\t");
		printf("%d - ",linha);
		for(i=0;i<60;i++) {
			c = getc(arq);
			if(c!='\n')printf("%c",c);
			str[0]=str[1];
			str[1]=str[2];
			str[3]=c;
			str[4]='\0';
			if(strcmp(str,".pp")==0) {
				linha++;	
				printf("\n");	
			}
		}
		getch();
		linha++;
		if(linha==60) {
			linha=1;
			pag++;	
		}
		printf("\n");
		}
	}
	getch();
	fclose(arq);
}

// 15 - Considere um arquivo de dados do tipo texto com o seguinte conteúdo:
// 3
// Cida Souza
// 5.5
// 4.0
// José Silva e Silva
// 7.5
// 8.5
// Maria das Dores
// 5.0
// 6.0
// O arquivo acima é apenas um exemplo. Neste arquivo de alunos a primeira linha contém o
// número de alunos no arquivo. As linhas seguintes contém os seguintes dados:
// nome do aluno com no máximo 50 caracteres;
// nota da primeira prova;
// nota da segunda prova.
// Escreva um programa qu
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	fflush(stdin);
	char str[51],nome[25],str2[2],nota1[4],nota2[4];
	int c,k,i,quant;
	float fl1,fl2;
	FILE *arq;
	printf("digite o nome do arquivo que deseja ser lido\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	system("cls");
	c = getc(arq);
	str2[0] = c;
	str2[1] = '\0';
	getc(arq);
	quant = atoi(str2);
	for(i=0;i<quant;i++) {
		fgets(str,20,arq);
		fgets(nota1,5,arq);
		nota1[3]='\0';
		fgets(nota2,5,arq);
		nota2[3]='\0';
		fl1 = atof(nota1);
		fl2 = atof(nota2);
		if(((fl1+fl2)/2)>=5) printf("================%s\nmedia: %.2f\n",str,(fl1+fl2)/2);
	}
	printf ("\n\n\n\n em um total de %d alunos\n",quant);
	getch();
	fclose(arq);
}

// 17 - Escreva um programa que compare dois arquivos especificados pelo usuário e imprima sem-
// pre que os caracteres dos dois arquivos coincidirem. Por exemplo:
// arquivo1.txt
// Olá, pessoal!
// arquivo2.txt
// Oi, como vai?
// Neste caso, os caracteres na primeira e décima primeira posição são iguais nos dois arqui-
// vos. A saída do seu programa deve ser algo como:
// 1 - O (79)
// 11 - a (97)
// Os valores entre parênteses são os respectivos códigos ASCII dos caracteres. 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<conio.h>
#include<ctype.h>
int main() {
	fflush(stdin);
	char str[51],nome[25],str2[2],nota1[4],nota2[4];
	int c,k,i,quant;
	float fl1,fl2;
	FILE *arq,*arq2;
	printf("digite o nome do arquivo que deseja ser lido\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	system("cls");
	printf("digite o nome do arquivo que deseja ser lido\n\n");
	gets(nome);
	nome[19]='\0';
	strcat(nome,".txt");
	if((arq2=fopen(nome,"r+t"))==NULL) {
		printf("nao deu p\ abrir\n");
		exit(1);
	}
	system("cls");
	char cm1,cm2;
	int cont=0;
	while(!feof(arq)||!feof(arq2)) {
		cm1 = getc(arq);
		cm2 = getc(arq2);
		cont++;
		if(cm1==cm2) printf("%d  %c  (%d)\n",cont,cm2,cm2);	
	}
	getch();
	fclose(arq);
}