/* Auto-generated by genmsg_cpp for file /home/jianlan/gps_tt4/gps_tt4/src/gps_agent_pkg/msg/SUPERballStateArray.msg */
#ifndef GPS_AGENT_PKG_MESSAGE_SUPERBALLSTATEARRAY_H
#define GPS_AGENT_PKG_MESSAGE_SUPERBALLSTATEARRAY_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "gps_agent_pkg/SUPERballState.h"

namespace gps_agent_pkg
{
template <class ContainerAllocator>
struct SUPERballStateArray_ {
  typedef SUPERballStateArray_<ContainerAllocator> Type;

  SUPERballStateArray_()
  : states()
  {
  }

  SUPERballStateArray_(const ContainerAllocator& _alloc)
  : states(_alloc)
  {
  }

  typedef std::vector< ::gps_agent_pkg::SUPERballState_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::gps_agent_pkg::SUPERballState_<ContainerAllocator> >::other >  _states_type;
  std::vector< ::gps_agent_pkg::SUPERballState_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::gps_agent_pkg::SUPERballState_<ContainerAllocator> >::other >  states;


  typedef boost::shared_ptr< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator>  const> ConstPtr;
}; // struct SUPERballStateArray
typedef  ::gps_agent_pkg::SUPERballStateArray_<std::allocator<void> > SUPERballStateArray;

typedef boost::shared_ptr< ::gps_agent_pkg::SUPERballStateArray> SUPERballStateArrayPtr;
typedef boost::shared_ptr< ::gps_agent_pkg::SUPERballStateArray const> SUPERballStateArrayConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace gps_agent_pkg

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> > {
  static const char* value() 
  {
    return "1e907e4084595e2265d98c9c7f16b2df";
  }

  static const char* value(const  ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x1e907e4084595e22ULL;
  static const uint64_t static_value2 = 0x65d98c9c7f16b2dfULL;
};

template<class ContainerAllocator>
struct DataType< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> > {
  static const char* value() 
  {
    return "gps_agent_pkg/SUPERballStateArray";
  }

  static const char* value(const  ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> > {
  static const char* value() 
  {
    return "SUPERballState[] states\n\
\n\
================================================================================\n\
MSG: gps_agent_pkg/SUPERballState\n\
geometry_msgs/Point pos1\n\
geometry_msgs/Point pos2\n\
std_msgs/Float64 motor_pos1\n\
std_msgs/Float64 motor_pos2\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: std_msgs/Float64\n\
float64 data\n\
";
  }

  static const char* value(const  ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.states);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct SUPERballStateArray_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::gps_agent_pkg::SUPERballStateArray_<ContainerAllocator> & v) 
  {
    s << indent << "states[]" << std::endl;
    for (size_t i = 0; i < v.states.size(); ++i)
    {
      s << indent << "  states[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::gps_agent_pkg::SUPERballState_<ContainerAllocator> >::stream(s, indent + "    ", v.states[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // GPS_AGENT_PKG_MESSAGE_SUPERBALLSTATEARRAY_H
