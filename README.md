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
