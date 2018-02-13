#include <stdio.h>
#include <stdlib.h>

typedef struct No No;

struct No{
	No *Esq;
	No *Dir;
	int Item;
};

No **CriaArvore(){
	No **Tree;
	Tree = (No**)malloc(sizeof(No*));
	(*Tree)	= (No*)malloc(sizeof(No));
	(*Tree)->Esq = NULL;
	(*Tree)->Dir = NULL;
	(*Tree)->Item = -1;
	return Tree;
}

void AddNodos(No** Tree, int Valor){	
	if ((*Tree)->Item == -1) {
		(*Tree)->Item = Valor;
	} else {
		if ((*Tree)->Item > Valor) {
			if (!(*Tree)->Esq) {
				(*Tree)->Esq = (No*)malloc(sizeof(No));
				(*Tree)->Esq->Item = Valor;
				(*Tree)->Esq->Esq = NULL;
				(*Tree)->Esq->Dir = NULL;
			} else AddNodos(&(*Tree)->Esq, Valor);
		} else {
			if (!(*Tree)->Dir) {
				(*Tree)->Dir = (No*)malloc(sizeof(No));
				(*Tree)->Dir->Item = Valor;
				(*Tree)->Dir->Dir = NULL;
				(*Tree)->Dir->Esq = NULL;
			} else AddNodos(&(*Tree)->Dir, Valor);
		}
	}
}

void Pre_Ordem(No **Tree){
	if ((*Tree)) {
		printf(" ");
		printf("%d",(*Tree)->Item);
		Pre_Ordem(&(*Tree)->Esq);
		Pre_Ordem(&(*Tree)->Dir);
	}
}

void Em_Ordem(No **Tree){
	if ((*Tree)) {
		Em_Ordem(&(*Tree)->Esq);
		printf(" ");
		printf("%d",(*Tree)->Item);
		Em_Ordem(&(*Tree)->Dir);
	}
}

void Pos_Ordem(No **Tree){
	if ((*Tree)) {
		Pos_Ordem(&(*Tree)->Esq);
		Pos_Ordem(&(*Tree)->Dir);
		printf(" ");
		printf("%d",(*Tree)->Item);
	}
}

void Imprime(No **Tree, int cont){
	printf("Case %d:\n", cont);
	printf("Pre.:");
	Pre_Ordem(Tree);
	printf("\n");
	printf("In..:");
	Em_Ordem(Tree);
	printf("\n");
	printf("Post:");
	Pos_Ordem(Tree);
	printf("\n");
}

void LimpaArvore(No **Tree){
	if ((*Tree)) {
		LimpaArvore(&(*Tree)->Esq);
		LimpaArvore(&(*Tree)->Dir);
	}
	free((*Tree));
}

int main(int argc, const char *argv[]){
	No **Tree;
	int N_Testes, N_Nos, Item, i=1;
	scanf("%d",&N_Testes);
	while (N_Testes--) {
		Tree = CriaArvore();
		scanf("%d",&N_Nos);
		while (N_Nos--) {
			scanf("%d",&Item);
			AddNodos(Tree, Item);
		}
		Imprime(Tree, i++);
		LimpaArvore(Tree);
		free(Tree);
		printf("\n");
	}
	return 0;
}
