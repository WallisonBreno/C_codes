#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char *jogador;
    char *funcao;
    int cansaco_mental;
    int cansaco_fisico;
    struct no *prox;
    struct no *ant;
}NO;


NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void adicionar(char *jog, char* func, int mental, int fisico){
  
    NO *novo = malloc (sizeof (NO));
    novo->jogador = jog;
    novo->funcao = func;
    novo->cansaco_mental = mental;
    novo->cansaco_fisico = fisico;
    novo->prox = NULL;
   
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        tam++;
    }else{
        fim->prox = novo;
        novo->ant = fim;
        fim = novo;
        tam++;
    }
}

char *remover(char *funcao){
    char * jogador = "Sem opções!";
    if(inicio != NULL){
        
        NO * lixo = NULL;
        float nivel_stress;
        
        if(inicio->funcao == funcao){
            nivel_stress = (inicio->cansaco_mental + inicio->cansaco_fisico)/2;
            if(nivel_stress < 5){
                lixo = inicio;
                jogador = inicio->jogador;
                inicio = inicio->prox;
                inicio->ant = NULL;
                free(lixo);
                tam--;
            }
        }
        if(lixo == NULL && fim->funcao == funcao){
            nivel_stress = (fim->cansaco_mental + fim->cansaco_fisico)/2;
            if(nivel_stress < 5){
                lixo = fim;
                jogador = fim->jogador;
                fim = fim->ant;
                fim->prox = NULL;
                free(lixo);
                tam--;
            }
        }
        if(lixo == NULL && inicio->prox != NULL){
         //apresente o codigo e explique OU
        //desenhe e explique esta parte do codigo
            NO * aux = inicio->prox;
            while(aux != fim){
                if(aux->funcao == funcao){
                    nivel_stress = (aux->cansaco_mental + aux->cansaco_fisico)/2;
                    if(nivel_stress < 5){
                        aux->ant->prox = aux->prox;
                        aux->prox->ant = aux->ant;
                        jogador = aux->jogador;
                        free(aux);
                        tam--;
                        break;
                    }
                }
                aux = aux->prox;
            }
        }
    }
    return jogador;
}


void imprimir(NO * aux){
    
    if(aux != NULL){

        printf("Jogador: %s\n", aux->jogador);
        printf("Função: %s\n", aux->funcao);
        aux = aux->prox;
        imprimir(aux);    
    }

}

int main(){
    adicionar("Alisson - Liverpool", "Goleiro", 9, 8);
    adicionar("Danilo - Juventus","Lateral", 4, 0);
    adicionar("Militão - Real Madrid", "Zagueiro", 5, 3);
    adicionar("Fabinho - Liverpool", "Goleiro", 2, 1);
    adicionar("Neymar - PSG", "Atacante", 8, 9);
    printf("Jogador removido: %s.\n", remover("Atacante"));
    printf("Jogadores disponíveis:\n");
    imprimir(inicio);
    
    return 0;
}


