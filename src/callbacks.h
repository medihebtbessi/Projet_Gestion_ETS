#include <gtk/gtk.h>


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_suivant_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_affichar_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);


