/**
 * @Description 人脸识别远程监控的客户端窗体源文件
 * @Version 1.0.0
 * @Date 2024/5/18 15:31
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
// You may need to build the project (run Qt uic code generator) to get "ui_superviseClientWidget.h" resolved

#include "../head/superviseClientWidget.h"
#include "../ui/ui_superviseClientWidget.h"


superviseClientWidget::superviseClientWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::superviseClientWidget) {
    ui->setupUi(this);

    // 设置窗体大小不可变
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

    // 将Label放入容器
    labelJpegs.append(ui->labelJpeg1);
    labelJpegs.append(ui->labelJpeg2);
    labelJpegs.append(ui->labelJpeg3);
    labelJpegs.append(ui->labelJpeg4);

    // 网络管理类对象
    manager = new QNetworkAccessManager(this);
    thread = new QThread(this);
    // 移动线程 不能指定父对象
    detectWork = new FaceDetection;
    // 将工作对象移动到thread线程负责
    detectWork->moveToThread(thread);
    connect(this, SIGNAL(imageAcquired(QImage)),detectWork, SLOT(onFaceDetection(QImage)));
    thread->start();
}

superviseClientWidget::~superviseClientWidget() {
    delete manager;
    manager = nullptr;
    thread->terminate();
    thread->wait();
    delete ui;
}

void superviseClientWidget::onMjpgReadyRead() {
    // 1.接收数据
    mjpgBuffer += mjpgReply->readAll();
    // 2.定义变量保存图片帧的起始标记 开始标记:0xff 0xd8 结束标记:0xff 0xd9
    // 开始标记
    char startFlag[3] = {(char)0xff,(char)0xd8};
    // 结束标记
    char endFlag[3] = {(char)0xff,(char)0xd9};
    // 3.查找发送来的数据流中的图片的起始标记
    // 从0开始查找图片的开始标记 找到返回索引 找不到返回-1
    int startIndex = mjpgBuffer.indexOf(startFlag,0);
    std::cout << "startIndex:" << startIndex << std::endl;
    if(startIndex == -1){
        // 没有找到起始标记
        qDebug() << "没有找到标记";
        mjpgBuffer.clear();
        return;
    }
    // 从开始标记位置向后查找结束标记的位置
    int endIndex = mjpgBuffer.indexOf(endFlag,startIndex);
    if(endIndex == -1){
        // 没有找到结束标记 图片数据还没有接收完毕
        return;
    }
    // 4.视频流中截取一张图片数据
    QByteArray imgBuffer = mjpgBuffer.mid(startIndex,(endIndex - startIndex) + 2);
    // 5.将QByteArray的数据加载到图片QImage中 图片格式位JPG
    bool ret = mjpgImg.loadFromData(imgBuffer,"JPG");
    if (ret == false){
        qDebug() << "图片加载失败";
        mjpgBuffer.clear();
        return;
    }else{
        // 图片加载成功 显示到labelMjpg上
        ui->labelMjpg->setPixmap(QPixmap::fromImage(mjpgImg));
        // 发射信号 进行人脸检测
        emit imageAcquired(mjpgImg);
        mjpgBuffer.clear();
    }

//
//    // 1.接收数据
//    mjpgBuffer += mjpgReply->readAll();
//
//    // 2.定义变量保存图片帧的起始标记和结束标记
//    const QByteArray startFlag = QByteArray::fromHex("FFD8");
//    const QByteArray endFlag = QByteArray::fromHex("FFD9");
//
//    // 3.查找图片的起始标记
//    int startIndex = mjpgBuffer.indexOf(startFlag);
//    std::cout << "startIndex: " << startIndex << std::endl;
//
//    if (startIndex == -1) {
//        // 没有找到起始标记
//        qDebug() << "没有找到起始标记";
//        return;
//    }
//
//    // 4.查找结束标记
//    int endIndex = mjpgBuffer.indexOf(endFlag, startIndex);
//
//    if (endIndex == -1) {
//        // 没有找到结束标记，图片数据还没有接收完毕
//        return;
//    }
//
//    // 5.从视频流中截取一张图片数据
//    QByteArray imgBuffer = mjpgBuffer.mid(startIndex, (endIndex - startIndex) + endFlag.size());
//
//    // 6.将QByteArray的数据加载到图片QImage中，图片格式为JPG
//    if (!mjpgImg.loadFromData(imgBuffer, "JPG")) {
//        qDebug() << "图片加载失败";
//        mjpgBuffer.clear();
//        return;
//    }
//
//    // 7.图片加载成功，显示到labelMjpg上
//    ui->labelMjpg->setPixmap(QPixmap::fromImage(mjpgImg));
//
//    // 8.发射信号进行人脸检测
//    emit imageAcquired(mjpgImg);
//
//    // 9.清除已处理的数据
//    mjpgBuffer.remove(0, endIndex + endFlag.size());



// 1.接收数据
//    mjpgBuffer += mjpgReply->readAll();
//
//    // 2.定义变量保存图片帧的起始标记和结束标记
//    const QByteArray startFlag = QByteArray::fromHex("FFD8");
//    const QByteArray endFlag = QByteArray::fromHex("FFD9");
//
//    // 调试输出缓冲区内容（仅前100字节用于调试）
//    qDebug() << "mjpgBuffer:" << mjpgBuffer.left(100).toHex();
//
//    // 3.查找图片的起始标记
//    int startIndex = mjpgBuffer.indexOf(startFlag);
//    std::cout << "startIndex: " << startIndex << std::endl;
//
//    if (startIndex == -1) {
//        // 没有找到起始标记
//        qDebug() << "没有找到起始标记";
//        return;
//    }
//
//    // 4.查找结束标记
//    int endIndex = mjpgBuffer.indexOf(endFlag, startIndex);
//
//    if (endIndex == -1) {
//        // 没有找到结束标记，图片数据还没有接收完毕
//        return;
//    }
//
//    // 5.从视频流中截取一张图片数据
//    QByteArray imgBuffer = mjpgBuffer.mid(startIndex, (endIndex - startIndex) + endFlag.size());
//
//    // 6.将QByteArray的数据加载到图片QImage中，图片格式为JPG
//    if (!mjpgImg.loadFromData(imgBuffer, "JPG")) {
//        qDebug() << "图片加载失败";
//        mjpgBuffer.clear();
//        return;
//    }
//
//    // 7.图片加载成功，显示到labelMjpg上
//    ui->labelMjpg->setPixmap(QPixmap::fromImage(mjpgImg));
//
//    // 8.发射信号进行人脸检测
//    emit imageAcquired(mjpgImg);
//
//    // 9.清除已处理的数据
//    mjpgBuffer.remove(0, endIndex + endFlag.size());


//    // 1.接收数据
//    QByteArray newData = mjpgReply->readAll();
//    mjpgBuffer += newData;
//
//    // 调试输出缓冲区内容（仅前100字节用于调试）
//    qDebug() << "Received data:" << newData.toHex();
//    qDebug() << "Current buffer:" << mjpgBuffer.left(100).toHex();
//
//    // 2.定义变量保存图片帧的起始标记和结束标记
//    const QByteArray startFlag = QByteArray::fromHex("FFD8");
//    const QByteArray endFlag = QByteArray::fromHex("FFD9");
//
//    // 3.查找图片的起始标记
//    int startIndex = mjpgBuffer.indexOf(startFlag);
//    std::cout << "startIndex: " << startIndex << std::endl;
//
//    if (startIndex == -1) {
//        // 没有找到起始标记
//        qDebug() << "没有找到起始标记";
//        return;
//    }
//
//    // 4.查找结束标记
//    int endIndex = mjpgBuffer.indexOf(endFlag, startIndex);
//
//    if (endIndex == -1) {
//        // 没有找到结束标记，图片数据还没有接收完毕
//        return;
//    }
//
//    // 5.从视频流中截取一张图片数据
//    QByteArray imgBuffer = mjpgBuffer.mid(startIndex, (endIndex - startIndex) + endFlag.size());
//
//    // 调试输出图像数据内容（仅前100字节用于调试）
//    qDebug() << "Extracted image buffer:" << imgBuffer.left(100).toHex();
//
//    // 6.将QByteArray的数据加载到图片QImage中，图片格式为JPG
//    if (!mjpgImg.loadFromData(imgBuffer, "JPG")) {
//        qDebug() << "图片加载失败";
//        mjpgBuffer.remove(0, endIndex + endFlag.size());  // 清除已处理的数据以避免缓冲区过大
//        return;
//    }
//
//    // 7.图片加载成功，显示到labelMjpg上
//    ui->labelMjpg->setPixmap(QPixmap::fromImage(mjpgImg));
//
//    // 8.发射信号进行人脸检测
//    emit imageAcquired(mjpgImg);
//
//    // 9.清除已处理的数据
//    mjpgBuffer.remove(0, endIndex + endFlag.size());

// 1.接收数据
//    QByteArray newData = mjpgReply->readAll();
//    mjpgBuffer += newData;
//
//    // 调试输出缓冲区内容（仅前100字节用于调试）
//    qDebug() << "Received data:" << newData.toHex();
//    qDebug() << "Current buffer:" << mjpgBuffer.left(100).toHex();
//
//    // 检查数据是否以FFD8开头（JPEG图像的起始标记）
//    if (mjpgBuffer.startsWith(QByteArray::fromHex("FFD8"))) {
//        qDebug() << "Received data starts with JPEG start marker (FFD8)";
//    }

// AVI格式
//    // 接收数据
//    QByteArray newData = mjpgReply->readAll();
//    mjpgBuffer += newData;
//
//    // AVI格式的起始和结束标志
//    const QByteArray aviStartFlag = QByteArray::fromHex("52494646"); // "RIFF"
//    const QByteArray aviEndFlag = QByteArray::fromHex("00000000");
//
//    // 查找起始标志
//    int startIndex = mjpgBuffer.indexOf(aviStartFlag);
//    if (startIndex == -1) {
//        // 没有找到起始标志
//        qDebug() << "没有找到起始标志";
//        return;
//    }
//
//    // 查找结束标志
//    int endIndex = mjpgBuffer.indexOf(aviEndFlag, startIndex);
//    if (endIndex == -1) {
//        // 没有找到结束标志，视频数据还没有接收完毕
//        return;
//    }
//
//    // 从视频流中截取一段数据，这里以起始标志为开头，结束标志为结尾
//    QByteArray videoData = mjpgBuffer.mid(startIndex, endIndex + aviEndFlag.size());
//
//    // 处理视频数据，例如保存到文件或进行解码等操作
//    // processVideoData(videoData);
//
//    // 清除已处理的数据
//    mjpgBuffer.remove(0, endIndex + aviEndFlag.size());


// MP4格式
//// 接收数据
//    QByteArray newData = mjpgReply->readAll();
//    mjpgBuffer += newData;
//
//    // MP4 格式的起始和结束标志
//    const QByteArray mp4StartFlag = QByteArray::fromHex("000000186674797069736F6D"); // "....ftypisom"
//    const QByteArray mp4EndFlag = QByteArray::fromHex("00000000");
//
//    // 查找起始标志
//    int startIndex = mjpgBuffer.indexOf(mp4StartFlag);
//    if (startIndex == -1) {
//        // 没有找到起始标志
//        qDebug() << "没有找到起始标志";
//        return;
//    }
//
//    // 查找结束标志
//    int endIndex = mjpgBuffer.indexOf(mp4EndFlag, startIndex);
//    if (endIndex == -1) {
//        // 没有找到结束标志，视频数据还没有接收完毕
//        return;
//    }
//
//    // 从视频流中截取一段数据，这里以起始标志为开头，结束标志为结尾
//    QByteArray videoData = mjpgBuffer.mid(startIndex, endIndex + mp4EndFlag.size());
//
//    // 处理视频数据，例如保存到文件或进行解码等操作
//    // processVideoData(videoData);
//
//    // 清除已处理的数据
//    mjpgBuffer.remove(0, endIndex + mp4EndFlag.size());

//// MOV格式
//    // 接收数据
//    QByteArray newData = mjpgReply->readAll();
//    mjpgBuffer += newData;
//
//    // MOV 格式的起始和结束标志
//    const QByteArray movStartFlag = QByteArray::fromHex("00000014667479706D703432"); // "....ftypmp42"
//    const QByteArray movEndFlag = QByteArray::fromHex("00000000");
//
//    // 查找起始标志
//    int startIndex = mjpgBuffer.indexOf(movStartFlag);
//    if (startIndex == -1) {
//        // 没有找到起始标志
//        qDebug() << "没有找到起始标志";
//        return;
//    }
//
//    // 查找结束标志
//    int endIndex = mjpgBuffer.indexOf(movEndFlag, startIndex);
//    if (endIndex == -1) {
//        // 没有找到结束标志，视频数据还没有接收完毕
//        return;
//    }
//
//    // 从视频流中截取一段数据，这里以起始标志为开头，结束标志为结尾
//    QByteArray videoData = mjpgBuffer.mid(startIndex, endIndex + movEndFlag.size());
//
//    // 处理视频数据，例如保存到文件或进行解码等操作
//    // processVideoData(videoData);
//
//    // 清除已处理的数据
//    mjpgBuffer.remove(0, endIndex + movEndFlag.size());



///*
// * 数据丢失或截断：在您的代码中，您假设了图像的起始标记位于数据流的开头，这意味着您只在数据的开头查找起始标记。
// * 如果数据流中的起始标记之前有数据丢失或者数据截断，您可能会错过起始标记。建议在查找起始标记时从数据流的当前位置开始搜索。
// * */
//
//    // 1.接收数据
//    QByteArray newData = mjpgReply->readAll();
//    mjpgBuffer += newData;
//
//    // 2.定义变量保存图片帧的起始标记和结束标记
//    const QByteArray startFlag = QByteArray::fromHex("FFD8");
//    const QByteArray endFlag = QByteArray::fromHex("FFD9");
//
//    // 3.调试输出缓冲区内容（仅前100字节用于调试）
//    qDebug() << "Received data:" << newData.toHex();
//    qDebug() << "Current buffer:" << mjpgBuffer.left(100).toHex();
//
//    // 4.查找图片的起始标记
//    int startIndex = mjpgBuffer.indexOf(startFlag);
//    qDebug() << "startIndex: " << startIndex;
//
//    while (startIndex != -1) {
//        // 5.查找结束标记
//        int endIndex = mjpgBuffer.indexOf(endFlag, startIndex);
//        if (endIndex == -1) {
//            // 没有找到结束标记，等待更多数据
//            return;
//        }
//
//        // 6.从视频流中截取一张图片数据
//        QByteArray imgBuffer = mjpgBuffer.mid(startIndex, (endIndex - startIndex) + endFlag.size());
//
//        // 7.将QByteArray的数据加载到图片QImage中，图片格式为JPG
//        QImage img;
//        if (!img.loadFromData(imgBuffer, "JPG")) {
//            qDebug() << "图片加载失败";
//        } else {
//            // 8.图片加载成功，显示到labelMjpg上
//            ui->labelMjpg->setPixmap(QPixmap::fromImage(img));
//            // 9.发射信号进行人脸检测
//            emit imageAcquired(img);
//        }
//
//        // 10.清除已处理的数据
//        mjpgBuffer = mjpgBuffer.mid(endIndex + endFlag.size());
//
//        // 11.继续查找下一个起始标记
//        startIndex = mjpgBuffer.indexOf(startFlag);
//    }

}

void superviseClientWidget::on_btnGetMjpg_clicked() {
    // 1.准备请求包 设置URL地址 根据URL自动生成请求包
    request.setUrl(QUrl("http://192.168.65.128:8080?action=stream"));
    // 2.发送请求包 使用Get方式 请求获取视频流数据 返回专门用于接收视频流数据的响应对象
    mjpgReply = manager->get(request);
    // 3.当服务器发送来数据时 触发readyRead()信号的发射
    connect(mjpgReply, SIGNAL(readyRead()),this, SLOT(onMjpgReadyRead()));
}

void superviseClientWidget::on_btnGetJpeg_clicked() {
    // 1.准备请求包 设置url地址 根据url地址自动生成请求包
    request.setUrl(QUrl("http://192.168.65.128:8080?action=snapshot"));
    // 2.发送请求包 使用Get方法请求获取快照数据 返回专门用于接收快照数据的响应对象
    jpegReply = manager->get(request);
    // 3.服务器发来数据触发readyRead()信号的发射
    connect(jpegReply, SIGNAL(readyRead()),this, SLOT(onJpegReadyRead()));
}

void superviseClientWidget::onJpegReadyRead() {
    // 1.接收数据
    jpegBuffer += jpegReply->readAll();
    // 2.定义变量保存图片帧的起始标记 开始标记:0xff 0xd8 结束标记:0xff 0xd9
    // 开始标记
    char startFlag[3] = {(char)0xff,(char)0xd8};
    char endFlag[3] = {(char)0xff,(char)0xd9};
    // 3.查找发送来的数据流中的图片的起始标记
    // 从0开始查找图片的开始标记 找到返回索引 找不到返回-1
    int startIndex = jpegBuffer.indexOf(startFlag,0);
    // 没有找到
    if(startIndex == -1){
        jpegBuffer.clear();
        return;
    }
    // 从开始标记位置向后查找结束标记的位置
    int endIndex = jpegBuffer.indexOf(endFlag,startIndex);
    // 找到开始标记 但没有找到结束标记位置:图片数据还没有接收完毕
    if (endIndex == -1){
        return;
    }
    // 4.从快照数据流中截取一张图片数据
    QByteArray imgBuffer = jpegBuffer.mid(startIndex,(endIndex - startIndex) + 2);
    // 5.将QByteArray的数据加载到图片QImage中 图片格式位JPG
    bool ret = jpegImg.loadFromData(imgBuffer,"JPG");
    if (ret == false){
        jpegBuffer.clear();
        return;
    } else{
        // 加载图片成功 放入在labelJpeg容器的label中
        labelJpegs[m_index]->setPixmap(QPixmap::fromImage(
                jpegImg.scaled(labelJpegs[m_index]->size(),Qt::KeepAspectRatio)));
        m_index = (++m_index) % 4;
        jpegBuffer.clear();
    }
}

