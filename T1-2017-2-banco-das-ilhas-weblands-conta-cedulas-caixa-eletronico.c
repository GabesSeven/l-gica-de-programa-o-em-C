#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
//------------------------------------------------------------------------------------------
void calculando(char str[])
{
	int i,j,ver2=0,ver3=0;
	if (str[0]=='1'&& str[1]=='0'&&str[2]=='0') 
	{
		printf("cem ");
		return;
	}
	else
	{	
		switch(str[0])
		{
			case '0': 
			break;
			case '1':
			printf("cento");
			ver3=1;
			break;
			case '2':
			printf("duzentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1;
			break;
			case '3':
			printf("trezentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1; 
			break;
			case '4':
			printf("quatrocentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1; 
			break;
			case '5':
			printf("quinhentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1; 
			break;
			case '6':
			printf("seiscentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1; 
			break;
			case '7':
			printf("setecentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1; 
			break;
			case '8':
			printf("oitocentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1; 
			break;
			case '9':
			printf("novecentos");
			if(str[1]=='0'&&str[2]=='0') return;
			else ver3=1; 
			break;
		}
		if (ver3==1) printf(" e ");
		if (str[1]=='0') 
		{
			switch(str[2])
			{
				case '0':
				return;
				case '1':
				printf("um");
				break;
				case '2':
				printf("dois");
				break;
				case '3':
				printf("tres");
				break;
				case '4':
				printf("quatro");
				break;
				case '5':
				printf("cinco");
				break;
				case '6':
				printf("seis");
				break;
				case '7':
				printf("sete");
				break;
				case '8':
				printf("oito");
				break;
				case '9':
				printf("nove");
				break;
			}
		}	
		else 
		{
			switch (str[1])
			{
				case '1':
				switch (str[2])
				{ 					
					case '0':
					printf("dez");
					return;
					case '1':
					printf("onze");
					return;
					case '2':
					printf("doze");
					return;
					case '3':
					printf("treze");
					return;
					case '4':
					printf("quatorze");
					return;
					case '5':
					printf("quinze");
					return;
					case '6':
					printf("dezesseis");
					return;
					case '7':
					printf("dezessete");
					return;
					case '8':
					printf("dezoito");
					return;
					case '9':
					printf("dezenove");
					return;
				}
				case '2':
				printf("vinte");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;
				}
				case '3':
				printf("trinta");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;
				}
				case '4':
				printf("quarenta");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;
				}
				case '5':
				printf("cinquenta");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;
				}
				case '6':
				printf("sessenta");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;	
				}
				case '7':
				printf("setenta");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;	
				}
				case '8':
				printf("oitenta");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;	
				}
				case '9':
				printf("noventa");
				if (str[2]=='0') return;
				else 
				{
					ver2=1;
					break;	
				}
			}
		}	
		if(ver2==1)
		{
			if(str[2]=='1'||str[2]=='2'||str[2]=='3'||str[2]=='4'||str[2]=='5'||str[2]=='6'||str[2]=='7'||str[2]=='8'||str[2]=='9') printf(" e ");
			switch(str[2])
			{
				case '1':
				printf("um");
				break;
				case '2':
				printf("dois");
				break;
				case '3':
				printf("tres");
				break;
				case '4':
				printf("quatro");
				break;
				case '5':
				printf("cinco");
				break;
				case '6':
				printf("seis");
				break;
				case '7':
				printf("sete");
				break;
				case '8':
				printf("oito");
				break;
				case '9':
				printf("nove");
				break;
			}
		}
	}
}
//------------------------------------------------------------------------------
void cheque()
{	
	system("cls");
	printf("\t\t\tBEM VINDO AO PREENCHIMENTO DE CHEQUE\n\nPRECIONE QUALQUER PARA CONTINUAR...");
	getch();
	system("cls");
	char r1[16],r2[16];
	int ver=0,i,j,cont=0,contPONTO=0,sin;
	do
	{
		printf("OBS: USE PONTO PARA INSERIR O VALOR DOS CENTAVOS\n");
		printf("INSIRA NO MAX 15 DIGITOS (12 PARA OS BITS, 1 PARA O PONTO E 2 PARA OS BITSCENTS)\n\n");
		printf("\t\tAPOS DIGITAR O VALOR PRESCIONE ENTER\n");
		gets(r1);
		ver=cont=contPONTO=0;
//verificações
		for (i=0; i<strlen(r1); i++) cont++;
		if (cont>15) ver=1;
		else
		{
			for (i=0; i<strlen(r1); i++) 
			{
				if(r1[i]=='.')
				{
					contPONTO++;
					sin=i;
				}	
			} 
			if (contPONTO==1) ver=0;
			else ver=1;
			if(ver==0) 
			{
				for (i=0; i<strlen(r1); i++) if (r1[i]!='0'&&r1[i]!='1'&&r1[i]!='2'&&r1[i]!='3'&&r1[i]!='4'&&r1[i]!='5'&&r1[i]!='6'&&r1[i]!='7'&&r1[i]!='8'&&r1[i]!='9'&&i!=sin) ver=1;
			}
		}
		system("cls");		
	}while(ver!=0);
//inserido um vetor ao outro
	int aux=11;
	char cent[4],reais[4],mil[4],milhoes[4],bilhoes[4];
	cent[3]='0';
	for(i=0;i<strlen(r1);i++)
	{
		if(r1[i]=='.')
		{
			r2[14]=r1[i+2];
			r2[13]=r1[i+1];
			r2[12]='0';
			
			for(j=i-1;j>=0;j--)
			{
				r2[aux]=r1[j];
				aux--;	
			}
		}
	}
	for(i=0;i<=aux;i++) r2[i]='0';
	r2[15]='\0';	
//dividindo os vetores
	cent[2]=r2[14];
	cent[1]=r2[13];
	cent[0]=r2[12];
	reais[2]=r2[11];
	reais[1]=r2[10];
	reais[0]=r2[9];
	mil[2]=r2[8];
	mil[1]=r2[7];
	mil[0]=r2[6];
	milhoes[2]=r2[5];
	milhoes[1]=r2[4];
	milhoes[0]=r2[3];
	bilhoes[2]=r2[2];
	bilhoes[1]=r2[1];
	bilhoes[0]=r2[0];
	
	cent[3]='\0';
	reais[3]='\0';
	mil[3]='\0';
	milhoes[3]='\0';
	bilhoes[3]='\0';	
//mandando para a função
	printf("\t\t\t----------%s-----------\n", r1);
    calculando(bilhoes);
	if(bilhoes[0]!='0'||bilhoes[1]!='0'||bilhoes[2]!='0') printf(" BILHOES\n");
	calculando(milhoes);
	if(milhoes[0]!='0'||milhoes[1]!='0'||milhoes[2]!='0') printf(" MILHOES\n"); 
	calculando(mil);
	if(mil[0]!='0'||mil[1]!='0'||mil[2]!='0') printf(" MIL\n");
	calculando(reais);
	if(reais[0]!='0'||reais[1]!='0'||reais[2]!='0') printf(" BITS\n");
	calculando(cent);
	if(cent[0]!='0'||cent[1]!='0'||cent[2]!='0') printf(" BITSCENTS\n");	
}
//----------------------------------------------------------------------------------------------------
void saque()
{
	printf("\t\t\tBEM VINDO AO SAQUE - CAIXA ELETRONICO\n\nPRECIONE QUALQUER PARA CONTINUAR...");
	getch();
	system("cls");
	int saque2,i,ver=0,cont=0,contPONTO=0,sin,notas[]={100,50,20,10,5,2,1},moedas[]={50,25,10,1};
	char saque[16];
	do
	{	
		printf("OBS: USE PONTO PARA INSERIR O VALOR DOS CENTAVOS\n");
		printf("INSIRA NO MAX 15 DIGITOS (12 PARA OS BITS, 1 PARA O PONTO E 2 PARA OS BITSCENTS)\n\n");
		printf("\t\tAPOS DIGITAR O VALOR PRESCIONE ENTER\n");
		gets(saque);
		ver=cont=contPONTO=0;
//verificações
		for (i=0; i<strlen(saque); i++) cont++;
		if (cont>15) ver=1;
		else
		{
			for (i=0; i<strlen(saque); i++) 
			{
				if(saque[i]=='.')
				{
					contPONTO++;
					sin=i;
				}	
			} 
			if (contPONTO==1) ver=0;
			else ver=1;
			if(ver==0) 
			{
				for (i=0; i<strlen(saque); i++) if (saque[i]!='0'&&saque[i]!='1'&&saque[i]!='2'&&saque[i]!='3'&&saque[i]!='4'&&saque[i]!='5'&&saque[i]!='6'&&saque[i]!='7'&&saque[i]!='8'&&saque[i]!='9'&&i!=sin) ver=1;
			}
		}
		system("cls");		
	}while(ver!=0);
//declarando os reais e os centavos
	int aux=11,j,k,contcent=0;
	char reais[13],cent[3];
	for(i=0;i<strlen(saque);i++)
	{
		if(saque[i]=='.')
		{
			for(k=i;k<strlen(saque);k++) if(saque[k]=='0'||saque[k]=='1'||saque[k]=='2'||saque[k]=='3'||saque[k]=='4'||saque[k]=='5'||saque[k]=='6'||saque[k]=='7'||saque[k]=='8'||saque[k]=='9') contcent++;
			if (contcent>2)
			{
				cent[1]=saque[i+2];
				cent[0]=saque[i+1];
				cent[2]='\0';
			}
			else
			{
				cent[0]=saque[i+1];
				cent[1]='0';
				cent[2]='\0';
			} 
			for(j=i-1;j>=0;j--)
			{
				reais[aux]=saque[j];
				aux--;
			}
		}
	}
	for(i=0;i<=aux;i++) reais[i]='0';
	reais[12]='\0';
//dividindo a grana
	printf("\n%s,%s\n\n", reais,cent);
//reais
	int nreais, ncent, Ncont=0;
	nreais = atoi(reais);
	for(i=0;i<7;i++)
	{	
		while(nreais>=notas[i])
		{
			nreais = nreais - notas[i];
			Ncont++;
		}
		if(Ncont!=0) 
		{
			if(notas[i]==1) printf("\n%dX: %d BitsCents\n", Ncont, notas[i]);
			else  printf("\n%dX: %d Bits\n", Ncont, notas[i]);
		}	
		Ncont=0;
	}
//centavos
	ncent = atoi(cent);
	for(i=0;i<4;i++)
	{	
		while(ncent>=moedas[i])
		{
			ncent = ncent - moedas[i];
			Ncont++;
		}
		if(Ncont!=0) printf("\n%dX: %d BitsCents\n", Ncont, moedas[i]);	
		Ncont=0;
	}
}
//-------------------------------------------------------------------------------------
int main()
{
	char n2,senha2[8],senha[]={'b','c','c','2','0','1','7','\0'} ;
	int n,versenha=0,k;
	do
	{
		system("cls");
		versenha=0;
		printf("SENHA CORRETA - bcc2017\n\ndigite sua senha:\n\n");
		gets(senha2);
		for(k=0;k<strlen(senha2);k++) if(senha2[k]!=senha[k]) versenha=1;
		if (versenha==1) printf("\nSENHA INCORRETA, APERTE QUALQUER TECLA E TENTE NOVAMENTE\n");
		printf("----senha correta: %s\n----senha inserida: %s",senha, senha2 ) ;
		if (versenha==0) printf("\nSENHA CORRETA, APERTE QUALQUER TECLA PARA CONTINUAR\n");
		getch();
	}while(versenha!=0);
	do{	
		system ("cls");
		do{
		printf("BANCO DAS ILHAS WEBLANDS\n-para saques - tecle 1\n-para cheques - tecle 2\n");
		scanf("%d",&n);
		if(n!=2&& n!=1) 
		{
			printf("\nOPCAO INVALIDA, PRECIONE QUALQUER TECLA E DIGITE NOVAMENTE\n");
			getch();
			system("cls");
		}
		}while(n!=2&&n!=1);
		system("cls");
		if(n==1) saque();
		else if (n==2) cheque();
		printf("\n\n\nPRECIONE QUALQUER TECLA PARA CONTINUAR\n");
		getch();
		system("cls");
		do{
			printf("deseja continuar?\nS - sim\nN - nao\n");
			scanf("%c", &n2);
			if (n2!='N'&&n2!='n'&&n2!='S'&&n2!='s')
			{
				printf("\n\nOPCAO INVALIDA\n\n");
				system("cls");
			}
		}while(n2!='N'&&n2!='n'&&n2!='S'&&n2!='s');
	}while(n2!='N'&&n2!='n');
}