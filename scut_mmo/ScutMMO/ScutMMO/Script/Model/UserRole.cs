using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProtoBuf;
using ZyGames.Framework.Model;

namespace GameServer.Script.Model
{
    /// <summary>
    /// 配置一个账号多个角色
    /// </summary>
    [Serializable, ProtoContract]
    [EntityTable(CacheType.Dictionary, "ConnData")]
    public class UserRole : BaseEntity
    {
        [ProtoMember(1)]
        [EntityField(true)]
        public int RoleId { get; set; }

        [ProtoMember(2)]
        [EntityField(true)]
        public int UserId { get; set; }

        [ProtoMember(3)]
        [EntityField]
        public string Name { get; set; }

        [ProtoMember(4)]
        [EntityField]
        public int Prof { get; set; }

        [ProtoMember(5)]
        [EntityField]
        public int Sex { get; set; }

        [ProtoMember(6)]
        [EntityField]
        public int Level { get; set; }

        [ProtoMember(7)]
        [EntityField]
        public int Exp { get; set; }

        [ProtoMember(8)]
        [EntityField]
        public int Hp { get; set; }

        [ProtoMember(9)]
        [EntityField]
        public int FightPower { get; set; }

        [ProtoMember(10)]
        [EntityField]
        public int Gold { get; set; }

        [ProtoMember(11)]
        [EntityField]
        public int BindGold { get; set; }

        [ProtoMember(12)]
        [EntityField]
        public int Diamond { get; set; }

        [ProtoMember(13)]
        [EntityField]
        public int BindDiamond { get; set; }

        [ProtoMember(14)]
        [EntityField]
        public int EnterSceneId { get; set; }

        [ProtoMember(15)]
        [EntityField]
        public int EnterMapId { get; set; }

        [ProtoMember(16)]
        [EntityField]
        public float EnterPosX { get; set; }

        [ProtoMember(17)]
        [EntityField]
        public float EnterPosY { get; set; }

        [ProtoMember(18)]
        [EntityField]
        public float EnterPosZ { get; set; }

        [ProtoMember(19)]
        [EntityField]
        public int LastSceneId { get; set; }

        [ProtoMember(20)]
        [EntityField]
        public int LastMapId { get; set; }

        [ProtoMember(21)]
        [EntityField]
        public float LastPosX { get; set; }

        [ProtoMember(22)]
        [EntityField]
        public float LastPosY { get; set; }

        [ProtoMember(23)]
        [EntityField]
        public float LastPosZ { get; set; }

        [ProtoMember(24)]
        [EntityField]
        public int Race { get; set; } //种族

        [ProtoMember(25)]
        [EntityField]
        public int Stamina { get; set; } //初始体力

        [ProtoMember(26)]
        [EntityField]
        public DateTime CreateTime { get; set; }

        [ProtoMember(27)]
        [EntityField]
        public DateTime OnlineTime { get; set; }

        [ProtoMember(28)]
        [EntityField]
        public DateTime LoginTime { get; set; }

        [ProtoMember(29)]
        [EntityField]
        public DateTime LogoutTime { get; set; }

        [ProtoMember(30)]
        [EntityField]
        public int Official { get; set; }

        [ProtoMember(31)]
        [EntityField]
        public int Knight { get; set; }

        [ProtoMember(32)]
        [EntityField]
        public int Camp { get; set; }

        protected override int GetIdentityId()
        {
            return UserId;
        }
    }
}
