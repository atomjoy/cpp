## Install C++ Gtk
```bash
# g++
sudo apt-get install build-essential gdb
# Gtk
sudo apt install libgtk-3-dev
sudo apt-get install libgtkmm-3.0-dev
# Curl
sudo apt install libcurl4-openssl-dev
sudo apt-get install libcurl4-gnutls-dev
```

## Compile SFML
```bash
sudo g++ -std=c++11 -lpthread -lcurl -I. -c main.cpp
g++ main.o -o main-app -lsfml-graphics -lsfml-window -lsfml-system -lpthread -std=c++11 -lcurl -I.
./main-app
```

## Compile Gtk 3
```bash
sudo g++ -std=c++11 -lpthread $(pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4) -c win.cpp
g++ win.o -o win-app -lpthread -std=c++11 $(pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4)
./win-app
```

## Compile SFML, GTK3
```bash
sudo g++ -std=c++11 -lpthread $(pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4) -c win.cpp
sudo g++ win.o -o win-app -lsfml-graphics -lsfml-window -lsfml-system -lpthread -std=c++11 $(pkg-config --cflags --libs gtkmm-3.0)
./win-app
```

## Compile with .h import location
```bash
sudo g++ -std=c++11 -lpthread $(pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4) -c win.cpp -I.
# Or files
sudo g++ -std=c++11 -lpthread $(pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4) -c win.cpp helloworld.cpp
sudo g++ win.o -o win-app -lsfml-graphics -lsfml-window -lsfml-system -lpthread -std=c++11 $(pkg-config --cflags --libs gtkmm-3.0) -I.
# Or files
sudo g++ win.o -o win-app -lsfml-graphics -lsfml-window -lsfml-system -lpthread -std=c++11 $(pkg-config --cflags --libs gtkmm-3.0) helloworld.cpp
```

### GTK3 Desktop Notification
```cpp
#include <giomm-2.4/giomm.h>

int main(int argc, char *argv[]) {
	auto Application = Gio::Application::create("hello.world", Gio::APPLICATION_FLAGS_NONE);
	Application->register_application();
	auto Notification = Gio::Notification::create("Nowa wiadomość");
	Notification->set_body("Twój kod do logowania: 4972369.");
	auto Icon = Gio::ThemedIcon::create("dialog-information");
	Notification->set_icon (Icon);
	Application->send_notification(Notification);
	return 0;
}
```

### GTK3 Desktop Top Bar Icon
```cpp
#include <gtkmm/main.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/statusicon.h> //Gtk::StatusIcon
#include <gdkmm/pixbuf.h> //Gdk::Pixbuf

int main(int argc, char *argv[]) {
	Gtk::Main kit(argc, argv);
	Gtk::MessageDialog Hello("Hello world!", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);

    Glib::RefPtr<Gdk::Pixbuf> pix = Gdk::Pixbuf::create_from_file("image.png");
    Glib::RefPtr<Gtk::StatusIcon> icon = Gtk::StatusIcon::create(pix);

	Hello.set_secondary_text("This is an example dialog.");
	Hello.run();
        return 0;
}
```

### GTK3 Desktop Top Bar Icon
```cpp
#include <gtkmm/main.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/statusicon.h> // Gtk::StatusIcon
#include <gdkmm/pixbuf.h> // Gdk::Pixbuf
#include <glibmm/ustring.h> // Glib::ustring

#include "helloworld.h"
#include <gtkmm/application.h>

using Glib::ustring;

int main(int argc, char *argv[]) {
    // No window only top bar icon
	Gtk::Main kit(argc, argv);

    // Icon top bar
    Glib::RefPtr<Gdk::Pixbuf> pix = Gdk::Pixbuf::create_from_file("image.png");
    Glib::RefPtr<Gtk::StatusIcon> icon = Gtk::StatusIcon::create(pix);

    Gtk::Main::run();
    return 0;

    // Dialog window
    // Gtk::MessageDialog Hello("Hello world!", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
	// Hello.set_secondary_text("This is an example dialog.");
	// Hello.run();
    // return 0;

    // Normal window app
    // auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    // HelloWorld helloworld;
    // return app->run(helloworld);
}
```
