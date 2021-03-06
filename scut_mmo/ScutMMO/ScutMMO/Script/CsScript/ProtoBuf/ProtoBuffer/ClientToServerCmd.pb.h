// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProtoBuffer/ClientToServerCmd.proto

#ifndef PROTOBUF_ProtoBuffer_2fClientToServerCmd_2eproto__INCLUDED
#define PROTOBUF_ProtoBuffer_2fClientToServerCmd_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace ProtoBuf {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ProtoBuffer_2fClientToServerCmd_2eproto();
void protobuf_AssignDesc_ProtoBuffer_2fClientToServerCmd_2eproto();
void protobuf_ShutdownFile_ProtoBuffer_2fClientToServerCmd_2eproto();


enum ClientToServerCmd {
  CLIENT_TO_SERVER_LOGIN_BEGIN = 1,
  CLIENT_TO_LOGIN_PING = 2,
  CLIENT_TO_LOGIN_CHECK_VERSION = 3,
  CLIENT_TO_LOGIN_ACCOUNT_LOGIN = 4,
  CLIENT_TO_LOGIN_BREAK_LOGIN = 5,
  CLIENT_TO_LOGIC_PING = 10,
  CLIENT_TO_LOGIC_RECONNECT = 11,
  CLIENT_TO_LOGIC_RESET_TIMEOUT = 12,
  CLIENT_TO_LOGIC_LOGIN_LOGICSERVER = 13,
  CLIENT_TO_LOGIC_GET_CHARACTER_LIST = 14,
  CLIENT_TO_LOGIC_CREATE_CHARACTER = 15,
  CLIENT_TO_LOGIC_DEL_CHARACTER = 16,
  CLIENT_TO_LOGIC_ENTER_WORLD = 17,
  CLIENT_TO_LOGIC_LEAVE_WORLD = 18,
  CLIENT_TO_SERVER_LOGIN_END = 50,
  CLIENT_TO_SERVER_SYSTEM_BEGIN = 60,
  CLIENT_TO_LOGIC_REDIRECT_CENTERSERVER = 82,
  CLIENT_TO_SERVER_SYSTEM_END = 100,
  CLIENT_TO_SERVER_PLAYER_BEGIN = 200,
  CLIENT_TO_LOGIC_PLAYER_ATRR_POINT = 201,
  CLIENT_TO_LOGIC_PLAYER_ATRR_CLEAR_POINT = 202,
  CLIENT_TO_LOGIC_PLAYER_AUTO_POINT = 203,
  CLIENT_TO_SERVER_PLAYER_END = 210,
  CLIENT_TO_SERVER_SKILL_BEGIN = 220,
  CLIENT_TO_LOGIC_SKILL_USE = 221,
  CLIENT_TO_LOGIC_SKILL_CHARGE_END = 222,
  CLIENT_TO_LOGIC_SKILL_LEVEL_UP_REQ = 223,
  CLIENT_TO_LOGIC_SKILL_STOP = 224,
  CLIENT_TO_SERVER_SKILL_END = 230,
  CLIENT_TO_SERVER_PACKAGE_BEGIN = 240,
  CLIENT_TO_LOGIC_PACKAGE_INFO = 241,
  CLIENT_TO_LOGIC_PACKAGE_SORT = 242,
  CLIENT_TO_LOGIC_PACKAGE_SELL = 243,
  CLIENT_TO_LOGIC_PACKAGE_USE = 244,
  CLIENT_TO_LOGIC_EQUIP_STREN = 245,
  CLIENT_TO_LOGIC_EQUIP_ONEKEY_STREN = 246,
  CLIENT_TO_LOGIC_EQUIP_REFINE = 247,
  CLIENT_TO_LOGIC_EQUIP_DIGHOLE = 248,
  CLIENT_TO_LOGIC_EQUIP_INLAY = 249,
  CLIENT_TO_LOGIC_EQUIP_TAKEOFF = 250,
  CLIENT_TO_LOGIC_EQUIP_COMPOSE = 251,
  CLIENT_TO_LOGIC_EQUIP_RECAST = 252,
  CLIENT_TO_LOGIC_EQUIP_INLAY_HOLY = 253,
  CLIENT_TO_LOGIC_EQUIP_TAKEOFF_HOLY = 254,
  CLIENT_TO_LOGIC_EQUIP_COMPOSE_MATERIAL = 255,
  CLIENT_TO_LOGIC_PLAYER_EQUIP_INFO = 256,
  CLIENT_TO_LOGIC_PLAYER_EQUIP_DRESS = 257,
  CLIENT_TO_LOGIC_PLAYER_EQUIP_UNDRESS = 258,
  CLIENT_TO_LOGIC_PLAYER_EQUIP_ONEKEY_DRESS = 259,
  CLIENT_TO_LOGIC_PLAYER_PICKUP_DROP = 260,
  CLIENT_TO_SERVER_PACKAGE_END = 300,
  CLIENT_TO_SERVER_DUPLICATE_BEGIN = 310,
  CLIENT_TO_LOGIC_DUPLICATE_INFO = 311,
  CLIENT_TO_LOGIC_DUPLICATE_ENTER = 312,
  CLIENT_TO_LOGIC_DUPLICATE_RESULT = 313,
  CLIENT_TO_LOGIC_DUPLICATE_AUTO_FIGHT = 314,
  CLIENT_TO_LOGIC_DUPLICATE_LOTTERY = 315,
  CLIENT_TO_LOGIC_DUPLICATE_BUY_NUM = 316,
  CLIENT_TO_LOGIC_DUPLICATE_RELIVE = 317,
  CLIENT_TO_LOGIC_DUPLICATE_LEAVE = 318,
  CLIENT_TO_LOGIC_DUPLICATE_ENTER_AREA = 319,
  CLIENT_TO_LOGIC_DUPLICATE_AUTO_CHALLENGE = 320,
  CLIENT_TO_SERVER_DUPLICATE_END = 350,
  CLIENT_TO_SERVER_MOVE_BEGIN = 360,
  CLIENT_TO_LOGIC_SCENE_REQ_ROUTEINFO = 361,
  CLIENT_TO_LOGIC_SCENE_TRANS = 362,
  CLIENT_TO_LOGIC_SCENE_LOAD_SUCCESS = 363,
  CLIENT_TO_LOGIC_CHARACTER_SKILLMOVE = 364,
  CLIENT_TO_LOGIC_CHARACTER_MOVE = 365,
  CLIENT_TO_LOGIC_CHARACTER_ROCKER_MOVE = 366,
  CLIENT_TO_LOGIC_CHARACTER_POS_UPDATE = 367,
  CLIENT_TO_SERVER_MOVE_END = 390,
  CLIENT_TO_SERVER_MISSION_BEGIN = 400,
  CLIENT_TO_LOGIC_QUERY_MiSSIONLIST = 401,
  CLIENT_TO_LOGIC_ACCEPTMISSION = 402,
  CLIENT_TO_LOGIC_ABANDONMISSION = 403,
  CLIENT_TO_LOGIC_SUBMITMISSION = 404,
  CLIENT_TO_LOGIC_TALKWITHNPC = 405,
  CLIENT_TO_LOGIC_GETCAMPMISSIONINFO = 406,
  CLIENT_TO_LOGIC_DICECAMPMISSION = 407,
  CLIENT_TO_LOGIC_GETCAMPBOXREWARD = 408,
  CLIENT_TO_SERVER_MISSION_END = 420,
  CLIENT_TO_SERVER_CHAT_BEGIN = 430,
  CLIENT_TO_LOGIC_CHATMSGREQ = 431,
  CLIENT_TO_CENTER_ASKOFFLINEMSG = 432,
  CLIENT_TO_CENTER_INTRVALASKOFFLINEMSG = 433,
  CLIENT_TO_CENTER_CHARACTER_DETAIL_DATA = 434,
  CLIENT_TO_SERVER_CHAT_END = 450,
  CLIENT_TO_SERVER_FRIEND_BEGIN = 460,
  CLIENT_TO_CENTER_APPLY_RELATION = 461,
  CLIENT_TO_CENTER_AGREE_RELATION = 462,
  CLIENT_TO_CENTER_DELETE_RELATION = 463,
  CLIENT_TO_CENTER_RECENT_CHAT_LIST = 464,
  CLIENT_TO_CENTER_ONEKEY_FRIEND = 465,
  CLIENT_TO_CENTER_RELATION_INFO = 466,
  CLIENT_TO_CENTER_SEARCH_USER = 467,
  CLIENT_TO_CENTER_GIVE_PHYSCIAL = 468,
  CLIENT_TO_CENTER_AllGIVE_PHYSICAL = 469,
  CLIENT_TO_CENTER_GET_PHYSICAL = 470,
  CLIENT_TO_CENTER_GET_PHYSICAL_GIFT = 471,
  CLIENT_TO_CENTER_APPLYLIST = 472,
  CLIENT_TO_CENTER_CLEARAPPLYLIST = 473,
  CLIENT_TO_SERVER_FRIEND_END = 500,
  CLIENT_TO_SERVER_SCENE_BEGIN = 510,
  CLIENT_TO_SERVER_SCENE_END = 550,
  CLIENT_TO_SERVER_MAIL_BEGIN = 560,
  CLIENT_TO_LOGIC_SENDMAIL = 561,
  CLIENT_TO_CENTER_GETMAILITEMLIST = 562,
  CLIENT_TO_CENTER_ASKMAIL = 563,
  CLIENT_TO_CENTER_DELETEMAIL = 564,
  CLIENT_TO_CENTER_CHECKNAME = 565,
  CLIENT_TO_CENTER_GETMAILATTACHMENT = 566,
  CLIENT_TO_CENTER_GETALLMAILATTACHMENT = 567,
  CLIENT_TO_CENTER_NDRMAIL = 568,
  CLIENT_TO_SERVER_MAIL_END = 600,
  CLIENT_TO_SERVER_CAMP_BEGIN = 610,
  CLIENT_TO_CENTER_CAMP_JOIN = 611,
  CLIENT_TO_CENTER_CAMP_CHANGE = 612,
  CLIENT_TO_CENTER_CAMP_INFO = 613,
  CLIENT_TO_CENTER_CAMP_RANK_INFO = 614,
  CLIENT_TO_CENTER_CAMP_HONOR_INFO = 615,
  CLIENT_TO_CENTER_CAMP_PUBLISH_NOTICE = 616,
  CLIENT_TO_SERVER_CAMP_END = 650,
  CLIENT_TO_SERVER_ACHIEVEMENT_BEGIN = 700,
  CLIENT_TO_SERVER_ACHIEVEMENTINFO = 701,
  CLIENT_TO_SERVER_GETACHIEVEMENTREWARD = 702,
  CLIENT_TO_SERVER_GETACHIEVEMENTBOXREWARD = 703,
  CLIENT_TO_SERVER_ACHIEVEMENT_END = 720,
  CLIENT_TO_SERVER_DEPUTY_BEGIN = 730,
  CLIENT_TO_SERVER_DEPUTY_COLLECT_SKILL_INFO = 731,
  CLIENT_TO_SERVER_DEPUTY_MAKE_SKILL_INFO = 732,
  CLIENT_TO_SERVER_DEPUTY_UPGRADE_COLLECT_SKILL = 733,
  CLIENT_TO_SERVER_DEPUTY_REFINE_MAKE_SKILL = 734,
  CLIENT_TO_SERVER_DEPUTY_COLLECT_OPERATE = 735,
  CLIENT_TO_SERVER_DEPUTY_MAKE_OPERATE = 736,
  CLIENT_TO_SERVER_DEPUTY_END = 750,
  CLIENT_TO_SERVER_PVP_BEGIN = 770,
  CLIENT_TO_SERVER_PVP_SET_MODE = 771,
  CLIENT_TO_SERVER_PVP_END = 779,
  CLIENT_TO_SERVER_CENTER_BEGIN = 780,
  CLIENT_TO_CENTER_GET_MALL_DATA = 781,
  CLIENT_TO_LOGIC_BUY = 782,
  CLIENT_TO_CENTER_GET_TIME = 783,
  CLIENT_TO_SERVER_CENTER_END = 800,
  CLIENT_TO_SERVER_ROOM_BEGIN = 820,
  CLIENT_TO_LOGIC_ROOM_CREATE = 821,
  CLIENT_TO_LOGIC_ROOM_SET_PWD = 822,
  CLIENT_TO_LOGIC_ROOM_JOIN = 823,
  CLIENT_TO_LOGIC_ROOM_INVITE_FRIEND = 824,
  CLIENT_TO_LOGIC_ROOM_INVITE_REPLY = 825,
  CLIENT_TO_LOGIC_ROOM_BE_LEAVE = 826,
  CLIENT_TO_LOGIC_ROOM_LEAVE = 827,
  CLIENT_TO_LOGIC_ROOM_AUTO_JOIN = 828,
  CLIENT_TO_SERVER_ROOM_END = 860
};
bool ClientToServerCmd_IsValid(int value);
const ClientToServerCmd ClientToServerCmd_MIN = CLIENT_TO_SERVER_LOGIN_BEGIN;
const ClientToServerCmd ClientToServerCmd_MAX = CLIENT_TO_SERVER_ROOM_END;
const int ClientToServerCmd_ARRAYSIZE = ClientToServerCmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* ClientToServerCmd_descriptor();
inline const ::std::string& ClientToServerCmd_Name(ClientToServerCmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    ClientToServerCmd_descriptor(), value);
}
inline bool ClientToServerCmd_Parse(
    const ::std::string& name, ClientToServerCmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ClientToServerCmd>(
    ClientToServerCmd_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace ProtoBuf

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ProtoBuf::ClientToServerCmd>() {
  return ::ProtoBuf::ClientToServerCmd_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ProtoBuffer_2fClientToServerCmd_2eproto__INCLUDED
