#include "message.h"
#include <gtest/gtest.h>

TEST(MessageTest, encode_decode)
{
    Message original_message;
    original_message.type = Type::READ;
    original_message.sender = "Alice";
    original_message.receiver = "Bob";
    original_message.contents = "Hello, World!";

    std::vector<uint8_t> encoded = Message::encode(original_message);

    ASSERT_THROW(Message::decode(encoded.data(), 1), std::runtime_error);

    Message decoded_message = Message::decode(encoded.data(), encoded.size());

    EXPECT_EQ(static_cast<int>(original_message.type), static_cast<int>(decoded_message.type));
    EXPECT_EQ(original_message.sender, decoded_message.sender);
    EXPECT_EQ(original_message.receiver, decoded_message.receiver);
    EXPECT_EQ(original_message.contents, decoded_message.contents);
}

TEST(MessageTest, invalid_decode)
{
    std::vector<uint8_t> invalid_encoded_message;

    // Invalid input
    invalid_encoded_message = {0x00, 0x00};

    ASSERT_THROW(Message::decode(invalid_encoded_message.data(), invalid_encoded_message.size()), std::runtime_error);

    // Incorrect magic number
    invalid_encoded_message = {0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05};

    ASSERT_THROW(Message::decode(invalid_encoded_message.data(), invalid_encoded_message.size()), std::runtime_error);

    // Incomplete message
    invalid_encoded_message = {0xAE, 0x73, 0x01, 0x02, 0x02, 0x00, 0x02};

    ASSERT_THROW(Message::decode(invalid_encoded_message.data(), invalid_encoded_message.size()), std::runtime_error);
}

TEST(MessageTest, type_to_string)
{
    EXPECT_EQ("READ", type_to_str(Type::READ));
    EXPECT_EQ("CREATE", type_to_str(Type::CREATE));
    EXPECT_EQ("RESPONSE", type_to_str(Type::RESPONSE));
    EXPECT_EQ("", type_to_str(static_cast<Type>((int)Type::RESPONSE + 1)));
    EXPECT_EQ("", type_to_str(static_cast<Type>((int)Type::READ - 1)));
}
