#include "Common/TableData/MonsterMonsterCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


MonsterMonsterCfg::MonsterMonsterCfg()
{

}

MonsterMonsterCfg::~MonsterMonsterCfg()
{

}

void MonsterMonsterCfg::Clear()
{
	m_MonsterMonsterCfgMap.clear();
}


bool MonsterMonsterCfg::Init(const char *szCfgFile, const char *szSplitChar)
{
	CfgReader reader;
	if (!reader.LoadCfg(szCfgFile, szSplitChar))
	{
		LogErrFmtPrint("[common] reader config error....cfg:%s ", szCfgFile);
		return false;
	}
	int32_t row = reader.GetRowCount();
	for (int i = 0; i < row; ++i)
	{
		const VecRow *pRow = reader.GetRow(i);
		if (nullptr != pRow)
		{
			int32_t colun = pRow->size();
			int32_t j = 0;
			if (colun < 59)
			{
				continue;
			}

			{
				MonsterMonsterCfgInfo info;
				std::string str = "";

				info.monsterID = atoi(pRow->at(j++).c_str());	 //怪物ID
				info.monsterLV = atoi(pRow->at(j++).c_str());	 //怪物等级
				info.monsterCfgType = atoi(pRow->at(j++).c_str());	 //怪物配置类型
				info.monsterRefreshTime = atoi(pRow->at(j++).c_str());	 //怪物刷新时间
				info.monsterFightType = atoi(pRow->at(j++).c_str());	 //怪物战斗类型
				info.monsterType = atoi(pRow->at(j++).c_str());	 //怪物类型
				info.monsterAtkType = atoi(pRow->at(j++).c_str());	 //普攻方式
				info.specialAI = atoi(pRow->at(j++).c_str());	 //怪物特殊AI
				info.bodyStayTime = atoi(pRow->at(j++).c_str());	 //尸体留存时间
				info.isSkin = atoi(pRow->at(j++).c_str());	 //是否可剥取
				info.deathTrigger = pRow->at(j++).c_str();	 //死亡触发器
				info.bornTrigger = pRow->at(j++).c_str();	 //出生触发器
				info.actionRange = atoi(pRow->at(j++).c_str());	 //怪物活动范围
				info.viewType = atoi(pRow->at(j++).c_str());	 //视野类型
				info.view = pRow->at(j++).c_str();	 //视野
				info.attackRange = atoi(pRow->at(j++).c_str());	 //攻击范围
				info.pursueRange = atoi(pRow->at(j++).c_str());	 //追击范围
				info.maxHP = atoi(pRow->at(j++).c_str());	 //最大生命值
				info.maxMP = atoi(pRow->at(j++).c_str());	 //最大魔法值
				info.ap = atoi(pRow->at(j++).c_str());	 //物理攻击
				info.mat = atoi(pRow->at(j++).c_str());	 //魔法攻击
				info.dp = atoi(pRow->at(j++).c_str());	 //物理防御
				info.mdp = atoi(pRow->at(j++).c_str());	 //魔法防御
				info.hit = atoi(pRow->at(j++).c_str());	 //命中
				info.dodge = atoi(pRow->at(j++).c_str());	 //闪避
				info.crit = atoi(pRow->at(j++).c_str());	 //暴击
				info.toughness = atoi(pRow->at(j++).c_str());	 //韧性
				info.critRate = atoi(pRow->at(j++).c_str());	 //暴击倍率
				info.critExtraDamage = atoi(pRow->at(j++).c_str());	 //暴击额外伤害
				info.critReduceDamage = atoi(pRow->at(j++).c_str());	 //暴击额外免伤
				info.extraDamage = atoi(pRow->at(j++).c_str());	 //额外伤害
				info.reduceDamage = atoi(pRow->at(j++).c_str());	 //额外免伤
				info.damageRate = atoi(pRow->at(j++).c_str());	 //伤害率
				info.reduceDamageRate = atoi(pRow->at(j++).c_str());	 //免伤率
				info.freezeRes = atoi(pRow->at(j++).c_str());	 //冰冻抗性
				info.burnRes = atoi(pRow->at(j++).c_str());	 //灼烧抗性
				info.weakRes = atoi(pRow->at(j++).c_str());	 //虚弱抗性
				info.fastingRes = atoi(pRow->at(j++).c_str());	 //禁食抗性
				info.funkRes = atoi(pRow->at(j++).c_str());	 //恐惧抗性
				info.mSpeed = atoi(pRow->at(j++).c_str());	 //移动速度
				info.aSpeed = atoi(pRow->at(j++).c_str());	 //攻击速度
				info.normalSkill = atoi(pRow->at(j++).c_str());	 //普攻技能
				info.normalSkillLevel = atoi(pRow->at(j++).c_str());	 //普攻技能等级
				info.dropDefault = atoi(pRow->at(j++).c_str());	 //默认掉落
				info.exp = atoi(pRow->at(j++).c_str());	 //经验产出
				info.isBelongToPlayer = atoi(pRow->at(j++).c_str());	 //怪物归属是否显示
				info.protectTime = atoi(pRow->at(j++).c_str());	 //怪物归属保护时间
				info.restWaitTime = atoi(pRow->at(j++).c_str());	 //怪物休闲等待时间
				info.deathEffect = pRow->at(j++).c_str();	 //死亡特效
				info.anchor = atoi(pRow->at(j++).c_str());	 //特效挂点
				info.skinLink = atoi(pRow->at(j++).c_str());	 //剥皮关联
				info.patrolType = atoi(pRow->at(j++).c_str());	 //巡逻类型
				info.patrolPath = atoi(pRow->at(j++).c_str());	 //巡逻路径
				info.isFormationOn = atoi(pRow->at(j++).c_str());	 //是否开启巡逻阵型
				info.isShiftOff = atoi(pRow->at(j++).c_str());	 //是否关闭位移
				info.isFloatingOff = atoi(pRow->at(j++).c_str());	 //是否关闭浮空
				info.isStiffOff = atoi(pRow->at(j++).c_str());	 //是否关闭僵直
				info.isDownOff = atoi(pRow->at(j++).c_str());	 //是否关闭击倒
				info.isAIWorkWhenNobody = atoi(pRow->at(j++).c_str());	 //是否无人时启用AI


				
				if (nullptr != GetMonsterMonsterCfgInfo(info.monsterID))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.monsterID);
					return false;
				}

				m_MonsterMonsterCfgMap[info.monsterID] = info;
			}
		}
	}

	return true;
}

bool MonsterMonsterCfg::UnInit()
{
	Clear();
	return true;
}

const MonsterMonsterCfgInfo *MonsterMonsterCfg::GetMonsterMonsterCfgInfo(int32_t monsterID)
{
	MonsterMonsterCfgMap::iterator iter = m_MonsterMonsterCfgMap.find(monsterID);
	return (iter != m_MonsterMonsterCfgMap.end()) ? &iter->second : nullptr;
}
