//
// Created by Filip Gieracki
//

#include "GUI.h"

void GUI::setup_window() {
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "SK0S v2");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), false);
    gtk_widget_set_size_request(GTK_WIDGET(window), 1650, 800);

    container = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), container);
}

void GUI::create_widgets() {
    surname_input = gtk_entry_new();
    gtk_widget_set_size_request(surname_input, 300, 40);
    GtkWidget *surname_label = gtk_label_new ("Nazwisko: ");
    gtk_fixed_put(GTK_FIXED(container), surname_label, 10, 10);
    gtk_fixed_put(GTK_FIXED(container), surname_input, 100, 10);
    gtk_widget_set_size_request(surname_input, 300, 50);
    gtk_widget_set_size_request(surname_label, 100, 50);
    g_signal_connect(G_OBJECT(surname_input), "changed", G_CALLBACK(update_data), (gpointer) window);

    name_input = gtk_entry_new();
    gtk_widget_set_size_request(name_input, 300, 40);
    GtkWidget *name_label = gtk_label_new ("Imię: ");
    gtk_fixed_put(GTK_FIXED(container), name_label, 430, 10);
    gtk_fixed_put(GTK_FIXED(container), name_input, 500, 10);
    gtk_widget_set_size_request(name_input, 300, 50);
    gtk_widget_set_size_request(name_label, 100, 50);
    g_signal_connect(G_OBJECT(name_input), "changed", G_CALLBACK(update_data), (gpointer) window);

    name2_input = gtk_entry_new();
    gtk_widget_set_size_request(name2_input, 300, 40);
    GtkWidget *name2_label = gtk_label_new ("Imię 2: ");
    gtk_fixed_put(GTK_FIXED(container), name2_label, 830, 10);
    gtk_fixed_put(GTK_FIXED(container), name2_input, 900, 10);
    gtk_widget_set_size_request(name2_input, 300, 50);
    gtk_widget_set_size_request(name2_label, 100, 50);
    g_signal_connect(G_OBJECT(name2_input), "changed", G_CALLBACK(update_data), (gpointer) window);

    email_input = gtk_entry_new();
    gtk_widget_set_size_request(email_input, 300, 40);
    GtkWidget *email_label = gtk_label_new ("Email: ");
    gtk_fixed_put(GTK_FIXED(container), email_label, 1225, 10);
    gtk_fixed_put(GTK_FIXED(container), email_input, 1300, 10);
    gtk_widget_set_size_request(email_input, 300, 50);
    gtk_widget_set_size_request(email_label, 100, 50);
    g_signal_connect(G_OBJECT(email_input), "changed", G_CALLBACK(update_data), (gpointer) window);

    crossed_out_input = gtk_entry_new();
    gtk_widget_set_size_request(crossed_out_input, 300, 40);
    GtkWidget *crossed_out_label = gtk_label_new ("Czy skreślony (1/0*): ");
    gtk_fixed_put(GTK_FIXED(container), crossed_out_label, 160, 70);
    gtk_fixed_put(GTK_FIXED(container), crossed_out_input, 300, 70);
    gtk_widget_set_size_request(crossed_out_input, 100, 50);
    gtk_widget_set_size_request(crossed_out_label, 150, 50);
    g_signal_connect(G_OBJECT(crossed_out_input), "changed", G_CALLBACK(update_data), (gpointer) window);

    resignation_input = gtk_entry_new();
    gtk_widget_set_size_request(resignation_input, 300, 40);
    GtkWidget *resignation_label = gtk_label_new ("Rezygnacja ze studiów (1/0*): ");
    gtk_fixed_put(GTK_FIXED(container), resignation_label, 510, 70);
    gtk_fixed_put(GTK_FIXED(container), resignation_input, 700, 70);
    gtk_widget_set_size_request(resignation_input, 100, 50);
    gtk_widget_set_size_request(resignation_label, 190, 50);
    g_signal_connect(G_OBJECT(resignation_input), "changed", G_CALLBACK(update_data), (gpointer) window);

    index_input = gtk_entry_new();
    gtk_widget_set_size_request(index_input, 300, 40);
    GtkWidget *index_label = gtk_label_new ("Numer indeksu: ");
    gtk_fixed_put(GTK_FIXED(container), index_label, 850, 70);
    gtk_fixed_put(GTK_FIXED(container), index_input, 1000, 70);
    gtk_widget_set_size_request(index_input, 200, 50);
    gtk_widget_set_size_request(index_label, 190, 50);
    g_signal_connect(G_OBJECT(index_input), "changed", G_CALLBACK(update_data), (gpointer) window);


    default_values_information = gtk_label_new("* - Wartości domyślne");
    gtk_widget_set_size_request(default_values_information, 200, 50);
    gtk_fixed_put(GTK_FIXED(container), default_values_information, 680, 750);

}


void GUI::run() {
    gtk_widget_show_all(window);
    gtk_main();
}

void GUI::updater() {
    std::string surname_ = gtk_entry_get_text(GTK_ENTRY(surname_input));
    std::string name_ = gtk_entry_get_text(GTK_ENTRY(name_input));
    std::string name2_ = gtk_entry_get_text(GTK_ENTRY(name2_input));
    std::string crossed_out_ = gtk_entry_get_text(GTK_ENTRY(crossed_out_input));
    std::string resignation_ = gtk_entry_get_text(GTK_ENTRY(resignation_input));
    std::string email_ = gtk_entry_get_text(GTK_ENTRY(email_input));
    std::string index_ = gtk_entry_get_text(GTK_ENTRY(index_input));

    auto DB = Database::instance();
    table_data_ = DB.search_records(surname_,
                                       name_,
                                       name2_,
                                       crossed_out_,
                                       resignation_,
                                       email_,
                                       index_);

    if(!policy_note){
        policy_note = gtk_label_new("Dane wygenerowane automatycznie, wszelkie zbieżności są przypadkowe!");
        gtk_fixed_put(GTK_FIXED(container), policy_note, 550, 700);
        gtk_widget_set_size_request(policy_note, 500, 50);
    }

    if(sw)
        gtk_container_remove(GTK_CONTAINER(container), sw);

    if(results_count)
        gtk_container_remove(GTK_CONTAINER(container), results_count);

    sw = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (sw),
                                    GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    vbox = gtk_vbox_new(FALSE, 0);

    results_count = gtk_label_new((("Znaleziono "+ std::to_string(table_data_.size()))
            + " Rekordów spełniających podane kryteria").c_str());

    for(auto I : table_data_){
        res_row = gtk_label_new(I->get_row().c_str());
        gtk_box_pack_start(GTK_BOX(vbox), res_row, TRUE, TRUE, 0);
    }

    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(sw), vbox);
    gtk_widget_set_size_request(sw, 800, 500);
    gtk_fixed_put(GTK_FIXED(container), sw, 400, 150);

    gtk_fixed_put(GTK_FIXED(container), results_count, 600, 650);
    gtk_widget_set_size_request(results_count, 400, 50);

    gtk_widget_show_all(window);
}