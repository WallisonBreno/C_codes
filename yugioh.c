#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Yugi Muto  estava sofrendo com as tecnologias ultrapassadas das máquinas que guardavam suas cartas, então ele viajou
// para Russas Ce em busca de uma tecnologia que melhor guardasse suas cartas, chegando na cidade ele decide buscar ajuda
// na universidade, onde um grupo de alunos decide que árvore binária de busca otimizaria muito os seus equipamentos.
typedef struct no {
  int chave;
  int ataque;
  int defesa;
  struct no *dir;
  struct no *esq;
  char *nome;
} NO;

NO *raiz = NULL;

NO *busca_arvore(int x, NO *pt) {
  if (pt == NULL) {
    return NULL;
  } else if (x == pt->chave) {
    return pt;
  } else if (x < pt->chave) {
    if (pt->esq == NULL) {
      return pt;
    } else {
      return busca_arvore(x, pt->esq);
    }
  } else {
    if (pt->dir == NULL) {
      return pt;
    } else {
      return busca_arvore(x, pt->dir);
    }
  }
}

void insercao_arvore(int x, char *nome, int ataque,int defesa) {
  NO *pt = busca_arvore(x, raiz);
  if (pt != NULL) {
    if (pt->chave == x) {
      printf("Chave duplicada!\n");
    } else {
      NO *pt1 = malloc(sizeof(NO));
      pt1->chave = x;
      pt1->nome = malloc((strlen(nome) + 1) * sizeof(char));
      strcpy(pt1->nome, nome);

      pt1->ataque = ataque;
      pt1->defesa = defesa;
      pt1->esq = NULL;
      pt1->dir = NULL;
      if (x < pt->chave) {
        pt->esq = pt1;
      } else {
        pt->dir = pt1;
      }
    }
  } else {
    NO *pt1 = malloc(sizeof(NO));
    pt1->chave = x;
    pt1->nome = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(pt1->nome, nome);
    pt1->ataque = ataque;
    pt1->defesa = defesa;
    pt1->esq = NULL;
    pt1->dir = NULL;
    raiz = pt1;
  }
}

void pre(NO *pt) {
  if (pt != NULL) {
    printf("%d - %s\n", pt->chave, pt->nome);
    printf("Ataque:%d Defesa:%d\n", pt->ataque, pt->defesa);
    pre(pt->esq);
    pre(pt->dir);
  }
}

void atualizar_arvore(int x) {
  NO *pt = busca_arvore(x, raiz);
  if (pt != NULL) { // arvore nao ta vazia
    
    int R=0;

    while (R != 1 || R != 2 || R != 3) {
        printf("Quais dados deseja alterar?\n[1]Nome\n[2]Ataque\n[3]Defesa\n[4]Finalizar alterações\n");
        scanf("%d", &R);
        
        if(R == 1){
            printf("Digite o novo nome da carta: ");
            char nome_atualizar[50];
            scanf("%s", nome_atualizar);
            pt->nome = malloc((strlen(nome_atualizar) + 1) * sizeof(char));
            strcpy(pt->nome, nome_atualizar);

        }
        else if(R == 2){
            printf("Digite o novo ataque da carta: ");
            int ataque_atualizar;
            scanf("%d", &ataque_atualizar);
            pt->ataque = ataque_atualizar;

        }
        else if(R == 3){
            printf("Digite a nova defesa da carta: ");
            int defesa_atualizar;
            scanf("%d", &defesa_atualizar);
             pt->defesa = defesa_atualizar;

        }else if(R == 4){
            break;
        }
        else{
            printf("Opção inválida. Tente novamente.\n");

        }
        
  }

  } else { // arvore vazia
    printf("Elemento não encontrado\n");
  }
}

NO *deleteNode(NO *raiz, int k) {
  // Caso base
  if (raiz == NULL)
    return raiz;

  // Chamadas recursivas para os ancestrais do nó a ser deletado
  if (raiz->chave > k) {
    raiz->esq = deleteNode(raiz->esq, k);
    return raiz;
  } else if (raiz->chave < k) {
    raiz->dir = deleteNode(raiz->dir, k);
    return raiz;
  }

  // Chegamos aqui quando raiz é o nó a ser deletado.

  // Se um dos filhos é vazio
  if (raiz->esq == NULL) {
    NO *temp = raiz->dir;
    free(raiz);
    return temp;
  } else if (raiz->dir == NULL) {
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


void exibirMenu() {
  printf("\n--- Menu ---\n");
  printf("1. Inserir uma carta\n");
  printf("2. Atualizar uma carta\n");
  printf("3. Deletar uma carta\n");
  printf("4. Exibir as cartas\n");
  printf("5. Fechar o programa\n");
  printf("Escolha uma opção: ");
}

int main() {

  int escolha = 0;

  while (escolha != 5) {
    exibirMenu();
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      printf("Digite a chave da carta: ");
      int chave;
      scanf("%d", &chave);

      printf("Digite o ataque do carta: ");
      int ataque;
      scanf("%d", &ataque);

      printf("Digite a defesa do carta: ");
      int defesa;
      scanf("%d", &defesa);

      printf("Digite o nome do carta: ");
      char nome[50];
      scanf("%s", nome);

      insercao_arvore(chave, nome,ataque,defesa);
      break;
    case 2:
      printf("Digite a chave da carta a ser atualizada: ");
      int chave_atualizar;
      scanf("%d", &chave_atualizar);


      atualizar_arvore(chave_atualizar);
      break;
    case 3:
      printf("Digite a chave da carta a ser deletada: ");
      int chave_deletar;
      scanf("%d", &chave_deletar);
      raiz = deleteNode(raiz, chave_deletar);
      break;
    case 4:
      printf("\n--- Suas cartas ---\n");
      pre(raiz);
      printf("---------------------------\n");
      break;
    case 5:
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }
  }

  return 0;
}