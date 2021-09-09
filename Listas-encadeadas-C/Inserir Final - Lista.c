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
	
	printf("\n\t\tINSERIR N�MERO NA LISTA:\n");
	printf("\nInforme o n�mero que deseja adicionar na lista: ");
	scanf("%d", &num);
	
	No *no = criar_no();
	no->num = num;
	
	if(lsta == NULL){
		no->prox = NULL;
		lsta = no;
	}
	else{
		No *aux = lsta;
		while(aux->prox != NULL){ // descobrir onde est� o �ltimo elemento
			aux = aux->prox;
		}
		no->prox = NULL; // n� criado aponta pra nulo
		aux->prox = no; // antigo �ltimo n� aponta para o novo �ltimo n�
	}
	return lsta;
}

void imprimir_lista(No *lsta){
	system("cls");
	
	No *aux = lsta;
	
	printf("\nLISTA:\n\n");
	
	if(aux == NULL) printf("A lista est� vazia!\n");
	
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
	
	printf("\nInforme o n�mero que deseja pesquisar: ");
	scanf("%d", &num);
	
	while(aux != NULL){
		if(aux->num == num){
			printf("\nN�mero %d est� na lista!\n", num);
			break;
		}
		aux = aux->prox;
	}
	if(aux  == NULL) printf("\nN�mero %d n�o est� na lista\n", num);
	
	printf("\nPressione qualquer tecla...");
	getch();
}

No* remover_elemento(No *lsta){
	int num;
	
	system("cls");
	
	printf("\n\t\tREMOVER ELEMENTO:\n");
	printf("\nInforme o n�mero que deseja remover: ");
	scanf("%d", &num);
	
	No *ant = NULL;
	No *atual = lsta;
	
	while(atual != NULL && atual->num != num){
		ant = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL) {	
		printf("\nN�mero %d n�o est� na lista!\n", num);
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
	printf("\n\t\tM�DIA DOS ELEMENTOS DA LISTA\n");
	
	if(aux != NULL){
		while(aux != NULL){
			cont++;
			soma = soma + aux->num;
			aux = aux->prox;
		}
		media = (float) soma/cont;
		
		printf("\nM�dia: %.2f\n", media);
	}
	else{
		printf("\nA lista est� vazia!\n");
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
		printf("\n[1]- Adicionar n�mero\n[2]- Imprimir lista\n[3]- Pesquisar n�mero\n[4]- Remover n�mero\n[5]- M�dia da lista\n[6]- Colocar em ordem crescente\n[7]- Sair do programa\n-> ");
		scanf("%d", &opc);
		switch(opc){
			case 1: lista = inserir_final(lista); break;
			case 2: imprimir_lista(lista); break;
			case 3: pesquisar_elemento(lista); break; 
			case 4: lista = remover_elemento(lista); break;
			case 5: media_lista(lista); break;
			case 6: lista = crescente(lista); break;
			case 7: return 0; break;
			default: printf("Op��o inv�lida!"); sleep(1); break;
		}
	} while(opc != 7);
}

