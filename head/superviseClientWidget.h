/**
 * @Description 人脸识别远程监控的客户端窗体头文件
 * @Version 1.0.0
 * @Date 2024/5/18 15:31
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef SUPERVISECLIENT_SUPERVISECLIENTWIDGET_H
#define SUPERVISECLIENT_SUPERVISECLIENTWIDGET_H

#include <QWidget>
#include "QVector"
#include "QLabel"
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QUrl"
#include "QThread"
#include "../head/FaceDetection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class superviseClientWidget; }
QT_END_NAMESPACE

class superviseClientWidget : public QWidget {
Q_OBJECT

public:
    explicit superviseClientWidget(QWidget *parent = nullptr);

    ~superviseClientWidget() override;

signals:
    // 剥离图片帧后发送此信号进行人脸检测
    void imageAcquired(QImage);

private slots:

    // 接收到视频流数据 从中剥离一张图片帧
    void onMjpgReadyRead();

    // 获取快照
    void onJpegReadyRead();

    // 获取视频按钮
    void on_btnGetMjpg_clicked();

    // 获取快照按钮
    void on_btnGetJpeg_clicked();

private:
    Ui::superviseClientWidget *ui;

    // 管理整个通信过程
    QNetworkAccessManager *manager;

    // 根据URL生成请求包
    QNetworkRequest request;

    // 获取视频流响应数据包
    QNetworkReply *mjpgReply;

    // 保存视频流响应数据的缓冲区
    QByteArray mjpgBuffer;

    // 保存从视频流中截取的图片
    QImage mjpgImg;

    // 获取快照响应数据包
    QNetworkReply *jpegReply;

    // 保存快照的缓冲区
    QByteArray jpegBuffer;

    // 保存快照图片
    QImage jpegImg;

    // 人脸检测工作线程
    QThread *thread;

    // 人脸检测工作对象
    FaceDetection *detectWork;

    // 保存显示的快照的label
    QVector<QLabel *> labelJpegs;

    // 索引
    int m_index;

};


#endif //SUPERVISECLIENT_SUPERVISECLIENTWIDGET_H
