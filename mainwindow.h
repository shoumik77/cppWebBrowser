#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QToolBar>
#include <QWebEngineView>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newTab(const QUrl &url = QUrl("https://www.google.com"));
    void closeCurrentTab(int index);
    void navigateToUrl();
    void updateUrlBar(const QUrl &url);
    void currentTabChanged(int index);

private:
    QLineEdit *urlBar;
    QWebEngineView *view;
    QTabWidget *tabs;
    QWebEngineView* currentWebView();
};

#endif // MAINWINDOW_H
