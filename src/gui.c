#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <gtk/gtk.h>

#include "../lib/gui.h"
#include "../lib/commun.h"
#include "../lib/fonctionMenu.h"
#include "../lib/fonctionGrille.h"

//-------------Variables globales---------------
static gboolean continue_timer = FALSE;
static gboolean start_timer = FALSE;
static int sec_expired = 0;

int clicked_1 = FALSE ;
int clicked_2 = FALSE ;
point x1, x2 ;

GtkWidget *label_time;

int m = 0 ;
int jeu_fin = 0 ;
int type_jeu = 0 ;
int a_trouver = N_TEST ;
char mat[N_TEST][N_TEST];
mot_tire liste_mot[N_TEST+1] ;
mot_tire liste_mot_trouves[N_TEST+1] ;
info informations[N_TEST*N_TEST] ;

GtkWidget *window_main, *window_menu, *window_win, *window_chargement, *window_pause;
GtkLabel *temps_ecoule ;
char themefile[50] = "./themes/theme_animal.txt" ;
char temps[32] ;

//-----------------------------------------------

int main(int argc, char *argv[])
{

    GtkBuilder *builder_win, *builder_menu, *builder_chargement, *builder_pause;

    srand(time(NULL));

    gtk_init(&argc, &argv);
    //window_main = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    builder_win = gtk_builder_new_from_file("glade/window_win.glade");
    builder_chargement = gtk_builder_new_from_file("glade/window_chargement.glade");
    builder_menu = gtk_builder_new_from_file("glade/window_menu.glade");
    builder_pause = gtk_builder_new_from_file("glade/window_pause.glade");

    window_menu = GTK_WIDGET(gtk_builder_get_object(builder_menu, "window_menu"));
    window_win = GTK_WIDGET(gtk_builder_get_object(builder_win, "window_win"));
    window_chargement = GTK_WIDGET(gtk_builder_get_object(builder_chargement, "window_chargement"));
    window_pause = GTK_WIDGET(gtk_builder_get_object(builder_pause, "window_pause"));

    //-----------------Windows Signaux Quit
    g_signal_connect(window_chargement, "destroy", G_CALLBACK(on_fin), NULL);
    g_signal_connect(window_menu, "destroy", G_CALLBACK(on_fin), NULL);
    g_signal_connect(window_win, "destroy", G_CALLBACK(on_fin), NULL);

    //-----------------Windows Signaux Jeu
    GtkWidget *menu_button_menu = GTK_WIDGET(gtk_builder_get_object(builder_chargement, "solo"));
    g_signal_connect(G_OBJECT(menu_button_menu), "clicked", G_CALLBACK(on_new_partie_menu), NULL);

    GtkFileChooserButton *chooser = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(builder_chargement, "filename"));

    GtkWidget *menu_import = GTK_WIDGET(gtk_builder_get_object(builder_chargement, "charg_button"));
    g_signal_connect(G_OBJECT(menu_import), "clicked", G_CALLBACK(on_import_save), chooser);

    GtkWidget *menu_button_jeu = GTK_WIDGET(gtk_builder_get_object(builder_menu, "start"));
    g_signal_connect(G_OBJECT(menu_button_jeu), "clicked", G_CALLBACK(on_new_partie_main), NULL);

    //-----------------Windows Signaux Choix Difficile
    int facile = FACILE ;
    GtkWidget *button_difficulte_facile = GTK_WIDGET(gtk_builder_get_object(builder_menu, "facile"));
    g_signal_connect(G_OBJECT(button_difficulte_facile), "clicked", G_CALLBACK(on_difficulte), &facile);

    int moyen = MOYEN ;
    GtkWidget *button_difficulte_moyen = GTK_WIDGET(gtk_builder_get_object(builder_menu, "moyen"));
    g_signal_connect(G_OBJECT(button_difficulte_moyen), "clicked", G_CALLBACK(on_difficulte), &moyen);

    int difficile = DIFFICILE ;
    GtkWidget *button_difficulte_difficile = GTK_WIDGET(gtk_builder_get_object(builder_menu, "difficile"));
    g_signal_connect(G_OBJECT(button_difficulte_difficile), "clicked", G_CALLBACK(on_difficulte), &difficile);

    //-----------------Windows Signaux Choix Themes
    GtkWidget *button_theme_animaux = GTK_WIDGET(gtk_builder_get_object(builder_menu, "animaux"));
    g_signal_connect(G_OBJECT(button_theme_animaux), "clicked", G_CALLBACK(on_theme), "./themes/theme_animal.txt");

    GtkWidget *button_theme_metiers = GTK_WIDGET(gtk_builder_get_object(builder_menu, "metiers"));
    g_signal_connect(G_OBJECT(button_theme_metiers), "clicked", G_CALLBACK(on_theme), "./themes/theme_metier.txt");

    GtkWidget *button_theme_nourriture = GTK_WIDGET(gtk_builder_get_object(builder_menu, "nourriture"));
    g_signal_connect(G_OBJECT(button_theme_nourriture), "clicked", G_CALLBACK(on_theme), "./themes/theme_nourriture.txt");

    GtkWidget *button_theme_villes = GTK_WIDGET(gtk_builder_get_object(builder_menu, "villes"));
    g_signal_connect(G_OBJECT(button_theme_villes), "clicked", G_CALLBACK(on_theme), "./themes/theme_ville.txt");

    //-----------------Windows Signaux Fin
    temps_ecoule = GTK_WIDGET(gtk_builder_get_object(builder_win, "time"));

    GtkWidget *win_button_fin = GTK_WIDGET(gtk_builder_get_object(builder_win, "fin"));
    g_signal_connect(G_OBJECT(win_button_fin), "clicked", G_CALLBACK(on_fin), NULL);

    GtkWidget *win_button_redo = GTK_WIDGET(gtk_builder_get_object(builder_win, "redo"));
    g_signal_connect(G_OBJECT(win_button_redo), "clicked", G_CALLBACK(on_new_partie_menu_win), NULL);


    GtkWidget *pause_button_fin = GTK_WIDGET(gtk_builder_get_object(builder_pause, "fin"));
    g_signal_connect(G_OBJECT(pause_button_fin), "clicked", G_CALLBACK(on_fin), NULL);

    GtkWidget *pause_button_resume = GTK_WIDGET(gtk_builder_get_object(builder_pause, "resume"));
    g_signal_connect(G_OBJECT(pause_button_resume), "clicked", G_CALLBACK(pause_resume_timer), NULL);

    gtk_widget_show_all(window_chargement);

    while(!jeu_fin)
    {
        gtk_main_iteration();
    }
    return 0;
}

/*
Remplace un mot par un autre dans une chaine de caractères.
*/
char *replaceWord(const char *s, const char *oldW, const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) 
    { 
        if (strstr(&s[i], oldW) == &s[i]) 
        { 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) 
    { 
        // compare the substring with the result 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 

/*
Permet de créer la matrice de jeu (sa forme graphique à l'aide de bouton Gtk) en utilisant les fonctions de la librarie
fonctionGrille.c

Permet de créer la matrice jeu à partir d'une sauvegarde

Crée le chronomètre et l'initialise à zéro
*/
void create_board(GtkWidget *button_menu)
{
    GtkBuilder *builder;
    GtkWidget *myGrid;
    GtkWidget *myBox;
    GtkWidget *chrono, *g_label1, *g_label2;
    GtkWidget *vbox;
    GtkWidget *pause_resume_button;
    GtkWidget *g_mot, *g_save;
    GtkWidget *g_liste, *g_liste_trouves;

    int size = 1 ;
    int line, col, k = 0;
    GtkWidget *button[N_TEST*N_TEST];

    srand(time(NULL));

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window_main = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    //-----------------Widget Window Main
    myBox = GTK_WIDGET(gtk_builder_get_object(builder, "grille"));
    chrono = GTK_WIDGET(gtk_builder_get_object(builder, "chrono"));
    g_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "coord1"));
    g_label2 = GTK_WIDGET(gtk_builder_get_object(builder, "coord2"));
    g_mot = GTK_WIDGET(gtk_builder_get_object(builder, "mot"));
    g_save = GTK_WIDGET(gtk_builder_get_object(builder, "save"));
    g_liste = GTK_WIDGET(gtk_builder_get_object(builder, "liste"));
    g_liste_trouves = GTK_WIDGET(gtk_builder_get_object(builder, "liste2"));

    //-----------------Windows Signaux Quit
    g_signal_connect(window_main, "destroy", G_CALLBACK(on_fin), NULL);

    myGrid = gtk_grid_new();

    //----------Matrice--------------

    if(type_jeu==0)
    {
        initGrille(mat);
    
        for(int i = 0 ; i < N_TEST ; i++)
        {
            strcpy(liste_mot[i].mot, "\0") ;
        }

        for(int i = 0 ; i < N_TEST ; i++)
        {
            strcpy(liste_mot_trouves[i].mot, "\0") ;
        }
    
        PlacerMot(mat, themefile, liste_mot);
        affGrille(mat);
        voidToChar(mat);
    }

    char liste_aff[N_TEST*N_TEST] = "\0";

    for(int i = 0; i<N_TEST ; i++)
    {
        strcat(liste_aff, liste_mot[i].mot);
    }

    gtk_label_set_label(g_liste, liste_aff);

    if(type_jeu==1)
    {

        char liste_aff_trouves[N_TEST*N_TEST] = "\0";

        for(int i = 0; i<N_TEST-a_trouver ; i++)
        {
            strcat(liste_aff_trouves, liste_mot_trouves[i].mot);
            strcat(liste_aff_trouves, "\n");
        }

        gtk_label_set_label(g_liste_trouves, liste_aff_trouves);
    }

    //-------------------------------

    //----------Timer----------------

    vbox = gtk_vbox_new (FALSE, 2);
    gtk_container_add(GTK_CONTAINER(chrono), vbox);

    label_time = gtk_label_new("00:00:00");

    pause_resume_button = gtk_button_new_with_label("Pause/Reprendre");
    g_signal_connect(G_OBJECT(pause_resume_button), "clicked", G_CALLBACK(pause_resume_timer), NULL);

    gtk_box_pack_start(GTK_BOX(vbox), label_time, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(vbox), pause_resume_button, 1, 0, 0);
    //gtk_box_pack_start(GTK_BOX(vbox), reset_button, 0, 0, 0);

    g_timeout_add_seconds(1, label_update, label_time);
    continue_timer = TRUE;
    start_timer = TRUE;

    //-------------------------------

    //----------Grille---------------
    for(line = 0; line < N_TEST; line++)
    {
        for(col = 0; col < N_TEST; col++)
        {
            char character = mat[line][col];
            char merge[4];
            sprintf(merge, " %c ", character) ;
            button[k] = gtk_button_new_with_label(merge);
            gtk_button_set_relief(GTK_BUTTON(button[k]), GTK_RELIEF_NONE);

            informations[k].label1 = g_label1 ;
            informations[k].label2 = g_label2 ;
            informations[k].mot = g_mot ;
            informations[k].letter = character ;
            informations[k].col = col ;
            informations[k].line = line ;
            informations[k].k = k ;
            informations[k].liste_mots = g_liste ;
            informations[k].liste_mots_trouves = g_liste_trouves ;
            memcpy(informations[k].mat, mat, sizeof(mat)) ;

            g_signal_connect(G_OBJECT(button[k]), "clicked", G_CALLBACK(on_btn_clicked), &informations[k]);

            gtk_grid_attach(GTK_GRID(myGrid), button[k], col, line, size, size);
            k++ ;
        }
    }
    //-------------------------------

    g_signal_connect(G_OBJECT(g_save), "clicked", G_CALLBACK(on_sauvegarde), &informations);
    gtk_container_add(GTK_CONTAINER(myBox), myGrid);
}

/*
Lance la sauvegarde quand le bouton sauvegarde est appuyé

Crée 3 fichiers : un pour la sauvegarde de la matrice, un autre pour la liste des mots à trouver et le dernier pour
les mots trouvés.
*/
void on_sauvegarde(GtkWidget *button, gpointer *data)
{
    printf("on_sauvegarde\n");
    //affGrille(mat);

    time_t now;
    struct tm *tm;

    now = time(0);
    if ((tm = localtime (&now)) == NULL) {
        printf ("Error extracting time\n");
    }

    printf ("%04d-%02d-%02d-%02d:%02d:%02d\n",
        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec);

    FILE *fp;

    char filename[256] ;
    snprintf(filename, 256, "./sauvegardes/sauvegarde_%04d-%02d-%02d-%02d:%02d:%02d",
                            tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
                            tm->tm_hour, tm->tm_min, tm->tm_sec);
    fp = fopen(filename, "w");

    for(int i = 0; i < N_TEST; i++)
    {
        for(int j = 0; j < N_TEST; j++)
        {
            fprintf(fp, "%c", mat[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    snprintf(filename, 256, "./sauvegardes/listes/mots_%04d-%02d-%02d-%02d:%02d:%02d",
                            tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
                            tm->tm_hour, tm->tm_min, tm->tm_sec);
    fp = fopen(filename, "w");
    for(int i = 0; i < a_trouver; i++)
    {
        //printf("%s", liste_mot[i].mot);
        fprintf(fp, "%s", liste_mot[i].mot);
    }

    snprintf(filename, 256, "./sauvegardes/listes/mots_trouves_%04d-%02d-%02d-%02d:%02d:%02d",
                            tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
                            tm->tm_hour, tm->tm_min, tm->tm_sec);
    fp = fopen(filename, "w");
    for(int i = 0; i < (N_TEST - a_trouver); i++)
    {
        //printf("%s", liste_mot_trouves[i].mot);
        fprintf(fp, "%s\n", liste_mot_trouves[i].mot);
    }
}

/*
Permet de charger une sauvegarde
*/
void charger(GtkFileChooserButton *chooser)
{

    //printf("%s\n", gtk_file_chooser_get_filename((GtkFileChooser *)chooser));
    //printf("%s\n", replaceWord(gtk_file_chooser_get_filename((GtkFileChooser *)chooser), "sauvegarde_", "listes/mots_"));
    //printf("%s\n", replaceWord(gtk_file_chooser_get_filename((GtkFileChooser *)chooser), "sauvegarde_", "listes/mots_trouves_"));

    FILE * fichier = fopen(gtk_file_chooser_get_filename((GtkFileChooser *)chooser), "r") ;
    if (fichier == NULL){
        printf("Problème à l'ouverture du fichier\n");
    }

    int i = 0, j = 0 ;
    char charLu ;

    while(charLu != EOF){
        charLu = fgetc(fichier);
        if(charLu=='\n')
        {
            i++ ;
            j = 0 ;
        }
        else
        {
            mat[i][j] = charLu ;
            j++ ;
        }
    }

    fichier = fopen(replaceWord(gtk_file_chooser_get_filename((GtkFileChooser *)chooser), "sauvegarde_", "listes/mots_"), "r") ;
    if (fichier == NULL){
        printf("Problème à l'ouverture du fichier\n");
    }

    char motLu[N_TEST+1] ;

    i = 0 ;
    while(fgets(motLu, 60, fichier))
    {
        //printf("%s\n", motLu);
        strcpy(liste_mot[i].mot, motLu) ;
        i++ ;
    }

    fichier = fopen(replaceWord(gtk_file_chooser_get_filename((GtkFileChooser *)chooser), "sauvegarde_", "listes/mots_trouves_"), "r") ;
    if (fichier == NULL){
        printf("Problème à l'ouverture du fichier\n");
    }

    i = 0 ;
    while(fgets(motLu, 60, fichier))
    {
        //printf("%s\n", motLu);
        motLu[strcspn(motLu, "\r\n")] = 0;
        strcpy(liste_mot_trouves[i].mot, motLu) ;
        i++ ;
    }
    //printf("%i\n", i);

    a_trouver -= i ;
    m = N_TEST-a_trouver ;
}

/*
Associe le bouton sauvegarder avec la fonction sauvegarde
*/
void on_import_save(GtkWidget *button_menu, gpointer *data)
{
    printf("save\n");

    GtkFileChooserButton *chooser = (GtkFileChooserButton *)data;

    charger(chooser) ;

    printf("------------ Chargement matrice : \n");

    affGrille(mat);

    // printf("------------ Chargement Mots à trouver (%i) : \n", a_trouver);
    // for(int i = 0; i < a_trouver; i++)
    // {
    //     printf("%s", liste_mot[i].mot);
    // }

    // printf("------------ Chargement Mots trouvés (%i) : \n", N_TEST-a_trouver);
    // for(int i = 0; i < (N_TEST - a_trouver); i++)
    // {
    //     printf("%s", liste_mot_trouves[i].mot);
    // }

    type_jeu = 1 ;
    gtk_widget_hide(window_chargement);
    create_board(button_menu);
    gtk_widget_show_all(window_main);

}

/*
Affiche un message de fin sur le terminal et quitte le jeu
*/
void on_fin(GtkWidget *button)
{
    jeu_fin = 1 ;
    printf("Au revoir!\n");
}

/*
Permet de choisir un thème parmi les thèmes proposés. Un thème est une longue liste de mots dans laquelle les
mots sont piochés aléatoirement pour remplir la grille.
*/
void on_theme(GtkWidget *button, gpointer *theme)
{
    printf("%s\n", (char*)theme);
    strcpy(themefile, theme);
}

/*
Permet de choisir une difficulté (10, 14, 16)
*/
void on_difficulte(GtkWidget *button, gpointer *difficulte)
{
    printf("Niveau de difficulté :\n");
    printf("%i\n", (int*)difficulte);
}

/*Permet d'afficher la fenêtre principale de jeu*/
void on_new_partie_main(GtkWidget *button)
{
    gtk_widget_hide(window_menu);
    //start_button = gtk_button_new_with_label("Début");
    //g_signal_connect(G_OBJECT(start_button), "clicked", G_CALLBACK(_start_timer), label);
    create_board(button);
    gtk_widget_show_all(window_main);

}

/*Permet d'afficher la fenêtre quand le joueur gagne une partie

Mets à jour toutes les variables globales pour la prochaine partie
*/
void on_new_partie_menu_win(GtkWidget *button)
{

    continue_timer = FALSE;
    start_timer = FALSE;
    sec_expired = 0;

    clicked_1 = FALSE ;
    clicked_2 = FALSE ;

    m = 0 ;
    jeu_fin = 0 ;
    type_jeu = 0 ;
    a_trouver = N_TEST ;

    for(int i = 0 ; i < N_TEST ; i++)
    {
        strcpy(liste_mot[i].mot, "\0");
    }
    for(int i = 0 ; i < N_TEST ; i++)
    {
        strcpy(liste_mot_trouves[i].mot, "\0");
    }

    strcpy(themefile, "./themes/theme_animal.txt") ;

    gtk_widget_hide(window_win);
    gtk_widget_show_all(window_chargement);
}

/*Permet d'afficher la fenêtre avec les menus pour choisir les options difficultés et les thèmes */
void on_new_partie_menu(GtkWidget *button)
{
    gtk_widget_hide(window_chargement);
    gtk_widget_show_all(window_menu);

}

/*Permet de revenir sur la première fenêtre (chargement de partie ou nouvelle partie) à partir du jeu*/
void on_menu_main(GtkWidget *button)
{
    gtk_widget_hide(window_main);
    gtk_widget_show_all(window_chargement);

}

/*Permet de revenir sur la première fenêtre (chargement de partie ou nouvelle partie) à partir de la fenêtre finale (gagner)*/
void on_menu_win(GtkWidget *button)
{
    gtk_widget_hide(window_win);
    gtk_widget_show_all(window_chargement);

}


/*Permet de supprimer les caractères de type retour chariot ou espace en trop à la fin d'une chaîne de caractères*/
char *choppy( char *s )
{
    char *n = malloc( strlen( s ? s : "\n" ) );
    if( s )
        strcpy( n, s );
    n[strlen(n)-1]='\0';
    return n;
}


/*Permet de revenir de récupérer un mot dans la matrice quand l'utilisateur a saisi les deux couples de coordonnées du mot*/
void mot_coords(char mat[N_TEST][N_TEST], char mot[N_TEST], point p1, point p2, info *b)
{
    int k = 0 ;

    //sud
    if ((p1.line < p2.line) & (p1.col == p2.col))
    {
        k = 0 ;
        for(int i = x1.line ; i <= x2.line ; i++)
        {
            mot[k] = b->mat[i][x1.col] ;
            k++ ;

        }
        mot[k] = '\0' ;
    }
    //nord
    else if ((p1.line > p2.line) & (p1.col == p2.col))
    {
        k = 0 ;
        for(int i = x1.line ; i >= x2.line ; i--)
        {
            mot[k] = b->mat[i][x1.col] ;
            k++ ;

        }
        mot[k] = '\0' ;
    }
    //est
    else if ((p1.line == p2.line) & (p1.col < p2.col))
    {
        k = 0 ;
        for(int j = x1.col ; j <= x2.col ; j++)
        {
            mot[k] = b->mat[x1.line][j] ;
            k++ ;

        }
        mot[k] = '\0' ;
    }
    //ouest
    else if ((p1.line == p2.line) & (p1.col > p2.col))
    {
        k = 0 ;
        for(int j = x1.col ; j >= x2.col ; j--)
        {
            mot[k] = b->mat[x1.line][j] ;
            k++ ;

        }
        mot[k] = '\0' ;
    }
}


/*Permet de donner la position d'un mot dans une liste de mots*/
int position(mot_tire *liste, char *word)
{
    for(int c = 0; c<N_TEST; c++)
    {
        if(compare_words(liste[c].mot, word))
        {
            return c ;
        }
    }
    return -1 ;
}

/*Permet de supprimer un mot dans une liste de mots*/
void supp_liste(mot_tire *liste, char *word, int nbr_mots)
{
    int index = position(liste, word) ;

    for(int c = index; c<nbr_mots-1; c++)
    {
        liste[c] = liste[c+1];
    }
}

/*Permet d'associer des paramètres à chacun des boutons de la matrice de jeu.

Quand un mot est trouvé, c'est cette fonction qui gère les variables globales qui permettent d'avancer dans le jeu.
C'est ici, qu'on gère les listes de mots (trouvés et à trouver). Quand un mot est trouvé, on utiliser les fonctions
précedemment définies pour supprimer/ajouter le mot dans la bonne liste.

C'est ici que l'on met à jour les zones textes de la fenêtre principale (de jeu) au fur et à mesure.

*/
void on_btn_clicked(GtkWidget *button, gpointer *data)
{
    GtkLabel *label ;
    GtkLabel *mot ;
    GtkLabel *liste ;
    GtkLabel *liste2 ;
    info *b = (info*) data ;
    char str_coord[20] ;
    char word[20] ;

    flag_clicked:
    if((clicked_1 == FALSE) & (clicked_2 == FALSE))
    {
        label = (GtkLabel*)b->label1;
        x1.col = b->col ;
        x1.line = b->line ;
        clicked_1 = TRUE ;
    }
    else if((clicked_1==TRUE) & (clicked_2 == FALSE))
    {
        label = (GtkLabel*)b->label2;
        x2.col = b->col ;
        x2.line = b->line ;
        clicked_2 = TRUE ;
    }
    else
    {
        clicked_1 = FALSE;
        clicked_2 = FALSE;
        goto flag_clicked ;
    }

    if((clicked_1==TRUE) & (clicked_2 == TRUE))
    {

        mot = (GtkLabel*)b->mot;
        liste = (GtkLabel*)b->liste_mots;
        liste2 = (GtkLabel*)b->liste_mots_trouves;
        mot_coords(b->mat, word, x1, x2, b);
        gtk_label_set_label(mot, word);

        // printf("======TEST in button (%i - %i) =====\n", a_trouver, N_TEST);
        // for(int i = 0; i<a_trouver ; i++)
        // {
        //     printf("%s", liste_mot[i].mot);
        // }

        char liste_aff[N_TEST*N_TEST] = "\0";

        for(int i = 0 ; i < a_trouver ; i++)
        {
            if(!compare_words(liste_mot[i].mot, word))
            {
                strcat(liste_aff, liste_mot[i].mot);
            }
            else
            {
                supp_liste(liste_mot, liste_mot[i].mot, a_trouver) ;
                strcpy(liste_mot_trouves[m].mot, word) ;
                a_trouver -- ;
                m ++ ;
            }
        }
        gtk_label_set_label(liste, liste_aff);

        char liste_aff_trouves[N_TEST*N_TEST] = "\0";

        for(int i = 0 ; i < m ; i++)
        {
            strcat(liste_aff_trouves, liste_mot_trouves[i].mot);
            strcat(liste_aff_trouves, "\n");
        }
        // printf("-------\n");

        // for(int i = 0; i<N_TEST-a_trouver ; i++)
        // {
        //     printf("%s\n", liste_mot_trouves[i].mot);
        // }

        gtk_label_set_label(liste2, liste_aff_trouves);

        if(a_trouver == 0)
        {

            printf("Gagné !!!!\n");
            gtk_widget_hide(window_main);

            int sec, h, m, s;
            char buf[256];
            memset(&buf, 0x0, 256);

            sec = ++sec_expired ;

            h = (sec/3600); 
            m = (sec -(3600*h))/60;
            s = (sec -(3600*h)-(m*60));

            snprintf(buf, 255, "Temps écoulé : %.2d:%.2d:%.2d", h, m, s);
            gtk_label_set_label(temps_ecoule, buf);

            gtk_widget_show_all(window_win);
        }
    }

    sprintf(str_coord, "%c (%i, %i)", b->letter, b->line, b->col);
    gtk_label_set_label(label, str_coord);
}

/*Permet de comparer deux chaînes de caractères sans prendre en compte les espaces, retour chariots, etc.*/

int compare_words(char *w1, char *w2)
{
    int m = 0 ;
    int same = 1 ;
    if(strlen(w1) < strlen(w2))
    {
        same = 0 ;
    }
    else
    {
        while(m < strlen(w2))
        {
            if(w1[m] != w2[m])
            {
                same = 0 ;
            }
            m++ ;
        }
    }
    return same ;
}

/*Permet d'update le label au fur et à mesure que les secondes passent*/
static gboolean label_update(gpointer data)
{
    int sec, h, m, s;
    GtkLabel *label = (GtkLabel*)data;
    char buf[256];
    memset(&buf, 0x0, 256);

    sec = ++sec_expired ;

    h = (sec/3600); 
    m = (sec -(3600*h))/60;
    s = (sec -(3600*h)-(m*60));

    snprintf(buf, 255, "%.2d:%.2d:%.2d", h, m, s);
    gtk_label_set_label(label, buf);
    return continue_timer;

}

/*Permet de mettre pause et de relancer le timer*/
static void pause_resume_timer (GtkWidget *button)
{
    (void)button;
    if(start_timer)
    {
        //GtkWidget *label = data;
        continue_timer = !continue_timer;
        if(continue_timer)
        {
            g_timeout_add_seconds(1, label_update, label_time);
            gtk_widget_hide(window_pause);
            gtk_widget_show_all(window_main);
        }
        else
        {
            sec_expired--;
            gtk_widget_hide(window_main);
            gtk_widget_show_all(window_pause);
        }
    }
}