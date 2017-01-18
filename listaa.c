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
int nadji(lista *glava,char x){
	lista *tek=glava;
	int k=0;
	while(tek!=NULL){
	
	if(tek->znak==x){
	printf("Karakter pronadjen\n");
	k++; }
	tek=tek->sledeci;
	}
	if(k==0)
	printf("Karakter nije pronadjen\n");
	return k;
}

void izbrisi(lista *glava,char d){
	lista *tek=glava;
	lista *pret=NULL;
	while(tek!=NULL && tek->znak!=d){
	pret=tek;
	tek=tek->sledeci;
	}
	if(glava==tek){
	glava=tek->sledeci;
	tej->sledeci=NULL;
	free(tek);
	}
	else{
	pret->sledeci=tek->sledeci;
	tek->sledeci=NULL;
	free(tek);}

	print(glava);
}
void zameni(lista *glava,char p,char o){
	lista *pom=glava;
	while(pom!=NULL){
	if(pom->znak==p){
	pom->znak=o;
		}
	pom=pom->sledeci;
	}
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
	
	do{
	printf("Unesite karakter za brisanje:");
	scanf(" %c",&d);}while(nadji(glava,d)==0);

	izbrisi(glava,d);

	do{
	printf("Unesite karakter koji menjate:");
	scanf(" %c",&p);}while(nadji(glava,p)==0);
	printf("Unesite karakter zamene:");
	scanf(" %c",&o);
	
	zameni(glava,p,o);
	
	izbrisilistu(&glava);

	return 0;
}












