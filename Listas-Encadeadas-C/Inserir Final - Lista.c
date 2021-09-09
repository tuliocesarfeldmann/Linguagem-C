#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int num;
	struct no *prox;
} No;

No* criar_no(void){
	No *no = (No*) malloc(sizeof(No));
	
	return no;
}

No* inserir_final(No* lsta){
	system("cls");
	
	int num;
	
	printf("\n\t\tINSERIR NÚMERO NA LISTA:\n");
	printf("\nInforme o número que deseja adicionar na lista: ");
	scanf("%d", &num);
	
	No *no = criar_no();
	no->num = num;
	
	if(lsta == NULL){
		no->prox = NULL;
		lsta = no;
	}
	else{
		No *aux = lsta;
		while(aux->prox != NULL){ // descobrir onde está o último elemento
			aux = aux->prox;
		}
		no->prox = NULL; // nó criado aponta pra nulo
		aux->prox = no; // antigo último nó aponta para o novo último nó
	}
	return lsta;
}

void imprimir_lista(No *lsta){
	system("cls");
	
	No *aux = lsta;
	
	printf("\nLISTA:\n\n");
	
	if(aux == NULL) printf("A lista está vazia!\n");
	
	else{
		while(aux != NULL){
			printf("%d \n", aux->num);
		
			aux = aux->prox;
		}
	}
	printf("\nPressione qualquer tecla...");
	getch();
}

void pesquisar_elemento(No *lsta){
	system("cls");
	
	No *aux = lsta;
	int num;
	
	printf("\n\t\tPESQUISAR ELEMENTO: \n");
	
	printf("\nInforme o número que deseja pesquisar: ");
	scanf("%d", &num);
	
	while(aux != NULL){
		if(aux->num == num){
			printf("\nNúmero %d está na lista!\n", num);
			break;
		}
		aux = aux->prox;
	}
	if(aux  == NULL) printf("\nNúmero %d não está na lista\n", num);
	
	printf("\nPressione qualquer tecla...");
	getch();
}

No* remover_elemento(No *lsta){
	int num;
	
	system("cls");
	
	printf("\n\t\tREMOVER ELEMENTO:\n");
	printf("\nInforme o número que deseja remover: ");
	scanf("%d", &num);
	
	No *ant = NULL;
	No *atual = lsta;
	
	while(atual != NULL && atual->num != num){
		ant = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL) {	
		printf("\nNúmero %d não está na lista!\n", num);
		sleep(2);
		return lsta;
	}
	if(ant == NULL){
		lsta = atual->prox;
		free(atual);
	}
	else{
		ant->prox = atual->prox;
		free(atual);
	}
	return lsta;
}

void media_lista(No *lsta){
	No *aux = lsta;
	int soma = 0, cont = 0;
	float media = 0;
	
	system("cls");
	printf("\n\t\tMÉDIA DOS ELEMENTOS DA LISTA\n");
	
	if(aux != NULL){
		while(aux != NULL){
			cont++;
			soma = soma + aux->num;
			aux = aux->prox;
		}
		media = (float) soma/cont;
		
		printf("\nMédia: %.2f\n", media);
	}
	else{
		printf("\nA lista está vazia!\n");
	}
	printf("\nPressione qualquer tecla...");
	getch();
}

No* crescente(No *lsta){
    No *aux = lsta;
    No *prox;
    int c;

    if (lsta == NULL || lsta->prox == NULL)
        return NULL;

    while (aux != NULL) {
        prox = aux->prox;
        while (prox != NULL) {
            if (aux->num > prox->num) {
                c = aux->num;
                aux->num = prox->num;
                prox->num = c;
            }
            prox = prox->prox;
        }
        aux = aux->prox;
    }
    return lsta;
}

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	No *lista = NULL;
	int opc;
	
	do{
		system("cls");
		printf("\n\t\tMENU:\n");
		printf("\n[1]- Adicionar número\n[2]- Imprimir lista\n[3]- Pesquisar número\n[4]- Remover número\n[5]- Média da lista\n[6]- Colocar em ordem crescente\n[7]- Sair do programa\n-> ");
		scanf("%d", &opc);
		switch(opc){
			case 1: lista = inserir_final(lista); break;
			case 2: imprimir_lista(lista); break;
			case 3: pesquisar_elemento(lista); break; 
			case 4: lista = remover_elemento(lista); break;
			case 5: media_lista(lista); break;
			case 6: lista = crescente(lista); break;
			case 7: return 0; break;
			default: printf("Opção inválida!"); sleep(1); break;
		}
	} while(opc != 7);
}

