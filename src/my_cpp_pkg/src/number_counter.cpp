#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"

using namespace std::placeholders;
     
    class NumberCounterNode : public rclcpp::Node 
    {
    public:
        NumberCounterNode() : Node("number_counter"), count_(0)
        {
            publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count",10);
            subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
                                                                                    "number",10,
                                                                                    std::bind(&NumberCounterNode::callbackNumber, this, _1));
            counter_server_ = this->create_service<example_interfaces::srv::SetBool>(
                "reset_counter",
                std::bind(&NumberCounterNode::callbackCounterServer, this, _1, _2));

            RCLCPP_INFO(this->get_logger(), "Number Counter has been started.");
        }
     
    private:
        
        void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
        {
            count_ += msg->data;

            auto out_msg = example_interfaces::msg::Int64();
            out_msg.data = count_;
            publisher_->publish(out_msg);

            //RCLCPP_INFO(this->get_logger(), "%ld", out_msg.data); // I can also use count_ instead of out_msg.data
        }

        void callbackCounterServer(const example_interfaces::srv::SetBool::Request::SharedPtr request,
                                   const example_interfaces::srv::SetBool::Response::SharedPtr response)
        {
            if(request->data){
                count_ = 0;

                response->success = true;
                response->message = "Counter has been reset";

                RCLCPP_INFO(this->get_logger(), "Counter Reset to 0");
            }
            else{
                response->success = false;
                response->message = "Counter was not reset";

                RCLCPP_INFO(this->get_logger(), "Reset request was false.");
            }
        }
        
        int64_t count_;
        rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
        rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
        rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr counter_server_;
    };
     
    int main(int argc, char **argv)
    {
        rclcpp::init(argc, argv);
        auto node = std::make_shared<NumberCounterNode>(); // MODIFY NAME
        rclcpp::spin(node);
        rclcpp::shutdown();
        return 0;
    }