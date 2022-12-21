# 一、本周工作
1、飞机绕信息楼一圈查看用时(双目)

2、跑数据集，生成点云



# 二、具体细节
## 2.1 飞机绕信息学院用时
7min左右  40G左右
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/30.png)

链接： https://www.bilibili.com/video/BV1mM411U78R/?vd_source=88bceb64b89804ec0cf90b2e004bf688


## 2.2 colmap 跑数据集
### 2.2.0 安装colmap
https://blog.csdn.net/peng_258/article/details/128346706

### 2.2.1 跑网上的数据集
- 数据集1(```9张图片```)

![](https://github.com/AIBluefisher/ComputerVisionDatasets/blob/master/Datasets/ET/et005.jpg)

- 稀疏点云1
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/1.gif)

- 稠密点云1
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/4.gif)
- 重建结果1
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/5.gif)

- 数据集2(```27张图片```)

![](https://github.com/AIBluefisher/ComputerVisionDatasets/blob/master/Datasets/david/B00.jpg)

- 稀疏点云2
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/7.gif)

- 稠密点云2
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/8.gif)
- 重建结果2
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/9.gif)


- 数据集3(```距离自己镜头较远```)
![](https://github.com/AIBluefisher/ComputerVisionDatasets/blob/master/Datasets/cathedral/100_7104.JPG)

- 稀疏点云3
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/15.gif)

- 稠密点云3
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/16.gif)
- 重建结果3
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/17.gif)


### 2.2.2 跑手机制作的数据集
- 手机拍摄照片(36张) | 重建时间(```52min```)
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/32.png)

重建时间

![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/34.png)

- 稀疏点云
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/14.gif)
- 稠密点云
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/11.gif)
- 重建结果
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/12.gif)

### 2.2.3 跑无人机拍摄的数据集
- 无人机拍摄照片(975张)
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/33.png)

- 稀疏点云2 || ```关键帧只有10帧```
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/10.gif)


## 2.3 原因分析
看了colmap的数据集，有相同的特点: ```重建的东西离自己的镜头很近，重建的东西离自己的镜头较远则图片清晰度很高```

所以```数据集清晰度越高，离自己镜头越近，重建效果越好```
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/35.png)

![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/36.png)


### 2.3.1 尝试
将无人机zed相机分辨率改为最大2K(没有我手机分辨率大)，制作数据集跑的时候没有关键帧
 
解决办法：是否可以更换飞机的zed相机，换成更高像素的相机
