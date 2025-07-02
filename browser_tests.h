#ifndef BROWSER_TESTS_H
#define BROWSER_TESTS_H

#include <QtTest/QtTest>
#include <QWebEngineView>
#include <QSignalSpy>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class BrowserTests : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testUrlLoading();
    void testAPIFetch();
    void testMultipleUrls_data();
    void testMultipleUrls();
};

#endif // BROWSER_TESTS_H
