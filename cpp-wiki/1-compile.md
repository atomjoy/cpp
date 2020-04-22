## Kompilacja g++, Makefile

### Tworzenie objektu
```bash
# Utwórz objekty main.o
g++ -c main.cpp
g++ -c Car.cpp
g++ -c Person.cpp

# Dodatkowe opcje
-Wall -pedantic -g
-std=c++11 -lpthread -lcurl

# Library
-L<path>

# Includes dir
-I<path>

# Library
-l<libName>

# Z nazwą objektu
g++ -Wall -pedantic -g -c main.cpp -o main.o
```


### Openssl dev
```sh
# Z bibliotekami openssl
# sudo apt install libcrypto++-dev
# sudo apt install libssl-dev
g++ ssl_client.c -L/usr/lib -lssl -lcrypto -o client-app -std=c++11
```

### Plik wykonywalny
```bash
# Utwórz plik wykonywalny
g++ -o main-app main.o Car.o Person.o

# Plik wykonywalny z bibliotekami
g++ main.o Car.o Person.o -o main-app -lsfml-graphics -lsfml-window -lsfml-system -lpthread -std=c++11 -lcurl $(pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4 gl)
```

## Makefile
```bash
CXX = g++
CXXFLAGS = -Wall -g -pedantic
CXXCMD = -std=c++11 -lpthread -lcurl
CXXSFML = -lsfml-graphics -lsfml-window -lsfml-system
CXXGTK = `pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4 gl`
CXXTLS = -L/usr/lib -lssl -lcrypto

all: main-app

main-app: main.o Date.o Num.o
	$(CXX) $(CXXFLAGS) $(CXXGTK) $(CXXSFML) $(CXXCMD) -o main-app main.o Date.o Num.o

main.o: main.cpp Date.h Num.h
	$(CXX) $(CXXFLAGS) $(CXXGTK) $(CXXCMD) -c main.cpp

Date.o: Date.h
Num.o: Num.h

clean:
	rm -rf main-app *.o
```
