// 3 - Faça a declaração de uma variável do tipo numérica inteira, três variáveis do tipo numérica real,
// duas variáveis de um único caractere e três variáveis do tipo cadeia de caracteres.
#include <stdio.h>
int main(){
	int A=10;
	float  pi=3.14, raiz_2 = 1.4, raiz_3 = 1.7;
	char C, D;
	char str[] = "gabriel";
	char str2[] = "vieira";
	char str3[] = "ferreira";
	printf("testando");
}

// 5 - Sendo P, Q, R variáveis inteiras e S variável real, cujos valores, 
// num determinado momento da execução do programa, são respectivamente, 5, 3, 12 e 6.5, 
// quais são os valores de cada uma das seguintes expressões aritméticas?
// a) 100 * (q / p) + r  = 100*(3/5) + 12 = 72
// b) p * (r % 5) - q / 2 = 5*(12%5) – (3/2) = 8.5
// c) sqrt(p*p-r) + int(s) = sqrt(5*5-12) + 6 = 9.6
// d) int(s) % (p + 1) - q * r  = 6%6–3*12 = -36
// e) p + int(2.9 + int(0.3 + s) * 2) =  5 + int(2.9 + int(0.3 + 6.5) * 2) = 19
// f) r / (int(s - p + 1.3)) + int(sqrt(r)) = 12 / (int(6.5 - 5 + 1.3)) + int(sqrt(12)) = 9  
// g) sqrt(exp(p* log(q-1))) + p * r = sqrt(exp(5* log(3-1))) + 5 * 12 = 62.12


//7 Qual o resultado das variáveis x, y e z depois da seguinte sequência de operações? 
// int x, y, z; x = y = 10; 
// z = (x++) = 10+1 = 11;
// x = -x = -10;
// y++ = 10+1 = 11;
// x = x + y – (z--) = 10 + 10 - (11-1) = 10

// 11 - Altere o programa anterior para que sejam requisitados o dia, o mês e o ano atuais, o dia, o mês e o ano 
// de nascimento do usuário, e então seja calculado e anunciado o número de dias vivido pelo usuário. 
#include <stdio.h>
#include <stdlib.h>
int main () {
	int Dias;
	float Anos;
	printf ("\n\t Entre com o número de dias: ");
	scanf ("%d", &Dias);
	Anos = Dias/365.25;
	printf ("\n\n\t %d dias equivalem a %f anos.\n",Dias,Anos);
	system ("Pause");
}

#include <stdio.h>
#include <stdlib.h>
int main () {
	int d1, d2, m1, m2, a1, a2;
	printf ("DIGITE A DATA ATUAL: DIA DD/MM/AAAA\n ");
	scanf ("%d", &d1);
	scanf ("%d", &m1);
	scanf ("%d", &a1);
	printf ("DIGITE A DATA DE SEU NASCIMENTO DD/MM/AAAA: ");
	scanf ("%d", &d2);
	scanf ("%d", &m2);
	scanf ("%d", &a2);
	printf ("\nVOCE VIVEU %.0f DIAS\n",((a1-a2)*360.25+(m1-m2)*30+(d1-d2)));
	system ("Pause");
}


// 13 - Execute o programa abaixo e comente os resultados obtidos.
#include <stdio.h>
#include <stdlib.h>
int main () {
	float x, y;
	printf ("\n Digite dois numeros: ");
	scanf ("%f %f", &x, &y);
	printf ( "\n O produto de %f e %f eh %f ", x, y, x*y );
	printf ( "\n O quociente de %f e %f eh %f ", x, y, x/y);
	system ("Pause");
}
/*Ao abrir o programa é solicitado que você digite dois números, depois de digita-los o programa
faz a divisão e a multiplicação e mostra o resultado de ambos em sua tela. Mostrando até mesmos os decimais.*/

// 15 - Determine os resultados que serão impressos depois de executado o programa a seguir.
#include <stdio.h>
#include <stdlib.h> /* para utilizar o system("Pause") */
int main () {
	int x, y;
	float X, Y;
	printf ("\n\t Digite dois numeros inteiros: \n");
	/* Para escrever os dois números pedidos pelo programa,
	pode-se digitar o primeiro, um espaço, digitar o segundo,
	e pressionar <enter>. Pode-se também digitar <enter>
	após cada número. */
	scanf ("%d %d", &x, &y);
	X = x;
	Y = y;
	printf ( "\n\t Divisao X/Y \n");
	printf ( "\n\t %f \n\t %d \n\t %d \n", X/Y, x/y, x%y);
	system ("Pause");
}
/*Primeiro pede pra ser digitado um numero inteiro ao usuário, depois o programa faz o numero 
digitado elevado ao cubo e monstra o resultado a usuário.
Agora o programa solicita que o usuário digite um numero real e o 
programa faz a soma do numero real e o numero inteiro digitado pelo usuário
Depois o programa irá fazer a divisão entre o numero inteiro e o numero real digitado
Depois o programa acrescenta  +1 a variável x digitada, arredonda a variável real a um numero inteiro,
faz a somatória das duas e só pega os resultados de números inteiros menor que cinco.
Logo depois mostra ao usuário*/

// 17 - Utilizando o seguinte trecho de programa:
// Explique o que está acontecendo em cada linha e qual é o resultado de cada ação executada.
#include <stdio.h>
#include <stdlib.h>
int main () {
	int x;
	float y, z;
	printf ("\nDigite um numero inteiro: ");
	scanf ("%d",&x);
	printf ("\n%d elevado ao cubo = %d",x,x*x*x);
	printf ("\n\nDigite um numero real: ");
	scanf ("%f",&y);
	printf ("\n %d + %f = %f",x,y,x+y);
	z = x/y;
	printf ("\n %d / %f = %f",x,y,z);
	x++;
	x = (int)(x + y) % 5;
	printf ("\n x = %d\n",x);
	system ("Pause");
}
/*Primeiro pede pra ser digitado um numero inteiro ao usuário, depois o programa faz o numero digitado elevado ao cubo e monstra o resultado a usuário.
Agora o programa solicita que o usuário digite um numero real e o programa faz a soma do numero real e o numero inteiro digitado pelo usuário
Depois o programa irá fazer a divisão entre o numero inteiro e o numero real digitado
Depois o programa acrescenta  +1 a variável x digitada, arredonda a variável real a um numero inteiro, faz a somatória das duas e só pega os resultados de números inteiros menor que cinco.
Logo depois mostra ao usuário*/

// 19 - Faça um programa que receba dois números inteiros, calcule e imprima: a)soma dos dois números; 
// b)subtração do primeiro pelo segundo
// c) subtração do segundo pelo primeiro; 
// d) multiplicação dos dois números; 
// e) divisão do primeiro pelo segundo; 
// f) divisão do segundo pelo primeiro; 
// g) quociente inteiro da divisão do primeiro pelo segundo; 
// h) quociente inteiro da divisão do segundo pelo primeiro; 
// i) resto da divisão do primeiro pelo segundo; 
// j) resto da divisão do segundo pelo primeiro. 
#include <stdlib.h>
#include <stdio.h>
int main () {
	int a,b,c,d, e, f, g, h, i, j;

	printf ("DIGITE O PRIMERIO NUMERO INTEIRO:\n");
	scanf ("%i", &a);
	printf ("DIGITE O SEGUNDO NUMERO INTEIRO:\n");
	scanf ("%i", &b);

	c = a + b;
	d = a - b;
	e = b - a;
	f = b * a;
	g = b / a;
	h = a / b;
	i = a % b;
	j = b % a;

	printf ("A SOMATORIA DOS ENTRE OS NUMEROS DIGITADOS É IGUAL A %i\n", c);
	printf ("A DIFERENÇA ENTRE PRIMERIO E O SEGUNDO NUMERO DIGITADO É IGUAL A %i\n", d);
	printf ("A DIFERENÇA ENTRE O SEGUNDO E O PRIMEIRO NUMERO DIGITADO É IGUAL A %i\n", e);
	printf ("A MULTIPLICAÇÃO ENTRE OS NUMEROS DIGITADOS É IGUAL A %i\n", f);
	printf ("A DIVISAO ENTRE O PRIMEIRO E O SEGUNDO NUMERO DIGITADO É IGUAL A %i\n", g);
	printf ("A DIVISAO ENTRE O SEGUNDO E  O PRIMEIRO NUMERO DIGITADOS É IGUAL A %i\n", h);
	printf ("O RESTO DA DIVISAO ENTRE O PRIMEIRO E O SEGUNDO NUMERO DIGITADO É IGUAL A %i\n", i);
	printf ("O RESTO DA DIVISÃO ENTRE O SEGUNDO E  O PRIMEIRO NUMERO DIGITADOS É IGUAL A %i\n", j);
	system ("pause");
}

// 21 - Faça um programa que receba duas notas de um aluno e seus respectivos pesos, calcule e imprima a média ponderada dessas notas.
#include <stdlib.h>
#include <stdio.h>
int main () {
	int a, b, c;
	float m;
	printf ("DIGITE A PRIMEIRA NOTA:\n");
	scanf ("%i", &a);
	printf ("DIGITE A SEGUNDA NOTA:\n");
	scanf ("%i", &b);
	c=b*2;

	m = (c+b)/3;
	printf ("SUA MÉDAI FINAL E %f:\n", m);
	system ("pause");

}

// 22 - Faça um programa que receba um número real, calcule e imprima: 
// a) a parte inteira do número; 
// b) a parte fracionária do número; 
// c) arredondamento do número. 
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int main () {
	float a, x, z, w;
	int  b ;
	printf ("DIGITE O NUMERO RACIONAL USANDO PONTO FINAL PARA SEPARAR O INTERIO DOS DECIMAIS:\n");
	scanf ("%f", &a);
	b = (int)a;
	printf ("PARTE INTERIA DO NUMERO E: %i\n", b);
	x = a - b;
	printf ("A PARTE FRACIONARIA DO NUMERO E: %f\n", x);
	z = ceil(a);
	printf ("O NUMERO ARREDONDADO E PARA CIMA E: %f\n", z);
	w = floor(a);
	printf ("O NUMERO ARREDONDADO E PARA BAIXO E: %f\n", w);
	system ("pause");
}

// 23 - Faça um programa que receba a medida de um ângulo em graus, calcule e imprima o seno, 
// o cosseno e a tangente desse ângulo.
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846264338327950288
int main () {
	float a, x, s, c, t;
	printf ("DIGITE O VALOR DO ANGULO EM GRAUS:\n");
	scanf ("%f", &a);
	x = (M_PI*a)/180;
	printf ("O VALOR DESSE ANGULO EM RAD E: %f\n", x);
	s = sin(x);
	c = cos (x);
	t = tan (x);
	printf ("OS VALORE TRIGONOMETRICOS SAO:\n sen(%f) = %f\n cos(%f) = %f\n tg(%f) = %f", a,s,a,c,a,t);
	system ("pause");
}

// 25 - Escreva um programa que receba o valor de um depósito e o valor da taxa de juros. 
// Calcule e imprima o valor do rendimento e o valor total depois do rendimento.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main () {
	float a, b, c, d, i,j ;
	printf ("DIGITE O  VALOR DO DEPOSITO:\n");
	scanf ("%f", &a);
	printf ("DIGITE O  VALOR DA TAXA DE JUROS AO MES, EM PORCENTAGEM:\n");
	scanf ("%f", &b);
	i= b/100;
	printf ("DIGITE O  VALOR DO TEMPO EM MESES QUE O DINHEIRO FICARA DEPOSITADO:\n");
	scanf ("%f", &c);

	j = a*i*c;
	printf(" O VALOR DO JUROS E %f AO MES:\n", j);

	d = a + j;
	printf(" O VALOR DO MONTANTE E %f:\n", d);
	system ("pause");
}

// 27 Faça um programa que, tendo como dados de entrada dois pontos quaisquer do plano,
// P(x1,y1) e Q(x2,y2), imprima a distância entre eles. A fórmula da distância é sqrt((x2-x1)^2 + (y2-y1)^2)
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main () {
	float a, b, c, d, x1, x2, y1, y2, final ,raiz;
	printf ("DIGITE O  VALOR DE X1:\n");
	scanf ("%f", &a);
	printf ("DIGITE O  VALOR DE Y1:\n");
	scanf ("%f", &b);
	printf ("DIGITE O  VALOR DE X2:\n");
	scanf ("%f", &c);
	printf ("DIGITE O  VALOR DE Y2:\n");
	scanf ("%f", &d);

	x1 =  c - a;
	x2 = x1*x1;
	y1 = d - b;
	y2 = y1*y1;
	final = x2 + y2;
	raiz = sqrt(final);
	printf(" O VALOR DA RETA QUE VAI DE UM PONTO A OUTRO E %f:\n", raiz);
	system ("pause");
}

// 29 - Faça um programa que receba dois números, calcule e imprima um elevado ao outro.
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int main ()
{
	float a,b,c;
	printf ("INSIRA O PRIMERIO NUMERO\n");
	scanf ("%f", &a);
	printf ("INSIRA O SEGUNDO NUMERO\n");
	scanf ("%f", &b);
	c = pow(a,b);
	printf ("O PRIMEIRO NUMERO ELEVADO AO SEGUNDO E IGUAL A: %f\n", c);
	system ("pause");
}

// 31 - Faça um programa que receba uma determinada hora (hora e minuto separados por ponto), 
// calcule e imprima essa hora em minutos.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main () 
{
	int a, b, c, d;
	printf ("DIGITE O  VALOR DA HORA:\n");
	scanf ("%i", &a);
	c = a * 60;
	printf ("DIGITE O  VALOR DO MINUTO:\n");
	scanf ("%i", &b); 
	d = c + b;
	printf(" O VALOR DO HORA EM MINUTOS E %i:\n", d);
	system ("pause");
}

// 33 Faça um programa que receba o salário de um funcionário, calcule e imprima o valor do imposto de renda a ser pago, sabendo que o imposto equivale a 5% do salário.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main () {
	float a, b, c;
	printf ("DIGITE O VALOR DO SALARIO:\n");
	scanf ("%f", &a);
	b = a*0.05;
	printf(" O VALOR DO EMPOSTO DE RENDA A SER PAGO E %f:\n", b);
	c = a - b;
	printf(" POR TANTO O VALOR DO SEU NOVO SALARIO E %f:\n", c);
	system ("pause");
}

// 35 Sabe-se que o quilowatt de energia custa um quinto do salário mínimo. Faça um programa que receba o valor do salário mínimo e a quantidade de quilowatts gasta por uma residência. Calcule e imprima: 
// a) o valor, em reais, de cada quilowatt; 
// b) o valor, em reais, a ser pago por essa residência; 
// c) o novo valor a ser pago por essa residência, a partir de um desconto de 15%. 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main () {
	float a, w, novovalor, valor, v = 187.4;
	printf ("DIGITE O VALOR DO SALARIO:\n");
	scanf ("%f", &a);
	printf ("DIGITE O VALOR DE QUILOWATTS GASTO EM SUA RESIDENCIA:\n");
	scanf ("%f", &w);
	system ("cls");
	valor = v*w;
	printf(" O VALOR DE CADA QUILOWATTS E %f:\n", v);
	printf(" O VALOR A SER PAGO POR ESSA RESIDENCIA E %f:\n", valor);

	novovalor = valor*(0.15);
	printf(" COM DESCONTO DE 15 POR CENTO, O NOVO VALOR A SER PAGO POR ESSA RESIDENCIA E %f:\n", novovalor);
	system ("pause");
}