// Generated by gencpp from file sena_msgs/KinematicsInverseResponse.msg
// DO NOT EDIT!


#ifndef SENA_MSGS_MESSAGE_KINEMATICSINVERSERESPONSE_H
#define SENA_MSGS_MESSAGE_KINEMATICSINVERSERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sena_msgs/Velocity.h>

namespace sena_msgs
{
template <class ContainerAllocator>
struct KinematicsInverseResponse_
{
  typedef KinematicsInverseResponse_<ContainerAllocator> Type;

  KinematicsInverseResponse_()
    : output()  {
    }
  KinematicsInverseResponse_(const ContainerAllocator& _alloc)
    : output(_alloc)  {
  (void)_alloc;
    }



   typedef  ::sena_msgs::Velocity_<ContainerAllocator>  _output_type;
  _output_type output;





  typedef boost::shared_ptr< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> const> ConstPtr;

}; // struct KinematicsInverseResponse_

typedef ::sena_msgs::KinematicsInverseResponse_<std::allocator<void> > KinematicsInverseResponse;

typedef boost::shared_ptr< ::sena_msgs::KinematicsInverseResponse > KinematicsInverseResponsePtr;
typedef boost::shared_ptr< ::sena_msgs::KinematicsInverseResponse const> KinematicsInverseResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator1> & lhs, const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator2> & rhs)
{
  return lhs.output == rhs.output;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator1> & lhs, const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sena_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d9927209763f6da8f4c0f2a39e06a306";
  }

  static const char* value(const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd9927209763f6da8ULL;
  static const uint64_t static_value2 = 0xf4c0f2a39e06a306ULL;
};

template<class ContainerAllocator>
struct DataType< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sena_msgs/KinematicsInverseResponse";
  }

  static const char* value(const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sena_msgs/Velocity output\n"
"\n"
"================================================================================\n"
"MSG: sena_msgs/Velocity\n"
"float64 v_right\n"
"float64 v_left\n"
"float64 v_back\n"
;
  }

  static const char* value(const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.output);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct KinematicsInverseResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sena_msgs::KinematicsInverseResponse_<ContainerAllocator>& v)
  {
    s << indent << "output: ";
    s << std::endl;
    Printer< ::sena_msgs::Velocity_<ContainerAllocator> >::stream(s, indent + "  ", v.output);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENA_MSGS_MESSAGE_KINEMATICSINVERSERESPONSE_H
