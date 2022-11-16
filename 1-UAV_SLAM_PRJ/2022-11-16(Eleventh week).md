# 一、本周工作
1、无人机轨迹圆的实现

#  二、工作细节1(仿真逻辑的理解)
## 2.1 仿真时正在运行的节点和话题关系图
```rqt_graph```
![rgb图](https://img-blog.csdnimg.cn/0c41b71e7eaa4d798f8770be29e84b83.png)

## 2.2 查看/uav1/prometheus/fake_rc_in话题输出 
```rostopic echo /uav1/prometheus/fake_rc_in```
![rgb图](https://img-blog.csdnimg.cn/c3290e0a876f48529faefe4b3233c785.png)

无人机遥控器通道

![rgb图](https://img-blog.csdnimg.cn/18d5ff0e0e194fb8a169f2e57d9e7f92.png)

## 2.3 转换为相应的控制状态
![rgb图](https://img-blog.csdnimg.cn/415196f2eafa46899aa9ce6845a093cb.png)


#  三、工作细节2(真机逻辑的更改)
## 3.1 更改仿真的launch文件
![rgb图](https://img-blog.csdnimg.cn/0c41b71e7eaa4d798f8770be29e84b83.png)
(1)将PX4、Gazebo仿真及MAVROS 替换为 真机的MAVROS

(2)修改真实遥控器通道映射



## 3.2









