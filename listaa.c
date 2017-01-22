#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct lista_st{
	char znak;
	struct lista_st *sledeci;
	}lista;
void init(lista **h){
	*h=NULL;
}
void add(lista **glava,char c){
	lista *novi;
	novi=malloc(sizeof(lista));

	novi->znak=c;
	novi->sledeci=NULL;

	if(*glava==NULL)
	*glava=novi;
	else{
	lista *tek=*glava;
	while(tek->sledeci)
	tek=tek->sledeci;
	tek->sledeci=novi;
	}
	
}
void print(lista *glava){
	lista *tek=glava;
	printf("[");
	while(tek!=NULL){
	printf(" %c",tek->znak);
	tek=tek->sledeci;
	if(tek!=NULL)
	printf(", ");
	}
	printf("]\n");
}
void nadji(lista *glava,char x){
	lista *tek=glava;
	int k=0;
	while(tek!=NULL && tek->znak!=x){
	tek=tek->sledeci;
	}
	if(tek==NULL)
	printf("Karakter nije pronadjen\n");
	else
	printf("Karakter je pronadjen\n");
}

void izbrisi(lista **glava,char d){
	lista *tek=*glava;
	lista *pret=NULL;
	while(tek!=NULL && tek->znak!=d){
	pret=tek;
	tek=tek->sledeci;
	}
	if(tek==NULL)
	printf("Element %c se ne nalazi u listi\n",d);
	else{
	if(*glava==tek){
	*glava=tek->sledeci;
	tek->sledeci=NULL;
	free(tek);
	}
	else{
	pret->sledeci=tek->sledeci;
	tek->sledeci=NULL;
	free(tek);}
	}

	print(*glava);
}
void zameni(lista *glava,char p,char o){
	lista *pom=glava;
	while(pom!=NULL && pom->znak!=p){
	pom=pom->sledeci;
	}
	if(pom==NULL)
	printf("ELement %c se ne nalazi u listi\n",p);
	else
	pom->znak=o;
	print(glava);
	
}
void izbrisilistu(lista **glava){
	if(*glava!=NULL){
		izbrisilistu(&(*glava)->sledeci);
		free(*glava);
		*glava=NULL;
	}
}
		
int main(){
	lista *glava;
	char x;
	char d;
	char p;
	char o;
	
	init(&glava);

	add(&glava,'x');
	add(&glava,'s');
	add(&glava,'g');
	add(&glava,'a');
	add(&glava,'h');
	add(&glava,'n');
	add(&glava,'j');

	print(glava);
	
	printf("Unesite karakter za pretragu:");
	scanf(" %c",&x);
	
	nadji(glava,x);
	
	
	printf("Unesite karakter za brisanje:");
	scanf(" %c",&d);

	izbrisi(&glava,d);

	
	printf("Unesite karakter koji menjate:");
	scanf(" %c",&p);
	printf("Unesite karakter zamene:");
	scanf(" %c",&o);
	
	zameni(glava,p,o);
	
	izbrisilistu(&glava);

	return 0;
}




