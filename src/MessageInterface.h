

#ifndef _MESSAGE_INTERFACE_H_
#define _MESSAGE_INTERFACE_H_

#include <cstdint>
#include <WireFormatter.h>

namespace EmbeddedProto {

class MessageInterface {
public:
    enum class Result {
        OK,
        ERROR_BUFFER_TO_SMALL,
    };

    MessageInterface() = default;

    virtual ~MessageInterface() = default;

    //! Function to serialize this message.
    /*!
        The data this message holds will be serialized into an byte array.

        \param buffer [out] The array of bytes into which the message will be serialized.
        \param length [in]  The number of bytes in the buffer array.

        \return An enum value indicating successful operation of this function or an error.
    */
    virtual Result serialize(uint8_t* buffer, uint32_t length) const = 0;

    //! Function to deserialize this message.
    /*!
        From an array of date fill this message object with data.

        \param buffer [in]  The array of bytes into which the message will be serialized.
        \param length [in]  The number of bytes in the buffer array.

        \return An enum value indicating successful operation of this function or an error.
    */
    virtual Result deserialize(const uint8_t* buffer, uint32_t length) = 0;

    //! Clear the content of this message and set it to it's default state.
    /*!
        The defaults are to be set according to the Protobuf standard.
    */
    virtual void clear() = 0;

    //! Calculate the size of this message when serialized.
    /*!
        \return The number of bytes this message will require once serialized.
    */
    virtual uint32_t serialized_size() const = 0;

protected:


private:


};

} // End of namespace EmbeddedProto

#endif // _MESSAGE_INTERFACE_H_
