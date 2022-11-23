#include <iostream>
#include <vector>
// #include <io.h>
#include <string>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(int argc, char** argv) {
    string path = "/expand/Lx/DynSLAM/data/right_rect";         //此处替换为自己的图片序列
    string write_path = "/expand/Lx/DynSLAM/data/kitti/pty_test1/test1/image_03/0006";
    vector<String> src_name;
    glob(path,src_name, false);    //调用opencv中的glob函数，将遍历路径path，将该路径下的全部文件名的绝对路径存进src_name,如/home/chuyi/xingqiu/homework/homework1/rgb/001.png
    if (src_name.size() == 0)
    {
        cerr << "That's no file in " << path <<endl;
        exit(1);
    }
    for (int i = 0; i < src_name.size(); ++i) {
        Mat image = imread(src_name[i]);
        if (image.empty())
        {
            cerr << "Read image " << src_name[i] << " failed!";
            exit(1);
        }
        //imshow("test", image);
        //waitKey(0);
        string new_name = write_path + format("/%06d",i) + ".png";     //控制输出为6位整数并在前面补0
        //cout << new_name <<endl;
        imwrite(new_name, image);
        if (remove(src_name[i].c_str()))       //删除源图片
        {
            cerr << "Delete " << src_name[i] << " failed" << endl;
        }
        cout << "Renaming " << src_name[i] << " to " << new_name <<endl;
    }
    cout << "Totally rename " << src_name.size() << " pictures!" <<endl;
    return 0;
}

