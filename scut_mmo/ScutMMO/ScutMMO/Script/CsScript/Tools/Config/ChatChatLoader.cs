
using System.Collections;
using System.Collections.Generic;



public class ChatChatConfig 
{
	public int   chatType; // 传闻类型 
	public int   chatId; // 传闻ID 

}

public class ChatChatConfigTable 
{
    Dictionary<int, ChatChatConfig> m_configs = 
        new Dictionary<int, ChatChatConfig>();
    public Dictionary<int, ChatChatConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 2)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        ChatChatConfig rec = new ChatChatConfig();

		rec.chatId = Utility.ToInt(rh.Read());	 //传闻ID
		rec.chatType = Utility.ToInt(rh.Read());	 //传闻类型

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Chat_chat.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            ChatChatConfig ac = ConfigProcess(row) as ChatChatConfig;
            configs.Add(ac.chatId, ac);
        }
    }
}
