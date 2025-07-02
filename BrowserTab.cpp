#include "BrowserTab.h"
#include <QMessageBox>

BrowserTab::BrowserTab(QWidget *parent) : QWebEngineView(parent) {}

QWebEngineView* BrowserTab::createWindow(QWebEnginePage::WebWindowType type) {
    Q_UNUSED(type);

    // Block the popup and optionally show a message
    QMessageBox::information(this, "Pop-up Blocked", "A website attempted to open a new window. Pop-ups are blocked.");

    return nullptr;
}
