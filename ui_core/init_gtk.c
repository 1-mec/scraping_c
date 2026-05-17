#include <gtk/gtk.h>
#include "../ui_header/init_gtk.h"
#include "../header/file_related.h"

void print_hello (GtkWidget *widget, gpointer   data){
  g_print ("Hello World\n");
}

void aff_links(GtkWidget * label,gpointer data){
    int links = get_nb_links();
    items * list = get_items();
    for(int i = 0 ; i < links ;i++){
      ssize_t len = strlen("-> lien =  & \n\0")+strlen(list[i].lst)+list[i].index;
      char * tmp = malloc(len);
      snprintf(tmp,len,"%s & %d\n",list[i].lst,list[i].index);
      label = gtk_label_new(tmp);
      free(tmp);
      //g_print("-> %s & %d\n",list[i].lst,list[i].index);
    }
}

void activate (GtkApplication *app, gpointer data){
  GtkWidget *window, *button, *button_box, *label;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_fullscreen(GTK_WINDOW(window));


  button_box = gtk_button_box_new (GTK_ORIENTATION_VERTICAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  label = gtk_label_new("This is my label");
  gtk_label_set_text(GTK_LABEL (label), "I cannot use this func");

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (aff_links), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);
  gtk_container_add (GTK_LABEL(button_box),label);



  gtk_widget_show_all (window);
}


