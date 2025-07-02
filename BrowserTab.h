#ifndef BROWSERTAB_H
#define BROWSERTAB_H

#include <QWebEngineView>

class BrowserTab : public QWebEngineView {
    Q_OBJECT

public:
    BrowserTab(QWidget *parent = nullptr);

protected:
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;
};

#endif // BROWSERTAB_H
