#include <glib.h>
#include <gtk/gtk.h>
#include "say.h"

extern char g_lngs[LNGS_LEN][6];

static	void	save_lng(GtkWidget *widget, int lng)
{
	system(ft_merge(" ", 2, "saycfg -l", g_lngs[lng]));
}

static	void	save_vol(GtkWidget *widget, float vol)
{
	float val = gtk_range_get_value(GTK_RANGE(widget));
	system(ft_merge(" ", 2, "saycfg -v", ftoa(gtk_range_get_value(GTK_RANGE(widget)))));
}

static	void	save_spd(GtkWidget *widget, float spd)
{
	system(ft_merge(" ", 2, "saycfg -s", ftoa(gtk_range_get_value(GTK_RANGE(widget)))));
}

int		main(int argc, char **argv)
{
	GtkWidget	*window;
	GtkWidget	*box_main;
	GtkWidget	*box_config;
	GtkWidget	*box_lngs;
	GtkWidget	*box_vol;
	GtkWidget	*box_spd;
	GtkWidget	*btn_save;
	GSList		*rad_group;
	GtkWidget	*rad_lng[6];
	GtkWidget	*bar_vol;
	GtkWidget	*bar_spd;
	AtkObject	*adj_vol;
	AtkObject	*adj_spd;
	t_config	config;

	gtk_init(&argc, &argv);

	ft_get_default_cfg(&config);
	ft_read_cfg(&config);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	box_main=gtk_vbox_new(0, 10);
	box_config=gtk_hbox_new(0, 10);
	box_lngs=gtk_vbox_new(0, 10);
	box_vol=gtk_vbox_new(0, 10);
	box_spd=gtk_vbox_new(0, 10);
	btn_save=gtk_button_new_with_mnemonic("_Close");
	rad_lng[0]=gtk_radio_button_new_with_label(NULL, "English (US)");
	rad_group=gtk_radio_button_get_group(GTK_RADIO_BUTTON(rad_lng[0]));
	rad_lng[1]=gtk_radio_button_new_with_label(rad_group, "English (GB)");
	rad_lng[2]=gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(rad_lng[1]), "French");
	rad_lng[3]=gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(rad_lng[1]), "German");
	rad_lng[4]=gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(rad_lng[1]), "Italian");
	rad_lng[5]=gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(rad_lng[1]), "Spanish");
	adj_vol= (AtkObject*) gtk_adjustment_new(config.vol, 0.5, 1.5, 0.1, 0.1, 0);
	adj_spd= (AtkObject*) gtk_adjustment_new(config.speed, 0.5, 1.5, 0.1, 0.1, 0);
	bar_vol=gtk_vscale_new(GTK_ADJUSTMENT(adj_vol));
	bar_spd=gtk_vscale_new(GTK_ADJUSTMENT(adj_spd));

	// Definition tu titre et de la taille de la fenetre
	gtk_window_set_title(GTK_WINDOW(window), "Say! Preferences");
	gtk_widget_set_size_request(window, 480, 480);



	// ########################################################

	// Definition des champs de la box lngs
	gtk_box_pack_start(GTK_BOX(box_lngs), gtk_label_new("Voice Language"), 0, 0, 0);
	for (int i = 0; i < 6; i++)
		gtk_box_pack_start(GTK_BOX(box_lngs), rad_lng[i], 0, 0, 10);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rad_lng[ft_get_lng_index(config.lng)]), true);

	// Definition des champs de la box volume
	gtk_box_pack_start(GTK_BOX(box_vol), gtk_label_new("Voice Volume"), 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(box_vol), bar_vol, 1, 1, 0);

	// Definition des champs de la box speed
	gtk_box_pack_start(GTK_BOX(box_spd), gtk_label_new("Voice Speed"), 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(box_spd), bar_spd, 1, 1, 0);

	// Definition des champs de la box config
	gtk_box_pack_start(GTK_BOX(box_config), box_lngs, 1, 1, 0);
	gtk_box_pack_start(GTK_BOX(box_config), gtk_hseparator_new(), 0, 1, 0);
	gtk_box_pack_start(GTK_BOX(box_config), box_vol, 1, 1, 0);
	gtk_box_pack_start(GTK_BOX(box_config), gtk_hseparator_new(), 0, 1, 0);
	gtk_box_pack_start(GTK_BOX(box_config), box_spd, 1, 1, 0);

	// Definition des champs de la box principale
	gtk_box_pack_start(GTK_BOX(box_main), box_config, 1, 0, 0);
	gtk_box_pack_start(GTK_BOX(box_main), gtk_vseparator_new(), 0, 1, 0);
	gtk_box_pack_start(GTK_BOX(box_main), btn_save, 0, 0, 0);

	// Definition des evenemts config
	for (int i = 0; i < 6; i++)
		g_signal_connect(rad_lng[i], "clicked", G_CALLBACK(save_lng), i);

	// Definition des events de volume et vitesse
	g_signal_connect(bar_vol, "value-changed", G_CALLBACK(save_vol), NULL);
	g_signal_connect(bar_spd, "value-changed", G_CALLBACK(save_spd), NULL);

	// ########################################################



	// Inclusion de la GUI dans la fenetre
	gtk_container_add(GTK_CONTAINER(window), box_main);

	// Gestion des events generaux
	g_signal_connect(btn_save, "clicked", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

	// Affichage de la fenetre
	gtk_widget_show_all(window);

	gtk_main();
	return (0);
}
