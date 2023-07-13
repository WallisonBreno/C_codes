#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    //dados dependem da aplicacao
    struct no * dir;
    struct no * esq;
    char *nome;
}NO;


NO *raiz = NULL;

NO * busca_arvore(int x, NO *pt){
    if(pt == NULL){ //arv. vazia
        return NULL;
    }else if(x == pt->chave){ //encontrado
        return pt;
    }else if(x < pt->chave){
        //esq! :D
        if(pt->esq == NULL){
            return pt;
        }else{
            return busca_arvore(x, pt->esq);
        }
    }else{
        //dir
        if(pt->dir == NULL){
            return pt;
        }else{
            return busca_arvore(x, pt->dir);
        }
    }
}

void insercao_arvore(int x, char* nome){
    NO * pt = busca_arvore(x, raiz);
    if(pt != NULL){ //arvore nao ta vazia
        if(pt->chave == x){
            printf("Chave duplicada!\n");
        }else{
            NO *pt1 = malloc(sizeof(NO));
            pt1->chave = x;
            pt1->nome = nome;
            pt1->esq = NULL;
            pt1->dir = NULL;
            if(x <pt->chave){
                pt->esq = pt1;
            }else{
                pt->dir = pt1;
            }
        }
    }else{//arvore vazia
        NO *pt1 = malloc(sizeof(NO));
        pt1->chave = x;
        pt1->esq = NULL;
        pt1->dir = NULL;
        raiz = pt1;
        
    }
}

void atualizar_arvore(int x, char* nome){
    NO * pt = busca_arvore(x, raiz);
    if(pt != NULL){ //arvore nao ta vazia
        pt->nome = nome;          
    }else{//arvore vazia
        printf("Elemento não encontrado");
    }
}

NO * deleteNode(NO *raiz, int k)
{
    // Caso base
    if (raiz == NULL)
        return raiz;
 
    // Chamadas recursivas para os ancestrais do nó a ser deletado
    if (raiz->chave > k) {
        raiz->esq = deleteNode(raiz->esq, k);
        return raiz;
    }
    else if (raiz->chave < k) {
        raiz->dir = deleteNode(raiz->dir, k);
        return raiz;
    }
 
    // Chegamos aqui quando raiz é o nó a ser deletado.
 
    // Se um dos filhos é vazio
    if (raiz->esq == NULL) {
        NO *temp = raiz->dir;
        free(raiz);
        return temp;
    }
    else if (raiz->dir == NULL) {
        NO *temp = raiz->esq;
        free(raiz);
        return temp;
    }
 
    // Se ambos os filhos existem
    else {
 
        NO *paisucessor = raiz;
 
        // Encontrar o sucessor
        NO *sucessor = raiz->dir;
        while (sucessor->esq != NULL) {
            paisucessor = sucessor;
            sucessor = sucessor->esq;
        }
 
        // Deletar o sucessor. Como o sucessor
        // é sempre filho esquerdo de seu pai,
        // podemos com segurança tornar o filho direito
        // do sucessor como filho esquerdo do seu pai.
        // Se não houver sucessor, então atribuímos
        // sucessor->dir a paisucessor->dir
        if (paisucessor != raiz)
            paisucessor->esq = sucessor->dir;
        else
            paisucessor->dir = sucessor->dir;
 
        // Copiar os dados do sucessor para raiz
        raiz->chave = sucessor->chave;
 
        // Deletar o sucessor e retornar raiz
        free(sucessor);
        return raiz;
    }
}

void pre(NO *pt){
    
    printf("%d - ", pt->chave);
    printf("%s\n", pt->nome);
    if(pt->esq != NULL){
        pre(pt->esq);
    }
    if(pt->dir != NULL){
        pre(pt->dir);
    }
}



int main(){
    insercao_arvore(30,"Wallison");
    insercao_arvore(20,"Wallison");
    insercao_arvore(40,"Wallison");
    insercao_arvore(10,"Wallison");
    insercao_arvore(25,"Wallison");
    insercao_arvore(5,"Wallison");
    insercao_arvore(15,"Wallison");
    insercao_arvore(22,"Wallison");
    insercao_arvore(35,"Wallison");
    insercao_arvore(50,"Wallison");
    insercao_arvore(45,"Wallison");
    insercao_arvore(60,"Wallison");
    deleteNode(raiz, 60);
    atualizar_arvore(30, "Vitor");
    pre(raiz);
    
    return 0;
}