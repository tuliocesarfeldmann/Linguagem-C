#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int num;
	struct no *prox;
} No;

No* criar_no(void){
	No *no = (No*) malloc(sizeof(No));
	
	return no;
}

No* inserir_no_inicio(No *lsta){
	int numero;
	
	printf("\nInforme um numero para adicionar na lista: ");
	scanf("%d", &numero);
	
	No *no = criar_no();
	no->num = numero;
	
	if(lsta == NULL){
		no->prox = NULL;
		lsta = no;
	}
	else{
		no->prox = lsta;
		lsta = no;
	}
	return lsta;
}

void imprimir_lista(No *lsta){
	system("cls");
	printf("Lista:\n");
	
	No *aux = lsta;
	
	if(aux == NULL) printf("Lista vazia!\n");
	
	else{
		while(aux != NULL){
		printf("%d \n", aux->num);
		
		aux = aux->prox;
		}
	}
	
	printf("\nPressione qualquer tecla...");
	getch();
}

No* remover (No *lsta) {
	No *ant = NULL; // ponteiro para elemento anterior
	No *atual = lsta; // ponteiro para percorrer a lista
	int nmr;
		
	printf("\nInforme o numero que deseja remover: ");
	scanf("%d", &nmr);
	
	while (atual != NULL && atual->num != nmr) { // procura elemento na lista, guardando anterior
		ant = atual;
		atual = atual->prox;
	}

	if (atual == NULL){ // verifica se achou elemento 
		return lsta; // não achou: retorna lista original 
		printf("\n\nNumero informado nao esta na lista!\n");
	}
	if (ant == NULL) { // retira elemento 
		lsta = atual->prox; // retira elemento do inicio 
		free(atual);
	}

	else {
		ant->prox = atual->prox; // retira elemento do meio da lista
		free(atual);
	}
	
	return lsta;
}

void pesquisa(No *lsta){ // Busca um elemento na lista
	No *aux = lsta;
	int pesq;
	
	printf("\nDigite um numero para pesquisa: \n");
	scanf("%d", &pesq);
	
	while(aux != NULL){
		if(aux->num == pesq){
			printf("\nNumero %d esta na lista!\n", pesq);
			break;
		} 
		aux = aux->prox;
	}
	
	if(aux == NULL) printf("\nNumero %d nao esta na lista!\n", pesq);
	
	printf("\nPressione qualquer tecla...");
	getch();
}

int main(){
	
	No *lista = NULL;
	int numero, opc;
	
	do{
		system("cls");
	
		printf("\n\t\tMENU:\n\n");
		printf("[1]- Adicionar numero na lista\n[2]- Imprimir lista\n[3]- Remover elemento da lista\n[4]- Pesquisar numero\n[5]- Sair\n");
		scanf("%d", &opc);
		
		switch(opc){
			case 1: lista = inserir_no_inicio(lista); break;
				
			case 2: imprimir_lista(lista); break;
			
			case 3: lista = remover(lista); break;
			
			case 4: pesquisa(lista); break;
			
			case 5: return 0; break;
			
			default: printf("\nOpcao invalida!"); sleep(1); break;
		}
	} while(opc != 5);
}

