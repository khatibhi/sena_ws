// Generated by gencpp from file sena_msgs/MotorInfo.msg
// DO NOT EDIT!


#ifndef SENA_MSGS_MESSAGE_MOTORINFO_H
#define SENA_MSGS_MESSAGE_MOTORINFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace sena_msgs
{
template <class ContainerAllocator>
struct MotorInfo_
{
  typedef MotorInfo_<ContainerAllocator> Type;

  MotorInfo_()
    : header()
    , motordata()  {
      motordata.assign(0);
  }
  MotorInfo_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , motordata()  {
  (void)_alloc;
      motordata.assign(0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef boost::array<uint32_t, 3>  _motordata_type;
  _motordata_type motordata;





  typedef boost::shared_ptr< ::sena_msgs::MotorInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sena_msgs::MotorInfo_<ContainerAllocator> const> ConstPtr;

}; // struct MotorInfo_

typedef ::sena_msgs::MotorInfo_<std::allocator<void> > MotorInfo;

typedef boost::shared_ptr< ::sena_msgs::MotorInfo > MotorInfoPtr;
typedef boost::shared_ptr< ::sena_msgs::MotorInfo const> MotorInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sena_msgs::MotorInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sena_msgs::MotorInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sena_msgs::MotorInfo_<ContainerAllocator1> & lhs, const ::sena_msgs::MotorInfo_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.motordata == rhs.motordata;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sena_msgs::MotorInfo_<ContainerAllocator1> & lhs, const ::sena_msgs::MotorInfo_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sena_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sena_msgs::MotorInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sena_msgs::MotorInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sena_msgs::MotorInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sena_msgs::MotorInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sena_msgs::MotorInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sena_msgs::MotorInfo_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sena_msgs::MotorInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3f0b34f70bedeea64d08b81a683da488";
  }

  static const char* value(const ::sena_msgs::MotorInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3f0b34f70bedeea6ULL;
  static const uint64_t static_value2 = 0x4d08b81a683da488ULL;
};

template<class ContainerAllocator>
struct DataType< ::sena_msgs::MotorInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sena_msgs/MotorInfo";
  }

  static const char* value(const ::sena_msgs::MotorInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sena_msgs::MotorInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"uint32[3] motordata\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::sena_msgs::MotorInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sena_msgs::MotorInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.motordata);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MotorInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sena_msgs::MotorInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sena_msgs::MotorInfo_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "motordata[]" << std::endl;
    for (size_t i = 0; i < v.motordata.size(); ++i)
    {
      s << indent << "  motordata[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.motordata[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENA_MSGS_MESSAGE_MOTORINFO_H
