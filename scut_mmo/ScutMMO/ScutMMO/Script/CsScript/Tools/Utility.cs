using System;
using System.Text;
using System.Security.Cryptography;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Reflection;


public class Utility
{

    private static uint mnEntityId = UInt32.MaxValue - 10000000;

    private const int SPLIT_ELEMENT_NUM = 12;
    private static int[] mnIntCache = new int[SPLIT_ELEMENT_NUM];
    private static string[] STRING_SEPARATORS = {","};

    static public uint RequestId()
    {
        return ++mnEntityId;
    }

    public static int ToInt(string str)
    {
        try
        {
            if (str == "")
                return 0;
            return System.Int32.Parse(str);
        }
        catch (System.Exception ex)
        {
            return 0;
        }
    }

    public static uint ToUInt(string str)
    {
        try
        {
            return System.UInt32.Parse(str);
        }
        catch (System.Exception ex)
        {
            return 0;
        }
    }

    public static float ToFloat(string str)
    {
        try
        {
            return (float)System.Double.Parse(str);
        }
        catch (System.Exception ex)
        {
            //LogError(ex.ToString());
            return 0;
        }
    }
}