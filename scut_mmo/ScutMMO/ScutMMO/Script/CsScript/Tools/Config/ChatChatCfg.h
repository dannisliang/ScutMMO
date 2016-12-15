
#pragma once

#include "base/core/singleton.h"
#include "Common/TableDefine.h"


class ChatChatCfg : public ManualSingleton <ChatChatCfg>
{
	friend ManualSingleton <ChatChatCfg>;
public:
	ChatChatCfg();
	~ChatChatCfg();
	bool Init(const char *szCfgFile, const char *szSplitChar);
	bool UnInit();
	void Clear();
	const ChatChatCfgInfo *GetChatChatCfgInfo(int32_t chatId);
	const ChatChatCfgMap *GetChatChatCfgMap() { return &m_ChatChatCfgMap; }
private:
	ChatChatCfgMap m_ChatChatCfgMap;
};

#define  g_MakeChatChatCfgTable() (ChatChatCfg::Instance())
#define  g_GetChatChatCfgTable() (ChatChatCfg::GetInstance())
#define  g_DelChatChatCfgTable() (ChatChatCfg::Destroy())