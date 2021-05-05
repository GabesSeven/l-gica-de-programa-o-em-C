// 1 - Após a execução do seguinte trecho de programa
/* ... */
// if (A2 <= B3) TESTE = 1;
// else TESTE = 0;
/* ... */
// na variável TESTE estará armazenado o valor falso se, originalmente:
// a) A2 < B3
// b) A2 <= B3
// c) A2 >= B3
// d) A2 > B3
// e) A2 == B3
// LETRA D

// 3 - /* ... */
/*if (A) C1;
else {
    if (B)
        if (C) C2;
        else {
            C3;
            C4;
        }
        C5;
}
C6;*/
/* ... */
// Dado o trecho de programa anterior, responda:
// a) Se A = 1, B = 1, C = 0, quais comandos serão executados? C1,C6.
// b) Se A = 0, B = 1, C = 0, quais comandos serão executados? C3,C4,C5,C6.
// c) Se A = 0, B = 1, C = 1, quais comandos serão executados? C2,C5,C6.
// d) Quais são os valores de A, B, C para que somente o comando C5 seja executado? NÃO HÁ COMO O C5 SER EXECULTADO SOZINHO
// e) Quais são os valores de A, B, C para que somente o comando C6 seja executado? 0,0,0

// 5 - O que está errado no programa a seguir?
// #include <stdio.h>
// #include <stdlib.h>
// int main () {
    // float n, par;
    // scanf ("%f",&n);
    // if (n % 2 == 1) par = 0;
    // else par = 0;
    // system ("Pause");
// }
/*O programa dará erro, pois não foi setado um valor para n*/

// 7 - Faça um programa que receba o peso de uma pessoa, um valor inteiro, calcule e imprima:
// a) o peso dessa pessoa em gramas;
// b) se essa pessoa engordar 5%, qual será seu novo peso em gramas.
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() {
    int a, b;
    printf("DIGITE O VALOR DE SEU PESO EM KG\n");
    scanf("%i",&a);
    printf("SEU PESO EM GRAMAS E: %dg, SE VOCE ENGORDAR 5 POR CENTO FICARA COM UM PESO TOTAL DE %dg\n", a*1000,((a*5/100)+a)*1000);
    getch(); 
}       

// 9 - Faça um programa que, dado um número inteiro, verifique se este número é par
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() {
    int a;
    printf("DIGITE O VALOR DE SEU PESO EM KG\n");
    scanf("%i",&a);
    if (a%2==0) printf ("ESTE NUMERO E PAR");
    else printf ("ESTE NUMERO E IMPAR");
    getch(); 
}

// 11 - Dados três valores (x,y,z), verifique se eles podem ser comprimentos dos lados de um triân-gulo, e caso afirmativo, verificar se o triângulo é eqüilátero, isósceles ou escaleno. Se não puderem formar um triângulo, escreva uma mensagem.
// Propriedade: O comprimento de cada lado de um triângulo é menor do que a soma dos comprimentos dos outros dois lados.
// Definição 1: Chama-se triângulo eqüilátero ao triângulo que tem os comprimentos dos três lados iguais.
// Definição 2: Chama-se triângulo isósceles ao triângulo que tem os comprimentos de dois la-dos iguais.
// Definição 3: Chama-se triângulo escaleno ao triângulo que tem os comprimentos de seus três lados diferentes.
#include<stdio.h>
// #include<conio.h>
#include<math.h>
#include<stdlib.h>
int main() 
{
	int a, b, c;
	printf("TRIANGULO:\n");
	printf("INSIRA O VALOR DO LADO A:\n");
	scanf("%i", &a);
	printf("INSIRA O VALOR DO LADO B:\n");
	scanf("%i", &b);
	printf("INSIRA O VALOR DO LADO C:\n");
	scanf("%i", &c);
	if(a!=b&&c!=b&&c!=a)printf("O TRIANGULO É ESCALENO\n");
	else if (a==b&&b==c&&a==c) printf("O TRIANGULO É EQUILATERO\n");
	else if (c==a||a==c&&a!=b||b!=a&&c!=b||b!=c) printf("O TRIANGULO É ISOSCELES\n");
	getch();
}

// 13 - Elabore um programa que, dada a idade de um nadador, classifique-o em uma das seguin-tes categorias: 
// -> infantil A: 5 - 7 anos; 
// -> infantil B: 8 - 10 anos; 
// -> juvenil A: 11 - 13 anos; 
// -> juvenil B: 14 - 17 anos; 
// -> sênior: maiores de 18 anos. 
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() {
	int a;
	printf("ENTRE COM O VALOR DA IDADE DO NADADOR:\n");
	scanf("%i", &a);
	if (a<5) printf("NADADOR NÃO PODE PARTICIPAR - IDADE INVALIDA");
	else if(a>=5&&a<=7) printf("NADADOR ADEPTO A CATEGORIA INFANTIL A");
	else if(a>=8&&a<=10) printf("NADADOR ADEPTO A CATEGORIA INFANTIL B");
	else if(a>=11&&a<=13) printf("NADADOR ADEPTO A CATEGORIA JUVENIL A");
	else if(a>=14&&a<=17) printf("NADADOR ADEPTO A CATEGORIA JUVENIL B");
	else if(a>=18) printf("NADADOR ADEPTO A CATEGORIA SENIOR");
    getch();
}

// 15 - Escreva um programa que calcule o que deve ser pago por um produto, considerando o preço normal de etiqueta e a escolha da condição de pagamento. Utilize os códigos da tabela a seguir para ler qual condição de pagamento escolhida e efetuar o cálculo adequado.
// Código.
// Condição de pagamento:
// 1 À vista em dinheiro ou cheque, recebe 10% desconto
// 2 À vista no cartão de crédito, recebe 5% desconto
// 3 Em 2 vezes, preço normal de etiqueta sem juros
// 4 Em 3 vezes, preço normal de etiqueta mais juros de 10%
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() 
{
	float a,b;
	printf("DIGITE O VALOR DO PRODUTO:\n");
	scanf("%f", &a);
	printf("ESCOLHA UM DOS SISTEMAS DE PAGAMENTOS:\n1 - A VISTA OU CHEQUE 10 POR CENTO DE DESCONTO\n2 - A VISTA NO CARTAO DE CREDITO 5 POR CENTO DE DESCONTO\n3 - 2X SEM JUROS\n4 - 3X COM 10 POR CENTO DE JUROS\n\n");
	scanf("%f", &b);
    while (b<1||b>4) {	
        printf ("OPÇAO DE PAGAMENTO INVALIDA!\n");
        scanf("%f", &b);
    } 
    if (b==1) printf ("OPÇAO 1: CUSTO DO SEU PRODUTO E: %.2f", a-a*10/100);
    else if (b==2) printf ("OPÇAO 2: CUSTO DO SEU PRODUTO E: %.2f", a-a*5/100);
    else if (b==3) printf ("OPÇAO 3: CUSTO DO SEU PRODUTO E: %.2f MENSAL", a/2);
    else if (b==4) printf ("OPÇAO 4: CUSTO DO SEU PRODUTO E: %.2f MENSAL", a/3+a*10/100);
    getch();
}

// 17 A solução (x,y) para o sistema de equações lineares abaixo:
// Escreva um programa que leia os parâmetros a, b, c, d, u, v do sistema,
// calcule e imprima a solução x, y do sistema.
#include<stdio.h>
// #include<conio.h>
#include<math.h>
#include<stdlib.h>
int main()  {
	float a,b,c,d,u,v,x,y;
	printf("DIGITE O VALOR A,B,C,D,U e V RESPECTIVAMENTE, TAL QUE SISTEMA{A*X+B*Y=U e C*X+D*Y=V}:\n");
	scanf("%f%f%f%f%f%f", &a,&b,&c,&d,&u,&v);
	// calculando valor de X:
	x = (d/((a*d)-(b*c)))*u-(b/((a*d)-(b*c)))*v;
	//calculando vaor de Y:
	y = (-c/((a*d)-(b*c)))*u+(a/((a*d)-(b*c)))*v;
	printf("OS VALORES DE X E Y SAO RESPECTIVAMENTE: %.2f E %2.f\n", x,y);
    getch();
}

// 19 - Escreva um programa que receba o código correspondente ao cargo de um funcionário e imprima seu cargo e o percentual de aumento ao qual este funcionário tem direito seguindo a tabela abaixo:
// Código  Cargo           Percentual
// 1       Escriturário    60% 
// 2       Secretário      40%  
// 3       Caixa           25% 
// 4       Gerente         5% 
// 5       Diretor         Não tem aumento 
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() 
{
	float b;
	printf("DIGITE O NUMERO DO CODIGO:\n1 - ESCRITUARIO\n2 - ESCRITUARIO\n3 - CAIXA\n4 - GERENTE\n5 - DIRETOR\n");
	scanf("%f", &b);
    while (b<1||b>5) {	
        printf ("OPÇAO DE PAGAMENTO INVALIDA!\n");
        scanf("%f", &b);
    } 
    if (b==1) printf ("OPÇAO 1 - ESCRITUARIO: DIREITO DE AUMENTO IGUAL A 60 POR CENTO");
    else if (b==2) printf ("OPÇAO 2 - ESCRITUARIO: DIREITO DE AUMENTO IGUAL A 40 POR CENTO");
    else if (b==3) printf ("OPÇAO 3 - CAIXA: DIREITO DE AUMENTO IGUAL A 25 POR CENTO");
    else if (b==4) printf ("OPÇAO 4 - GERENTE: DIREITO DE AUMENTO IGUAL A 5 POR CENTO");
    else if (b==5) printf ("OPÇAO 5 - DIRETOR: NAO HA DIREITO DE AUMENTO");
    getch();
}

// 21 - No curso de física, a nota final do estudante é calculada a partir de 3 notas atribuídas res-pectivamente a um trabalho de laboratório, uma avaliação semestral e um exame final. As notas variam de 0 a 10 e, a nota final é a média ponderada das 3 notas mencionadas. A ta-bela a seguir fornece os pesos das notas:
// Laboratório  Peso 3 
// Avaliação semestral  Peso 2 
// Exame Final  Peso 5 

// Faça um programa que receba as 3 notas do estudante, calcule e imprima a média final e o conceito desse estudante. O conceito segue a tabela abaixo:
// Média Final             Conceito 
// 8,5 (inclusive) a 10,0  A 
// 7,0 (inclusive) a 8,5   B 
// 6,0 (inclusive) a 7,0   C 
// 5,0 (inclusive) a 6,0   D 
// Menor que 5,0           E 
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() 
{
	float l,as,ef,media;
	printf ("CALCULO DA MEDIA FINAL DE FISICA\n");
	printf("DIGITE OS VALORES DA NOTAS DE LABORATORIO (DE 0 A 10), AVALIACAO SEMESTRAL E EXAME FINAL RESPECTIVAMENTE\n");
	scanf("%f%f%f", &l,&as,&ef);
	media  = ((l*3)+(as*2)+(ef*5))/10;
	printf ("SUA MEDIA FINAL E %2.f\n", media);
    while (media>10||media<0){
        printf("HOUVE ERRO NO VALOR DAS NOTAS COLOCADAS, TENTE NOVAMENTE:\n");
        scanf("%f%f%f", &l,&as,&ef);
    }
    media  = ((l*3)+(as*2)+(ef*5))/10;
    if (media>=8.5&&media<=10) printf ("SEU CONCEITO E: A");
    else if (media>=7&&media<8.5) printf ("SEU CONCEITO E: B");
    else if (media>=6&&media<7) printf ("SEU CONCEITO E: C");
    else if (media>=5&&media<6) printf ("SEU CONCEITO E: D");
    else if (media>=0&&media<5) printf ("SEU CONCEITO E: E");
    getch();
}

// 23 - Uma empresa decide dar um aumento de 13% aos funcionários cujo 
// salário é inferior a R$840,00. Escreva um programa que receba o salário de um 
// funcionário e imprima o valor do salário reajustado ou uma mensagem caso o 
// funcionário não tenha direito ao aumento.
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() {
	float a;
	printf ("CALCULO DE REAJUSTE DE SALARIO\n");
	printf("DIGITE OVALOR DE SEU SALARIO\n");
	scanf("%f", &a);
    if (a>=840.00) printf ("NAO HA DIREITO A AUMENTO");
    else printf ("SEU NOVO SALARIO E: %.2f", a+(a*13/100));
    getch();
}

// 25 - Escreva um programa que, tendo como dados de entrada o preço de um 
// produto e um có-digo de origem, emita o preço junto de sua procedência. 
// Caso o código não seja nenhum dos especificados, o produto deve ser encarado como importado. 
// A procedência obedece a seguinte tabela:
// Código de origem    Procedência 
// 1                   Sul 
// 2                   Norte 
// 3                   Leste 
// 4                   Oeste 
// 5 ou 6              Nordeste 
// 7, 8 ou 9           Sudeste 
// 10 até 20           Centro-oeste 
// 21 até 30           Nordeste 
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main()  {
	float a,b;
	printf("DIGITE OS PRECO DO PRODUTO E DE SEU CODIGO (DE 1 A 30)\n");
	scanf("%f%f", &a,&b);
    while (b<0||b>30||a<0) {
	printf("HOUVE ERRO EM ALGUM DOS VALORES INSERIDO, TENTE NOVAMENTE:\n");
	printf("DIGITE OS PRECO DO PRODUTO E DE SEU CODIGO (DE 1 A 30)\n");
	scanf("%f%f", &a,&b);  
    }
    if (b==1) printf ("PROCEDENCIA: SUL, VALOR:%.2f",a);
    if (b==2) printf ("PROCEDENCIA: NORTE, VALOR:%.2f",a);
    if (b==3) printf ("PROCEDENCIA: LESTE, VALOR:%.2f",a);
    if (b==4) printf ("PROCEDENCIA: OESTE, VALOR:%.2f",a);
    if (b==5||b==6) printf ("PROCEDENCIA: NORDESTE, VALOR:%.2f",a);
    if (b==7||b==8||b==9) printf ("PROCEDENCIA: SUDESTE, VALOR:%.2f",a);
    if (b>=10&&b<=20) printf ("PROCEDENCIA: CENTRO-OESTE, VALOR:%.2f",a);
    if (b>20&&b<=30) printf ("PROCEDENCIA: NORDESTE, VALOR:%.2f",a);
    getch();
}

// 27 - Faça um programa que mostre um menu com as seguintes opções: 
// -> Soma 
// -> Produto 
// -> Raiz quadrada 
// -> Sair 
// O programa deve receber a opção desejada, receber os dados necessários para a operação de cada opção,
// realizar a operação e imprimir o resultado. Na opção <Sair> nada deve acontecer.
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
#include<math.h>
int main() 
{
	float a,b,c;
	printf("CALCULADORA");
	printf("DIGITE O CODIGO PARA OPERAR:\n1 - SOMA\n2 - MULTIPLICACAO\n3 - RAIZ\n4 - SAIR\n");
	scanf("%f", &a);
    while (a<0||a>4||a==4) {
	    printf("SAIR, SE DESEJAR TENTE NOVAMENTE:\n");
	    scanf("%f", &a); 
    }
    if (a==1) {
	    printf ("SOMA: DIGITE DOIS VALORES QUE SERAO SOMADOS\n");
	    scanf("%f%f",&b,&c);
	    printf ("RESULTADO:%.2f",b+c);
    } else
    if (a==2) {
	    printf ("MULTIPLCACAO: DIGITE DOIS VALORES QUE SERAO MULTIPLICADOS\n");
	    scanf("%f%f",&b,&c);
	    printf ("RESULTADO:%.2f",b*c);
    } else
    if (a==3) {
	    printf ("RAIZ: DIGITE DO NUMERO REAL PARA SABER SUA RAIZ\n");
	    scanf("%f",&b);
	    printf ("RESULTADO:%.2f",sqrt(b));
    }
    getch();
}

// 29 - Uma empresa decidiu dar uma gratificação de Natal aos seus funcionários, 
// baseada no número de horas extras e no número de horas que o funcionário faltou ao trabalho. 
// O valor do prêmio é obtido pela consulta na tabela a seguir, em que:
// H = (Número de horas extras)-(2/3 *(Número de horas-falta))
// H (minutos)             Prêmio ($) 
// Maior que 2400          800 
// Entre 1800 e 2400       600 
// Entre 1200 e 1800       550 
// Entre 600 e 1200        400 
// Menor ou igual a 600    350 

// Faça um programa que receba o número de horas extras e o número de horas-falta em 
// minutos de um funcionário. Imprima o número de horas extras em horas, 
// o número de horas-falta em horas e o valor do prêmio.
#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
int main() {
    float a,b,h;
    printf("DIGITE O VALOR (EM MINUTOS) DE HORAS EXTRAS E DE HORAS-FALTAS, RESPECTIVAMENTE\n");
    scanf("%f%f",&a,&b);
    h = (a)-(2/3*b);
    if (h<=600) printf ("O NUMERO DE HORAS EXTRAS(EM HORAS):%.2f\nO NUMERO DE HORAS-FALTAS(EM HORAS):%.2f\nO VALOR DA BONIFICACAO: 350.00",a/60,b/60);
    else if (h>600&&h<=1200) printf ("O NUMERO DE HORAS EXTRAS(EM HORAS):%.2f\nO NUMERO DE HORAS-FALTAS(EM HORAS):%.2f\nO VALOR DA BONIFICACAO:400.00",a/60,b/60);
    else if (h>1200&&h<=1800) printf ("O NUMERO DE HORAS EXTRAS(EM HORAS):%.2f\nO NUMERO DE HORAS-FALTAS(EM HORAS):%.2f\nO VALOR DA BONIFICACAO:550.00",a/60,b/60);
    else if (h>1800&&h<=2400) printf ("O NUMERO DE HORAS EXTRAS(EM HORAS):%.2f\nO NUMERO DE HORAS-FALTAS(EM HORAS):%.2f\nO VALOR DA BONIFICACAO:600.00",a/60,b/60);
    else if (h>2400) printf ("O NUMERO DE HORAS EXTRAS(EM HORAS):%.2f\nO NUMERO DE HORAS-FALTAS(EM HORAS):%.2f\nO VALOR DA BONIFICACAO:800.00",a/60,b/60);
    getch(); 
}       

// 33 - Faça um programa que calcule as raízes de uma equação do segundo grau.
#include<stdio.h>
// #include<conio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	float a, b, c, delta, x1, x2;
	printf("EQUAÇÃO DO SEGUNDO GRAU:\n");
	printf("ENTRE COM O VALOR DE A:\n");
	scanf("%f", &a);
	printf("ENTRE COM O VALOR DE B:\n");
	scanf("%f", &b);
	printf("ENTRE COM O VALOR DE C:\n");
	scanf("%f", &c);
	delta = pow(b,2) - 4*a*c;
	
	if(delta<0)printf("NAO EXISTE RAIZES REAIS");
	else if (delta==0) {
		x1 = (-b+sqrt(delta))/2*a;
		x2 = (-b-sqrt(delta))/2*a;
		printf("EXISTE DUAS RAIZES REAIS E IGUAIS: %.2f E % .2f", x1,x2);
	}
	else if (delta>0) {
        x1 = (-b+sqrt(delta))/2;
        x2 = (-b-sqrt(delta))/2;
        printf("AS RAIZES REAIS SAO: %.2f E % .2f", x1,x2);		
    }
	getch();
}