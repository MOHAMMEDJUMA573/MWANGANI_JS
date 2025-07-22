// src/main.c
//created by MOHAMMEDJUMA573
//
#include "dashboards.h"

int main(int argc, char *argv[]) {
    //initialize gtk
    gtk_init(&argc, &argv);

    //SHOW MAIN DASHBOARD
    int choice = showMainDashboard();

    return 0;
}