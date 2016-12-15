#include "Common/TableData/ChatChatCfg.h"
#include "Common/Reader/CfgReader.h"
#include "base/core/log.h"


ChatChatCfg::ChatChatCfg()
{

}

ChatChatCfg::~ChatChatCfg()
{

}

void ChatChatCfg::Clear()
{
	m_ChatChatCfgMap.clear();
}


bool ChatChatCfg::Init(const char *szCfgFile, const char *szSplitChar)
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
			if (colun < 2)
			{
				continue;
			}

			{
				ChatChatCfgInfo info;
				std::string str = "";

				info.chatId = atoi(pRow->at(j++).c_str());	 //传闻ID
				info.chatType = atoi(pRow->at(j++).c_str());	 //传闻类型


				
				if (nullptr != GetChatChatCfgInfo(info.chatId))
				{
					LogErrFmtPrint("[common] load config error....cfg:%s, key:%d  ", szCfgFile,info.chatId);
					return false;
				}

				m_ChatChatCfgMap[info.chatId] = info;
			}
		}
	}

	return true;
}

bool ChatChatCfg::UnInit()
{
	Clear();
	return true;
}

const ChatChatCfgInfo *ChatChatCfg::GetChatChatCfgInfo(int32_t chatId)
{
	ChatChatCfgMap::iterator iter = m_ChatChatCfgMap.find(chatId);
	return (iter != m_ChatChatCfgMap.end()) ? &iter->second : nullptr;
}
