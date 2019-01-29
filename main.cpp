//#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/viz.hpp>
#include <iostream>

#include <Eigen/Geometry> 
#include <boost/format.hpp>  // for formating strings
#include <pcl/point_types.h> 
#include <pcl/io/pcd_io.h> 
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>

#include "math.h"
#include "limits.h"
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Dense"

#include <ceres/rotation.h>
#include <ceres/problem.h>
#include <ceres/ceres.h>

#include "tinydir.h"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include <typeinfo>
#include <string>
#include <vector>
#include <utility>

#define OUTPUT_NAME "/home/ferdyan/sfm-two-8b10fb671b791e818d12e24157c3ce787849d0b9/Viewer/structures.yml"

using std::cin;
using namespace cv;
using namespace std;
using namespace ceres;
using ceres::AutoDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solve;
using ceres::Solver;

int main( int argc, char** argv )
{
    int i = 0;
    int j = 0;
    int number = 5;
    int x1[100], x2[100], y1[100], y2[100];
    int xx1, xx2, yy1, yy2;
    
    while ( i <= number) {
        string file_name = string("/home/ferdyan/Coba-Viz/bbox/fix1_") + to_string(i) + ".txt";
        j = 0;

        //std::fstream file(string file_name, std::ios_base::in);
        //std::fstream file("/home/ferdyan/Coba-Viz/bbox/fix1_0.txt", std::ios_base::in);
        
        //std::fstream file(file_name.c_str(), ios_base::in);
        ifstream file;
        file.open(file_name);

        cout <<"File name = " << file_name;
        cout << "   i = " << i << endl;
        
        while (file >> yy1 >> xx1 >> yy2 >> xx2)
        {
            //cout << "In the while" << endl;
            cout << "y1 = " << yy1 << " x1 = " << xx1 << " y2 = " << yy2 << " x2 = " << xx2 << endl;
            y1[j] = yy1;
            x1[j] = xx1;
            y2[j] = yy2;
            x2[j] = xx2;
            j++;
        }

        cout << endl;

        cout << "Simpanan j = " << j << endl;
        for (int n = 0; n < j; ++n)
        {
            cout << "y1 = " << y1[n] << " x1 = " << x1[n] << " y2 = " << y2[n] << " x2 = " << x2[n] << endl;
        }

        cout << endl << endl;

        i++;
    }

    /// Once more event loop is stopped
    cout << "Last event loop is over" << endl;
    return 0;
}