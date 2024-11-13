#include "nxt_remote/nxt_remote.h"

Nxt_Remote::Nxt_Remote(ros::NodeHandle &nh, ros::NodeHandle &pn)
{
    std::string topic_remote_vel, topic_remote_button topic_auto, topic_choice_vel;
    std::string topic_remote_vel, topic_remote_button topic_auto, topic_choice_vel;
    pn.param<std::string>("remote_vel_topic", topic_remote_vel, "remote_vel_topic");
    pn.param<std::string>("auto_vel_topic", topic_auto, "auto_vel_topic");
    pn.param<std::string>("remote_button_topic", topic_remote, "remote_button_topic");

    _button_sub = nh.subscribe(topic_remote_vel, 10, &Nxt_Remote::laser_cb, this);
    _remote_vel_sub = nh.subscribe(topic_remote_vel, 10, &Nxt_Remote::laser_cb, this);
    _cmd_vel_pub = nh.advertise<geometry_msgs::Twist>(topic_choice_vel, 10);
}

Nxt_Remote::autoVelCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    _auto_velocity = *msg;
}

void remoteVelCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    _remote_velocity = *msg;
}

void modeCallback(const std_msgs::Int32::ConstPtr& msg)
{
    _mode = msg->data;
}

void update()
{
    geometry_msgs::Twist cmd_vel;

    if (_mode == 0) {
        cmd_vel = _auto_velocity;  // 自動モードの速度指令を使用
    } else {
        cmd_vel = _remote_velocity;  // リモートモードの速度指令を使用
    }

    // 選択した速度指令を送信
    _cmd_vel_pub.publish(cmd_vel);
}
