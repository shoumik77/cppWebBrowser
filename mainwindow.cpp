#include "mainwindow.h"
#include <QToolBar>
#include <QLineEdit>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    view = new QWebEngineView(this);
    view->load(QUrl("https://www.google.com"));
    setCentralWidget(view);

    // Create toolbar
    QToolBar *toolbar = addToolBar("Navigation");

    // Back
    QAction *backAction = toolbar->addAction("Back");
    connect(backAction, &QAction::triggered, view, &QWebEngineView::back);

    // Forward
    QAction *forwardAction = toolbar->addAction("Forward");
    connect(forwardAction, &QAction::triggered, view, &QWebEngineView::forward);

    // Reload
    QAction *reloadAction = toolbar->addAction("Reload");
    connect(reloadAction, &QAction::triggered, view, &QWebEngineView::reload);

    // URL bar
    urlBar = new QLineEdit(this);
    urlBar->setPlaceholderText("Enter URL...");
    urlBar->setClearButtonEnabled(true);
    toolbar->addWidget(urlBar);

    connect(urlBar, &QLineEdit::returnPressed, this, &MainWindow::navigateToUrl);
    connect(view, &QWebEngineView::urlChanged, this, &MainWindow::updateUrlBar);
}

void MainWindow::navigateToUrl() {
    QUrl url = QUrl::fromUserInput(urlBar->text());
    view->load(url);
}

void MainWindow::updateUrlBar(const QUrl &url) {
    urlBar->setText(url.toString());
}

MainWindow::~MainWindow() {}
