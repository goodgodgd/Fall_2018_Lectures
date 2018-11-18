#include "self_drive/tb3driver.h"

TB3Driver::TB3Driver(ros::Publisher* _vel_pub)
{
	pubVelo = _vel_pub;
	velMsg.linear.x = 0; velMsg.linear.y = 0; velMsg.linear.z = 0;
	velMsg.angular.x = 0; velMsg.angular.y = 0; velMsg.angular.z = 0;
}

void TB3Driver::ldsCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
	// copy before processing for data time sync
	curScan = *scan;
	velMsg = selfDrive(curScan);
	publishVelocity();
}

geometry_msgs::Twist TB3Driver::selfDrive(const sensor_msgs::LaserScan& scan)
{
	geometry_msgs::Twist vel;
	vel.linear.x = 0; vel.linear.y = 0; vel.linear.z = 0;
	vel.angular.x = 0; vel.angular.y = 0; vel.angular.z = 0;

	// TODO: write some algorithm to move to target avoding obstacles

	return vel;
}

void TB3Driver::publishVelocity()
{
	pubVelo->publish(velMsg);
}
