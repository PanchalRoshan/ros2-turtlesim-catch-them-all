 #include "rclcpp/rclcpp.hpp" //This is a Package
 #include "example_interfaces/msg/string.hpp" // This is a Package

 using namespace std::chrono_literals;
     
    class RobotNewsStationNode : public rclcpp::Node // RobotNewsStation is an object (one particylar node)
    {
    public:
        RobotNewsStationNode() : Node("robot_news_station"), robot_name_("R2D2") // Initialization List here (robot_news_station) is a node
        {
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10); // robot_news is a TOPIC name
            timer_ = this->create_wall_timer(0.5s, std::bind(&RobotNewsStationNode::publishNews, this));
            RCLCPP_INFO(this->get_logger(), "Robot News Station has been started");
        }
     
    private:
        void publishNews() // PublishNews is a function
        {
            auto msg = example_interfaces::msg::String();
            msg.data = std::string("Hi, this is ") + robot_name_ + std::string(" from the robot news station");
            publisher_->publish(msg);
        }
        
        std::string robot_name_;
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
    };
     
    int main(int argc, char **argv)
    {
        rclcpp::init(argc, argv);
        auto node = std::make_shared<RobotNewsStationNode>(); 
        rclcpp::spin(node);
        rclcpp::shutdown();
        return 0;
    }