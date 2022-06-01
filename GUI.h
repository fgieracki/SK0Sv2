//
// Created by Filip Gieracki
//

#ifndef SK0SV2_GUI_H
#define SK0SV2_GUI_H

#include <gtk/gtk.h>
#include <string>
#include <iostream>
#include <vector>
#include "Database.h"
#include "Row.h"

class GUI {
private:
    Database DB = Database::instance();
    GtkWidget *window;
    GtkWidget *container;
    GtkWidget *surname_input;
    GtkWidget *name_input;
    GtkWidget *name2_input;
    GtkWidget *crossed_out_input;
    GtkWidget *resignation_input;
    GtkWidget *email_input;
    GtkWidget *index_input;
    GtkWidget *res_row;
    GtkWidget *vbox;
    GtkWidget *sw;
    GtkWidget *results_count;
    GtkWidget *default_values_information;
    GtkWidget *policy_note;
    std::vector <Row*> table_data_ = DB.search_records("", "", "", "", "", "", "");
private:
    void setup_window();
    void create_widgets();
    static void update_data(){GUI::instance().updater();};
    void updater();

public:
    void run();
    static GUI &instance(){
        static GUI window;
        return window;
    }

    GUI(){
        setup_window();
        create_widgets();
    }

};

#endif //SK0SV2_GUI_H
