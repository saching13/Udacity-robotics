#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"


ros::Publisher motor_command_publisher;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities

bool handleCmdRobotRequest(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res){
    ROS_INFO("Received the sent comamnds");

        geometry_msgs::Twist motor_command;
        
        motor_command.linear.x = req.linear_x;
        motor_command.angular.z = req.angular_z;
        
        motor_command_publisher.publish(motor_command);
        std::cout << "updated value of command is sent";
        res.msg_feedback = "Updated the value of command";
        ROS_INFO_STREAM(res.msg_feedback);

    return true;
}


int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handleCmdRobotRequest);
    ROS_INFO("Ready to send comamnds");
    ros::spin();

    return 0;
}
