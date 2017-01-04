#ifndef DICTCCIMPORTWORKER_H
#define DICTCCIMPORTWORKER_H

#include <QMap>
#include <QThread>
#include <QSqlDatabase>
#include <QString>
#include <QTextStream>

class DictCCImportWorker : public QThread
{
    Q_OBJECT
    void run() Q_DECL_OVERRIDE {
        importDictionaries();
        emit importFinished();
    }
signals:
        void importFinished();
        void statusChanged(const QString &statusText);
private:

    void importDictionaries();
    void readFile(QString &completeFileName);
    QMap<QString,QString> getMetadata(QTextStream &inputStream);
    void writeDictionary(QTextStream &inputStream, QMap<QString,QString> &metadata);
    void writeMetadata(QMap<QString,QString> &metadata, QSqlDatabase &database);
    void writeDictionaryEntries(QTextStream &inputStream, QMap<QString,QString> &metadata, QSqlDatabase &database);
    QString getTempDirectory();
    QString getDirectory(const QString &directoryString);
};

#endif // DICTCCIMPORTWORKER_H
