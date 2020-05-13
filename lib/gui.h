/**
 * \file gui.h
 * \brief
 * \author Asmae Bouhandi
 * \version 1
 * \date 13 mai 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <gtk/gtk.h>

#include "../lib/commun.h"
#include "../lib/fonctionGrille.h"

/**
* \struct point
*/

typedef struct point point ;
struct point{
	int col ;
	int line ;
};

/**
* \struct info
*/

typedef struct info info ;
struct info{
	int k ;
	int col ;
	int line ;
	char letter ;
	GtkWidget *mot ;
	GtkWidget *label1 ;
	GtkWidget *label2 ;
	GtkWidget *liste_mots ;
	GtkWidget *liste_mots_trouves ;
	char mat[N_TEST][N_TEST] ;
};

void charger(GtkFileChooserButton *chooser);
char *replaceWord(const char *s, const char *oldW, const char *newW);
void on_import_save(GtkWidget *button_menu, gpointer *data);
void on_sauvegarde(GtkWidget *button, gpointer *data);
void on_fin(GtkWidget *button);
void on_theme(GtkWidget *button, gpointer *theme);
void on_difficulte(GtkWidget *button, gpointer *difficulte);
void on_new_partie_main(GtkWidget *button);
void on_new_partie_menu(GtkWidget *button);
void on_new_partie_menu_win(GtkWidget *button);
void on_menu_main(GtkWidget *button);
void on_menu_win(GtkWidget *button);
void mot_coords(char mat[N_TEST][N_TEST], char mot[N_TEST], point p1, point p2, info *b);
int position(mot_tire *liste, char *word);
void supp_liste(mot_tire *liste, char *word, int nbr_mots);
int compare_words(char *w1, char *w2);
char *choppy( char *s );
void on_btn_clicked(GtkWidget *button, gpointer *data) ;
static gboolean label_update(gpointer data) ;
static void pause_resume_timer (GtkWidget *button) ;
