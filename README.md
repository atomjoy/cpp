## G++
Programowanie w C++ (g++ linux curl, opengl, sfml, thread).

### Instalacja
https://github.com/moovspace/cpp/blob/master/cpp-wiki/0-install.md

### Kompilacja
https://github.com/moovspace/cpp/blob/master/cpp-wiki/1-compile.md
```bash
# Kompiluj
sudo g++ -c main.cpp
# Lub
sudo g++ -c main.cpp -o main.o

# Plik wykonywalny
g++ -o main-app main.o

# Uruchom
./main-app
```

### Kompilacja parametry
```bash
# Błędy, debugowanie
-g -Wall -pedantic 

# Import bibliotek
-std=c++11 -lpthread -lcurl -I. -L.

# Import gtk
`pkg-config --cflags --libs gtk+-3.0 gtkmm-3.0 giomm-2.4 gl`

# Import SFML
-lsfml-graphics -lsfml-window -lsfml-system
```

### Przykład kodu
```cpp
/*
Kompilacja
sudo g++ -c main.cpp -std=c++11 -lpthread
sudo g++ -o main-app main.o -std=c++11 -lpthread
./main-app

Lub
sudo g++ main.cpp -std=c++11 -pthread -o main-app
*/
#include <iostream>
#include <thread>
#include <chrono>

//This function will be called from a thread
void call_from_thread(int n) {  
  // std::this_thread::sleep_for(std::chrono::milliseconds(200));
  std::this_thread::sleep_for(std::chrono::seconds(n));
  std::cout << "Hello, World from thread " << n << std::endl;
}
 
int main() {
  
  std::cout << "Hello, World from main thread " << std::endl;
  
  //Launch a thread
  std::thread t1(call_from_thread, 1);
  std::thread t2(call_from_thread, 2);
 
  //Join the thread with the main thread
  t1.join();
  t2.join();
  
  std::cout << "Bye, from main thread " << std::endl;
  
  return 0;
}
```

### Przykład pliku Makefile
nano Makefile
```bash
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
```

### Uruchom Makefile
```bash
# Uruchom kompilację
sudo make

# Wyczyść
sudo make clean
```

### Visual Code C++ Run Task konfig
https://github.com/moovspace/cpp/blob/master/.vscode/tasks.json
```.json
// See https://go.microsoft.com/fwlink/?LinkId=733558
// for the documentation about the tasks.json format
// ${fileDirname}
// ${fileBasenameNoExtension}
// ${workspaceFolderBasename}
    
{    
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "BUILD NOW",
            "command": "g++",
            "args": [
                "-g",
                "-Wall",
                "-pedantic",
                "${file}",
                "-o",
                "${fileBasenameNoExtension}"
            ],
            "problemMatcher": [],
            "group": "build"
        },
        {
            "type": "shell",
            "label": "RUN NOW",
            "command": "./${fileBasenameNoExtension}",
            "dependsOn": [
                "BUILD NOW"
            ],
            "problemMatcher": []
        }
    ]
}
```
