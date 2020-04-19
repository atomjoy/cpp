/*
sudo g++ -std=c++11 -pthread -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -pthread -std=c++11
./sfml-app
*/
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h> // printf();
// Curl
#include <curl/curl.h>
// Thread
#include <thread>
// Sleep: std::this_thread::sleep_for(std::chrono::milliseconds(200));
#include <chrono>

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

void Curl()
{
	CURLcode result;
	auto curl = curl_easy_init();

	// curl_global_init(CURL_GLOBAL_DEFAULT);

    if (curl)
	{
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/todos/1");
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

        std::string response_string;
        std::string header_string;

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

		char* url;
        long response_code;
        double elapsed;

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

        curl_easy_perform(curl);

		if (result != CURLE_OK) {
			std::cerr << "Error during curl request: " << curl_easy_strerror(result) << std::endl;
		}

        curl_easy_cleanup(curl);

		// curl_global_cleanup();
        curl = NULL;

		std::cout << response_string << std::endl;
    }
	// CURL *curl;
	// CURLcode result;

	// curl_global_init(CURL_GLOBAL_DEFAULT);

	// curl = curl_easy_init();
	// if (curl) {
	// 	curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/todos/1");

	// 	// Show
	// 	// result = curl_easy_perform(curl);
	// 	curl_easy_perform(curl);

	// 	if (result != CURLE_OK) {
	// 		std::cerr << "Error during curl request: " << curl_easy_strerror(result) << std::endl;
	// 	}
	// 	curl_easy_cleanup(curl);
	// } else {
	// 	std::cerr << "Error initializing curl." << std::endl;
	// }
	// curl_global_cleanup();
}

void Worker()
{
	while(1 < 2){
    	std::cout << "!!!! @@@@@@@@@ ######### Another thread " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

int SetIcon(sf::RenderWindow w, std::string image)
{
	sf::Image icon;
	if (!icon.loadFromFile(image)) {
      return -1;
    }
	w.setIcon(32,32,icon.getPixelsPtr());
	// w.getSystemHandle(); // sf::WindowHandle
	return 1;
}

void LoadImage(std::string image)
{
	sf::FileInputStream stream;
	stream.open(image);

	sf::Texture texture;
	texture.loadFromStream(stream);
}

sf::Text MoveObject(sf::Text text){
	// retrieve the absolute position of the entity
	sf::Vector2f position = text.getPosition();
	sf::Vector2f alfa(0.1f, 0.2f);
	sf::Vector2f newpos;

	newpos = position + alfa;

	text.setPosition(newpos);

	// text.setOrigin(10.f, 20.f);
	// text.setPosition(newpos);
	// text.move(1.3f, 1.2f);
	// position = text.getPosition();

	std::cout << "Text position: " <<  position.x << " " << position.y << std::endl;
	return text;
}

sf::Text ShowText(std::string str, sf::Text text, sf::Font font)
{
	// sf::Font font;
	if (!font.loadFromFile("Roboto-Regular.ttf"))
	{
		std::cout << "Error font!!!" << std::endl;
		// exit (EXIT_FAILURE);
	}

	// sf::Text text;
	// select the font
	text.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString(str);
	// set the character size
	text.setCharacterSize(24); // in pixels, not points!
	// set the color
	text.setFillColor(sf::Color::Green);
	// set the text style
	// text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	// Move text
	// text = MoveObject(text);

	return text;
}

int main()
{
	Curl();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	window.setVerticalSyncEnabled(false);

	sf::Clock clock;

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	sf::Font font;
	sf::Text text;

	std::cout << "Main thread" << std::endl;
	std::thread t(Worker);
	// t.join();
	t.detach();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		// std::thread t(Worker);
		// t.detach();
		// std::cout << "Main thread" << std::endl;
		// t.join();
		// t.detach();

		float fpsx = 1.f / clock.getElapsedTime().asSeconds();

		// Int to string
		std::string s = std::to_string(clock.getElapsedTime().asMicroseconds());
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		std::cout << "Elapsed time since previous frame(microseconds): " << clock.getElapsedTime().asMicroseconds() << " FPS: " << fpsx << std::endl;

		// Start the countdown over. Think of laps on a stop watch.
		clock.restart();

		// Move text
		text = MoveObject(text);
		// Clear window
		window.clear();
		// Draw shape
		window.draw(shape);
		// Add text
		window.draw(ShowText(s, text, font));
		// Show
		window.display();
    }

    return 0;
}
