#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "pupperstatecontroller/ik.h"
#include "pupperstatecontroller/config.h"

using namespace std::chrono_literals;

class PupperController : public rclcpp::Node
{
public:
    PupperController() : Node("pupper_controller"), count_(0)
    {   
        publisher_ = this->create_publisher<std_msgs::msg::String>("pupper_state", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&PupperController::timer_cb, this)
        );
    }

private:
    void timer_cb()
    {
        auto msg = std_msgs::msg::String();
        msg.data = "Pupper state!"; 
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
        publisher_->publish(msg);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PupperController>());
    rclcpp::shutdown();
    return 0;
}