# 一、本周工作
1、看无人机代码(附带笔记)

2、联系购买电池


# 二、部分笔记
## 2.1 cmake,CMakeLists.txt,make,makefile的关系
![rgb图]( https://img-blog.csdnimg.cn/c6ce20771a434c678afe8e0c01432a2d.png)
### 2.1.1 各部分作用
CMakeLists.txt的作用：告诉cmake，如何生成makefile

makefile的作用：设置编译规则，项目会按照makefile执行

make的作用：执行makefile，生成可执行文件

### 2.1.2 编译过程
编译的过程大致有两步：
1.cmake
2.make

catkin_make把这两步做了一个封装，一步即可完成。

### 2.1.3 catkin_make
catkin_make编译的是所有功能包，也可以单单指定一个功能包做编译
``` catkin_make --pkg 功能包名```

catkin_make可特别指定读取源文件路径
```catkin_make --source Simulator/gazebo_simulator --build build/prometheus_gazebo```

--source 后面是src路径

-- build 后面是build路径
### 2.1.4 src & build 
![rgb图](https://img-blog.csdnimg.cn/bd5fedbe575645ee9ed573f0140be411.png)


## 2.2 launch 文件
### 2.2.1 roslaunch 命令
（1）roslaunch  功能包名称  launch文件 [参数设置]

roslaunch命令会在对应的功能包中找到名称匹配的launch文件，并执行这个launch文件。如果设置了参数的话，会将参数传入到launch文件中赋给对应的参数。

![rgb图](https://img-blog.csdnimg.cn/bf30ed3a3bea4b479b64d062f1a7151e.png)
![rgb图](https://img-blog.csdnimg.cn/511075890e6b416d9c7154b73655b435.png)

（2）launch 文件

``` 
<launch>
 
    <node pkg="prometheus_demo" type="circular_trajectory_control" name="circular_trajectory_control" output="screen">
        <param name="uav_id" value="1"/>
    </node>
 
</launch>
```
（2.1）node描述了roslaunch运行的节点，选项包括pkg、type和name。

pkg、type、name字段含义如下：
pkg        功能包名称。
  
type       实际运行的节点名。 必须有一个具有相同名称的相应可执行文件

name    与上述type对应的节点被运行时,起的名称(节点启动后的名字，将覆盖ros::init设置的节点名称，不可重复，除非不在同一命名空间下)。一般情况下使用与type相同的名称,但可以根据需要,在运行时更改名称。
 ![rgb图](https://img-blog.csdnimg.cn/3c8e1f4fc992414db1d8b886bd12aa31.png)
 ![rgb图](https://img-blog.csdnimg.cn/0161ae60d82943c08881e624a162e0b1.png)

（2.2）output可以设为‘screen’、‘log’ 以及‘both’
默认情况下，launch 启动 node 的信息会存在/.ros/log/run_id/node_name-number-stdout.log中，通过此处参数设置，可令信息显示在屏幕上

screen   令信息显示在屏幕上

log 输出到日志

both 就是screen和log两个都要。就结果而言，控制台中get_logger()和std::cout的内容都输出了  
 ![rgb图](https://img-blog.csdnimg.cn/9c65c81158fa458e8e6ea727d689a27b.png)

  去除output, 则没有log输出
  
   ![rgb图](https://img-blog.csdnimg.cn/f6990dce5268495cbf7528e4e49399b1.png)

  加上output, 则有log输出
  
  ![rgb图](https://img-blog.csdnimg.cn/7f0ad6d1e6864e6c85008acb962f4412.png)
  
  
  ```
 <launch>
	<!-- Gazebo configs -->
    <arg name="gazebo_enable" default="true"/>
	<arg name="world" default="$(find prometheus_gazebo)/gazebo_worlds/prometheus_empty.world"/>
 
    <!-- 启动Gazebo -->
    <group if="$(arg gazebo_enable)">
        <include file="$(find gazebo_ros)/launch/empty_world.launch">
            <arg name="world_name" value="$(arg world)"/>
        </include>
    </group>
  
 
    <!--无人机编号-->
    <arg name="uav1_id" default="1"/>
	<!-- 无人机初始位置 -->
	<arg name="uav1_init_x" default="0.0"/>
    <arg name="uav1_init_y" default="0.0"/>
    <arg name="uav1_init_yaw" default="0.0"/>
	<arg name="sdf" default="$(find prometheus_gazebo)/gazebo_models/uav_models/multi_p450/p450_uav$(arg uav1_id)/p450_uav$(arg uav1_id).sdf"/>
	<!-- 1号无人机 -->
	<include file="$(find prometheus_gazebo)/launch_basic/sitl_px4_outdoor.launch">
		<arg name="uav_id" value="$(arg uav1_id)"/>
		<arg name="sdf" value="$(arg sdf)"/>
		<arg name="model" value="p450_uav$(arg uav1_id)"/>
		<arg name="uav_init_x" value="$(arg uav1_init_x)"/>
		<arg name="uav_init_y" value="$(arg uav1_init_y)"/>
		<arg name="uav_init_z" value="0.15"/>
		<arg name="uav_init_yaw" value="$(arg uav1_init_yaw)"/>
	</include>
</launch>
  ```
  
（2.3）arg描述了系统运行中所需要的参数。
  
arg中的name表示参数的名称，default表示参数默认的值。如果需要设置别的值，可以在roslaunch命令中加入节点名。
  
  
（2.4） include 将另一个xml格式的launch文件导入到当前文件(实现代代码复用)

  格式：file="$(find 功能包名)/xxx/xxx.launch"

  if=value (optional) 如果value值为真，包含标签及其内容
 unless=value (optional)  除非value为假，包含标签及其内容
  
  

  
  
  
