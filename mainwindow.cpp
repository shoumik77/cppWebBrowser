#include "mainwindow.h"
#include "BrowserTab.h"
#include <QToolBar>
#include <QAction>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create toolbar
    QToolBar *toolbar = addToolBar("Navigation");

    QAction *back = toolbar->addAction("Back");
    QAction *forward = toolbar->addAction("Forward");
    QAction *reload = toolbar->addAction("Reload");

    urlBar = new QLineEdit(this);
    urlBar->setPlaceholderText("Enter URL...");
    toolbar->addWidget(urlBar);

    QAction *newTabAction = toolbar->addAction("New Tab");
    QAction *runJSAction = toolbar->addAction("Run JS");
    connect(runJSAction, &QAction::triggered, this, &MainWindow::runJSInCurrentTab);

    // Tabs
    tabs = new QTabWidget(this);
    tabs->setTabsClosable(true);
    setCentralWidget(tabs);

    connect(tabs, &QTabWidget::tabCloseRequested, this, &MainWindow::closeCurrentTab);
    connect(tabs, &QTabWidget::currentChanged, this, &MainWindow::currentTabChanged);
    connect(urlBar, &QLineEdit::returnPressed, this, &MainWindow::navigateToUrl);
    connect(newTabAction, &QAction::triggered, this, [=]() { newTab(); });

    connect(back, &QAction::triggered, this, [=]() {
        if (auto *view = currentWebView()) view->back();
    });

    connect(forward, &QAction::triggered, this, [=]() {
        if (auto *view = currentWebView()) view->forward();
    });

    connect(reload, &QAction::triggered, this, [=]() {
        if (auto *view = currentWebView()) view->reload();
    });

    // Start with one tab
    newTab();
}

MainWindow::~MainWindow() {}

void MainWindow::newTab(const QUrl &url) {
    BrowserTab *view = new BrowserTab;
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::handleAPIResponse);

    if (url.isEmpty()) {
        view->load(QUrl("qrc:/home.html"));  // Embedded HTML via .qrc
    } else {
        view->load(url);
    }

    int index = tabs->addTab(view, "New Tab");
    tabs->setCurrentIndex(index);

    connect(view, &QWebEngineView::titleChanged, this, [=](const QString &title) {
        tabs->setTabText(index, title);
    });

    connect(view, &QWebEngineView::iconChanged, this, [=](const QIcon &icon) {
        tabs->setTabIcon(index, icon);
    });

    connect(view, &QWebEngineView::urlChanged, this, &MainWindow::updateUrlBar);
}


void MainWindow::closeCurrentTab(int index) {
    if (tabs->count() > 1)
        tabs->removeTab(index);
}

QWebEngineView* MainWindow::currentWebView() {
    return qobject_cast<QWebEngineView*>(tabs->currentWidget());
}

void MainWindow::navigateToUrl() {
    QUrl url = QUrl::fromUserInput(urlBar->text());
    if (auto *view = currentWebView())
        view->load(url);
}

void MainWindow::updateUrlBar(const QUrl &url) {
    urlBar->setText(url.toString());
}

void MainWindow::currentTabChanged(int index) {
    if (auto *view = qobject_cast<QWebEngineView*>(tabs->widget(index)))
        urlBar->setText(view->url().toString());
}

void MainWindow::fetchAPI() {
    QUrl url("https://jsonplaceholder.typicode.com/todos/1");
    QNetworkRequest request(url);
    manager->get(request);
}

void MainWindow::handleAPIResponse(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QString data = reply->readAll();
        QMessageBox::information(this, "API Response", data);
    } else {
        QMessageBox::warning(this, "Error", reply->errorString());
    }
    reply->deleteLater();
}

void MainWindow::runJSInCurrentTab() {
    QWebEngineView *view = qobject_cast<QWebEngineView *>(tabs->currentWidget());
    if (view) {
        view->page()->runJavaScript("alert('This JS ran from C++');");
    }
}


