/*
 *  Copyright (C) 2020 Embedded AMS B.V. - All Rights Reserved
 *
 *  This file is part of Embedded Proto.
 *
 *  Embedded Proto is open source software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, version 3 of the license.
 *
 *  Embedded Proto  is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Embedded Proto. If not, see <https://www.gnu.org/licenses/>.
 *
 *  For commercial and closed source application please visit:
 *  <https://EmbeddedProto.com/license/>.
 *
 *  Embedded AMS B.V.
 *  Info:
 *    info at EmbeddedProto dot com
 *
 *  Postal address:
 *    Johan Huizingalaan 763a
 *    1066 VH, Amsterdam
 *    the Netherlands
 */

// This file is generated. Please do not edit!
#ifndef _AMESSAGE_H_
#define _AMESSAGE_H_

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>

// Include external proto definitions


class AMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    AMessage() :
        a_(0),
        b_(0)
    {

    };
    ~AMessage() override = default;

    enum class id
    {
      NOT_SET = 0,
      A = 1,
      B = 2
    };

    AMessage& operator=(const AMessage& rhs)
    {
      set_a(rhs.get_a());
      set_b(rhs.get_b());
      return *this;
    }

    inline void clear_a() { a_.clear(); }
    inline void set_a(const EmbeddedProto::int32& value) { a_ = value; }
    inline void set_a(const EmbeddedProto::int32&& value) { a_ = value; }
    inline EmbeddedProto::int32& mutable_a() { return a_; }
    inline const EmbeddedProto::int32& get_a() const { return a_; }
    inline EmbeddedProto::int32::FIELD_TYPE a() const { return a_.get(); }

    inline void clear_b() { b_.clear(); }
    inline void set_b(const EmbeddedProto::int32& value) { b_ = value; }
    inline void set_b(const EmbeddedProto::int32&& value) { b_ = value; }
    inline EmbeddedProto::int32& mutable_b() { return b_; }
    inline const EmbeddedProto::int32& get_b() const { return b_; }
    inline EmbeddedProto::int32::FIELD_TYPE b() const { return b_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const final
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != a_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = a_.serialize_with_id(static_cast<uint32_t>(id::A), buffer);
      }

      if((0 != b_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = b_.serialize_with_id(static_cast<uint32_t>(id::B), buffer);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) final
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type;
      uint32_t id_number = 0;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        switch(id_number)
        {
          case static_cast<uint32_t>(id::A):
          {
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              return_value = a_.deserialize(buffer);
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
            break;
          }

          case static_cast<uint32_t>(id::B):
          {
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              return_value = b_.deserialize(buffer);
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
            break;
          }

          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
            // Read the next tag.
            tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() final
    {
      clear_a();
      clear_b();

    }

    private:

      EmbeddedProto::int32 a_;
      EmbeddedProto::int32 b_;

};

#endif // _AMESSAGE_H_