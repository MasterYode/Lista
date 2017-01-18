#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
	char inf;
	struct node_st *pnext;
} NODE;

typedef struct list_st {
	struct node_st *phead;
} LIST;

NODE *make_node(char inf);
void init(LIST *);
void print_descriptor(LIST);
void insert_on_begining(LIST *, NODE *);
void insert_on_end(LIST *, NODE *);
void print_list(LIST);
void delete_node(LIST *, char);
void destroy_list(LIST *);

int main() {
	LIST list;

	printf("\nPre inicijalizacije liste...\n");
	print_descriptor(list);

	printf("\nPosle inicijalizacije liste...\n");
	init(&list);
	print_descriptor(list);

	printf("\nDodavanje elemenata...\n");
	insert_on_begining(&list, make_node('t'));
	insert_on_begining(&list, make_node('s'));
	insert_on_begining(&list, make_node('i'));
	insert_on_begining(&list, make_node('l'));
	insert_on_end(&list, make_node('!'));
	print_descriptor(list);
	print_list(list);

	printf("\nPosle brisanja elemenata...\n");
	delete_node(&list, 'l');
	print_descriptor(list);
	print_list(list);

	printf("\nPosle brisanja cele liste...\n");
	destroy_list(&list);
	print_descriptor(list);
	print_list(list);

	return 0;
}

NODE *make_node(char inf) {
	NODE *pnew = malloc(sizeof(NODE));

	if (pnew == NULL) exit(EXIT_FAILURE);

	pnew->inf = inf;
	pnew->pnext = NULL;

	return pnew;
}

void init(LIST *plist) {
	plist->phead = NULL;
}

void print_descriptor(LIST list) {
	printf("Descriptor:\n");
	printf("\tphead -> %p\n", list.phead);
}

void insert_on_begining(LIST *plist, NODE *pnew) {
	pnew->pnext = plist->phead;
	plist->phead = pnew;
}

void insert_on_end(LIST *plist, NODE *pnew) {
	NODE *pcurr = plist->phead;
	while (pcurr->pnext != NULL) {
		pcurr = pcurr->pnext;
	}
	pcurr->pnext = pnew;
}

void print_list(LIST list) {
	NODE *pcurr = list.phead;

	printf("[");
	while (pcurr != NULL) {
		printf("%c", pcurr->inf);
		if (pcurr->pnext != NULL) {
			printf(", ");
		}
		pcurr = pcurr->pnext;
	}
	printf("]\n");
}

void delete_node(LIST *plist, char inf) {
	NODE *pcurr = plist->phead;
	NODE *pprev = NULL;

	while (pcurr != NULL && pcurr->inf != inf) {
		pprev = pcurr;
		pcurr = pcurr->pnext;
	}
	if (pcurr != NULL) {
		if (pprev != NULL)
			pprev->pnext = pcurr->pnext;
		else
			plist->phead = pcurr->pnext;

		pcurr->pnext = NULL;
		free(pcurr);
	}
}

void destroy_list(LIST *plist) {
	/*
	while (plist->phead) {
		delete_node(plist, plist->phead->inf);
	}
	init(plist);
	*/
	NODE *ptemp = plist->phead;
	while (plist->phead != NULL) {
		ptemp = plist->phead;
		plist->phead = ptemp->pnext;

		ptemp->pnext = NULL;
		free(ptemp);
	}
}
