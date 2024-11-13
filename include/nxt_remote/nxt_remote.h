#ifndef NXT_REMOTE_H
#define NXT_REMOTE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>

class Nxt_remote
{
    public:
        Nxt_Remote(ros::NodeHandle &nh, ros::NodeHandle &pn);
        void init();
        void update();
        void remote_velocity_cb(geometry_msgs::Twist& msg);

    private:
        ros::Subscriber auto_cmd_vel

        ros::Subscriber button_sub 
        ros::Subscriber remote_cmd_sub

        bool _mode_buttn = false;
        geometry_msgs::Twist _auto_velocity;
        geometry_msgs::Twist _remote_velocity;

};

#endif