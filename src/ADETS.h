
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct {

char nom [20];
char ville [20];
char region [20];
char type_ETS[20];
char capacite[20] ;
char telephone[20] ;
char ID[20];
}administrateur_Ets ;
void genener_ID(char ch1[],char ch2[],char ch3[]);
int ajouter(char *  , administrateur_Ets );
/*int modifier( char * ADETS, char id[], administrateur_Ets nouv );
int supprimer(char * ADETS, char id[]);
administrateur_Ets chercher(char * ADETS, char id[]);
int ETSParRegion(char *ADETS, char reg[]);
void ETSTrieCapacite(char * ADETS);*/

void afficher_personne(GtkWidget *liste);
void vider(GtkWidget *liste);


