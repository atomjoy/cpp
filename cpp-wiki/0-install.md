## Instalacja g++ (c++) debian

### Instalacja g++, make
```bash
sudo apt update
sudo apt install build-essential gdb
sudo apt install manpages-dev

# Test install
whereis g++ make
g++ --version
make --version
```

### Instalacja Gtk+
```bash
# Gtk
sudo apt install libgtk-3-dev
sudo apt-get install libgtkmm-3.0-dev
```

### Instalacja biblioteki curl
```bash
# Curl lib
sudo apt install libcurl4-openssl-dev
sudo apt-get install libcurl4-gnutls-dev
```

### Instalacja SFML
```bash
# SFML C++ 11
sudo apt install libsfml-dev
sudo apt install mesa-utils

# OpenGl
sudo glxinfo | grep "OpenGL version"
```

### Instalacja Tls/Ssl, openssl
```sh
sudo apt install libssl-dev
sudo apt install libcrypto++-dev
```

### Links
 - https://www.sfml-dev.org/tutorials/2.5/start-linux.php
 - https://github.com/SFML/SFML/wiki/Source:-Bouncing-ball
 - https://web.stanford.edu/class/cs193d/handouts/make.pdf
 - http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/SeparateCompilation.pdf
 - https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
 - https://www.cs.bu.edu/teaching/cpp/writing-makefiles
