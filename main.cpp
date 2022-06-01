//
// Created by Filip Gieracki
//
#include <iostream>
#include <gtk/gtk.h>
#include "GUI.h"
#include "Database.h"

using namespace std;


int main (int argc, char *argv[]) {

    gtk_init(&argc, &argv);
    try{
        auto DB = Database::instance();
        auto window = GUI::instance();
        window.run();
    }
    catch(const std::logic_error e){
        cerr << e.what();
    }

    return 0;
}