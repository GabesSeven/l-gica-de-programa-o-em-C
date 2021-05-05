#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<string.h>
typedef struct
{
	char nome[20],desenho[20],tel[15],idade[4],preco[9];
	int existe;
}tatoo;
//-------------------------------------------------------------------------------------------
void deletar(char nome[])
{
	FILE *arq,*arq2;
	tatoo cad;
	arq = fopen(nome,"r+b");
	arq2 = fopen("trocaa.dat","wb");
	while(fread(&cad,sizeof(cad),1,arq)==1) if(cad.existe!=1) fwrite(&cad,sizeof(cad),1,arq2);
	fclose(arq);
	fclose(arq2);
	remove(nome);
	rename("trocaa.dat",nome);
	return;
}
//--------------------------------------------------------------------------------------------
int funcao53(char num)
{
	FILE *arq;
	system("cls");
	fflush(stdin);
	char nome[35],novo_nome[35],resp;
	if(num=='1'){
		printf("digite o nome do arquivo que deseja renomear\n");
		gets(nome);
		nome[29]='\0';
		strcat(nome,".dat");
		if ((arq = fopen(nome,"rb"))==NULL){
			printf("\n\nerro ao abrir o arquivo....aperte qualquer tecla para continuar\n\n");
			getch();
			return 0;
		}
		fclose(arq);
		printf("\n\ndigite o novo nome do arquivo\n");
		gets(novo_nome);
		novo_nome[29]='\0';
		strcat(novo_nome,".dat");
		rename(nome,novo_nome);
	}
	//
	else{
		printf("digite o nome do arquivo que deseja excluir\n\n");
		gets(nome);
		nome[29]='\0';
		strcat(nome,".dat");
		if ((arq = fopen(nome,"rb"))==NULL){
			printf("\n\nerro ao abrir o arquivo....aperte qualquer tecla para continuar\n\n");
			getch();
			return 0;
		}
		fclose(arq);
		do{
			system("cls");
			printf("deseja mesmo excluir esse arquivo??\nS - sim\nN - nao\n");
			scanf("%c",resp);
		}while(resp!='s'&&resp!='S'&&resp!='n'&&resp!='N');
		if(resp=='S'||resp=='s') remove(nome);
		else return 0;
	}
	return 1;
}	
//--------------------------------------------------------------------------------------
int ConfNum(char str[])
{
	int i,ver;
	ver=0;
	for(i=0;i<strlen(str);i++) if(str[i]!='0'&&str[i]!='1'&&str[i]!='2'&&str[i]!='3'&&str[i]!='4'&&str[i]!='5'&&str[i]!='6'&&str[i]!='7'&&str[i]!='8'&&str[i]!='9') ver=1;
	if(ver==1) return 1;
	else return 0;
}
//-------------------------------------------------------------------------------------------
tatoo modifica(char num, tatoo *cad)
{
	system("cls");
	fflush(stdin);
	switch(num)
	{		
		case '1':
			printf("digite o novo nome\n\n");
			gets((*cad).nome);
			break;
		case '2':
			do{
				system("cls");
				printf("digite o novo valor da idade do cliente:\n");
				gets((*cad).idade);
				(*cad).idade[3]='\0';
			}while(ConfNum((*cad).idade)==1);
			break;
		case '3':
			do{
				system("cls");
				printf("digite o novo numero de telefone do cliente:\n");
				(*cad).tel[14]='\0';
				gets((*cad).tel);
			}while(ConfNum((*cad).tel)==1);
			break;
		case '4':
			printf("digite o novo nome da tatoo do cliente:\n");
			gets((*cad).desenho);
			break;
		case '5':
			do{
				system("cls");
				printf("digite o novo valor da tatoo(somente os valor inteiro):\n");
				gets((*cad).preco);
				(*cad).preco[8]='\0';
			}while(ConfNum((*cad).preco)==1);
			break;
	}
	return *cad;
}
//---------------------------------------------------------------------------------------------
void mostra()
{
	printf("-----------------------------MOSTRAR LISTA-----------------------\n\naperte qualque tecla para continuar...\n\n");
	getch();
	system("cls");
	fflush(stdin);
	char nome[35];
	tatoo cad;
	FILE *arq;
	printf("digite o nome do arquivo que deseja abrir\n\n");
	gets(nome);
	nome[29]='\0';
	strcat(nome,".dat");
	if ((arq = fopen(nome,"r+b"))==NULL){
		printf("\n\nerro ao abrir o arquivo....aperte qualquer tecla para continuar\n\n");
		getch();
		return;
	}
	system("cls");
	rewind(arq);
	while(fread(&cad, sizeof(cad),1,arq)==1){	
		if(cad.existe==0){
			printf("nome: %s\n",cad.nome);
			printf("idade: %s anos\n",cad.idade);
			printf("telefone: %s\n",cad.tel);
			printf("nome da tatoo: %s\n",cad.desenho);
			printf("preco: %s\n\n",cad.preco);	
		}
	}
	getch();
	printf("aperte para continuar...\n");
	fclose(arq);
}
//----------------------------------------------------------------------------------------------
void cadastrar(tatoo *cad)
{
	int i;
	char nome[35];
	printf("-----------------------------CADASTRO-----------------------\n\naperte qualque tecla para continuar...\n\n");
	getch();
	fflush(stdin);
	FILE *arq;
	char resp;
	system("cls");
	//
	printf("digite o nome do arquivo que deseja cadastrar\n");
	gets(nome);
	nome[29]='\0';
	strcat(nome,".dat");
	if ((arq = fopen(nome,"r+b"))==NULL){
		arq = fopen(nome,"wb");
	}
	system("cls");
	//
	do{
		fflush(stdin);
		system("cls");
		(*cad).existe=0;
		printf("digite o nome:\n");
		gets((*cad).nome);
		//
		do{
			system("cls");
			printf("digite a idade do cliente:\n");
			gets((*cad).idade);
			(*cad).idade[3]='\0';
		}while(ConfNum((*cad).idade)==1);
		//
		system("cls");
		do{
			system("cls");
			printf("digite o telefone do cliente:\n");
			(*cad).tel[14]='\0';
			gets((*cad).tel);
		}while(ConfNum((*cad).tel)==1);
		//
		system("cls");
		printf("digite o nome da tatoo do cliente:\n");
		gets((*cad).desenho);
		//
		do{
			system("cls");
			printf("digite o valor da tatoo(somente os valor inteiro):\n");
			gets((*cad).preco);
			(*cad).preco[8]='\0';
		}while(ConfNum((*cad).preco)==1);
		system("cls");
		//
		fseek(arq,0,2);
		fwrite(cad,sizeof(*cad),1,arq);
		fflush(stdin);
		do{
			system("cls");
			printf("deseja continuar a cadastrar??\nS - sim\nN - nao\n\n");
			scanf("%c",&resp);
		}while(resp!='S'&&resp!='s'&&resp!='N'&&resp!='n');	
	}while(resp!='N'&&resp!='n');
	system("cls");
	printf("cadastro realizado com sucesso...aperte qualquer tecla para continuar..\n\n");
	getch();
	system("cls");
	fclose(arq);
}
//-------------------------------------------------------------------------------
void descadastrar(tatoo *cad)
{
	int i,ver,cont,cont2;
	char resp2,nome[35],nomecomp[20],resp[4];
	printf("-----------------------------DESCADASTRO-----------------------\n\naperte qualque tecla para continuar...\n\n");
	getch();
	fflush(stdin);
	FILE *arq;
	ver=cont=cont2=0;
	system("cls");
	//
	printf("digite o nome do arquivo que deseja descadastrar\n");
	gets(nome);
	nome[29]='\0';
	strcat(nome,".dat");
	if ((arq = fopen(nome,"r+b"))==NULL){
		printf("\n\nerro ao abrir o arquivo....aperte qualquer tecla para continuar\n\n");
		getch();
		return;
	}
	system("cls");
	//
	printf("digite o nome do cliente que deseja descadastrar\n");
	gets(nomecomp);
	rewind(arq);
	while(fread(cad,sizeof(*cad),1,arq)==1)
	{
		if(strcmp(nomecomp,(*cad).nome)==0&&(*cad).existe==0){
			printf("nome: %s\n",(*cad).nome);
			printf("idade: %s anos\n",(*cad).idade);
			printf("telefone: %s\n",(*cad).tel);
			printf("nome da tatoo: %s\n",(*cad).desenho);
			printf("preco: %s\n\n",(*cad).preco);
			ver=1;
			cont++;
		}
	}
	//
	if (ver==0){
		system("cls");
		printf("\nnao existe cliente na lista\n\n");
		getch();
		return;
	}
	printf("\n...aperte qualquer tecla para continuar\n\n");
	if (cont>1){
		printf("ha mais de um cadastro com esse nome, digite o numero equivalente a ordem de cadastros que apareceu na tela\nEX: se deseja descadastrar o primeiro tecle '1', se deseja descadastrar o segundo tecle '2' e assim por diante...\nOBS: se nao for selecionado nada o programa excluira automaticamente o primeiro\n\n");
		do{
			fflush(stdin);
			gets(resp);
			resp[3]='\0';
			if(ConfNum(resp)==1||cont<atoi(resp)) printf("opcao invalida... aperte qualquer tecla e digite novamente\n");
		}while(ConfNum(resp)==1||cont<atoi(resp));
/////		//
		system("cls");
		rewind(arq);
		while(fread(cad,sizeof(*cad),1,arq)==1)
		{
			if(strcmp(nomecomp,(*cad).nome)==0&&(*cad).existe==0) cont2++;
			if(cont2==atoi(resp)){
				printf("nome: %s\n",(*cad).nome);
				printf("idade: %s anos\n",(*cad).idade);
				printf("telefone: %s\n",(*cad).tel);
				printf("nome da tatoo: %s\n",(*cad).desenho);
				printf("preco: %s\n\n",(*cad).preco);
				do{
				printf("deseja mesmo remover este cliente?\nS - sim\nN - nao\n");
				scanf("%c",&resp2);
				}while (resp2!='s'&&resp2!='n'&&resp2!='S'&&resp2!='N');
				if(resp2=='N'||resp2=='n') return;
				else{
					(*cad).existe=1;
					fseek (arq, -sizeof(*cad), 1);
					fwrite(cad,sizeof(*cad),1,arq);
					break;
				}	 		
			}
		}
	}
	else{
		do{
			printf("deseja mesmo remover este cliente?\nS - sim\nN - nao\n");
			scanf("%c",&resp2);
		}while (resp2!='s'&&resp2!='n'&&resp2!='S'&&resp2!='N');
		if(resp2=='N'||resp2=='n') return;
		else{
			(*cad).existe=1;
			fseek (arq, -sizeof(*cad), 1);
			fwrite(cad,sizeof(*cad),1,arq);
		}	 
	}
rewind(arq);
system("cls");
printf("descadastro realizado com sucesso...aperte qualquer tecla para continuar..\n\n");
getch();
system("cls");
fclose(arq);
deletar(nome);
}
//-------------------------------------------------------------------------------
 void buscar_alterar(tatoo *cad)
{
	fflush(stdin);
	printf("-----------------------------CONSULTA - ALTERA-----------------------\n\naperte qualque teclapara continuar...\n\n");
	getch();
	system("cls");
	FILE *arq;
	int ver,cont,cont2;
	char nome2[20],nome[35],resp,resp2[4],resp3,resp4;
	ver=cont=cont2=0;
	//
	printf("digite o nome do arquivo que deseja busca-alterar\n");
	gets(nome);
	nome[29]='\0';
	strcat(nome,".dat");
	if ((arq = fopen(nome,"r+b"))==NULL){
		printf("\n\nerro ao abrir o arquivo....aperte qualquer tecla para continuar\n\n");
		getch();
		return;
	}
	//
	do
	{
		system("cls");
		printf("digite uma das opcoes de consulta:\n1 - consuta por nome de tatuagem do cliente\n2 - consuta por preco de tatuagem\n");
		scanf("%c",&resp);
	}while(resp!='1'&&resp!='2');
	fflush(stdin);
	system("cls");
	//
	if(resp=='2') printf("digite o valor do preco para fazer a busca\n\n");
	else printf("digite o nome da tatoo para fazer a busca\n\n");
	gets(nome2);
	system("cls");
	if(resp=='1'){
		while(fread(cad,sizeof(*cad),1,arq)==1){
			if(strcmp(nome2,(*cad).desenho)==0&&(*cad).existe==0){
				printf("nome: %s\n",(*cad).nome);
				printf("idade: %s anos\n",(*cad).idade);
				printf("telefone: %s\n",(*cad).tel);
				printf("nome da tatoo: %s\n",(*cad).desenho);
				printf("preco: %s\n\n",(*cad).preco);
				ver=1;
				cont++;
			}
		}
		if (ver==0){
			printf("\nnao existe cliente na lista\n\n");
			getch();
			return;
		}
		printf("\n...aperte qualquer tecla para continuar\n\n");
		getch();
		if (cont>1){
		printf("ha mais de um cadastro com esse nome, digite o numero equivalente a ordem de cadastros que apareceu na tela\nEX: se deseja descadastrar o primeiro tecle '1', se deseja descadastrar o segundo tecle '2' e assim por diante...\nOBS: se nao for selecionado nada o programa excluira automaticamente o primeiro\n\n");
		do{
			fflush(stdin);
			gets(resp2);
			resp2[3]='\0';
			if(ConfNum(resp2)==1||cont<atoi(resp2)) printf("opcao invalida... aperte qualquer tecla e digite novamente\n");
		}while(ConfNum(resp2)==1||cont<atoi(resp2));
		//
		system("cls");
		rewind(arq);
		while(fread(cad,sizeof(*cad),1,arq)==1)
		{
			if(strcmp(nome2,(*cad).desenho)==0&&(*cad).existe==0&&cont2==atoi(resp2)){
				printf("nome: %s\n",(*cad).nome);
				printf("idade: %s anos\n",(*cad).idade);
				printf("telefone: %s\n",(*cad).tel);
				printf("nome da tatoo: %s\n",(*cad).desenho);
				printf("preco: %s\n\n",(*cad).preco);
				printf("\no seguinte cliente foi selecionado\n...aperte qualquer tecla para continuar\n\n");
				getch();
				break;
			}
		cont2++;
		}
		//
		do{
			system("cls");
			printf("deseja alterar algum campo do cliente?\nS - sim\nN - nao\n");
			scanf("%c",&resp3);
		}while (resp3!='s'&&resp3!='n'&&resp3!='S'&&resp3!='N');
		if(resp3=='N'||resp3=='n')return;
		else{
			do{
				system("cls");
				printf("digite o campo que deseja ser alterado:\n1 - nome\n2 - idade\n3 - telefone\n4 - nome da tatoo\n5 - preco\n\n");
				scanf("%c", &resp4);	
			}while(resp4!='1'&&resp4!='2'&&resp4!='3'&&resp4!='4'&&resp4!='5');
			rewind(arq);
			cont2=0;
		while(fread(cad,sizeof(*cad),1,arq)==1)
		{
			if(strcmp(nome2,(*cad).desenho)==0&&(*cad).existe==0) cont2++;
			if(cont2==atoi(resp2)){
				modifica(resp4,&(*cad));
				fseek (arq, -sizeof(*cad), 1);
				fwrite(cad,sizeof(*cad),1,arq);
				break;
			}
		}
	}
	}else{
			system("cls");
			rewind(arq);
			while(fread(cad,sizeof(*cad),1,arq)==1)
			{
				if(strcmp(nome2,(*cad).desenho)==0&&(*cad).existe==0&&cont2==atoi(resp2)){
					printf("nome: %s\n",(*cad).nome);
					printf("idade: %s anos\n",(*cad).idade);
					printf("telefone: %s\n",(*cad).tel);
					printf("nome da tatoo: %s\n",(*cad).desenho);
					printf("preco: %s\n\n",(*cad).preco);
					break;
				}
			cont2++;
			}		
			do{
				printf("deseja alterar alterar algum campo do cliente?\nS - sim\nN - nao\n");
				scanf("%c",&resp3);
			}while (resp3!='s'&&resp3!='n'&&resp3!='S'&&resp3!='N');
			if(resp3=='N'||resp3=='n') return;
			else{
				do{
					system("cls");
					printf("digite o campo que deseja ser alterado:\n1 - nome\n2 - idade\n3 - telefone\n4 - nome da tatoo\n5 - preco\n\n");
					scanf("%c", &resp4);	
			}while(resp4!='1'&&resp4!='2'&&resp4!='3'&&resp4!='4'&&resp4!='5');
			rewind(arq);
			while(fread(cad,sizeof(*cad),1,arq)==1) {
				if(strcmp(nome2,(*cad).desenho)==0&&(*cad).existe==0){
					modifica(resp4,&(*cad));
					fseek (arq, -sizeof(*cad), 1);
					fwrite(cad,sizeof(*cad),1,arq);
					break;
				}
			} 
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	}else{
		while(fread(cad,sizeof(*cad),1,arq)==1){
			if(strcmp(nome2,(*cad).preco)==0&&(*cad).existe==0){
				printf("nome: %s\n",(*cad).nome);
				printf("idade: %s anos\n",(*cad).idade);
				printf("telefone: %s\n",(*cad).tel);
				printf("nome da tatoo: %s\n",(*cad).desenho);
				printf("preco: %s\n\n",(*cad).preco);
				ver=1;
				cont++;
			}
		}
		if (ver==0){
			printf("\nnao existe cliente na lista\n\n");
			getch();
			return;
		}
		printf("\n...aperte qualquer tecla para continuar\n\n");
		getch();
		if (cont>1){
		printf("ha mais de um cadastro com esse nome, digite o numero equivalente a ordem de cadastros que apareceu na tela\nEX: se deseja descadastrar o primeiro tecle '1', se deseja descadastrar o segundo tecle '2' e assim por diante...\nOBS: se nao for selecionado nada o programa excluira automaticamente o primeiro\n\n");
		do{
			fflush(stdin);
			gets(resp2);
			resp2[3]='\0';
			if(ConfNum(resp2)==1||cont<atoi(resp2)) printf("opcao invalida... aperte qualquer tecla e digite novamente\n");
		}while(ConfNum(resp2)==1||cont<atoi(resp2));
		//
		system("cls");
		rewind(arq);
		while(fread(cad,sizeof(*cad),1,arq)==1)
		{
			if(strcmp(nome2,(*cad).preco)==0&&(*cad).existe==0&&cont2==atoi(resp2)){
				printf("nome: %s\n",(*cad).nome);
				printf("idade: %s anos\n",(*cad).idade);
				printf("telefone: %s\n",(*cad).tel);
				printf("nome da tatoo: %s\n",(*cad).desenho);
				printf("preco: %s\n\n",(*cad).preco);
				printf("\no seguinte cliente foi selecionado\n...aperte qualquer tecla para continuar\n\n");
				getch();
				break;
			}
		cont2++;
		}
		//
		do{
			system("cls");
			printf("deseja alterar algum campo do cliente?\nS - sim\nN - nao\n");
			scanf("%c",&resp3);
		}while (resp3!='s'&&resp3!='n'&&resp3!='S'&&resp3!='N');
		if(resp3=='N'||resp3=='n')return;
		else{
			do{
				system("cls");
				printf("digite o campo que deseja ser alterado:\n1 - nome\n2 - idade\n3 - telefone\n4 - nome da tatoo\n5 - preco\n\n");
				scanf("%c", &resp4);	
			}while(resp4!='1'&&resp4!='2'&&resp4!='3'&&resp4!='4'&&resp4!='5');
			rewind(arq);
			cont2=0;
		while(fread(cad,sizeof(*cad),1,arq)==1)
		{
			if(strcmp(nome2,(*cad).preco)==0&&(*cad).existe==0) cont2++;
			if(cont2==atoi(resp2)){
				modifica(resp4,&(*cad));
				fseek (arq, -sizeof(*cad), 1);
				fwrite(cad,sizeof(*cad),1,arq);
				break;
			}
		}
	}
	}else{
			system("cls");
			rewind(arq);
			while(fread(cad,sizeof(*cad),1,arq)==1)
			{
				if(strcmp(nome2,(*cad).preco)==0&&(*cad).existe==0&&cont2==atoi(resp2)){
					printf("nome: %s\n",(*cad).nome);
					printf("idade: %s anos\n",(*cad).idade);
					printf("telefone: %s\n",(*cad).tel);
					printf("nome da tatoo: %s\n",(*cad).desenho);
					printf("preco: %s\n\n",(*cad).preco);
					break;
				}
			cont2++;
			}		
			do{
				printf("deseja alterar alterar algum campo do cliente?\nS - sim\nN - nao\n");
				scanf("%c",&resp3);
			}while (resp3!='s'&&resp3!='n'&&resp3!='S'&&resp3!='N');
			if(resp3=='N'||resp3=='n') return;
			else{
				do{
					system("cls");
					printf("digite o campo que deseja ser alterado:\n1 - nome\n2 - idade\n3 - telefone\n4 - nome da tatoo\n5 - preco\n\n");
					scanf("%c", &resp4);	
			}while(resp4!='1'&&resp4!='2'&&resp4!='3'&&resp4!='4'&&resp4!='5');
			rewind(arq);
			while(fread(cad,sizeof(*cad),1,arq)==1) {
				if(strcmp(nome2,(*cad).preco)==0&&(*cad).existe==0){
					modifica(resp4,&(*cad));
					fseek (arq, -sizeof(*cad), 1);
					fwrite(cad,sizeof(*cad),1,arq);
					break;
				}
			} 
		}
	}
	}
	system("cls");
	printf("busca/alteracao realizado com sucesso...aperte qualquer tecla para continuar..\n\n");
	getch();
	system("cls");
	fclose(arq);
}
//--------------------------------------------------------------------------------------------------------------
int main()
{
	int tecla,tecla_conf,ver=0;
	tatoo cad;
	printf("BEM VINDO AO ESTUDIO DE TATOO\n\naperte qualquer tecla para continuar...");
	getch();
	do
	{
		do{
			ver=0;
			fflush(stdin);
			system("cls");
			printf("digite uma das seguintes opcoes:\n");
			printf("1 - mostrar arquivo\n2 - marcar cliente\n3 - descadastrar cliente\n4 - consutar(buscar) ou alterar algum campo cliente\n5 - renomear ou deletar arquivo\n6 - sair\nF1 - ajuda\n\n");
			tecla = getch();
			if(tecla==224) ver=1;
			else if(tecla==0){
				tecla_conf = getch();
				if(tecla_conf!=59) ver=1;
			}else{
				tecla_conf = tecla;
				if(tecla_conf!=49&&tecla_conf!=50&&tecla_conf!=51&&tecla_conf!=52&&tecla_conf!=53&&tecla_conf!=54) ver=1;
			}
			printf("%d",tecla);
		} while(ver==1);
		system("cls");
		switch(tecla_conf)
		{
			case 49:
				mostra();
				break;
			case 50:		
				cadastrar(&cad);
				break;
			case 51:
				descadastrar(&cad);
				break;
			case 52:
				buscar_alterar(&cad);
				break;
			case 59:
				fflush(stdin);
				FILE *arq;
				char c;
				arq = fopen("help.txt","rt");
				while(!feof(arq)) {
				fread(&c,sizeof(c),1,arq); 
				if (c=='-') printf("a");
				else if (c=='#') printf("e");
				else if (c=='&') printf("o");
				else if (c=='7') printf("p");
				else if (c=='8') printf("r");
				else if (c=='9') printf("s");
				else printf("%c",c);
				}
				//
				printf("\n\ntecle qualquer tecla para continuar...\n\n");
				getch();
				system("cls");
				fclose(arq);
				break;
			case 53:
				char resp53;
				do{
				system("cls");
				printf("tecle uma das opcoes:\n1 - renomear arquivo\n2 - deletar arquivo\n");
				scanf("%c",&resp53);
				}while(resp53!='1'&&resp53!='2');
				if (funcao53(resp53)==1){
					printf("\n\nalteracao feita com sucesso...tecle qualquer tecla para continuar...\n\n");
					getch();
				}
				else break;
				break;
			case 54:
				break;
		}
	}while(tecla_conf!=54);
}