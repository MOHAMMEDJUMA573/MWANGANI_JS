//src/dashboard.c
//created by MOHAMMEDJUMA573
//
#include "dashboards.h"
#include "main_grids.h"

int showMainDashboard(void) {
   //initialize components of the main window
   GtkWidget *main_window;
   GtkWidget *vbox_main, *hbox_main;
   GtkWidget *header_main;
   GtkWidget *grid_main;
   GtkWidget *menu1_main, *menu2_main, *menu3_main;

   //create a window and initialize it
   main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(main_window), "MWANGANI JUNIOR SECONDARY");
   gtk_window_set_default_size(GTK_WINDOW(main_window), 600, 400);
   gtk_window_set_position(GTK_WINDOW(main_window), GTK_WIN_POS_CENTER);
   gtk_widget_set_size_request( GTK_WIDGET(main_window), 600, 400);
   gtk_container_set_border_width(GTK_CONTAINER(main_window), 10);

   //create a vertical box to hold the contents and add it to the main window
   vbox_main = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
   gtk_container_add(GTK_CONTAINER(main_window), vbox_main);

   //add the header label at the top of the dashboard...radio buttons
   header_main = gtk_label_new("🏫MWANGANI JUNIOR SECONDARY SYSTEM🏫");
   gtk_box_pack_start(GTK_BOX(vbox_main), header_main, FALSE, FALSE, 5);

   //create a horizontal box to hold Main options of the system and pack it not expanding
   hbox_main = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
   gtk_box_pack_start(GTK_BOX(vbox_main), hbox_main, FALSE, FALSE, 5);

   //create radio buttons for the menu and add them to the horizontal box
   menu1_main = gtk_radio_button_new_with_label(NULL, "🏡Home");
   menu2_main = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(menu1_main), "⚙️Settings");
   menu3_main = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(menu1_main), "ℹ️About");
   gtk_box_pack_start(GTK_BOX(hbox_main), menu1_main, TRUE, TRUE, 0);
   gtk_box_pack_start(GTK_BOX(hbox_main), menu2_main, TRUE, TRUE, 0);
   gtk_box_pack_start(GTK_BOX(hbox_main), menu3_main, TRUE, TRUE, 0);

   //create a grid for the menu items
   grid_main = gtk_grid_new();
   gtk_box_pack_start(GTK_BOX(vbox_main), grid_main, TRUE, TRUE, 0);

   //connect the signals button with the grid to present
   g_signal_connect(menu1_main, "toggled", G_CALLBACK(on_menu1_main_selected), grid_main);
   g_signal_connect(menu2_main, "toggled", G_CALLBACK(on_menu2_main_selected), grid_main);
   g_signal_connect(menu3_main, "toggled", G_CALLBACK(on_menu2_main_selected), grid_main);


   //set defaults e.g menu1 toggled
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(menu1_main), TRUE);



   //signal to destroy the main window
   g_signal_connect(main_window, "destroy",G_CALLBACK(gtk_main_quit), NULL);

   gtk_widget_show_all(main_window);
   gtk_main();
   return 0;
 }