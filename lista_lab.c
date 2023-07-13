#include<stdio.h>
#include<stdlib.h>

int main(){
    const int IDADE = 25;
    int anoNascimento = 1998;
    float preco = 2.99;
    const char SEXO = 'M';
    char inicial = 'A';
    double taxaJuros = 0.05;
    printf("Valor da constante IDADE: %d\n", IDADE);
    printf("Valor da variavel anoNascimento: %d\n", anoNascimento);
    printf("Valor da variavel preço: %.2f\n",preco);
    printf("Valor da constante SEXO: %c\n",SEXO);
    printf("Valor da variavel inicial: %c\n",inicial);
    printf("Valor da variavel taxaJuros: %.2f\n",taxaJuros);
    int idade = IDADE;
    char sexo = SEXO;
    float desconto = preco*0.1;
    double valorFinal = preco - desconto;
    printf("Valor da variavel idade: %d\n", idade);
    printf("Valor da variavel sexo: %c\n",sexo);
    printf("Valor da variavel desconto: %.2f\n",desconto);
    printf("Valor da variavel valorFinal: %.2f\n",valorFinal);
    }