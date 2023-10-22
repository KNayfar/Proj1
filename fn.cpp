#include <string.h>
#include <stdio.h>

int main() {
	int i;//d�claration de i (compteur parcourant la cha�ne)
    int j = 0;//d�claration de j (compteur pour sauvegarder la position de l'espace � chaque fois)
    int k = 0;//d�claration de k (compteur parcourant les cases du tableau T)
    
	//d�claration du tableu ou je vais sauvegarder les mots de la chaine source
	char T[50][100];
    
	//d�claration et scan de la chaine source
	char ch[100];
    printf("Entrez une chaine : ");
    scanf("%99[^\n]", ch);//j'ai utilisez %99[^\n] pour lire toute la ligne jusqu'au retour � la ligne
	
	//initialisation de j � 0
    j = 0;

    //d�composition de la cha�ne source
    for (i = 0; i <= strlen(ch); i++) {
        if (ch[i] == ' ' || ch[i] == '\0') {
            strncpy(T[k], ch + j, i - j);
            T[k][i - j] = '\0';
            k++;
            j = i + 1;
        }
    }

    //d�claration et initialisation � 0 d'un tableau V pour stocker le nombre d'occurrences de chaque mot
    int V[50];
    for (i = 0; i < k; i++) {
        V[i] = 0;
    }

    //compter les occurrences de chaque mot
    for (i = 0; i < k; i++) {
        if (T[i][0] != '\0') {
            for (j = i + 1; j < k; j++) {
                if (strcmp(T[i], T[j]) == 0) {
                    V[i]++;
                    T[j][0] = '\0';
                }
            }
        }
    }

    //afficher les mots et leurs occurrences
    for (i = 0; i < k; i++) {
        if ((T[i][0] != '\0') && (V[i] != 0)) {
            printf("%s est repete %d fois.\n", T[i], V[i]+1);
        }
    }

}
