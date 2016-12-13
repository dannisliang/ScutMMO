using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using GameServer.Script.Model;
using ProtoBuf;
using ZyGames.Framework.Common;
using ZyGames.Framework.Model;
using ZyGames.Framework.Cache.Generic;

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

        private Vector3 m_Pos = new Vector3();

        private Vector3 m_Dir = new Vector3();

        private readonly uint m_ViewLayer;

        public List<UInt32> SeeLst { get {return m_SeeLst; } }

        public List<UInt32> BeenSeeLst { get { return m_BeenSeeLst; } }

        public Vector3 Pos
        {
            get { return m_Pos; }
            set { m_Pos = value; }
        }

        public Vector3 Dir
        {
            get { return m_Dir; }
            set { m_Pos = value; }
        }

        public Grid Grid { get; set; }

        public Scene Scene { get; set; }

        public uint ViewLayer { get { return m_ViewLayer; } }

        public Creature()
        {

        }

        //public virtual bool Init();

        //public virtual bool UnInit();

        //public virtual void Update();
    }
}
