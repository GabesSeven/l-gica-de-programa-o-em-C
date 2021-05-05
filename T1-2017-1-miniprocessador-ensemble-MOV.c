#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
char MOV1(char dados[], char resu[])
{
	int i,cont,ver,NUM;
	char var,mov[9],memoria[4],resp[9];
	
	fflush(stdin);
		
	do{
	system("cls");
	printf("\n\nDIGITE UM VALOR EM DECIMAL DE 0 - 256, REFERENTE A POSICAO DA MEMORIA\n");
	cont=ver=0;
	gets(memoria);
	for(i=0;i<strlen(memoria);i++) cont++;
	if (cont>4)ver=1;
	else 
	{ 
		if(cont==1)
		{
			memoria[2]=memoria[0];
			memoria[1]='0';
			memoria[0]='0';
		}
		else if(cont==2)
		{
			memoria[2]=memoria[1];
			memoria[1]=memoria[0];
			memoria[0]='0';
		}
		else if(cont==0) ver=1;
		memoria[3]='\0';
		for(i=0;i<strlen(memoria);i++) if(memoria[i]!='0'&&memoria[i]!='1'&&memoria[i]!='2'&&memoria[i]!='3'&&memoria[i]!='4'&&memoria[i]!='5'&&memoria[i]!='6'&&memoria[i]!='7'&&memoria[i]!='8'&&memoria[i]!='9') ver=1;
	}
	if (ver==0) NUM = atoi(memoria);
	if (NUM>256) ver=1;
	}while(ver!=0);
	
	fflush(stdin);
	
	if(cont==1)
	{
		mov[0]='A';
		mov[1]=',';
		mov[2]='[';
		mov[3]=memoria[2];
		mov[4]=']';
		mov[5]='\n';
		mov[6]='\0';
		resp[0]='A';
		resp[1]='0';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[2];
		resp[5]='\n';
		resp[6]='\0';
	}
	else if(cont==2)
	{
		mov[0]='A';
		mov[1]=',';
		mov[2]='[';
		mov[3]=memoria[1];
		mov[4]=memoria[2];
		mov[5]=']';
		mov[6]='\n';
		mov[7]='\0';
		resp[0]='A';
		resp[1]='0';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[1];
		resp[5]=memoria[2];
		resp[6]='\n';
		resp[7]='\0';
	}
	else
	{
		mov[0]='A';
		mov[1]=',';
		mov[2]='[';
		mov[3]=memoria[0];
		mov[4]=memoria[1];
		mov[5]=memoria[2];
		mov[6]=']';
		mov[7]='\n';
		mov[8]='\0';
		resp[0]='A';
		resp[1]='0';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[0];
		resp[5]=memoria[1];
		resp[6]=memoria[2];
		resp[7]='\n';
		resp[8]='\0';	
	}
	
	strcat (dados, mov);
	strcat (resu, resp);
	
	system("cls");
	printf("%s\n\nPARA CONTINUAR PRECIONE QUALQUER TECLA...", mov);		
	getch();
	system("cls");
}
//---------------------------------------------------------------------------------------------------------------
char MOV2(char dados[], char resu[])
{int i,cont,ver,NUM;
	char var,mov[9],memoria[4],resp[9];
	
	mov[0]='[';
		
	do{
	system("cls");
	printf("\n\nDIGITE UM VALOR EM DECIMAL DE 0 - 256, REFERENTE A POSICAO DA MEMORIA\n");
	cont=ver=0;
	gets(memoria);
	for(i=0;i<strlen(memoria);i++) cont++;
	if (cont>4)ver=1;
	else 
	{ 
		if(cont==1)
		{
			memoria[2]=memoria[0];
			memoria[1]='0';
			memoria[0]='0';
		}
		else if(cont==2)
		{
			memoria[2]=memoria[1];
			memoria[1]=memoria[0];
			memoria[0]='0';
		}
		else if(cont==0) ver=1;
		memoria[3]='\0';
		for(i=0;i<strlen(memoria);i++) if(memoria[i]!='0'&&memoria[i]!='1'&&memoria[i]!='2'&&memoria[i]!='3'&&memoria[i]!='4'&&memoria[i]!='5'&&memoria[i]!='6'&&memoria[i]!='7'&&memoria[i]!='8'&&memoria[i]!='9') ver=1;
	}
	if (ver==0) NUM = atoi(memoria);
	if (NUM>256) ver=1;
	}while(ver!=0);
	
	fflush(stdin);
	
	if(cont==1)
	{
		mov[1]=memoria[2];
		mov[2]=']';
		mov[3]=',';
		mov[4]='A';
		mov[5]='\n';
		mov[6]='\0';
		resp[0]='A';
		resp[1]='2';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[2];
		resp[5]='\n';
		resp[6]='\0';
	}
	else if(cont==2)
	{
		mov[1]=memoria[1];
		mov[2]=memoria[2];
		mov[3]=']';
		mov[4]=',';
		mov[5]='A';
		mov[6]='\n';
		mov[7]='\0';
		resp[0]='A';
		resp[1]='2';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[1];
		resp[5]=memoria[2];
		resp[6]='\n';
		resp[7]='\0';	
	}
	else
	{
		mov[1]=memoria[0];
		mov[2]=memoria[1];
		mov[3]=memoria[2];
		mov[4]=']';
		mov[5]=',';
		mov[6]='A';
		mov[7]='\n';
		mov[8]='\0';
		resp[0]='A';
		resp[1]='2';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[0];
		resp[5]=memoria[1];
		resp[6]=memoria[2];
		resp[7]='\n';
		resp[8]='\0';	
	}
	strcat (dados, mov);
	strcat (resu, resp);
	
	system("cls");
	printf("%s\n\nPARA CONTINUAR PRECIONE QUALQUER TECLA...", mov);		
	getch();
	system("cls");
}
//---------------------------------------------------------------------------------------------------------------
char MOV3(char dados[], char resu[])
{
	int i,cont,ver;
	char var,mov[7],memoria[4],resp[9];
	
	fflush(stdin);
		
	do{
	system("cls");
	printf("\n\nDIGITE UM VALOR EM DECIMAL DE 0 - 256, REFERENTE A VALOR A SER SALVO NA MEMORIA\n");
	printf("\nOBS: O PROGRAMA SÓ RECONHECE VALORES INTEIROS E DECIMAIS NO INTERVALO DE 0 - 999 \n");
	cont=ver=0;
	gets(memoria);
	for(i=0;i<strlen(memoria);i++) cont++;
	if (cont>4)ver=1;
	else 
	{ 
		if(cont==1)
		{
			memoria[2]=memoria[0];
			memoria[1]='0';
			memoria[0]='0';
		}
		else if(cont==2)
		{
			memoria[2]=memoria[1];
			memoria[1]=memoria[0];
			memoria[0]='0';
		}
		else if(cont==0) ver=1;
		memoria[3]='\0';
		for(i=0;i<strlen(memoria);i++) if(memoria[i]!='0'&&memoria[i]!='1'&&memoria[i]!='2'&&memoria[i]!='3'&&memoria[i]!='4'&&memoria[i]!='5'&&memoria[i]!='6'&&memoria[i]!='7'&&memoria[i]!='8'&&memoria[i]!='9') ver=1;
	}
	}while(ver!=0);
	
	fflush(stdin);
	
	if(cont==1)
	{
		mov[0]='A';
		mov[1]=',';
		mov[2]=memoria[2];
		mov[3]='\n';
		mov[4]='\0';
		resp[0]='B';
		resp[1]='0';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[2];
		resp[5]='\n';
		resp[6]='\0';
	}
	else if(cont==2)
	{
		mov[0]='A';
		mov[1]=',';
		mov[2]=memoria[1];
		mov[3]=memoria[2];
		mov[4]='\n';
		mov[5]='\0';
		resp[0]='B';
		resp[1]='0';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[1];
		resp[5]=memoria[2];
		resp[6]='\n';
		resp[7]='\0';
	}
	else
	{
		mov[0]='A';
		mov[1]=',';
		mov[2]=memoria[0];
		mov[3]=memoria[1];
		mov[4]=memoria[2];
		mov[5]='\n';
		mov[6]='\0';
		resp[0]='B';
		resp[1]='0';
		resp[2]='h';
		resp[3]=' ';
		resp[4]=memoria[0];
		resp[5]=memoria[1];
		resp[6]=memoria[2];
		resp[7]='\n';
		resp[8]='\0';	
	}
	strcat (dados, mov);
	strcat (resu, resp);
	
	system("cls");
	printf("%s\n\nPARA CONTINUAR PRECIONE QUALQUER TECLA...", mov);	
	getch();
	system("cls");
}
//---------------------------------------------------------------------------------------------------------------
int main()
{
	fflush(stdin);
	int tam2,cont,i,ver=0;
	char tam[3],resu[1000],dados[1000];
	dados[0]=resu[0]='\0';
	printf("BEM VINDO AO MINI PROCESSADOR MOVIDO SOMENTE A MOV\n\n\nPARA CONTINUAR PRECIONE QUALQUER TECLA...\n");
	getch();
	system("cls");
	printf("OBS:\n- O PROGRAMA E CAPAZ DE LER SOMENTE 99 COMANDO MOV POR VEZ\n- A CADA VEZ QUE FOR DIGITADO 'MOV' PRECIONE ENTER\n");
	printf("\n\n\nPARA CONTINUAR PRECIONE QUALQUER TECLA...\n");
	getch();
	do{
	cont=ver=0;
	system("cls");
	printf("SELECIONE A QUANTIDADE DE COMANDOS QUE DESEJA FAZER\n");
	gets(tam);
	for(i=0;i<=strlen(tam);i++) cont++;
	if (cont>3) ver=1;
	else 
	{
	tam[2]='\0';	
	for(i=0;i<strlen(tam);i++) if(tam[i]!='0'&&tam[i]!='1'&&tam[i]!='2'&&tam[i]!='3'&&tam[i]!='4'&&tam[i]!='5'&&tam[i]!='6'&&tam[i]!='7'&&tam[i]!='8'&&tam[i]!='9') ver=1;
	}
	if (ver==0) tam2 = atoi(tam);
	if (tam2<=0) ver=1;
	if (ver==1) 
	{
	printf("\n\t\t\t----------%s----------\n\nOPCAO INVALIDA... APERTE QUALQUER TECLA E DIGITE NOVAMENTE\n\n",tam);
	getch();	
	}
	}while(ver!=0);
	
	system("cls");
	printf("\n%d MOVIMENTOS SELECIONADOS...APERTE QUALQUER TECLA PARA PROSSEGUIR\n", tam2);
	getch();
	
	char n;
	
	for(i=0;i<tam2;i++)
	{
		system("cls");
		do{
		system("cls");
		fflush(stdin);
		printf("-------------------MOV %d-------------------\n\n", i+1);
		printf("ESCOLHA ENTRE AS OPCOES:\n1 - MOV A,[ ]\n2 - MOV [ ],A\n3 - MOV A, \n\n\n");
		scanf("%c", &n);
		if(n!='1'&&n!='2'&&n!='3') 
		{
			printf("\n\n\nOPCAO INVALIDA...APERTE QUALQUER TECLA E DIGITE NOVAMENTE\n\n");
			getch();
		}
		}while(n!='1'&&n!='2'&&n!='3');
		system("cls");
		switch(n)
		{
			case '1':
			MOV1(dados,resu);
			break;
			case '2':
			MOV2(dados,resu);
			break;
			case '3':
			MOV3(dados,resu);
			break;
		}	
	}
	printf("%s\n\n%s\n\n\n", dados, resu);	
}