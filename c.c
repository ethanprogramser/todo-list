#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<unistd.h>

const gchar *ch;
GtkWidget *window;
GtkWidget *todo_label;
GtkWidget *box;
GtkWidget *create_new_button;
GtkWidget *new;
GtkWidget *save;
GtkWidget *hardcode;

static void delete(GtkWidget *p, gpointer data) {
	gtk_widget_destroy(p);
}

static void save_(GtkWidget *ent, gpointer data) {
	GtkWidget *new_but;

	ch = gtk_entry_get_text(GTK_ENTRY(new));
	
	new_but = gtk_button_new_with_label(ch);

	g_signal_connect(new_but, "clicked", G_CALLBACK(delete), NULL);
	
	gtk_container_add(GTK_CONTAINER(box), new_but);

	gtk_widget_destroy(save);
	gtk_widget_destroy(new);
  gtk_widget_show_all(window);


}

static void read_file(GtkWidget *button, gpointer data) 
{
	
	save = gtk_button_new_with_label("Save");
	new = gtk_entry_new();

	g_signal_connect(save, "clicked", G_CALLBACK(save_),  new);
	
	gtk_container_add(GTK_CONTAINER(box), new);
	gtk_container_add(GTK_CONTAINER(box), save);
	
	gtk_widget_show_all(data);
}

int main(int argc, char* argv[]) {

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	todo_label = gtk_label_new_with_mnemonic("_TODO");
	create_new_button = gtk_button_new_with_label("Create New");
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

	g_signal_connect(create_new_button, "clicked", G_CALLBACK(read_file), box);

	gtk_container_add(GTK_CONTAINER(window), box);
	gtk_container_add(GTK_CONTAINER(box), create_new_button);
	gtk_container_add(GTK_CONTAINER(box), todo_label);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
