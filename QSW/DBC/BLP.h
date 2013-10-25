#ifndef BLP_H
#define BLP_H

#include <QImage>

#define BLP_MAGIC "BLP2"

struct BLPHeader
{
    char magic[4];
    quint32 type;
    quint8 compression;
    quint8 alphaDepth;
    quint8 alphaType;
    quint8 hasMips;
    quint32 width;
    quint32 height;
    quint32 mipmapOffset[16];
    quint32 mipmapLength[16];
};

class BLP : public QObject
{
    Q_OBJECT

    public:
        BLP() {}

        QImage getImage(const QString &fileName);

        QByteArray m_data;
        BLPHeader *m_header;
};

#endif
