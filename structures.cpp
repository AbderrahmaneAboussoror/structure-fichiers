#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nom[20];
	char prenom[20];
	int age;
	char module[10];
}formateur;

typedef struct{
	char login[20];
	int pw;
}auth;

typedef struct{
	char nom[20];
	char prenom[20];
	int age;
	formateur f;
	auth a;
}etudiant;

main(){
	int nb;
	printf("donner le nombre des etudiants que vous voulez saisir: ");
	scanf("%d", &nb);
	etudiant table[nb];
	for(int i = 0; i < nb; i++){
		printf("\nsasir le login d'etudiant: ");
		scanf("%s", &table[i].a.login);
		printf("\ndonner le pw d'etudiant: ");
		scanf("\n%d", &table[i].a.pw);
		printf("\ndonner le nom d'etudiant: ");
		scanf("%s", &table[i].nom);
		printf("\ndonner le prenom d'etudiant: ");
		scanf("\n%s", &table[i].prenom);
		printf("\ndonner l'age' d'etudiant: ");
		scanf("\n%d", &table[i].age);
		printf("\ndonner le nom de son formateur: ");
		scanf("\n%s", &table[i].f.nom);
		printf("\ndonner le prenom de son formateur: ");
		scanf("\n%s", &table[i].f.prenom);
		printf("\ndonner l'age de son formateur: ");
		scanf("\n%d", &table[i].f.age);
		printf("\ndonner le module de son formateur: ");
		scanf("\n%s", &table[i].f.module);
		printf("\n\t-----------------------------------------------------\n\n");
	}
	int conteur = 1;
	for(int i = 0; i < nb; i++){
		printf("Etudiant numero : %d\nNom : %s\nPrenom : %s\nAge : %d\nSon formateur :\nNom : %s\nPrenom : %s\nAge : %d\nModule : %s", 
		conteur, table[i].nom, table[i].prenom, table[i].age, table[i].f.nom, table[i].f.prenom, table[i].f.age, table[i].f.module);
		printf("\n\t-----------------------------------------------------\n\n");
		conteur++;
	}
	FILE* fichier ;
	fichier = fopen("etudiant.doc", "w");
	if(fichier == NULL){
		printf("error!");
		
	}else{
		for(int i = 0; i < nb; i++){
			fprintf(fichier, "Login : %s, Pw : %d, Nom : %s, Prenom : %s, Age : %d, Son formateur : Nom : %s,Prenom : %s, Age : %d, Module : %s",
			table[i].a.login, table[i].a.pw, table[i].nom, table[i].prenom, table[i].age, table[i].f.nom, table[i].f.prenom, table[i].f.age, table[i].f.module);
			fputc('\n', fichier);
		}
	}
	char c;
	fclose(fichier);
	printf("\n\t-----------------------------------\n");
	fichier = fopen("etudiant.doc", "r");
	if(fichier == NULL){
		printf("error!");
	}else{
		do{
			c = fgetc(fichier);
			printf("%c", c);
		}while(c != EOF);
		fclose(fichier);
	}
}
