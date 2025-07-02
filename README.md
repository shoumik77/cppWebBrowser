# cppWebBrowser

A lightweight, tabbed C++ web browser built with Qt 6. It features a custom home page, modern tabbed navigation, and JavaScript execution support. Designed to demonstrate system-level C++ and Qt development with a minimal and clean UI.

---

## Features

- Tabbed browsing with closable tabs  
- URL bar with forward, back, and reload controls  
- Embedded HTML homepage via Qt resource system (`home.html`)  
- JavaScript execution from C++  
- API request capability using `QNetworkAccessManager`  
- Favicon and title updates per tab  
- Lightweight, fast, and designed for modern Qt builds

---

## Requirements

- macOS (Apple Silicon or Intel)  
- Homebrew package manager  
- Xcode Command Line Tools (for `clang++`)  
- Qt 6.9+ installed via Homebrew

---

## Installation Instructions (macOS)

## Install dependencies

Install Qt using Homebrew:

```bash
brew install qt
```

## Structure
```pgsql
CBrowser/
├── main.cpp
├── mainwindow.h / mainwindow.cpp
├── BrowserTab.h / BrowserTab.cpp
├── home.html
├── resources.qrc
├── qrc_resources.cpp (generated)
├── moc_mainwindow.cpp (generated)
├── moc_BrowserTab.cpp (generated)
```

## Build Instructions
```bash
# Clone Repo
git clone https://github.com/shoumik77/cppWebBrowser.git
cd cppWebBrowser

# Generate Qt Resource.cpp file
/opt/homebrew/Cellar/qt/6.9.1/share/qt/libexec/rcc resources.qrc -o qrc_resources.cpp

# Generate MOC Files
/opt/homebrew/Cellar/qt/6.9.1/share/qt/libexec/moc mainwindow.h -o moc_mainwindow.cpp
/opt/homebrew/Cellar/qt/6.9.1/share/qt/libexec/moc BrowserTab.h -o moc_BrowserTab.cpp

# Compile with clange
clang++ main.cpp mainwindow.cpp BrowserTab.cpp \
  moc_mainwindow.cpp moc_BrowserTab.cpp qrc_resources.cpp \
  -std=c++17 -fPIC \
  -I. \
  -I/opt/homebrew/opt/qt/include \
  -I/opt/homebrew/opt/qt/include/QtCore \
  -I/opt/homebrew/opt/qt/include/QtGui \
  -I/opt/homebrew/opt/qt/include/QtWidgets \
  -I/opt/homebrew/opt/qt/include/QtWebEngineWidgets \
  -I/opt/homebrew/opt/qt/include/QtWebEngineCore \
  -I/opt/homebrew/opt/qt/include/QtNetwork \
  -F/opt/homebrew/opt/qt/lib \
  -framework QtCore -framework QtGui -framework QtWidgets \
  -framework QtWebEngineCore -framework QtWebEngineWidgets \
  -framework QtNetwork -framework AppKit -framework Foundation \
  -Wl,-rpath,/opt/homebrew/opt/qt/lib \
  -o browser

# Run
./browser

```

## Running Tests
 - This browser has 50+ automated test cases using the QtTest framework to verify:
    - URL loading success
    - Page load completion
    - API Data fetching
    - Visual validation via QWebEngineView

# Build and Run Tests
```bash
/opt/homebrew/Cellar/qt/6.9.1/share/qt/libexec/moc browser_tests.h -o moc_browser_tests.cpp

clang++ browser_tests.cpp moc_browser_tests.cpp -std=c++17 \
  -I. -I/opt/homebrew/opt/qt/include \
  -F/opt/homebrew/opt/qt/lib \
  -framework QtTest -framework QtCore -framework QtGui -framework QtWidgets \
  -framework QtWebEngineCore -framework QtWebEngineWidgets -framework QtNetwork \
  -Wl,-rpath,/opt/homebrew/opt/qt/lib \
  -o browser-tests

./browser-tests
```


## This project was created to demonstrate:
 - Modern C++ application structure
 - Qt GUI event handling
 - Multi-tabbed browser design
 - Networking with REST API integration
 - WebEngine embedding and JS execution
 - GUI resource packaging with .qrc




## License
 - MIT License

## Author
 - Developed by Shoumik Bisoi
 - GitHub: @shoumik77