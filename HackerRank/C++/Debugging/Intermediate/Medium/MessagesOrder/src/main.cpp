#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message final
{
public:
    Message() = default;
    explicit Message(const std::string &text_, const int serial_ = 0)
        : i_serial {serial_}, s_text {text_} {}
    Message(const Message &other) = default;
    Message(Message &&other) = default;

    ~Message() = default;

    Message &operator= (const Message &other) = default;
    Message &operator= (Message &&other) = default;

    const std::string &get_text()
    {
        return s_text;
    }

    bool operator< (const Message &other) const
    {
        return i_serial < other.i_serial;
    }

private:
    int i_serial {0};
    std::string s_text;
};

class MessageFactory final
{
public:
    MessageFactory() = default;
    MessageFactory(const MessageFactory &other) = default;
    MessageFactory(MessageFactory &&other) = default;

    ~MessageFactory() = default;

    MessageFactory &operator= (const MessageFactory &other) = default;
    MessageFactory &operator= (MessageFactory &&other) = default;

    Message create_message(const std::string &text_) {
        return Message(text_, i_currMsgSerial++);
    }

private:
    int i_currMsgSerial {0};
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
