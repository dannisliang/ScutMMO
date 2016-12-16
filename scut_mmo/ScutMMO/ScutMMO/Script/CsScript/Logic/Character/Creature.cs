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
        bool AddAttr(CreatureCommonAttr CAttrType, int attrValue);

        void SetAttr(CreatureCommonAttr CAttrType, int attrValue);

        int GetAttrType(CreatureCommonAttr CAttrType);

        uint GetAttrCount(CreatureCommonAttr CAttrType);
    }

    public abstract class Creature : BaseDisposable
    {
        protected uint m_SceneId;
        protected uint m_MapId;
        protected uint m_Cid;
        protected CreatureTypeEnum m_CreatureType;
        protected List<UInt32> m_SeeLst;
        protected List<UInt32> m_BeenSeeLst;
        protected Vector3 m_Pos;
        protected Vector3 m_Dir;
        protected uint m_ViewLayer;
        protected CreatureState m_CurState;

        public uint SceneId
        {
            get { return m_SceneId; }
            set { m_SceneId = value; }
        }

        public uint MapID
        {
            get { return m_MapId; }
            set { m_MapId = value; }
        }

        public uint Cid
        {
            get { return m_Cid; }
            set { m_Cid = value; }
        }

        public CreatureTypeEnum CreatureType
        {
            get { return m_CreatureType; }
            protected set { m_CreatureType = value; }
        }

        public List<UInt32> SeeLst { get {return m_SeeLst; } }

        public List<UInt32> BeenSeeLst { get { return m_BeenSeeLst; } }

        public CreatureState CurState
        {
            get { return m_CurState; }
            set { m_CurState = value; }
        }

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

        public uint ViewLayer { get { return m_ViewLayer; } }

        public Creature()
        {
            m_SceneId = 0;
            m_MapId = 0;
            m_Cid = 0;
            m_CreatureType = CreatureTypeEnum.CREATURE_NONE;
            m_CurState = CreatureState.State_Init;
            m_SeeLst = new List<uint>();
            m_BeenSeeLst = new List<uint>();
            m_Pos = new Vector3();
            m_Dir = new Vector3();
            m_ViewLayer = (uint)ViewLayerType.ENUM_NINE_GRID_LITTLE; //1级9各宫
        }

        public abstract bool Init();

        public abstract bool UnInit();

        public abstract void Update();

        public abstract void UpdateSeeLst();

        public abstract bool AddAttr(CreatureCommonAttr attrType, int attrCount, bool syn, uint relationCid);

        public abstract void SetAttr(CreatureCommonAttr attrType, int attrCount, bool syn);

        public abstract void SetAttrCache(CreatureCommonAttr attrType, int attrCount);

        public abstract void OnDead(uint killerCid);

        public abstract void OnNormal();

        public abstract void OnCorpse();

        public abstract void OnRelive(uint saveCid);

        	//******************调用部件接口******************
	    //1、知道场景Id调用场景Id sceneId
	    //2、如果不知道场景Id, sceneId=0, 调用mapId(策划表id)
        public abstract bool TransScene(uint scenceId, Vector3 dstPos, uint mapId = 0); //强制传送(场景内传送、切场景传送)
	    //进入场景(这个接口只给移动部件和生物内部自身调用，其他请调用transScene)
        public abstract bool EnterScene(uint sceneId, Vector3 enterPos);

	    //离开场景
        public abstract bool LeaveScene();

	    //瞬间移动
        public abstract bool Teleporting(Vector3 dstPos);
	    //被击退
        public abstract bool BeatBack(Vector3 dstPos);

	    //向目标点移动 主要AI用
        public abstract bool MoveTo(Vector3 dstPos);
	    //停止当前移动
        public abstract void StopMove();

        public abstract void GetVisibleDataToClient(CreaturesCreateData cvData);

        /// <summary>
        /// 
        /// </summary>
        /// <param name="disposing"></param>
        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                //释放 托管资源 
                m_SeeLst = null;
                m_BeenSeeLst = null;
                m_Pos = null;
                m_Dir = null;
            }
            base.Dispose(disposing);
        }
    }
}
