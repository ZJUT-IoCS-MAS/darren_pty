# 一、本周工作
1、验证dynslam建图效果(```11.23 ~ 11.25 ```)


# 二、工作细节
## 2.1 建图与重建结果
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/14.png)

视频链接：https://www.bilibili.com/video/BV15R4y1o7Ei/?spm_id_from=333.999.0.0&vd_source=88bceb64b89804ec0cf90b2e004bf688

![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/15.png)

视频链接：https://www.bilibili.com/video/BV1jv4y1279X/?spm_id_from=333.999.0.0&vd_source=88bceb64b89804ec0cf90b2e004bf688

### 2.1.1 建图不完整问题
InfiniTAM has run out of space in the Voxel Block Array 
InfiniTAM在体素阵列中空间不足
![](https://github.com/ZJUT-IoCS-MAS/darren_pty/blob/main/1-UAV_SLAM_PRJ/1-pic/11.png)

- 代码定位
```
float allocatedSizeMiB = scene->localVBA.allocatedSize * sizeof(ITMVoxel) / 1024.0f / 1024.0f;
printf("[Visible: %6d | Used blocks (primary): %8ld/%ld (%.2f%% free)\n" " Used excess list slots: %8ld/%ld | Total allocated size: %.2fMiB]\n",
			tempData->noVisibleBlocks,
			usedBlocks,
			allocatedBlocks,
			percentFree,
			usedExcessEntries,
			allocatedExcessEntries,
			allocatedSizeMiB);
```
- 修改参数

![](https://github.com/ZJUT-IoCS-MAS/darren_pty/blob/main/1-UAV_SLAM_PRJ/1-pic/12.png)





## 2.1.2 深度图的问题
![](https://github.com/ZYJ-Group/darren_pty/blob/main/darren_pty/pic(Ninth%20week)/16.png)




      
      
      
