#include "nxt_remote/nxt_remote.h"


int main(int argc, char **argv)
{
   ros::init(argc, argv, "nxt_remote_node");
   ros::NodeHandle nh;
   ros::NodeHandle pn("~");


   int frequency;
   pn.param<int>("frequency", frequency, 20);


   ros::Rate loop_rate(frequency);


   Nxt_Remote nxt(nh, pn);


   while(ros::ok())
   {
       nxt.update();
       ros::spinOnce();
       loop_rate.sleep();
   }


   return 0;
}
