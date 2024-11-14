#ifndef NXT_REMOTE_H
#define NXT_REMOTE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>

class Nxt_Remote
{
    public:
        Nxt_Remote(ros::NodeHandle &nh, ros::NodeHandle &pn);
        void init();
        void update();
        void autoVelCallback(const geometry_msgs::TwistConstPtr msg);
        void remoteVelCallback(const geometry_msgs::TwistConstPtr msg);
        void modeCallback(const std_msgs::Int32ConstPtr msg);


    private:

        ros::Publisher _cmd_vel_pub;
        ros::Subscriber _auto_vel_sub;

        ros::Subscriber _button_sub;
        ros::Subscriber _remote_vel_sub;

        bool _mode_buttn = false;
        geometry_msgs::Twist _auto_velocity;
        geometry_msgs::Twist _remote_velocity;
        std_msgs::Int32 _mode;

};

#endif