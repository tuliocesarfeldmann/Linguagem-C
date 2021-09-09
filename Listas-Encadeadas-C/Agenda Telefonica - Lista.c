#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato{
	char nome[25];
	int celular;
	char email[27];
	int data;
} Contato;

typedef struct elemento{
	Contato info;
	struct elemento *prox;
} Elemento;

Elemento* cria_agenda(void){
	Elemento *no = (Elemento*) malloc(sizeof(Elemento));
	
	return no;
}

Elemento* inserir_contato(Elemento *lsta){
	system("cls");
	Elemento *no = cria_agenda();
	Elemento *aux = lsta;
	
	printf("\n\t\tINSERIR NOVO CONTATO:\n");
	
	printf("\nNome: ");
	fflush(stdin);
	gets(no->info.nome);

	printf("\nCelular: ");
	scanf("%d", &no->info.celular);
	
	printf("\nEmail: ");
	fflush(stdin);
	gets(no->info.email);
	
	printf("\nData de nascimento (ddmm): ");
	scanf("%d", &no->info.data);
	
	if(lsta == NULL){
		no->prox = NULL;
		lsta = no;
	}
	else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		no->prox = NULL;
		aux->prox = no;
	}
	return lsta;
}

void lista_contatos(Elemento *lsta){
	system("cls");
	Elemento *aux = lsta;
	
	if(aux == NULL) printf("\nAgenda vazia!");
	else{
			printf("\n\t\t\t\tAGENDA COMPLETA:\n");
			printf("\n |           NOME           |   CELULAR   |         EMAIL              | NASCIMENTO  |");
		while(aux != NULL){
			printf("\n | %-25s|   %-9d | %-27s|   %-10d|", aux->info.nome, aux->info.celular, aux->info.email, aux->info.data);
			aux = aux->prox;
		}
	}
	printf("\n\nPressione alguma tecla...");
	getch();
}

Elemento* busca_contato(Elemento *lsta){
	system("cls");
	char name[30];
	int tamanhoName;
	
	printf("\n\t\tBUSCA DE CONTATO:\n");
	
	Elemento *aux = lsta;
	
	if(lsta == NULL) {
		printf("\nAgenda vazia!");
	}
	
	else{
		printf("\nInforme o nome do contato: ");
		fflush(stdin);
		gets(name);
		int tamanhoNome = strlen(name);
		do{
			if(strncmp(name, aux->info.nome, tamanhoNome) == 0){
				printf("\n\t\t\t\tRESULTADOS ENCONTRADOS:\n");
				printf("\n |           NOME           |   CELULAR   |         EMAIL              | NASCIMENTO  |");
				printf("\n | %-25s|  %-10d | %-27s|   %-10d|", aux->info.nome, aux->info.celular, aux->info.email, aux->info.data);
				break;
			}
			aux = aux->prox;
		} while(aux != NULL);
		
		if(aux == NULL) printf("\nContato inexistente!");	
	}
	printf("\n\nPressione alguma tecla...\n");
	getch();
	return aux;
}

Elemento* remove_contato(Elemento *lsta, Elemento *aux){
	int opc;
	Elemento *ant = NULL, *atual = lsta, *posicao = aux;
	
	if(posicao != NULL){
		printf("\nDeseja remover esse contato? [1]-Sim [2]- Nao\n");
		scanf("%d", &opc);
		
		if(opc == 2) return lsta; // Não quer remover
		
		else{
			while(atual->info.nome != posicao->info.nome && atual != NULL){
				ant = atual;
				atual = atual->prox;
			}
			if(ant == NULL){
				lsta = atual->prox;
				free(atual);
			}
			else{
				ant->prox = atual->prox;
				free(atual);
			}
			printf("\nContato removido com sucesso!\n");
			
			sleep(2);
			return lsta;
		}
	}
}

void remove_duplicados(Elemento* lsta){
    Elemento *anterior;
    Elemento* atual;
    Elemento* proximo;

    for(atual = lsta; atual != NULL; atual = atual->prox){
        anterior = NULL; //a cada varrimento a começa a NULL

        for(proximo = atual->prox; proximo != NULL; ){ //sem incremento
            if(strcmp(atual->info.nome, proximo->info.nome) == 0){ //teste de igual
                if(anterior == NULL){ //remove do inicio
                    atual->prox = proximo->prox;
                }
                else{ //ou do meio/fim
                    anterior->prox = proximo->prox;
                }

                Elemento* remover = proximo;
                proximo = proximo->prox;
                free(remover);
            }
            else { //so atualiza o anterior quando não é igual
                anterior = proximo;
                proximo = proximo->prox;
            }
        }
    }
}

void atualiza_contato(Elemento *lsta, Elemento *aux){
	Elemento *atual = lsta, *posicao = aux;
	int opc;
	
	if(posicao != NULL){
		while(atual->info.nome != posicao->info.nome && atual != NULL){
			atual = atual->prox;
		}
		
		printf("\nO que deseja atualizar no contato?\n[1]- Nome\n[2]- Celular\n[3]- Email\n[4]- Data de nascimento\n");
		scanf("%d", &opc);
		
		switch(opc){
			case 1: 
				printf("\nNovo nome: ");
				fflush(stdin);
				gets(atual->info.nome);
				break;
			case 2: 
				printf("\nNovo celular: ");
				scanf("%d", &atual->info.celular);
				break;
			case 3:
				printf("\nNovo email: ");
				fflush(stdin);
				gets(atual->info.email);
				break;
			case 4:
				printf("\nNova data de nascimento (ddmm): ");
				scanf("%d", &atual->info.data);
				break;
			default: printf("\nOpcao Invalida!");
		}
	}
}

Elemento* libera_agenda(Elemento *lsta){
	Elemento *atual = lsta, *aux;
	
	while(atual != NULL){
		aux = atual;
		free(atual);
		atual = aux->prox;
	}
	lsta = NULL;
	
	return lsta;
}

int main(void){
	Elemento *lista = NULL, *auxiliar;
	int opc;
	
	do{
		system("cls");
		printf("\n\tMENU:\n");
		printf("\n1- Inserir contato\n2- Listar agenda\n3- Buscar contato\n4- Remover contato\n5- Editar contato\n6- Remover duplicados\n7- Apagar tudo\n8- Sair\n");
		scanf("%d", &opc);
		switch(opc){
			case 1: lista = inserir_contato(lista); break;
			case 2: lista_contatos(lista); break;
			case 3: busca_contato(lista); break;
			case 4: auxiliar = busca_contato(lista); lista = remove_contato(lista, auxiliar); break;
			case 5: auxiliar = busca_contato(lista); atualiza_contato(lista, auxiliar); break;
			case 6: remove_duplicados(lista); break;
			case 7: lista = libera_agenda(lista); break;
			case 8: return 0; break;
			default: printf("\nOpcao Invalida!"); sleep(2);
		}
	} while(opc != 8);
}
