#include <QApplication>
#include "browser_tests.h"
#include "moc_browser_tests.cpp"
void BrowserTests::initTestCase() {
    qDebug("Starting browser tests...");
}

void BrowserTests::cleanupTestCase() {
    qDebug("Finished browser tests.");
}

void BrowserTests::testUrlLoading() {
    QWebEngineView view;
    QUrl expectedUrl("https://example.com");
    view.setUrl(expectedUrl);

    QSignalSpy loadSpy(&view, &QWebEngineView::loadFinished);
    QVERIFY(loadSpy.wait(5000)); // Wait for page load (5s max)

    QUrl loadedUrl = view.url();
    QVERIFY2(
        loadedUrl.host().contains(expectedUrl.host()),
        qPrintable(QString("Expected host: %1, but got: %2")
                   .arg(expectedUrl.host(), loadedUrl.host()))
    );
}


void BrowserTests::testAPIFetch() {
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://jsonplaceholder.typicode.com/todos/1"));
    QNetworkReply *reply = manager.get(request);

    QSignalSpy spy(reply, &QNetworkReply::finished);
    QVERIFY(spy.wait(3000));

    QVERIFY(reply->error() == QNetworkReply::NoError);
    QByteArray data = reply->readAll();
    QVERIFY(!data.isEmpty());

    delete reply;
}

void BrowserTests::testMultipleUrls_data() {
    QTest::addColumn<QString>("url");

    QStringList urls = {
        "https://www.google.com",
        "https://www.youtube.com",
        "https://www.facebook.com",
        "https://www.amazon.com",
        "https://www.wikipedia.org",
        "https://www.reddit.com",
        "https://www.yahoo.com",
        "https://www.instagram.com",
        "https://www.netflix.com",
        "https://www.twitter.com",
        "https://www.linkedin.com",
        "https://www.microsoft.com",
        "https://www.apple.com",
        "https://www.bing.com",
        "https://www.twitch.tv",
        "https://www.ebay.com",
        "https://www.office.com",
        "https://www.stackoverflow.com",
        "https://www.github.com",
        "https://www.quora.com",
        "https://www.pinterest.com",
        "https://www.paypal.com",
        "https://www.adobe.com",
        "https://www.medium.com",
        "https://www.imdb.com",
        "https://www.dropbox.com",
        "https://www.salesforce.com",
        "https://www.cnn.com",
        "https://www.nytimes.com",
        "https://www.bbc.com",
        "https://www.weather.com",
        "https://www.walmart.com",
        "https://www.tiktok.com",
        "https://www.nike.com",
        "https://www.bestbuy.com",
        "https://www.hulu.com",
        "https://www.roblox.com",
        "https://www.spotify.com",
        "https://www.canva.com",
        "https://www.slack.com",
        "https://www.airbnb.com",
        "https://www.booking.com",
        "https://www.zoom.us",
        "https://www.trello.com",
        "https://www.whatsapp.com",
        "https://www.fandom.com",
        "https://www.figma.com",
        "https://www.docker.com",
        "https://www.heroku.com",
        "https://www.mozilla.org"
    };

    for (const QString &url : urls) {
        QTest::newRow(url.toUtf8().constData()) << url;
    }
}


QString normalizeHost(const QUrl& url) {
    QString host = url.host();
    return host.startsWith("www.") ? host.mid(4) : host;
}

void BrowserTests::testMultipleUrls() {
    QFETCH(QString, url);

    QWebEngineView view;
    view.setUrl(QUrl(url));
    QSignalSpy loadSpy(&view, &QWebEngineView::loadFinished);
    QVERIFY2(loadSpy.wait(7000),
             qPrintable(QString("Timeout loading: %1").arg(url)));

    QUrl loadedUrl = view.url();
    QUrl expectedUrl(url);

    QVERIFY2(
        normalizeHost(loadedUrl) == normalizeHost(expectedUrl),
        qPrintable(QString("Expected host: %1, but got: %2")
                   .arg(normalizeHost(expectedUrl), normalizeHost(loadedUrl)))
    );
}



// ADD THIS
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    BrowserTests tests;
    return QTest::qExec(&tests, argc, argv);
}
