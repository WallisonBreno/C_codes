#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    
    char * nome_musica;
    double minutos;
    struct no * prox;
    struct no * ant;
}NO;

NO * inicio = NULL;

void adicionar (char * musica, double duracao){

    NO * novo = malloc(sizeof(NO));
    novo -> nome_musica = musica;
    novo -> minutos = duracao;
    novo -> prox = NULL;
    novo -> ant = NULL;

    if (inicio == NULL){

        inicio = novo;
        novo -> prox = novo;
        novo -> ant = novo;
        //no meu entendimento, caso a lista de música contenha somente uma música, tocará somente ela
    } else {
        //lógica de adicionar músicas com mais de um elemento na playlist, pela ordem em que são adicionados
        NO * aux_posicao = inicio -> ant;//a intenção é organizar a playlist mantendo o loop

        aux_posicao -> prox = novo;
        novo -> ant = aux_posicao;
        novo -> prox = inicio; //a ideia é criar o loop semelhante à anterior
        inicio -> ant = novo; //de maneira abstrata, torna o novo o último elemento da playlist
    }
}

void play (NO * aux, int num_repeticoes){

    if (num_repeticoes > 0) {
        NO* aux = inicio;
        do {
            printf ("Musica: %s | Duracao: %.2f\n", aux -> nome_musica, aux -> minutos);
            aux = aux -> prox;
        } while (aux != inicio);
        num_repeticoes--;
        play(inicio, num_repeticoes);
    }
}

void remover (){
    
    if (inicio == NULL) printf ("Operacao inviável.\n");
    else if (inicio -> prox -> prox != inicio){

        NO * maior_duracao = inicio;
        NO * proxima_duracao = inicio -> prox;

        do {
            if (proxima_duracao -> prox -> minutos > maior_duracao -> minutos) maior_duracao = proxima_duracao -> prox;
            proxima_duracao = proxima_duracao -> prox;
        } while (proxima_duracao -> prox != inicio);    

        if (maior_duracao -> minutos > inicio -> minutos){

            NO * lixo = maior_duracao;

            if (maior_duracao -> minutos == inicio -> ant -> minutos){

                maior_duracao -> ant -> prox = inicio;               
                inicio -> ant = maior_duracao -> ant;
            } else {

                maior_duracao -> ant -> prox = maior_duracao -> prox;
                maior_duracao -> prox -> ant = maior_duracao -> ant;
            }
            free (lixo);
        } else if (inicio -> prox == inicio) {
            
        } else {

            if (inicio -> minutos < inicio -> prox -> minutos){
                
                NO * lixo = inicio -> prox;

                inicio -> prox = inicio -> prox -> prox;
                inicio -> ant = inicio -> prox;
                free (lixo);
            } else {

                NO * lixo = inicio;

                inicio = inicio -> prox;
                inicio -> prox = inicio;
                inicio -> ant = inicio;
                free (lixo);
            }
        }
    } else {

        NO * lixo = inicio;
        inicio = NULL;
        free (lixo);
    }
}

void printPlayList (){

    NO * aux = inicio;

    do {
        printf ("Musica: %s | Duracao: %.2f\n", aux -> nome_musica, aux -> minutos);
        aux = aux -> prox;
    } while (aux != inicio);
}

int main (){

    adicionar ("Evoque Prata", 1.47);
    adicionar ("Eu gosto assim", 2.28);
    adicionar ("Pacto", 3.03);
    adicionar ("Bombonzinho", 2.34);
    printPlayList ();
    remover ();
    remover ();
    
    printf ("Top Spotify Brasil hoje:\n");
    play (inicio, 2);
    printf ("\n");
    return 0;
}