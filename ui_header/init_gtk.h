#ifndef INIT_GTK_H
#define INIT_GTK_H

#include <gtk/gtk.h>

void print_hello (GtkWidget *widget, gpointer   data);
void aff_links(GtkWidget * widget,gpointer user_data);
void activate (GtkApplication *app, gpointer user_data);
void gtk_label_set (GtkLabel *label,char* link);

#endif 