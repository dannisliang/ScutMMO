using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Common
{
    public interface IEventExecuteSink
    {

    }

    public static class ServerEvent
    {
        public const uint EVENT_FIRE_MAX_LAYER = 20;//事件发送最大层数
        public const uint EVENT_REF_MAX_CNT = 5;//事件引用最大层数(避免事件嵌套层数太多出现死循环)
        public bool Init()
        {

        }

        public bool UnInit()
        {

        }

        //订阅执行事件
        bool Subscribe(IEventExecuteSink pSink, uint nEventId, uint nSrcId, );
    }
}
