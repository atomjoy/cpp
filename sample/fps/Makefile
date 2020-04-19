CXX = g++
CXXFLAGS = -Wall -g -pedantic
CXXCMD = -std=c++11 -lpthread -lcurl
CXXSFML = -lsfml-graphics -lsfml-window -lsfml-system
CXXGTK = `pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4 gl`

all: main-app

main-app: main.o Date.o Num.o
	$(CXX) $(CXXFLAGS) $(CXXGTK) $(CXXSFML) $(CXXCMD) -o main-app main.o Date.o Num.o

main.o: main.cpp Date.h Num.h
	$(CXX) $(CXXFLAGS) $(CXXGTK) $(CXXCMD) -c main.cpp

Date.o: Date.h
Num.o: Num.h

clean:
	rm -rf main-app *.o