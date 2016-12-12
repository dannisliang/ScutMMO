using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using GameServer.Script.Model;

namespace GameServer.Script.Logic
{
    public enum CreatureTypeEnum : uint
    {
        CREATURE_NONE = 0,
        CREATURE_PLAYER,    //玩家类型
        CREATURE_MONSTER,   //玩家类型
        CREATURE_NPC,		//NPC类型
        CREATURE_DROP,		//掉落类型
        CREATURE_SUMMON,	//召唤物
        CREATURE_HERBS,		//草药类型
        CREATURE_MINE,		//矿石类型
        CREATURE_FISH,		//渔类型
        CREATURE_MAX
    };

    public abstract class Creature
    {
        public uint SceneId { get; set; }

        public uint MapID { get; set; }

        public uint Cid { get; set; }

        public uint CreatureType { get; protected set; }

        private readonly List<UInt32> m_SeeLst = new List<uint>();

        private readonly List<UInt32> m_BeenSeeLst = new List<uint>();

        private Vector3 _Pos = new Vector3();

        public List<UInt32> SeeLst { get {return m_SeeLst; } }

        public List<UInt32> BeenSeeLst { get { return m_BeenSeeLst; } }

        public Vector3 Pos
        {
            get { return _Pos; }
            set { _Pos = value; }
        }
    }
}
