#include <rtthread.h>

#include "amessage.h"
#include "UartReadBuffer.h"
#include "UartWriteBuffer.h"

AMessage encode_msg;
AMessage decode_msg;

UartReadBuffer  read_buffer;
UartWriteBuffer write_buffer;

int encode_decode(int argc, char const *argv[])
{
	encode_msg.set_a(20);
	encode_msg.set_b(10);

	rt_kprintf("---- Encoding ---\n");
	rt_kprintf("a=%ld, b=%ld\n", encode_msg.a(), encode_msg.b());

	auto serialization_status = encode_msg.serialize(write_buffer);
	if(::EmbeddedProto::Error::NO_ERRORS == serialization_status)
	{
		// The number of bytes in the message.
		uint8_t n_bytes = write_buffer.get_size();
		// The actual encoded data
		uint8_t* buffer = write_buffer.get_data();

		rt_kprintf("Encoding %d serialized bytes\n", n_bytes);

		for(uint8_t i = 0; (i < n_bytes); ++i)
		{
			read_buffer.push(buffer[i]);
		}

		rt_kprintf("---- Decoding ---\n");
		auto deserialize_status = decode_msg.deserialize(read_buffer);
		if(::EmbeddedProto::Error::NO_ERRORS == deserialize_status) 
		{
			rt_kprintf("a=%ld, b=%ld\n", decode_msg.a(), decode_msg.b());
		}
	}

	return 0;
}
MSH_CMD_EXPORT(encode_decode, Embedded Proto encode decode example)
