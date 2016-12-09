using System;

namespace Recast.Data
{
    [Serializable]
    public class Span
    {
        public uint SMin { get; set; }
        public uint SMax { get; set; }
        public uint Area { get; set; }
        public Span Next { get; set; }

        public Span()
        {
        }
    }
}