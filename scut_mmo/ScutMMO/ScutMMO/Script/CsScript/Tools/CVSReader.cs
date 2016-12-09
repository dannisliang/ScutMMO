using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class RowHelper
{
    string[] rows;
    int idx;

    public RowHelper(string[] rs)
    {
        rows = rs;
        idx = 0;
    }

    public string Read()
    {
        return rows[idx++];
    }

    public int ReadInt()
    {
        string s = rows[idx++];
        if (s == null || s == "") return 0;
        try
        {
            return int.Parse(s);
        }
        catch
        {
            Console.WriteLine("强转int数据有误=" + s + "=");
            return 0;
        }

    }
    public bool ReadBool()
    {
        string str = rows[idx++];
        return str.Equals("1") || str.ToLower().Equals("true");
    }
}

public class CVSReader
{
    public struct FieldData
    {
        public string[] FieldText;
    }

    public const int mMaxColumn = 128;
    public const char mSplit = '#';

    private int mSkinLine = 1;

    private int mColumn = 0;

    private List<FieldData> mItems = new List<FieldData>();

    public CVSReader()
    {

    }

    ~CVSReader()
    {

    }

    /// <summary>
    /// 加载配置
    /// </summary>
    public bool LoadText(string configName, int skinLine)
    {
        if (string.IsNullOrEmpty(configName))
        {
            return false;
        }

        mSkinLine = skinLine;

        string strText = System.IO.File.ReadAllText(configName);

        ParseData(strText);
        return true;
    }

    public int FindRowIndex(string key, int iFieldIndex)
    {
        for (int i = 0; i < mItems.Count; i++)
        {
            if (mItems[i].FieldText[iFieldIndex] == key)
            {
                return i;
            }
        }

        return -1;
    }

    public int GetColumnCount() { return mColumn; }
    public int GetRowCount() { return mItems.Count; }

    public string[] GetRow(int idx)
    {
        return mItems[idx].FieldText;
    }
    public void ParseData(string strText)
    {
        string[] lines = strText.Split(new char[] { '\n' });
        int iStartLine = Math.Max(0, mSkinLine);

        for (int i = iStartLine; i < lines.Length; i++)
        {
            ParseLines(lines[i]);
        }
    }

    public void ParseLines(string line)
    {
        string[] vals = line.Split(mSplit);
        FieldData item = new FieldData();
        item.FieldText = new string[mMaxColumn];

        if (vals.Length > mMaxColumn)
        {
            Console.WriteLine("the  table column > " + mMaxColumn);
            return;
        }

        if (mColumn == 0)
        {
            mColumn = vals.Length;

            //empty table
            if (mColumn <= 0)
            {
                Console.WriteLine("the  table column is empty");
            }
        }

        if (mColumn == vals.Length)
        {
            for (int i = 0; i < vals.Length; i++)
            {
                item.FieldText[i] = vals[i].Trim();
            }

            mItems.Add(item);
        }
    }
}
