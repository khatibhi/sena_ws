; Auto-generated. Do not edit!


(cl:in-package sena_msgs-msg)


;//! \htmlinclude MotorInfo.msg.html

(cl:defclass <MotorInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (motordata
    :reader motordata
    :initarg :motordata
    :type (cl:vector cl:integer)
   :initform (cl:make-array 3 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass MotorInfo (<MotorInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MotorInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MotorInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sena_msgs-msg:<MotorInfo> is deprecated: use sena_msgs-msg:MotorInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MotorInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sena_msgs-msg:header-val is deprecated.  Use sena_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'motordata-val :lambda-list '(m))
(cl:defmethod motordata-val ((m <MotorInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sena_msgs-msg:motordata-val is deprecated.  Use sena_msgs-msg:motordata instead.")
  (motordata m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MotorInfo>) ostream)
  "Serializes a message object of type '<MotorInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'motordata))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MotorInfo>) istream)
  "Deserializes a message object of type '<MotorInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:setf (cl:slot-value msg 'motordata) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'motordata)))
    (cl:dotimes (i 3)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MotorInfo>)))
  "Returns string type for a message object of type '<MotorInfo>"
  "sena_msgs/MotorInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MotorInfo)))
  "Returns string type for a message object of type 'MotorInfo"
  "sena_msgs/MotorInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MotorInfo>)))
  "Returns md5sum for a message object of type '<MotorInfo>"
  "3f0b34f70bedeea64d08b81a683da488")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MotorInfo)))
  "Returns md5sum for a message object of type 'MotorInfo"
  "3f0b34f70bedeea64d08b81a683da488")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MotorInfo>)))
  "Returns full string definition for message of type '<MotorInfo>"
  (cl:format cl:nil "Header header~%uint32[3] motordata~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MotorInfo)))
  "Returns full string definition for message of type 'MotorInfo"
  (cl:format cl:nil "Header header~%uint32[3] motordata~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MotorInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'motordata) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MotorInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'MotorInfo
    (cl:cons ':header (header msg))
    (cl:cons ':motordata (motordata msg))
))
