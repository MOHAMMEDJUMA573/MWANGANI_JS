//src/main_grids.c
//created by MOHAMMEDJUMA573
//
#include "common.h"
//menu one selected
static void on_menu1_main_selected(GtkToggleButton *button, gpointer user_data) {
    GtkWidget *grid = GTK_GRID(user_data);
    GtkWidget *admin_butt_home, *teacher_butt_home, *student_butt_home, *parent_butt_home;

    //add the buttons to the grid
    gtk_grid_attach(GTK_GRID(grid), admin_butt_home, 0, 0, 1,1);
    gtk_grid_attach(GTK_GRID(grid), teacher_butt_home, 1, 0, 1,1);
    gtk_grid_attach(GTK_GRID(grid), student_butt_home, 0, 1, 1,1);
    gtk_grid_attach(GTK_GRID(grid), parent_butt_home, 1, 1, 1,1);      
}
//menu two selected
static void on_menu2_main_selected(GtkToggleButton *button, gpointer user_data) {

}
//menu three selected
static void on_menu3_main_selected(GtkToggleButton *button, gpointer user_data) {

}