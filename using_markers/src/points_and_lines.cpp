#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include <cmath>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "points_and_lines");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

  ros::Rate r(1);

  while (ros::ok())
  {
    visualization_msgs::Marker points, line_strip, line_list;
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "livox_frame";
    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_list.ns = "points_and_lines";
    points.action = line_list.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_list.pose.orientation.w = 1.0;



    points.id = 0;
    line_list.id = 1;



    points.type = visualization_msgs::Marker::POINTS;
    line_list.type = visualization_msgs::Marker::LINE_LIST;

    line_list.scale.x = 0.1;
    line_list.color.r = 1.0;
    line_list.color.a = 1.0;


    geometry_msgs::Point p;
    p.x = 0;
    p.y = 0;
    p.z = 0;

    line_list.points.push_back(p);
    p.x += 26.0;
    line_list.points.push_back(p);

    marker_pub.publish(line_list);
    r.sleep();
  }
}
