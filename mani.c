#include <stdio.h>
#include <stdlib.h>
#include "FILI.h"
#define clear system("clear")


void usebd(){
	char*nFile = Entry("Entrez le nom de votre fichier :");
	while(!isExist(nFile)){
		printf("Votre fichier n'existe pas encore !! \n");
		nFile = Entry("Entrez le nom de votre fichier :");
	}
	char*command;
	FILE*file = fopen(nFile,"r");
	while(1){
		command = Entry(fusess(fusess("┌──(Ianao㉿)",nFile),"-[~]\n└─>"));
		if(isEqual(command,"exit")){
			break;
		}
		else if(isEqual(command,"desc")){
			char**dataName = extractDataName(file);
			fclose(file);file = fopen(nFile,"r");
			char**dataType = extractDataType(file);
			fclose(file);file = fopen(nFile,"r");
			int line = lelenTab(dataName);
			char* padding = "    ";
			for (int i = 0; i < line; ++i){
				printf("┌");
				for (int f = -2*lelen(padding) ; f < lelen(*(dataName + i)); ++f){
					printf("─");
				}
				if(i == line - 1){
					printf("|\n");
				}
			}
			for (int i = 0; i < line; ++i){
				printf("|%s",padding);printf("%s",*(dataName + i));printf("%s",padding);
				if(i == line - 1){
					printf("|\n");
				}
			}
			break;
		}
	}
	

	fclose(file);
}

void createbd(){
	char*entry = Entry("Entrez le nom de votre modele : ");
	FILE*bd = fopen(entry,"r");
	int i = 1;
	while(!bd){
		if(!(i%4)){
			printf("Aza masspr ee !!\n");
		}
		else {
			printf("Desole votre fichier n'existe pas !!\n");			
		}
/*		if(isEqual(entry,"exit")){
			break;
		}
*/		bd = fopen(Entry("Entrez le nom de votre modele : "),"r");
		i++;
	}

	FILE*nBd = fopen(Entry("Entrez le nom de votre fichier : "),"w");
	char**data = extractDataName(bd);
	for (int i = 0; i < lelenTab(data); ++i){
		fprintf(nBd,"%s:\n",*(data + i));		
	}
	free(data);
	fclose(bd);
	fclose(nBd);
}

int main(int argc, char const *argv[]){
	char*commande;
	while(1){
		commande = Entry("┌──(Ianao㉿trano)-[~]\n└─>");
		if(isEqual(commande,"exit")){
			printf("Veloma pory \n");
			break;
		}
		else if(isEqual(commande,"clear")){
			clear;
		}
		else if(isEqual(commande,"usebd")){
			usebd();
		}
		else if(isEqual(commande,"help")){
			printf("%s\n",help);
		}
		else if(isEqual(commande,"createbd")){
			createbd();// Ceci influence la commande 
			clear;
		}
		else {
			printf("your fucking command is 1%s\n",commande);
			printf("Commande inconnue tapez exit pour quittez\n");
		}
	}

	return 0;
}
