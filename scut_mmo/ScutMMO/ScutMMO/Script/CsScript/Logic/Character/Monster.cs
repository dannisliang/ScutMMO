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
    public class MonsterAttribute : ICreatureAttribute
    {
        private uint[] m_Attrs;

        public MonsterAttribute()
        {
            m_Attrs = new uint[(int)MonsterAttr.M_MAX];
        }

        public bool AddAttr(CreatureCommonAttr CAttrType, int attrValue)
        {
            MonsterAttr mAttrType = AttrMgr.GetMonsterAttr(CAttrType);

            if (attrValue < 0)
            {
                uint absValue = (uint)Math.Abs(attrValue);
                m_Attrs[(int)mAttrType] = ((m_Attrs[(int)mAttrType] > absValue) ? (m_Attrs[(int)mAttrType] - absValue) : 0);
                
            }
            else
            {
                m_Attrs[(int)mAttrType] = m_Attrs[(int)mAttrType] + (uint)attrValue;
            }

            return true;
        }

        public void SetAttr(CreatureCommonAttr CAttrType, int attrValue)
        {
            m_Attrs[GetAttrType(CAttrType)] = (uint)(attrValue > 0 ? attrValue : 0);
        }

        public int GetAttrType(CreatureCommonAttr CAttrType)
        {
            return (int)AttrMgr.GetMonsterAttr(CAttrType);
        }

        public uint GetAttrCount(CreatureCommonAttr CAttrType)
        {
            return m_Attrs[GetAttrType(CAttrType)];
        }
    }

    public class Monster : Creature
    {
        private int m_MonsterId;
        private MonsterMonsterConfig m_MonsterConfig;
        private MonsterAttribute m_MonsterAttr;

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

        public MonsterAttribute MonsterAttr
        {
            get { return m_MonsterAttr; }
            set { m_MonsterAttr = value; }
        }

        public Monster():base()
        {
            m_MonsterAttr = new MonsterAttribute();
            m_MonsterConfig = null;
            m_MonsterId = 0;
            CreatureType = CreatureTypeEnum.CREATURE_MONSTER;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="disposing"></param>
        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                m_MonsterAttr = null;
                m_MonsterConfig = null;
            }
            base.Dispose(disposing);
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

            MonsterAttr.SetAttr(CreatureCommonAttr.C_HP, MonsterConfig.maxHP);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_MAX_HP, MonsterConfig.maxHP);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_MP, MonsterConfig.maxMP);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_MAX_MP, MonsterConfig.maxMP);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_AP, MonsterConfig.ap);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_MAT, MonsterConfig.mat);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_DP, MonsterConfig.dp);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_MDP, MonsterConfig.mdp);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_HIT, MonsterConfig.hit);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_DODGE, MonsterConfig.dodge);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_CRIT, MonsterConfig.crit);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_TOUGHNESS, MonsterConfig.toughness);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_CRIT_RATE, MonsterConfig.critRate);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_CRIT_EXTRADAMAGE, MonsterConfig.critExtraDamage);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_CRIT_REDUCEDAMAGE, MonsterConfig.critReduceDamage);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_EXTRA_DAMAGE, MonsterConfig.extraDamage);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_REDUCE_DAMAGE, MonsterConfig.reduceDamage);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_FREEZERES,MonsterConfig.freezeRes);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_BURNRES, MonsterConfig.burnRes);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_WEAK, MonsterConfig.weakRes);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_FASTINGRES, MonsterConfig.fastingRes);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_FUNKRES, MonsterConfig.funkRes);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_ASPEED, MonsterConfig.aSpeed);
            MonsterAttr.SetAttr(CreatureCommonAttr.C_MSPEED, MonsterConfig.mSpeed);

            //处理视野
            m_ViewLayer = (uint)ViewLayerType.ENUM_NINE_GRID_LITTLE;
            
            return true;
        }

        public override bool UnInit()
        {
            m_MonsterAttr = null;
            m_MonsterConfig = null;
            return true;
        }

        public override void Update()
        {
            
        }

        public void UpdateSeeLst()
        {
            Scene curScene = SceneMgr.Inst().GetScene(SceneId);
            if (curScene == null)
            {
                return;
            }

            List<uint> newSeeLst = curScene.FindCreatureInSceneFrom9Grid(Pos, ViewLayer);
            if (newSeeLst == null)
            {
                return;
            }

            List<uint> notifySeeLst = new List<uint>();

            CreaturesCreateData createData = new CreaturesCreateData();
            CreatureDestoryData destroyData = new CreatureDestoryData();

            foreach(uint newCid in newSeeLst)
            {
                if (SeeLst.Find(cid => cid == newCid) != newCid)
                {
                    Creature creature = curScene.GetCreature(newCid);
                    if (creature != null)
                    {
                        notifySeeLst.Add(newCid);
                        creature.GetVisibleDataToClient(createData);
                    }
                }
            }

            foreach(uint oldCid in SeeLst)
            {
                if (newSeeLst.Find(cid => cid == oldCid) != oldCid)
                {
                    Creature creature = curScene.GetCreature(oldCid);
                    if (creature != null)
                    {
                        creature.BeenSeeLst.Remove(Cid);
                        destroyData.cids.Add(oldCid);
                    }
                }
            }
        }

        public List<uint> FindCreatureInScene()
        {
            Scene curScene = SceneMgr.Inst().GetScene(SceneId);
            if (curScene != null)
            {
                return curScene.FindCreatureInSceneFrom9Grid(Pos, ViewLayer);
            }
            return null;
        }


        public override bool AddAttr(CreatureCommonAttr attrType, int attrCount, bool syn, uint relationCid)
        {
            if (attrType == CreatureCommonAttr.C_HP && attrCount < 0)
            {

            }

            if (attrCount == 0)
            {
                return false;
            }

            MonsterAttr.AddAttr(attrType, attrCount);

            if (attrType == CreatureCommonAttr.C_HP && MonsterAttr.GetAttrCount(attrType) <= 0)
            {
                syn = true;
                OnDead(relationCid);
            }

            return true;
        }

        public override void SetAttr(CreatureCommonAttr attrType, int attrCount, bool syn)
        {
            MonsterAttr.SetAttr(attrType, attrCount);
        }

        public override void SetAttrCache(CreatureCommonAttr attrType, int attrCount)
        {

        }

        public override void GetVisibleDataToClient(CreaturesCreateData cvData)
        {
            if (cvData != null)
            {
                CreaturesCreateData.Monster monster = new CreaturesCreateData.Monster();
                monster.hp = MonsterAttr.GetAttrCount(CreatureCommonAttr.C_HP);
                monster.monsterCid = Cid;
                monster.monsterConfigId = (uint)MonsterId;
                monster.posX = Pos.X;
                monster.posY = Pos.Y;
                monster.posZ = Pos.Z;
                monster.mspeed = MonsterAttr.GetAttrCount(CreatureCommonAttr.C_MSPEED);
                monster.curstate = (uint)CurState; 
                cvData.monsters.Add(monster);
            }
        }
    }
}
