    #include "rclcpp/rclcpp.hpp"
    #include "my_robot_interfaces/msg/led_panel_state.hpp"
    #include "my_robot_interfaces/srv/set_led.hpp"

    using namespace std::chrono_literals;
    using namespace std::placeholders;
     
    class LedPanelNode : public rclcpp::Node // MODIFY NAME
    {
    public:
        LedPanelNode() : Node("led_panel"), led_states_(3, 0)
        {
            led_panel_publisher_ = this->create_publisher<my_robot_interfaces::msg::LedPanelState>("led_panel_state", 10);

            timer_ = this->create_wall_timer(
                                            1s,
                                            std::bind(&LedPanelNode::PublisherLedPanel, this));

            led_panel_service = this->create_service<my_robot_interfaces::srv::SetLed>("set_led",
                                                                                        std::bind(&LedPanelNode::CallbackLedPanel, this, _1, _2));

            RCLCPP_INFO(this->get_logger(), "LED Panel Node has benn started");
        }
     
    private:

        void PublisherLedPanel()
        {
            auto msg = my_robot_interfaces::msg::LedPanelState();
            msg.leds = led_states_;
            led_panel_publisher_->publish(msg);
        }

        void CallbackLedPanel(const my_robot_interfaces::srv::SetLed::Request::SharedPtr request,
                              const my_robot_interfaces::srv::SetLed::Response::SharedPtr response)
        {
            int64_t led_number = request->led_number;
            int64_t state = request->state;

            if(led_number>=(int64_t)led_states_.size() || led_number<0){
                response->success = false;
                return;
            }

            if(state!=0 && state!=1){
                response->success = false;
                return;
            }

            led_states_.at(led_number)=state;
            response->success = true;
            PublisherLedPanel();

        }

        std::vector<int64_t> led_states_;

        rclcpp::Publisher<my_robot_interfaces::msg::LedPanelState>::SharedPtr led_panel_publisher_;
        rclcpp::Service<my_robot_interfaces::srv::SetLed>::SharedPtr led_panel_service;
        rclcpp::TimerBase::SharedPtr timer_;
    };
     
    int main(int argc, char **argv)
    {
        rclcpp::init(argc, argv);
        auto node = std::make_shared<LedPanelNode>(); // MODIFY NAME
        rclcpp::spin(node);
        rclcpp::shutdown();
        return 0;
    }