/**
 * @Description 人脸识别接口 头文件
 * @Version 1.0.0
 * @Date 2024/5/18 15:47
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef SUPERVISECLIENT_FACEDETECTION_H
#define SUPERVISECLIENT_FACEDETECTION_H

#include "QObject"
#include "opencv2/opencv.hpp"
#include "iostream"
#include "QImage"
#include "QDebug"

using namespace cv;


class FaceDetection : public QObject{
    Q_OBJECT
public:
    explicit FaceDetection(QObject *parent = nullptr);

public slots:
    // 人脸识别
    void onFaceDetection(QImage img);

};


#endif //SUPERVISECLIENT_FACEDETECTION_H
