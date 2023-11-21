#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ADETS.h"

void genener_ID(char ch1[],char ch2[],char ch3[])
{
	int l ;
	char Long[20] , c[10];
	l=strlen(ch1)*strlen(ch2);
	strncpy(ch3 , ch1 ,1);
	sprintf(Long , "%d" ,l);
	strcat(ch3, Long);
	strncpy(c,ch2,1);
	strcat(ch3 , c);

}
int ajouter(char* ADETS, administrateur_Ets AETS1 )
{
	FILE * f=fopen(ADETS, "a");
	char ID[20];

    if(f==NULL)
    {
        printf("erreur lors de l'ouverture du fichier .\n");
        return 0;
    }
    else
    {
        fprintf(f,"%s %s %s %s %s %s", AETS1.nom ,AETS1.ville ,AETS1.region ,AETS1.type_ETS ,AETS1.capacite ,AETS1.telephone);
	genener_ID(AETS1.nom,AETS1.ville,ID);
	fprintf(f,"%s\n",ID);
        fclose(f);
        return 1;
    }
}
// fonction modifier
/*int modifier( char * ADETS, char id[], administrateur_Ets nouv )
{
    int tr=0;
    administrateur_Ets AETS;
    FILE * f=fopen(ADETS, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %s\n", AETS.nom,AETS.ville,AETS.region,AETS.type_ETS,&AETS.capacite,&AETS.telephone , AETS.ID )!=EOF)
        {
            if(strcmp(AETS.ID , id)==0)
            {
                fprintf(f2," %s %s %s %s %d %d %s\n", nouv.nom,nouv.ville,nouv.region,nouv.type_ETS,nouv.capacite,nouv.telephone,nouv.ID );
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %d %d %s\n", AETS.nom,AETS.ville,AETS.region,AETS.type_ETS,AETS.capacite,AETS.telephone,AETS.ID );

        }
    }
    fclose(f);
    fclose(f2);
    remove(ADETS);
    rename("nouv.txt", ADETS);
    return tr;

}*/
//fonction supprimer

int supprimer(char * ADETS, char id[])
{
    int tr=0;
    administrateur_Ets AETS;
    FILE * f=fopen(ADETS, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n", AETS.nom,AETS.ville,AETS.region,AETS.type_ETS,AETS.capacite,AETS.telephone,AETS.ID )!=EOF)
        {
            if(strcmp(AETS.ID , id)==0)
            {
              tr=1;
            }

            else
                {
                    fprintf(f2,"%s %s %s %s %s %s %s\n", AETS.nom,AETS.ville,AETS.region,AETS.type_ETS,AETS.capacite,AETS.telephone,AETS.ID);
                }
        }
    }
    fclose(f);
    fclose(f2);
    remove(ADETS);
    rename("nouv.txt", ADETS);
    return tr;
}
/*//fonction chercher
administrateur_Ets chercher(char * ADETS, char id[])
{
    administrateur_Ets AETS;
    int tr=0;
    FILE * f=fopen(ADETS, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f," %s %s %s %s %d %d %s\n", AETS.nom,AETS.ville,AETS.region,AETS.type_ETS,&AETS.capacite,&AETS.telephone,AETS.ID )!=EOF)
        {
            if(strcmp(AETS.ID , id)==0)
                tr=1;
        }
    }
    fclose(f);
   if(tr==0)
        AETS.ID=="-1";
    return AETS;
}
//nombre des ETS par region
int ETSParRegion(char *ADETS, char reg[])
{
    administrateur_Ets AETS1;
    int nb_ETS = 0, tr = 0;
    FILE *f = fopen(ADETS, "r");
    FILE *f2 = fopen("listeETS.txt", "a");

    if (f != NULL && f2 != NULL)
        {
        while (fscanf(f, "%s %s %s %s %d %d %s\n",  AETS1.nom, AETS1.ville, AETS1.region, AETS1.type_ETS, &AETS1.capacite, &AETS1.telephone,AETS1.ID) != EOF)
        {
            if (strcmp(AETS1.region, reg) == 0)
             {
                nb_ETS++;
                fprintf(f2, "%s %s %s %s %d %d %s\n",  AETS1.nom, AETS1.ville, AETS1.region, AETS1.type_ETS, AETS1.capacite, AETS1.telephone,AETS1.ID);
                tr = 1;
            }
        }
    }

    fclose(f);
    fclose(f2);
    return nb_ETS;
}
//fonction de tri par capacité
void ETSTrieCapacite(char *ADETS) {
    administrateur_Ets *tab_ETS, AETS1;
    int nb_ETS = 0, i;

    FILE *f = fopen(ADETS, "r");
    FILE *f2 = fopen("liste_ETS_trie.txt", "w");

    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %s %s %d %d %s\n",  AETS1.nom, AETS1.ville, AETS1.region, AETS1.type_ETS, &AETS1.capacite, &AETS1.telephone,AETS1.ID) != EOF) {
            nb_ETS++;
        }

        rewind(f);

        tab_ETS = (administrateur_Ets *)malloc(nb_ETS * sizeof(administrateur_Ets));

        for (i = 0; i < nb_ETS; i++) {
            fscanf(f, " %s %s %s %s %d %d %s\n",  tab_ETS[i].nom, tab_ETS[i].ville, tab_ETS[i].region, tab_ETS[i].type_ETS, &tab_ETS[i].capacite, &tab_ETS[i].telephone,tab_ETS[i].ID);
        }
//fonction trie de tableau par selection
        for (i = 0; i < nb_ETS - 1; i++) {
            int min = i;
            for (int j = i + 1; j < nb_ETS; j++) {
                if (tab_ETS[min].capacite > tab_ETS[j].capacite) {
                    min = j;
                }
            }
            administrateur_Ets tmp = tab_ETS[i];
            tab_ETS[i] = tab_ETS[min];
            tab_ETS[min] = tmp;
        }

        for (int i = 0; i < nb_ETS; i++) {
            fprintf(f2, "%s %s %s %s %d %d %s\n",  tab_ETS[i].nom, tab_ETS[i].ville, tab_ETS[i].region, tab_ETS[i].type_ETS, tab_ETS[i].capacite, tab_ETS[i].telephone,tab_ETS[i].ID);
        }

        free(tab_ETS);
    }

    fclose(f);
    fclose(f2);
}*/
enum
{
	NOM,
	VILLE,
	REGION,
	TYPE_ETS,
	CAPACITE,
	TELEPHONE,
	ID1,
	COLUMNS
};
void afficher_personne(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter	iter;
        GtkListStore *store;
	administrateur_Ets AETS;
	char nom [20];
	char ville [20];
	char region [20];
	char type_ETS[20];
	int capacite ;
	int telephone ;
	char ID[20];	
	store=NULL;
	FILE *f;


	store=gtk_tree_view_get_model(liste);
        if(store==NULL)
	{
	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("ville",renderer,"text",VILLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("region",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("type_ETS",renderer,"text",TYPE_ETS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("capacite",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("telephone",renderer,"text",TELEPHONE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("AD.txt","r");
if(f=NULL)
{
return ;
}
else
{ f = fopen("AD.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s\n", AETS.nom ,AETS.ville ,AETS.region ,AETS.type_ETS ,AETS.capacite ,AETS.telephone,AETS.ID)!=EOF)
	 	{

 gtk_list_store_append(store,&iter);
 gtk_list_store_set(store,&iter,NOM,AETS.nom,VILLE,AETS.ville,REGION,AETS.region,TYPE_ETS,AETS.type_ETS,CAPACITE,AETS.capacite,TELEPHONE,AETS.telephone,ID1,AETS.ID,-1);
	 	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);	
}
}
}
void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
        administrateur_Ets AETS;
	char nom [20];
	char ville [20];
	char region [20];
	char type_ETS[20];
	int capacite ;
	int telephone ;
	char ID[20];	
	store=NULL;
	FILE *f;

        store=gtk_tree_view_get_model(liste);
        if(store==NULL)
        {
        renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("ville",renderer,"text",VILLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("region",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("type_ETS",renderer,"text",TYPE_ETS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("capacite",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("telephone",renderer,"text",TELEPHONE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer= gtk_cell_renderer_text_new();
        column= gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	}

       	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	gtk_list_store_append(store,&iter);        
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));

}


