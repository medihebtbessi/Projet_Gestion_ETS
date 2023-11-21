#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "ADETS.h"

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_ajout;
	GtkWidget *fenetre_afficher;
	GtkWidget *treeview1;
	
	fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

	gtk_widget_destroy(fenetre_ajout);
	fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
	fenetre_afficher=create_fenetre_afficher();

	gtk_widget_show(fenetre_afficher);

	treeview1=lookup_widget(fenetre_afficher,"treeview1");
	
	afficher_personne(treeview1);
}


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	administrateur_Ets AETS;
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;
	GtkWidget *fenetre_ajout;

	fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
	input1=lookup_widget(objet,"nom");
	input2=lookup_widget(objet,"ville");
	input3=lookup_widget(objet,"region");
	input4=lookup_widget(objet,"type_ETS");
	input5=lookup_widget(objet,"capacite");
	input6=lookup_widget(objet,"telephone");
	
	strcpy(AETS.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(AETS.ville,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(AETS.region,gtk_entry_get_text(GTK_ENTRY(input3)));	
	strcpy(AETS.capacite,gtk_entry_get_text(GTK_ENTRY(input5)));	
	strcpy(AETS.telephone,gtk_entry_get_text(GTK_ENTRY(input6)));
	
	ajouter("AD.txt",AETS);

}
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	/*GtkTreeIter iter;
	gchar* nom;	
	gchar* ville;
	gchar* region;
	gchar* type_ETS;
	gchar* capacite;
	gchar* telephone;
	gchar* ID;
	administrateur_Ets AETS;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	
	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&ville,2,&region,3,&type_ETS,4,&capacite,5,&telephone,6,&ID,-1);
	strcpy(AETS.nom,nom);
	strcpy(AETS.ville,ville);
	strcpy(AETS.region,region);
	strcpy(AETS.type_ETS,type_ETS);
	
	
	strcpy(AETS.capacite,capacite);
	
	strcpy(AETS.telephone,telephone);
	strcpy(AETS.ID,ID);
	char id[20];
	supprimer ("AD.txt",id);
	afficher_personne(treeview);
	
	}*/
}



void
on_suivant_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_afficher,*w1;
	GtkWidget *treeview1;

	w1=lookup_widget(objet,"fenetre_afficher");
	fenetre_afficher=create_fenetre_afficher();

	gtk_widget_show(fenetre_afficher);
	gtk_widget_hide(w1);
	treeview1=lookup_widget(fenetre_afficher,"treeview1");

	vider(treeview1);
	afficher_personne(treeview1);
}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_ajout, *fenetre_afficher;
	fenetre_afficher=lookup_widget(objet,"fenetre_afficher");

	gtk_widget_destroy(fenetre_afficher);
	fenetre_ajout=create_fenetre_ajout();
	gtk_widget_show(fenetre_ajout);
}







