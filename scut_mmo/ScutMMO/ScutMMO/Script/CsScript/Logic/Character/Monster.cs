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
    public interface ICreatureAttribute
    {
        bool AddAttr(uint CAttrType, int attrValue, bool syn, uint relationCid);
        void SetAttr(uint CAttrType, int attrValue, bool syn);
        void SetAttrCache(uint CAttrType, int attrValue);

        int GetAttrType(uint CAttrType);

        int GetAttrCount(uint CAttrType);
    }

    public class MonsterAttribute : ICreatureAttribute
    {
        private uint[] m_Attrs;

        public MonsterAttribute()
        {
            m_Attrs = new uint[(int)MonsterAttr.M_MAX];
        }

        public bool AddAttr(uint CAttrType, int attrValue, bool syn, uint relationCid)
        {
            throw new NotImplementedException();
        }

        public void SetAttr(uint CAttrType, int attrValue, bool syn)
        {
            throw new NotImplementedException();
        }

        public void SetAttrCache(uint CAttrType, int attrValue)
        {
            throw new NotImplementedException();
        }

        public int GetAttrType(uint CAttrType)
        {
            throw new NotImplementedException();
        }

        public int GetAttrCount(uint CAttrType)
        {
            throw new NotImplementedException();
        }
    }

    public class Monster : Creature
    {
        private int m_MonsterId;
        private MonsterMonsterConfig m_MonsterConfig;

        public int MonsterId
        {
            get { return m_MonsterId; }
            set { m_MonsterId = value; }
        }

        public MonsterMonsterConfig MonsterConfig
        {
            get { return m_MonsterConfig; }
            set { m_MonsterConfig = value; }
        }

        public Monster():base()
        {
            m_MonsterConfig = null;
            m_MonsterId = 0;
            CreatureType = CreatureTypeEnum.CREATURE_MONSTER;
        }

        public override bool Init()
        {
            if (MonsterId == 0)
            {
                return false;
            }

            bool ret = ConfigMgr.Inst().MonsterMonster.configs.TryGetValue(MonsterId, out m_MonsterConfig);
            if (ret == false || MonsterConfig == null)
            {
                return false;
            }

            return true;
        }

        public override bool UnInit()
        {
            return base.UnInit();
        }

        public override void Update()
        {
            base.Update();
        }
    }
}
