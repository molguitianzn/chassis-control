#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <ros/ros.h>
#include <string>
#define robotNumMax 100 // max number support

ros::Publisher pub_estimate_pose[robotNumMax];
int robotNum = 0;
void GetPoseEstimate(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr &initial)
{
    static int time = 0;
    pub_estimate_pose[time % robotNum].publish(*initial);
    time += 1;
    if (time >= robotNum)
    {
        time = 0;
    }
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "set_estimate_pose");
    if (argc != 2)
    {
        ROS_ERROR("please input the number of robots!");
        return 0;
    }
    else if (atoi(argv[1]) > robotNumMax)
    {
        ROS_ERROR("too many robots! max number: %d", robotNumMax);
        return 0;
    }
    robotNum = atoi(argv[1]);
    ROS_INFO("set_estimate_pose OK! robotNum: %d", robotNum);
    ros::NodeHandle nh;
    std::string pub_topic_prefix = "/robot", pub_topic_suffix = "/initialpose", pub_topic = "";
    for (int i = 0; i < robotNum; i++)
    {
        pub_topic = pub_topic_prefix + std::to_string(i + 1) + pub_topic_suffix;
        pub_estimate_pose[i] = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>(pub_topic, 10);
    }
    ros::Subscriber sub_rviz_2d_pose_estimate = nh.subscribe<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1, GetPoseEstimate);
    ros::spin();
}