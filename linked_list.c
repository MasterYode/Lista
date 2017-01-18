#include <stdio.h>
#include <stdlib.h>

struct linked_list_st {
    struct node_st *phead;
};

struct node_st {
    char inf;
    struct node_st *pnext;
};

void init(struct linked_list_st *);
struct node_st *make_node(char);
void insert_on_start(struct linked_list_st *, struct node_st *);
void insert_on_end(struct linked_list_st *, struct node_st *);
void print_list(struct linked_list_st);
struct node_st *search(struct linked_list_st, char);
void delete_node(struct linked_list_st *, char);
void destroy_list(struct linked_list_st *);

// Recursive functions
void print_list_recursively(struct linked_list_st);
void destroy_list_recursively(struct linked_list_st *);

int main() {
    struct linked_list_st list;

    init(&list);

    insert_on_start(&list, make_node('a'));
    insert_on_end(&list, make_node('b'));
    print_list(list);

    insert_on_start(&list, make_node('c'));
    insert_on_end(&list, make_node('d'));
    print_list(list);

    delete_node(&list, 'c');
    print_list(list);

    delete_node(&list, 'b');
    print_list_recursively(list);

    destroy_list(&list);
    print_list(list);

    
    insert_on_start(&list, make_node('a'));
    insert_on_end(&list, make_node('b'));
    print_list(list);

    destroy_list_recursively(&list);
    print_list(list);

    return EXIT_SUCCESS;
}

void init(struct linked_list_st *plist) {
    plist->phead = NULL;
}

struct node_st *make_node(char c) {
    struct node_st *pnew = malloc(sizeof(struct node_st));

    if(pnew == NULL) {
        exit(EXIT_FAILURE);
    }

    pnew->inf = c;
    pnew->pnext = NULL;

    return pnew;
}

void insert_on_start(struct linked_list_st *plist, struct node_st *pnew) {
    if(plist->phead != NULL) {
        pnew->pnext = plist->phead;
    }

    plist->phead = pnew;
}

void insert_on_end(struct linked_list_st *plist, struct node_st *pnew) {
    if(plist->phead == NULL) {
        plist->phead = pnew;
    } else {
        struct node_st *pcurr = plist->phead;

        while(pcurr->pnext != NULL) {
            pcurr = pcurr->pnext;
        }

        pcurr->pnext = pnew;
    }
}

void print_list(struct linked_list_st list) {
    struct node_st *pcurr = list.phead;

    printf("[");
    while(pcurr != NULL) {
        printf("%c", pcurr->inf); 

        pcurr = pcurr->pnext;

        if(pcurr != NULL) {
            printf(", ");
        }

    }
    printf("]\n");
}

struct node_st *search(struct linked_list_st list, char c) {
    struct node_st *pcurr = list.phead;

    while(pcurr != NULL) {
        if(pcurr->inf == c) {
            break;
        }
        pcurr = pcurr->pnext;
    }

    return pcurr;
}

void delete_node(struct linked_list_st *plist, char c) {
    struct node_st *pcurr = plist->phead, *pprev;

    while(pcurr != NULL && pcurr->inf != c) {
        pprev = pcurr;
        pcurr = pcurr->pnext;
    }

    if(pcurr == plist->phead) {
        plist->phead = pcurr->pnext;            
    } else {
        pprev->pnext = pcurr->pnext;
    }

    pcurr->pnext = NULL;
    free(pcurr);
}


void destroy_list(struct linked_list_st *plist) {
    struct node_st *ptemp;

    while(plist->phead != NULL) {
        ptemp = plist->phead;
        plist->phead = ptemp->pnext;

        ptemp->pnext = NULL;
        free(ptemp);
    }
}

void print_list_recursively(struct linked_list_st list) {
    struct linked_list_st temp_list;
    static int is_first = 1;    // rekurzivni pozivi funkcije u slucaju static promenljive koriste istu promenljivu sa istom adresom koja se jednom inicijalizuje

    if(list.phead != NULL) {
        if(is_first) {
            printf("[");
            is_first = 0;
        }

        printf("%c", list.phead->inf);
        temp_list.phead = list.phead->pnext;

        if(temp_list.phead != NULL) {
            printf(", ");
        }

        print_list_recursively(temp_list);
    } else {
        printf("]\n");
    }
}

void destroy_list_recursively(struct linked_list_st *plist) {
    struct node_st *ptemp;

    if(plist->phead != NULL) {
        ptemp = plist->phead;
        plist->phead = ptemp->pnext;

        ptemp->pnext = NULL;
        free(ptemp);

        destroy_list_recursively(plist);
    }
}
