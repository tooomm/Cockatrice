#ifndef PICTURE_LOADER_WORKER_WORK_H
#define PICTURE_LOADER_WORKER_WORK_H

#include "../../../game/cards/card_database.h"
#include "picture_loader_worker.h"
#include "picture_to_load.h"

#include <QLoggingCategory>
#include <QMutex>
#include <QNetworkAccessManager>
#include <QObject>
#include <QThread>

#define REDIRECT_HEADER_NAME "redirects"
#define REDIRECT_ORIGINAL_URL "original"
#define REDIRECT_URL "redirect"
#define REDIRECT_TIMESTAMP "timestamp"
#define REDIRECT_CACHE_FILENAME "cache.ini"

inline Q_LOGGING_CATEGORY(PictureLoaderWorkerWorkLog, "picture_loader.worker");

class PictureLoaderWorker;
class PictureLoaderWorkerWork : public QThread
{
    Q_OBJECT
public:
    explicit PictureLoaderWorkerWork(const PictureLoaderWorker *worker, const CardInfoPtr &toLoad);
    ~PictureLoaderWorkerWork() override;

    PictureToLoad cardToDownload;

public slots:
    void picDownloadFinished(QNetworkReply *reply);
    void picDownloadFailed();

private:
    static QStringList md5Blacklist;
    QThread *pictureLoaderThread;
    QNetworkAccessManager *networkManager;
    bool picDownload, downloadRunning, loadQueueRunning;

    void startNextPicDownload();
    bool imageIsBlackListed(const QByteArray &);

private slots:
    void picDownloadChanged();

signals:
    void startLoadQueue();
    void imageLoaded(CardInfoPtr card, const QImage &image);
    void requestImageDownload(const QUrl &url, PictureLoaderWorkerWork *instance);
};

#endif // PICTURE_LOADER_WORKER_WORK_H
