// 3 - Escreva uma função que retorne o cubo de seu argumento.
#include<stdlib.h>	
#include<stdio.h>
// #include<conio.h>
#include<math.h>	
int cubo(int n) {
	return pow(n,3);
}
int main() {
	int n;
	printf("digite um numero\n");
	scanf ("%d", &n);
	printf ("%d",cubo(n));
}


// 7 - Escreva uma função que retorne 1 se o argumento for um caractere de 0 a 9 e, 0 caso contrário.
#include<stdlib.h>	
#include<stdio.h>
// #include<conio.h>	
int numero(int n) {
	if (n>0&&n<9) return 1;
	else return 0;
}
int main() {
	int n;
	printf("digite um numero\n");
	scanf ("%d", &n);
	printf ("%d",numero(n));
}

// 9 - Escreva uma função que retorne o absoluto de um número real (Não utilize a função fabs() do compilador). Faça um programa, com reprocessamento, que utilize esta função.
#include<stdlib.h>	
#include<stdio.h>
// #include<conio.h>	
float modulo(float n) {
	if (n<0) return -n;
	else return n;
}
int main() {
	char resp;
	float n;
	system ("cls");
	do{
        printf("digite um numero\n");
        scanf ("%f", &n);
        printf ("%.2f",modulo(n));
        printf("\ndeseja continuar<s/n>\n");
        do{
            scanf ("%c", &resp);
        }while(resp!='n'&&resp!='N'&&resp!='s'&&resp!='S');
    }while(resp!='n'&&resp!='N');
}

// 11 - Faça uma função que retorne xy, sendo dados x e y reais como parâmetros de entrada. Escreva um programa que calcule a potência de 15 valores lidos.
#include<stdlib.h>	
#include<stdio.h>
// #include<conio.h>
#include<math.h>	
float exponencial(float x[], float y[]) {
	int j;
	for (j=0;j<15;j++) {
		printf ("%.2f\t", pow(x[j],y[j]));
	}
}
int main() {
    int i;
    float x[15],y[15];
    for(i=0;i<15;i++) {
        printf("digite o valor de X\n");
        scanf("%f", &x[i]);
        printf("digite o valor de Y\n");
        scanf("%f", &y[i]);
    }
    exponencial(x,y);
}

// 13 - Utilizando a função do exercício anterior, faça um programa, com reprocessamento, 
// que calcule e imprima o valor do coeficiente binomial, dado pela expres-são a seguir:
#include<stdlib.h>	
#include<stdio.h>
// #include<conio.h>
#include<math.h>	
int CP(int x, int y) {
	int a,i,n1=1,n2=1,n3=1;
	a = x-y;
	for (i=1;i<=a;i++) n1 = n1*i;
	for (i=1;i<=x;i++) n2 = n2*i;
	for (i=1;i<=y;i++) n3 = n3*i;
	return (n2)/(n1*n3);
}
int main() {
	int x,y;
	system ("cls");
	do{
        printf("digite o valor de X\n");
        scanf("%d", &x);
        printf("digite o valor de Y\n");
        scanf("%d", &y);
    }while(x<=0||y<=0);
    printf ("%d",CP(x,y));
}

// 17 - Escreva uma função que calcule o valor de ex através da série:
// e^x = 1 + x/(1!) + (x^2)/(2!) + (x^3)/(3!) + (x^4)/(4!) + ...
// em que são dados por parâmetros o valor de x e o número de termos. Faça um
// programa que leia 10 valores de x e o número de termos e, calcule o valor da
// série usando a função acima.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<math.h>
int calculando(int x,int nt) {
    int i,j,exp=1,cont=1,resultado,soma=1,soma2=0;
    for (i=0;i<nt;i++) {
        for (j=0;j<cont;j++)
            soma = soma*j;
        resultado = pow(x,exp)/soma;
        cont++;
        exp++;
        soma2 = soma2+resultado;
    }
    return soma2+1;
}
int main() {
    printf("digite o numero de termos\n");
    scanf("%d",&nt);
    printf("digite o numero de termos\n");
    scanf("%d",&x);
    printf ("%d",calclulando(nt,x));
}

// 21 - Um número primo é qualquer inteiro positivo que é divisível apenas por si pró-prio e por 
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
#include<math.h>
int NP(int n) {
    int cont=0, i;
    for (i=1;i<=n;i++)
    if (n%i==0) cont++; 
    if (cont>2) return 1;  
    else return 0;
}
int main() {
    int n;
    do {
        printf("digite o numero\n");
        scanf("%d",&n);
    } while(n<0);
    switch(NP(n)) {
        case 1: printf("%d nao e primpo\n",n);
            break;
        case 0: printf("%d e primpo\n", n);
            break;          
    }
    getch();
}

// 25 - Um matemático italiano da idade média conseguiu modelar o ritmo de crescimento
// da população de coelhos através de uma sequência de números naturais
// que passou a ser conhecida como sequência de Fibonacci. O n-ésimo número
// da sequência de Fibonacci F é dado pela seguinte fórmula de recorrência:
// F1 = 1
// F2 = 1
// Fn = Fn-1 + Fn-2, n>=3
// Escreva uma função que dado n calcule Fn. Faça um programa, com reprocessamento,
// que utilize esta função.
#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
int main() {
	char resp;
	int n,soma=0,i,fn1,fn2,aux;
	do {
	    system("cls");
        do{
            printf ("insira um numero\n");
            scanf("%d",&n);
        }while (n<=0);
        
        if(n==1) printf("1\n");
        else if(n==2) printf("1,1\n");
        else {
            printf("1,1,");
            fn1=1;
            fn2=1;
            for (i=3;i<=n;i++) {
                printf("%d,",fn1+fn2);	
                aux=fn2;
                fn2=fn1;
                fn1=aux+fn2;
            } 
        }
        printf ("\ndeseja continuar<s/n>\n");
        do{
            scanf ("%c",&resp);
        }while (resp!='n'&&resp!='N'&&resp!='S'&& resp!='s');
	}while (resp!='n'&&resp!='N');
	getch();	
}

// 27 - Qualquer número natural de quatro algarismos pode ser dividido em duas dezenas
// formadas pelos seus dois primeiros e dois últimos dígitos.
// Exemplo: 1278: 12 e 78.
// Escreva um programa que imprima todos os milhares (4 algarismos) cuja raiz
// quadrada seja a soma das dezenas formadas pela divisão acima. Utilize o conceito
// de função.
// Exemplo: A raiz de 9801 = 99 = 98 + 01.
// Portanto, 9801 é um dos números a ser impresso.
#include<stdio.h>
#incl/ude<conio.h>
#include<stdlib.h>
int calculo(int num) {
	int d1,d2;
    d1 = num%100;
    d2 = num/100;
    if( (d1+d2)*(d1+d2) == num )
    printf("%d\n",num);
}
int main() {
    int i;
    for(i=1000;i<10000;i++)
        calculo (i);
}

// 29 - Um número natural é triangular se ele é produto de três números naturais consecutivos. 
// Faça uma função que dado N natural, verifique se N é triangular. Es-creva um programa que verifique se M números são triangulares.
// Exemplo: 120 é triangular, pois 4*5*6 = 120.
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int calculo(int num) {
	int i, cont=0,soma=1,a=1;
	while(soma!=num||soma<num)
	{
		system ("cls");
		a++;
		soma=1;
		for(i=a;i<a+3;i++) {
				printf("%d\n",i);
				soma = soma*i;
			}
			printf("%d",soma);
		if (soma<num||soma>num){
			if (soma>num) {
				system("cls");
				printf("nao existe sequencia nesse numero\n");
				break;
			}
		}else {
			printf("\nessa e a sequencia correta\n");
			break;
		}
	}
}
int main() {
    int num;
    do {
        printf("digite um numero\n");
        scanf("%d", &num);
    }while(num<=0);
    calculo (num);
    getch();
}


// 33 Para evitar erros de digitação de sequências de números de importância fundamental, como a matrícula de um aluno, o C.P.F. do Imposto de Renda, 
// o número da conta bancária, geralmente se adiciona ao número um dígito verificador. Por exemplo, o número de matrícula 811057 é usado como 8110573, onde 3 é o dígito verificador calculado da seguinte maneira:
// a) cada algarismo do número é multiplicado por um peso começando por 2 e crescendo de 1 da direita para a esquerda;
// Exemplo: 8*7, 1*6, 1*5, 0*4, 5*3, 7*2
// b) somam-se as parcelas obtidas;
// Exemplo: 56 + 6 + 5 + 0 + 15 + 14 = 96
// c) obtém-se o resto da divisão desta soma por 11;
// Exemplo: 96 dividido por 11 dá resto 8.
// d) subtrai-se de 11 o resto obtido;
// Exemplo: 11 - 8 = 3
// e) se o valor encontrado for 10 ou 11, o dígito verificador será 0, nos outros ca-sos o dígito verificador é o próprio valor encontrado.
// Escreva uma função que retorne o dígito verificador de um número inteiro. Faça um programa, com reprocessamento, que utilize esta função.
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int calculo(int num, int *quan) {
    printf("%d-----------------------------\n", num*(*quan));
    num = num*(*quan);
    *quan--;
}
int main() {
    int resto,a,aux,quont,soma=0,num,n,quan,cont = 0;
    printf("digite a quantidade de digitos que vai ter se codigo\n");
    scanf("%d", &quan);
    n=quan;
    quan = quan + 1;
    while(cont!=n) {
        do {
            printf("digite um numero\n");
            scanf("%d", &num); 
        } while(num<0);
        soma = soma+calculo(num,&quan);
        printf("%d-----------------------------======================\n", quan);
        cont++;
    }
    printf("%d",soma);
    while(n>=11) {
        n/11;
        quont++;
    }
    aux = quont*11;
    resto = n - quont;
    a = 11-resto;
    if (a==10||a==11) printf("digito é 0\n");
    else printf("digito é %d\n",a);
    getch();
}