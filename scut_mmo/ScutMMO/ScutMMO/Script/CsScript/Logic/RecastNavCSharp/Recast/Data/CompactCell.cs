using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Recast.Data
{
    [Serializable]
	public struct CompactCell
	{
        public uint Index { get; set; }
        public uint Count { get; set; }
	}
}
