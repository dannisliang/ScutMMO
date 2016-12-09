using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Web;
using ZyGames.Framework.Common.Serialization;
using ZyGames.Framework.Game.Contract;
using ZyGames.Framework.Game.Service;
using ZyGames.Framework.RPC.IO;
using ZyGames.Framework.RPC.Sockets;

namespace Game.Script
{
    public class CustomActionDispatcher : IActionDispatcher
    {
        public bool TryDecodePackage(ConnectionEventArgs e, out RequestPackage package)
        {
            //������ͷ����Ϣ����ActionId���ַ�������Ӧ��Action����
            package = null;
            byte[] content;
            MessagePack head = ReadMessageHead(e.Data, out content);
            if (head == null)
            {
                return false;
            }
            package = new RequestPackage(head.MsgId, head.SessionId, head.ActionId, head.UserId) { Message = content };

            return true;
        }

        public bool TryDecodePackage(HttpListenerRequest request, out RequestPackage package, out int statusCode)
        {
            statusCode = 200;
            package = null;
            byte[] content;
            var bytes = GetRequestStream(request.InputStream);
            MessagePack head = ReadMessageHead(bytes, out content);
            if (head == null)
            {
                return false;
            }
            package = new RequestPackage(head.MsgId, head.SessionId, head.ActionId, head.UserId) { Message = content };
            return true;
        }

        public bool TryDecodePackage(HttpListenerContext context, out RequestPackage package)
        {
            int statuscode;
            if (TryDecodePackage(context.Request, out package, out statuscode))
            {
                return true;
            }
            return false;
        }

        public bool TryDecodePackage(HttpContext context, out RequestPackage package)
        {
            package = null;
            MessagePack head = null;
            byte[] content = new byte[0];
            var bytes = GetRequestStream(context.Request.InputStream);
            head = ReadMessageHead(bytes, out content);
            if (head == null)
            {
                return false;
            }
            package = new RequestPackage(head.MsgId, head.SessionId, head.ActionId, head.UserId) { Message = content };
            return true;
        }

        public ActionGetter GetActionGetter(RequestPackage package, GameSession session)
        {
            return new ActionGetter(package, session);
        }

        /// <summary>
        /// ����byte[]��ʽ��headLength + headBytes + contentBytes
        /// </summary>
        /// <returns></returns>
        private MessagePack ReadMessageHead(byte[] data, out byte[] content)
        {
            MessagePack headPack = null;
            content = new byte[0];
            try
            {
                //��ͷ��(��֮ǰ��Ȼ����Ҫ��byte[]���ܣ����������ⲽ)
                int pos = 0;
                byte[] headLenBytes = new byte[4];
                Buffer.BlockCopy(data, pos, headLenBytes, 0, headLenBytes.Length);
                pos += headLenBytes.Length;
                int headSize = BitConverter.ToInt32(headLenBytes, 0);
                if (headSize < data.Length)
                {
                    byte[] headBytes = new byte[headSize];
                    Buffer.BlockCopy(data, pos, headBytes, 0, headBytes.Length);
                    pos += headBytes.Length;
                    headPack = ProtoBufUtils.Deserialize<MessagePack>(headBytes);

                    //����Ϣ������
                    if (data.Length > pos)
                    {
                        int len = data.Length - pos;
                        content = new byte[len];
                        Buffer.BlockCopy(data, pos, content, 0, content.Length);
                        //�������ݷŵ�����Actionҵ���ϴ���
                    }
                }
                else
                {
                    //��֧�ֵ����ݸ�ʽ
                }
            }
            catch (Exception ex)
            {
                //��֧�ֵ����ݸ�ʽ
            }
            return headPack;
        }

        public void ResponseError(BaseGameResponse response, ActionGetter actionGetter, int errorCode, string errorInfo)
        {
            //ʵ�ֳ������·�
            ResponsePack head = new ResponsePack()
            {
                MsgId = actionGetter.GetMsgId(),
                ActionId = actionGetter.GetActionId(),
                ErrorCode = errorCode,
                ErrorInfo = errorInfo,
                St = actionGetter.GetSt()
            };
            byte[] headBytes = ProtoBufUtils.Serialize(head);
            byte[] buffer = BufferUtils.AppendHeadBytes(headBytes);
            response.BinaryWrite(buffer);
        }
        private static byte[] GetRequestStream(Stream stream)
        {
            using (BinaryReader readStream = new BinaryReader(stream))
            {

                List<byte> dataBytes = new List<byte>();
                int size = 0;
                while (true)
                {
                    var buffer = new byte[512];
                    size = readStream.Read(buffer, 0, buffer.Length);
                    if (size == 0)
                    {
                        break;
                    }
                    byte[] temp = new byte[size];
                    Buffer.BlockCopy(buffer, 0, temp, 0, size);
                    dataBytes.AddRange(temp);
                }
                return dataBytes.ToArray();
            }
        }

    }
}
