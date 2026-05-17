#include <gtk/gtk.h>
#include "../ui_header/init_gtk.h"
#include "../header/file_related.h"

void print_hello (GtkWidget *widget, gpointer   data){
  g_print ("Hello World\n");
}

void aff_links(GtkWidget * widget,gpointer data){
    int links = get_nb_links();
    items * lst = get_lst();
    GtkLabel * label;
    for(int i = 0 ; i < links ;i++){
      //set_label(lst[i]->lst);
      g_print("-> %d ème %s",lst[i].index,lst[i].lst);
    }
    //free_items(lst);
}

void activate (GtkApplication *app, gpointer data){
  GtkWidget *window, *button, *button_box, *label;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (aff_links), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);



  gtk_widget_show_all (window);
}


