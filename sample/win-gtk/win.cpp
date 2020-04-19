#include <gtkmm/main.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/statusicon.h> // Gtk::StatusIcon
#include <gdkmm/pixbuf.h> // Gdk::Pixbuf
#include <glibmm/ustring.h> // Glib::ustring
#include <gtkmm/tooltip.h>

#include "helloworld.h"
#include <gtkmm/application.h>

using Glib::ustring;

int main(int argc, char *argv[]) {
	/*
    Gtk::Main kit(argc, argv);

    Glib::RefPtr<Gdk::Pixbuf> pix = Gdk::Pixbuf::create_from_file("image.png");
    Glib::RefPtr<Gtk::StatusIcon> icon = Gtk::StatusIcon::create(pix);

    const Glib::ustring text = std::string("Kurwa mać");
    const Glib::ustring tip = "<i>Markup</i> in a tooltip.";

    // Gtk::Main::run();
    // return 0;
    */

    // gtk_tooltip_set_text (GtkTooltip *tooltip, const gchar *text);

    // Gtk::MessageDialog Hello("Hello world!", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
	// Hello.set_secondary_text("This is an example dialog.");
	// Hello.run();

    // Gtk::Main kit(argc, argv);
    // Glib::RefPtr<Gdk::Pixbuf> pix = Gdk::Pixbuf::create_from_file("image.png");
    // Glib::RefPtr<Gtk::StatusIcon> icon = Gtk::StatusIcon::create(pix);

    auto app = Gtk::Application::create(argc, argv, "Sample app");

    HelloWorld helloworld;

    return app->run(helloworld);


}