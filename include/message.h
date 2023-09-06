#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <vector>
#include <string>
#include <sstream>

enum class Type
{
    READ,
    CREATE,
    RESPONSE
};

std::string type_to_str(Type type);

struct Message
{
    Type type;
    std::string sender;
    std::string receiver;
    std::string contents;

    static std::vector<uint8_t> encode(const Message &message);
    static Message decode(const uint8_t *message, size_t len);

    std::string to_string() const
    {
        std::stringstream ss;
        ss << "Type: " << type_to_str(type) << std::endl
           << "Sender: " << sender << std::endl
           << "Receiver: " << receiver << std::endl
           << "Contents: " << contents;

        return ss.str();
    }

private:
    static constexpr uint16_t MAGIC_NUMBER = 0xAE73;
};

#endif // __MESSAGE_H__