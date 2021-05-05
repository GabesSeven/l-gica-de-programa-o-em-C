// 1 - Faça um programa que leia um número N que indique o número de valores inteiros e positivos a serem lidos. Para cada número lido, mostre o fatorial desse valor.
#include<stdio.h>
// #include<conio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	float i,a,b=1;
	printf("INDIQUE O VALOR DE SEU NUMERO REAL:\n");
	scanf("%f", &a);
	if (a<0) a=0;
	for ( i=a;a>=1;a--) { 
        while (i>=1) {
        b=b*i;
        i--;
        }
    printf("O fatorial de %.2f e'\n",a);
    printf("FATORIAL = %.2f\n",b);
    i=a-1;
    b=1;
    }
    getch();
}

// 5 - Escreva um programa que determine o signo a partir do dia e mês de nascimento de uma pessoa.
// Mês     Último Dia      Signo 
// 1       20              Capricórnio 
// 2       19              Aquário 
// 3       20              Peixes 
// 4       20              Áries 
// 5       20              Touro 
// 6       20              Gêmeos 
// 7       21              Câncer 
// 8       22              Leão 
// 9       22              Virgem 
// 10      22              Libra 
// 11      21              Escorpião 
// 12      21              Sagitário 
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() {
    int diaT,mes,ano;
    do {
        printf("digite o dia e o mes do seu nascimento, respectivamente\n\n");
        scanf("%d%d",&diaT, &mes);
        if (mes==1) ano = diaT;
        else if (mes==2) ano = 31+diaT;
        else if (mes==3) ano = 28+31+diaT;
        else if (mes==4) ano = 28+2*31+diaT;
        else if (mes==5) ano = 28+30+2*31+diaT;
        else if (mes==6) ano = 28+30+3*31+diaT;
        else if (mes==7) ano = 28+2*30+3*31+diaT;
        else if (mes==8) ano = 28+2*30+4*31+diaT;
        else if (mes==9) ano = 28+3*30+4*31+diaT;
        else if (mes==10) ano = 28+3*30+5*31+diaT;
        else if (mes==11) ano = 28+4*30+5*31+diaT;
        else if (mes==12) ano = 28+4*30+6*31+diaT;
    } while (ano>365);

    if (ano>=355&&ano<=20) printf ("seu signo e capricornio");
    else if (ano>=21&&ano<=59) printf ("seu signo e aquario");
    else if (ano>=60&&ano<=88) printf ("seu signo e peixe");
    else if (ano>=89&&ano<=119) printf ("seu signo e aries");
    else if (ano>=120&&ano<=149) printf ("seu signo e touro");
    else if (ano>=150&&ano<=180) printf ("seu signo e gemeos");
    else if (ano>=181&&ano<=211) printf ("seu signo e cancer");
    else if (ano>=212&&ano<=243) printf ("seu signo e leao");
    else if (ano>=244&&ano<=274) printf ("seu signo e virgem");
    else if (ano>=275&&ano<=304) printf ("seu signo e libra");
    else if (ano>=305&&ano<=334) printf ("seu signo e escorpiao");
    else if (ano>=335&&ano<=365) printf ("seu signo e sagitario");
}

// 7 - Escreva um programa que leia dois valores inteiros e positivos, x e y, calcule e mostre a
// potência y x , utilizando uma estrutura de repetição.
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
#include<math.h>
int main() {
    int a,x,y,i;
    printf("digite o valor de X e Y, onde X^Y\n\n");
    scanf("%d%d",&x, &y);
    for (i=y;i>=1;i--) {
        a = pow(x,i);
        printf ("%d\t", a);
    }
    getch();
}

// 9 - Faça um programa que receba um número, calcule e imprima o caractere correspondente 
// desse caractere na tabela de código ASCII.
// #include<conio.h>
#include<stdio.h>
int main() {
	int a;
	printf("digite um numero\n");
	scanf("%d",&a);
	printf("%c",a);
	getch();
}

// 11 - Faça um programa que calcule o volume de uma esfera em função do raio R. O raio
// deverá variar de 0 a 20 cm, de 0,5 em 0,5 cm.
// V = 4/3 * pi * R^3
// #include<conio.h>
#include<stdio.h>
#include<math.h>
int main() {
	float v,i=0;
	printf("volume do raio de 0 20cm variando de 0,5cm a 0,5cm \n");
	for (i=0;i<21;i=i+0.5) {
		v = ((4)*M_PI*(pow(i,3)))/3;
		printf("raio: %.2f volume:%.2f\n", i,v);
	}
	getch();
}

// 13 - Escreva um programa que solicite um valor inteiro não negativo n e, 
// visualize a seguin-te saída (n=6): 
// 1   2   3   4   5   6
// 1   2   3   4   5
// 1   2   3   4
// 1   2   3
// 1   2
// 1 
// #include<conio.h>
#include<stdio.h>
#include<math.h>
int main() {
    int	i=1,n;
    char resp;	
    do{
        do{
            do {
                printf("digite um numero interio maior que zero\n\n");
                scanf("%d",&n);
                while (n>=1) {
                    for (i=1;i<=n;i++) {
                        printf("%d",i);
                    }
                    printf("\n");
                    n = n-1;
                }
            }while (n<0);
            printf("deseja continuar...\n");
            scanf("%c",&resp);
        }while (resp!='n' && resp!='N' && resp!='S' && resp!='s');
    }while (resp!='n' && resp!='N');
    getch();
}

// 15 - Escreva um programa que receba o ano de nascimento de uma pessoa e o ano atual.
// Calcule e imprima a idade dessa pessoa e essa idade convertida em semanas.
// #include<conio.h>
#include<stdio.h>
#include<math.h>
int main() {
    float d1, d2, m1, m2, a1, a2;;
    char resp;
    do{
        printf ("DIGITE A DATA ATUAL: DIA DD/MM/AAAA\n ");
        scanf ("%f%f%f", &d1,&m1,&a1);
        printf ("DIGITE A DATA DE SEU NASCIMENTO DD/MM/AAAA\n: ");
        scanf ("%f%f%f", &d2,&m2,&a2);
        printf ("\nVOCE VIVEU %.0f SEMANAS\n",((a1-a2)*360.25+(m1-m2)*30+(d1-d2))/7);
        printf("deseja continuar...\n");
        do{ 	
            scanf("%c", &resp);
        }while (resp!='N' && resp!='n' && resp!='S' && resp!='s');
    }while(resp!='N' && resp!='n');
getch();
}

// 17 - Escreva um programa que imprima os números ímpares de 3500 a 7000.
// #include<conio.h>
#include<stdio.h>
#include<math.h>
int main() {
    int i=3501;
    for (i=3501;i<7000;i=i+2) printf ("%d\t",i);
    getch();
}

// 19 - Escreva um programa que imprima o quadrado de todos os inteiros de 1 a n,
// sendo n um número fornecido pelo usuário.
// #include<conio.h>
#include<stdio.h>
#include<math.h>
int main() {
    float i=1,n;
    char resp;
    do{
        printf("digite um valor interio\n");
        scanf("%f",&n);
        for (i=1;i<=n;i++) printf("%.0f\n",pow(i,2));
        printf("\ndeseja continuar...\n\n");
        do{
            scanf("%c",&resp);
        }while (resp!='n'&&resp!='N'&&resp!='s'&&resp!='S');
    }while(resp!='n'&&resp!='N');
    getch();
}

// 21 - Dados dois números A e B, faça um programa que calcule a soma de todos os inteiros existentes entre A e B.
// #include<conio.h>
#include<stdio.h>
#include<math.h>
int main() {
    int a,b,i, soma=0;
    char resp;
    do {
        printf("digite um valor intervalo MIN e MAX respectivamente\n");
        scanf("%d%d",&a,&b);
        if(a<b) {
            for (i=a;i<=b;i++)
                soma = soma + i;
        } else {
            for (i=a;i>=b;i--)
                soma = soma + i;
            printf("o segundo numero foi maior que o primerio, mas calculando o intervali inversamente temos:");
        }
        printf("%d\n", soma);
        printf("\ndeseja continuar...\n");
        do{
            scanf("%c",&resp);
        } while (resp!='n'&&resp!='N'&&resp!='s'&&resp!='S');
    } while(resp!='n'&&resp!='N');
    getch();
}

// 23 - Escreva um programa que imprima a tabuada de um determinado número.
#include <stdio.h>
// #include <conio.h>
int main (){
	int n,i=1;
	printf ("digite o numero que deseja saber a tabuada:\n\n");
	scanf("%d",&n);
	for(i=1;i<=10;i++) printf("%d x %d = %d\n", n,i,n*i);
	getch ();
}

// 25 - Escreva um programa para calcular a média aritmética de um 
// conjunto de valores inteiros positivos fornecidos pelo usuário.
// #include<conio.h>
#include<stdio.h>
#include<math.h>
int main() {
    float a,b,i,cont=0,soma=0;
    printf("digite um valor intervalo MIN e MAX respectivamente\n");
    scanf("%f%f",&a,&b);
    if(a<b) {
        for (i=a;i<=b;i++) {
        soma = soma + i;
        cont++;
        }
    }else {
        printf("calculando o intervalo inversamente temos:");
        for (i=a;i>=b;i--) {
        soma = soma + i;
        cont++;
        }	
    }
    printf(" media: %.2f\n", soma/cont);
    getch();
}

// 31 - Escreva um programa que calcule e escreva o valor de S:
#include <stdio.h>
// #include <conio.h>
    int main() {
    int j=1,soma1=0,soma2=0;
    for (j=1;j<11;j++) {
        if (j%2==0) {
            printf ("%d/%d = %d\n",-(j*j),j,-(j*j)/j );
            soma1 = soma1+-(j*j)/j;
        }else {
            printf ("%d/%d = %d\n",(j*j),j, (j*j)/j );
            soma2=soma2+(j*j)/j;
        }
    }
    printf ("%d", soma1+soma2);
    getch();
}

// 33 - Faça um programa que calcule e imprima a seguinte soma:
#include <stdio.h>
// #include <conio.h>
int main() {
    float j=38,soma1=0,i=1;
    for (j=38;j>0;j--) {
        printf ("%.0f*%.0f/%.0f = %.2f\n",j,j-1,i,(j*(j-1)/i));
        i++;
        soma1 = soma1 + (j*(j-1)/i);
    }
    printf ("%.2f", soma1);
    getch();
}

// 35 - O valor aproximado de pode ser calculado usando a série: S = 1/(1^3) + 1/(3^3) + 1/(5^3) + 1/(7^3)...
// sendo pi=cbrt(32*S). Faça um programa que calcule e escreva o valor de 'pi' com 30 termos.
#include <stdio.h>
// #include <conio.h>
#include<math.h>
int main() {
    float j=1,soma2=0,soma1=0,i=3;
    for (j=1;j<=30;j=j+4) {
        printf ("1/%.0f = %.4f\n",j,1/(pow(j,3)));
        soma1 = soma1 + 1/(pow(j,3));
    }
    for (i=3;i<=30;i=i+4) {
        printf ("-1/%.0f = %.4f\n",i,-1/(pow(-i,3)));
        soma2 = soma2 + -1/(pow(i,3));
    }
    printf ("%.4f\n", soma1+soma2);
    printf ("o valor de PI e:%.4f\n", pow(32*(soma1+soma2),1/3));
    getch();
}