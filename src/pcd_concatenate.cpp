#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " input1.pcd input2.pcd output.pcd" << std::endl;
        return -1;
    }

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr mergedCloud(new pcl::PointCloud<pcl::PointXYZ>);

    // Load the first PCD file
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud1) == -1) {
        PCL_ERROR("Couldn't read the first PCD file.\n");
        return -1;
    }

    // Load the second PCD file
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[2], *cloud2) == -1) {
        PCL_ERROR("Couldn't read the second PCD file.\n");
        return -1;
    }

    // Merge the point clouds
    *mergedCloud = *cloud1 + *cloud2;

    // Save the merged point cloud as binary
    if (pcl::io::savePCDFileBinary(argv[3], *mergedCloud) == -1) {
        PCL_ERROR("Couldn't write the output PCD file.\n");
        return -1;
    }

    std::cout << "Successfully merged and saved the point cloud to " << argv[3] << std::endl;
    return 0;
}
