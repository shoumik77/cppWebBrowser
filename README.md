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

### 1. Install dependencies

Install Qt using Homebrew:

```bash
brew install qt

### Project Structure
pgsql
Copy
CBrowser/
├── main.cpp
├── mainwindow.h / mainwindow.cpp
├── BrowserTab.h / BrowserTab.cpp
├── home.html
├── resources.qrc
├── qrc_resources.cpp (generated)
├── moc_mainwindow.cpp (generated)
├── moc_BrowserTab.cpp (generated)

### Build Instructions
### 1. Clone the repository
bash
Copy
git clone https://github.com/shoumik77/cppWebBrowser.git
cd cppWebBrowser
### 2. Generate Qt Resource .cpp file
bash
Copy
/opt/homebrew/Cellar/qt/6.9.1/share/qt/libexec/rcc resources.qrc -o qrc_resources.cpp
### 3. Generate MOC files
bash
Copy
/opt/homebrew/Cellar/qt/6.9.1/share/qt/libexec/moc mainwindow.h -o moc_mainwindow.cpp
/opt/homebrew/Cellar/qt/6.9.1/share/qt/libexec/moc BrowserTab.h -o moc_BrowserTab.cpp
### 4. Compile the project
bash
Copy
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
### 5. Run the application
bash
Copy
./browser
$$ Notes for Reviewers
$$ This project was created to demonstrate:

$$ Modern C++ application structure

$$ Qt GUI event handling

$$ Multi-tabbed browser design

$$ Networking with REST API integration

$$ WebEngine embedding and JS execution

$$ GUI resource packaging with .qrc

It is a standalone native desktop application and can be extended with features like bookmarks, history, and WebGL support.

Troubleshooting
QWebEngine headers not found?
Make sure Qt was installed via Homebrew and paths are correct.

vtable errors?
Regenerate .cpp files using moc as shown above.

JavaScript not executing?
Make sure QWebEnginePage::runJavaScript() is called on the current tab.

License
MIT License

Author
Developed by Shoumik Bisoi
GitHub: @shoumik77

