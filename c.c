#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<unistd.h>

const gchar *ch;

static void delete(GtkWidget *del, gpointer delt) {
	gchar *c = ch;	
	gtk_button_set_label(GTK_BUTTON(del), c);	

	gtk_widget_show_all(delt);

}

static void save_(GtkWidget *ent, gpointer data, gpointer dat) {
	ch = gtk_entry_get_text(GTK_ENTRY(data));
	
	gtk_widget_destroy(dat);
	gtk_widget_destroy(ent);

}

static void read_file(GtkWidget *button, gpointer data) 
{
	GtkWidget *new;
	GtkWidget *save;
	GtkWidget *hard_code;
	
	hard_code = gtk_button_new_with_label("finalize");
	save = gtk_button_new_with_label("Save");
	new = gtk_entry_new();

	g_signal_connect(save, "clicked", G_CALLBACK(save_),  new);
	g_signal_connect(hard_code, "clicked", G_CALLBACK(delete), data);
	
	gtk_container_add(GTK_CONTAINER(data), new);
	gtk_container_add(GTK_CONTAINER(data), save);
	gtk_container_add(GTK_CONTAINER(data), hard_code);
	
	gtk_widget_show_all(data);
}

int main(int argc, char* argv[]) {

	gtk_init(&argc, &argv);

	GtkWidget *window;
	GtkWidget *todo_label;
	GtkWidget *box;
	GtkWidget *create_new_button;

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
