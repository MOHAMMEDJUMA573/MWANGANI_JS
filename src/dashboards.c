//src/dashboard.c
//created by MOHAMMEDJUMA573
//
#include "dashboards.h"

int showMainDashboard(void) {
   GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(main_window), "MWANGANI JUNIOR SECONDARY");
   gtk_window_set_default_size(GTK_WINDOW(main_window), 600, 400);
   gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
   gtk_widget_set_size_request( GTK_WIDGET(main_window), 600, 400);
   gtk_container_set_border_width(GTK_CONTAINER(main_window), 10);


   //signal to destroy the main window
   g_signal_connect(main_window, "destroy",G_CALLBACK(gtk_main_quit), NULL);

   gtk_widget_show_all(main_window);
   gtk_main();
   return 0;
 }