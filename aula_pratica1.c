#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int idade;
    float peso;
    float altura;
    struct no * prox;
}NO;

NO * inicio = NULL;

void add(int idade, float peso, float altura){
        //1 - COMPILADOR! cria espaco na memoria para o no e nao desaloca!!!! Por favor!
        NO * novo = malloc(sizeof(NO));
        //2 - seto os valores desse no
        novo->idade = idade;
        novo->peso = peso;
        novo->altura = altura;
        novo->prox = NULL;
        //3 - encaixo esse no na lista
        if(inicio == NULL){//vazia
            inicio = novo;
        }else{
            //inicio
            novo->prox = inicio;
            inicio = novo;
            
            //DESAFIO: //criar os casos para add no fim e no meio
        }
}
void addLast(NO **inicio, int idade, float peso, float altura)
{

    NO *novo = malloc(sizeof(NO));
    novo->idade = idade;
    novo->peso = peso;
    novo->altura = altura;
    novo->prox = NULL;


    if(*inicio == NULL)
        *inicio = novo;

    else
    {
        NO *ultimo = *inicio;


        while(ultimo->prox != NULL)
        {
            ultimo = ultimo->prox;
        }


        ultimo->prox = novo;
    }
}
int getCurrSize (NO *inicio)
{
  int size = 0;

  while (inicio != NULL)
    {
      inicio = inicio->prox;
      size++;
    }
  return size;
}
void insert(int pos,NO **inicio, int idade, float peso, float altura)
{
  int size = getCurrSize(*inicio);

    NO *novo = malloc(sizeof(NO));
    novo->idade = idade;
    novo->peso = peso;
    novo->altura = altura;
    novo->prox = NULL;


  if (pos < 0 || pos > size)
    printf ("Posição inválida\n");

  else if (pos == 0)
    {
      novo->prox = *inicio;
      *inicio = novo;
    }

  else
    {

      NO *aux = *inicio;

      while (--pos)
	  aux = aux->prox;


      novo->prox = aux->prox;

      aux->prox = novo;

    }
}
void imprimir(){
    
    //logica para percorrer a lista imprimindo os dados (altura, peso e idade) de cada elemento da lista
    //DICA:
    NO * aux = inicio;
    printf("Dados:\n");
    while(aux != NULL){
        printf("Idade: %d anos\n", aux->idade);
        printf("Peso: %.2f kg\n", aux->peso);
        printf("Altura: %.2f metros\n", aux->altura);
        printf("\n");
        aux = aux->prox;
    }
    
}

int main(){
    add(18, 59.5, 1.7);
    add(19, 61.7, 1.65);
    add(17, 72.1, 1.8);
    addLast(&inicio,18, 73.1, 1.9);
    addLast(&inicio,21, 40.1, 1.6);
    insert(1,&inicio,40, 73.1, 1.9);
    insert(3,&inicio,40, 73.1, 1.9);
    insert(5,&inicio,40, 73.1, 1.9);
    insert(7,&inicio,40, 73.1, 1.9);
    imprimir();
    
    return 0;
}


