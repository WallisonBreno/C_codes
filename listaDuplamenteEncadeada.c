#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
    struct no * ant;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void add(int pos, int valor){
    
    if(pos >= 0 && pos <= tam){
        //Passo 1 - aloco espaco de memoria e coloco os valores no NO novo
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;
        //Passo 2 - encaixo esse no na lista
        if(inicio == NULL){//vazia
            inicio = novo;
            fim = novo;
        }else if(pos == 0){  //inicio
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        }else if(pos == tam){//fim!
                fim->prox = novo;
                novo->ant = fim;
                fim = novo;
        }else{//entre os elementos da lista ("meio")
                NO * aux = inicio;
                for(int i = 0; i<pos; i++){
                    aux = aux->prox; //caminhada
                }
                //operacoes de encaixe! CUIDADE A ORDEM IMPORTA!
                novo->prox = aux;
                aux->ant->prox = novo;
                aux->ant = novo->ant;
                aux->ant = novo;
        }
        tam++;
    }
}

void imprimir(){
    
     NO * aux = inicio;
                   
    for(int i = 0; i<tam; i++){
        printf("idade: %d\n", aux->valor);
        aux = aux->prox;
    }
    
    
}

int remover(pos){
    
    //DICA e necessario desalocar o no com a funcao free()
    if(pos >=0 && pos <=tam - 1){
        NO * lixo;
        if(tam == 1){ //lista so tem um elemento
            
            //etapa 1: aponto o lixo para no a ser removido
            lixo = inicio;
            //etapa 2: removo o no da lista (logica)
            inicio = NULL;
            fim = NULL;

            
        }else if (pos == 0){//inicio
            //etapa 1: aponto o lixo para no a ser removido
            lixo = inicio;
             //etapa 2: removo o no da lista (logica)
            inicio = inicio->prox;
            inicio->ant = NULL;
            
            
        }else if(pos == tam -1){//fim
            //etapa 1: aponto o lixo para no a ser removido
            lixo = fim;
            //etapa 2: removo o no da lista (logica)
            fim = fim->ant;
            fim->prox = NULL;
            
            
        }else{//entre os elementos da lista ("meio")
             lixo = inicio;
            for(int i = 0; i<pos; i++){
                lixo = lixo->prox; //caminhada
            }
            
            lixo->ant->prox = lixo->prox;
            lixo->prox->ant = lixo->ant;
        }
        
        //etapa 3: removo o no da memoria
        int aux = lixo->valor;
        free(lixo);
        tam--;
        return aux;
    }
    return 0;
}


void add_ordenado(int valor){
    
  NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (inicio == NULL){//lista vazia

        inicio = novo;
        fim = novo;
    }else if (inicio -> valor > novo -> valor){//adição de valor menor que o primeiro elemento

        inicio -> ant = novo;
        novo -> prox = inicio;
        inicio = novo;
    }else if (fim -> valor < novo -> valor){//adição de elemento maior que o último

        fim -> prox = novo;
        novo -> ant = fim;
        fim = novo;
    }else{

        if ((novo -> valor - inicio -> valor) < (fim -> valor - novo -> valor)){//se o elemento a ser inserido estiver mais próximo do inicio

            NO * aux = inicio;
            while (aux -> valor < novo -> valor){
                aux = aux -> prox;
            }

            aux -> ant -> prox = novo;
            novo -> ant = aux -> ant;
            novo -> prox = aux;
            aux -> ant = novo;
        }else{

            NO * aux = fim;
            while (aux -> valor > novo -> valor){
                aux = aux -> ant;
            }

            aux -> prox -> ant = novo;
            novo -> prox = aux -> prox;
            novo -> ant = aux;
            aux -> prox = novo;
        }
    }
    tam++;
    
}

void remover_por_valor(int valor){
    
    NO * lixo = NULL;
    if ((inicio -> valor == valor) && (fim -> valor == valor)){

        lixo = inicio;
        inicio = NULL;
        fim = NULL;
    }else if (inicio -> valor  == valor){

        lixo = inicio;
        inicio = inicio -> prox;
        inicio -> ant = NULL;
    }else if (fim -> valor == valor){

        lixo = fim;
        fim = fim -> ant;
        fim -> prox = NULL;
    }else{

        NO * aux;
        if ((valor - inicio -> valor) < (fim -> valor - valor)){

            aux = inicio;
            while ((aux -> valor != valor) && (aux -> prox != NULL)){
                aux = aux -> prox;
            }

            if (aux -> ant == NULL){

                return -1;
            }else{

                lixo = aux;
                aux -> ant -> prox = aux -> prox;
                aux -> prox -> ant = aux -> ant;
            }
        }else{

            aux = fim;
            while ((aux -> valor != valor) && (aux -> ant != NULL)){
                aux = aux -> ant;
            }

            if (aux -> ant == NULL){

                return -1;
            }else{

                lixo = aux;
                aux -> ant -> prox = aux -> prox;
                aux -> prox -> ant = aux -> ant;
            }
        }
    }

    int aux = lixo->valor;
    free(lixo);
    tam--;
    return aux;
    
}


int main(){
    add(0, 18);
    add(0, 19);
    add(0, 17);
    add(3, 21);
    add(3, 15);
    add(2, 20);
    add_ordenado(45);
    imprimir();
    return 0;
}


