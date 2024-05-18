/**
 * @Description 人脸识别接口 源文件
 * @Version 1.0.0
 * @Date 2024/5/18 15:47
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#include "../head/FaceDetection.h"

FaceDetection::FaceDetection(QObject *parent) : QObject(parent) {

}

void FaceDetection::onFaceDetection(QImage img) {
    // 将图像转成为RGB24位
    QImage image = img.convertToFormat(QImage::Format_RGB888);
    // 将QImage格式转换成Mat格式
    Mat matImg = Mat(image.height(), image.width(), CV_8UC3,image.bits(),image.bytesPerLine());
    // 将图片进行灰度处理
    Mat imgGray;
    cvtColor(matImg,imgGray, COLOR_RGB2GRAY);
    std::cout << cvtColor << std::endl;
    // 加载分类器
    CascadeClassifier faceDetector;
    std::string detectPath = "../resource/haarcascade_frontalface_default.xml";
    faceDetector.load(detectPath);
    std::vector<Rect> faces;
    // 直方图均衡化
    equalizeHist(imgGray,imgGray);
    // 多尺寸检测人脸
    faceDetector.detectMultiScale(imgGray,faces,1.1,3,0,Size(30,30));
    if (!faces.empty()){
        QString str = "检测到有:" + QString::number(faces.size()) + "人进入监控区域";
        qDebug() << str;
    }
}

