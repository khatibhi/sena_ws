// Auto-generated. Do not edit!

// (in-package sena_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let PPoint = require('./PPoint.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class BallInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.ballinfostate = null;
      this.pos_known = null;
      this.velocity_known = null;
      this.real_pos = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('ballinfostate')) {
        this.ballinfostate = initObj.ballinfostate
      }
      else {
        this.ballinfostate = 0;
      }
      if (initObj.hasOwnProperty('pos_known')) {
        this.pos_known = initObj.pos_known
      }
      else {
        this.pos_known = false;
      }
      if (initObj.hasOwnProperty('velocity_known')) {
        this.velocity_known = initObj.velocity_known
      }
      else {
        this.velocity_known = false;
      }
      if (initObj.hasOwnProperty('real_pos')) {
        this.real_pos = initObj.real_pos
      }
      else {
        this.real_pos = new PPoint();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type BallInfo
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [ballinfostate]
    bufferOffset = _serializer.int32(obj.ballinfostate, buffer, bufferOffset);
    // Serialize message field [pos_known]
    bufferOffset = _serializer.bool(obj.pos_known, buffer, bufferOffset);
    // Serialize message field [velocity_known]
    bufferOffset = _serializer.bool(obj.velocity_known, buffer, bufferOffset);
    // Serialize message field [real_pos]
    bufferOffset = PPoint.serialize(obj.real_pos, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BallInfo
    let len;
    let data = new BallInfo(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [ballinfostate]
    data.ballinfostate = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [pos_known]
    data.pos_known = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [velocity_known]
    data.velocity_known = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [real_pos]
    data.real_pos = PPoint.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'sena_msgs/BallInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '842fb4e2989d0235594fa714af57acbd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int32  ballinfostate
    bool   pos_known
    bool   velocity_known
    PPoint real_pos
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: sena_msgs/PPoint
    float32 angle
    float32 radius
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BallInfo(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.ballinfostate !== undefined) {
      resolved.ballinfostate = msg.ballinfostate;
    }
    else {
      resolved.ballinfostate = 0
    }

    if (msg.pos_known !== undefined) {
      resolved.pos_known = msg.pos_known;
    }
    else {
      resolved.pos_known = false
    }

    if (msg.velocity_known !== undefined) {
      resolved.velocity_known = msg.velocity_known;
    }
    else {
      resolved.velocity_known = false
    }

    if (msg.real_pos !== undefined) {
      resolved.real_pos = PPoint.Resolve(msg.real_pos)
    }
    else {
      resolved.real_pos = new PPoint()
    }

    return resolved;
    }
};

module.exports = BallInfo;
