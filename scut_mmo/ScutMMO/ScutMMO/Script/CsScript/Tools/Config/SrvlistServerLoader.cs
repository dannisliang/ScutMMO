
using System.Collections;
using System.Collections.Generic;



public class SrvlistServerConfig 
{
	public int   isnew; // 是否新服 
	public string   ip; // ip 
	public int   id; // 标识 
	public int   state; // 状态 
	public int   areaid; // 区名 
	public string   name; // 服务器名 
	public int   port; // 端口 

}

public class SrvlistServerConfigTable 
{
    Dictionary<int, SrvlistServerConfig> m_configs = 
        new Dictionary<int, SrvlistServerConfig>();
    public Dictionary<int, SrvlistServerConfig> configs   
    {
        get {
            return m_configs; 
        }
    }

    public object ConfigProcess(string[] row)
    {
        if (row.Length < 7)
        {
            return null;
        }
        RowHelper rh = new RowHelper(row);
        SrvlistServerConfig rec = new SrvlistServerConfig();

		rec.id = Utility.ToInt(rh.Read());	 //标识
		rec.areaid = Utility.ToInt(rh.Read());	 //区名
		rec.name = rh.Read();	 //服务器名
		rec.ip = rh.Read();	 //ip
		rec.port = Utility.ToInt(rh.Read());	 //端口
		rec.state = Utility.ToInt(rh.Read());	 //状态
		rec.isnew = Utility.ToInt(rh.Read());	 //是否新服

        return rec;
    }

    public void Load()
    {
        CVSReader reader = new CVSReader();
        reader.LoadText("Data/Config/Srvlist_server.txt", 1);
        int rows = reader.GetRowCount();
        for (int r = 0; r < rows; ++r)
        {
            string[] row = reader.GetRow(r);
            SrvlistServerConfig ac = ConfigProcess(row) as SrvlistServerConfig;
            configs.Add(ac.id, ac);
        }
    }
}
