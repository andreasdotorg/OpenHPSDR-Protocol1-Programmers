#ifndef RECEIVETHREAD_H
#define RECEIVETHREAD_H

#include <sys/types.h>
#if defined(_WIN32) || defined(_WIN64)
#include <winsock2.h>
#else
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <ifaddrs.h>
#endif
#include <QThread>
#include <QUdpSocket>

class ReceiveThread : public QObject {
    Q_OBJECT
public:
    ReceiveThread(QUdpSocket *s,QString myip,QString metis);
    void send(const char* buffer,int length);
    void stop();
signals:
    void eraseCompleted();
    void nextBuffer();
    void timeout();
    void discover();
    void idle();
public slots:
    void readyRead();
private:
    unsigned char buffer[2048];

    QString myip;
    QString metisip;
    QUdpSocket* socket;
};

#endif // RECEIVETHREAD_H
