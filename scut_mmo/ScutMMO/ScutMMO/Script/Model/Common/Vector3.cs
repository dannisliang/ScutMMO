using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Model
{
    [Serializable]
    public class Vector3
    {
        public float X;
        public float Y;
        public float Z;

        public static Vector3 Zero = new Vector3();

        public Vector3(float value = 0)
        {
            X = value;
            Y = value;
            Z = value;
        }

        public Vector3(float x, float y, float z)
        {
            X = x;
            Y = y;
            Z = z;
        }

        public static Vector3 operator -(Vector3 value)
        {
            return new Vector3(-value.X, -value.Y, -value.Z);
        }

        public static Vector3 operator -(Vector3 value1, Vector3 value2)
        {
            return new Vector3(value1.X - value2.X, value1.Y - value2.Y, value1.Z - value2.Z);
        }

        public static bool operator !=(Vector3 value1, Vector3 value2)
        {
            return (value1.X != value2.X || value1.Y != value2.Y || value1.Z != value2.Z);
        }

        public static Vector3 operator *(float scaleFactor, Vector3 value)
        {
            return new Vector3(scaleFactor * value.X, scaleFactor * value.Y, scaleFactor * value.Z);
        }

        public static Vector3 operator *(Vector3 value, float scaleFactor)
        {
            return new Vector3(scaleFactor * value.X, scaleFactor * value.Y, scaleFactor * value.Z);
        }

        public static Vector3 operator *(Vector3 value1, Vector3 value2)
        {
            return new Vector3(value1.X * value2.X, value1.Y * value2.Y, value1.Z * value2.Z);
        }

        public static Vector3 operator /(Vector3 value, float divider)
        {
            return new Vector3(value.X / divider, value.Y / divider, value.Z / divider);
        }

        public static Vector3 operator /(Vector3 value1, Vector3 value2)
        {
            return new Vector3(value1.X/value2.X, value1.Y/value2.Y, value1.Z/value2.Z);
        }

        public static Vector3 operator +(Vector3 value1, Vector3 value2)
        {
            return new Vector3(value1.X + value2.X, value1.Y + value2.Y, value1.Z + value2.Z);
        }

        public static bool operator ==(Vector3 value1, Vector3 value2)
        {
            return (value1.X == value2.X && value1.Y == value2.Y && value1.Z == value2.Z);
        }

        public static Vector3 Add(Vector3 value1, Vector3 value2)
        {
            return new Vector3(value1.X + value2.X, value1.Y + value2.Y, value1.Z + value2.Z);
        }

        public static void Add(ref Vector3 value1, ref Vector3 value2, out Vector3 result)
        {
            result = new Vector3(value1.X + value2.X, value1.Y + value2.Y, value1.Z + value2.Z);
        }

//         public static float Angle(Vector3 from, Vector3 to);
//         public static void Angle(ref Vector3 from, ref Vector3 to, out float result);
//         public static Vector3 Clamp(Vector3 value1, Vector3 min, Vector3 max);
//         public static void Clamp(ref Vector3 value1, ref Vector3 min, ref Vector3 max, out Vector3 result);
//         public static Vector3 Cross(Vector3 vector1, Vector3 vector2);
//         public static void Cross(ref Vector3 vector1, ref Vector3 vector2, out Vector3 result);
        public static float Distance(Vector3 value1, Vector3 value2)
        {
            return (float)Math.Sqrt((value1.X - value2.X) * (value1.X - value2.X) + (value1.Y - value2.Y) * (value1.Y - value2.Y) + (value1.Z - value2.Z) * (value1.Z - value2.Z));
        }
        public static void Distance(ref Vector3 value1, ref Vector3 value2, out float result)
        {
            result = (float)Math.Sqrt((value1.X - value2.X) * (value1.X - value2.X) + (value1.Y - value2.Y) * (value1.Y - value2.Y) + (value1.Z - value2.Z) * (value1.Z - value2.Z));
        }
        public static float DistanceSquared(Vector3 value1, Vector3 value2)
        {
            return ((value1.X - value2.X) * (value1.X - value2.X) + (value1.Y - value2.Y) * (value1.Y - value2.Y) + (value1.Z - value2.Z) * (value1.Z - value2.Z));
        }

        public static void DistanceSquared(ref Vector3 value1, ref Vector3 value2, out float result)
        {
            result = ((value1.X - value2.X) * (value1.X - value2.X) + (value1.Y - value2.Y) * (value1.Y - value2.Y) + (value1.Z - value2.Z) * (value1.Z - value2.Z));
        }

        public static Vector3 Divide(Vector3 value, float divider)
        {
            return new Vector3(value.X / divider, value.Y / divider, value.Z / divider);
        }

        public static Vector3 Divide(Vector3 value1, Vector3 value2)
        {
            return new Vector3(value1.X / value2.X, value1.Y / value2.Y, value1.Z / value2.Z);
        }

        public static void Divide(ref Vector3 value, float divider, out Vector3 result)
        {
            result = new Vector3(value.X / divider, value.Y / divider, value.Z / divider);
        }

        public static void Divide(ref Vector3 value1, ref Vector3 value2, out Vector3 result)
        {
            result = new Vector3(value1.X / value2.X, value1.Y / value2.Y, value1.Z / value2.Z);
        }
// 
//         public static float Dot(Vector3 vector1, Vector3 vector2);
//         public static void Dot(ref Vector3 vector1, ref Vector3 vector2, out float result);
        public override bool Equals(object obj)
        {
            return this == obj;
        }
        public bool Equals(Vector3 other)
        {
            return this == other;
        }

        public override int GetHashCode()
        {
            return (X + Y + Z).GetHashCode();
        }
// 
//         public static Vector3 Hermite(Vector3 value1, Vector3 tangent1, Vector3 value2, Vector3 tangent2, float amount);
//         public static void Hermite(ref Vector3 value1, ref Vector3 tangent1, ref Vector3 value2, ref Vector3 tangent2, float amount, out Vector3 result);
        public float Length()
        {
            return (float)Math.Sqrt(X * X + Y * Y + Z * Z);
        }

        public float LengthSquared()
        {
            return X * X + Y * Y + Z * Z;
        }

//         public static Vector3 Lerp(Vector3 value1, Vector3 value2, float amount);
//         public static void Lerp(ref Vector3 value1, ref Vector3 value2, float amount, out Vector3 result);
//         public static Vector3 Max(Vector3 value1, Vector3 value2);
//         public static void Max(ref Vector3 value1, ref Vector3 value2, out Vector3 result);
//         public static Vector3 Min(Vector3 value1, Vector3 value2);
//         public static void Min(ref Vector3 value1, ref Vector3 value2, out Vector3 result);
        public static Vector3 Multiply(Vector3 value, float scaleFactor)
        {
            return new Vector3(scaleFactor * value.X, scaleFactor * value.Y, scaleFactor * value.Z);
        }

        public static Vector3 Multiply(Vector3 value1, Vector3 value2)
        {
            return new Vector3(value1.X * value2.X, value1.Y * value2.Y, value1.Z * value2.Z);
        }

        public static void Multiply(ref Vector3 value, float scaleFactor, out Vector3 result)
        {
            result = new Vector3(scaleFactor * value.X, scaleFactor * value.Y, scaleFactor * value.Z);
        }

        public static void Multiply(ref Vector3 value1, ref Vector3 value2, out Vector3 result)
        {
            result = new Vector3(value1.X * value2.X, value1.Y * value2.Y, value1.Z * value2.Z);
        }

//         public static Vector3 Negate(Vector3 value);
//         public static void Negate(ref Vector3 value, out Vector3 result);
        public void Normalize()
        {
            float v_length = Length();
            if (v_length == 0)
            {
                X = 0;
                Y = 0;
                Z = 0;
            }
            else
            {
                X = X / v_length;
                Y = Y / v_length;
                Z = Z / v_length;
            }
        }
        public static Vector3 Normalize(Vector3 value)
        {
            Vector3 n = new Vector3();
            float v_length = value.Length();
            if (v_length == 0)
            {
                n.X = 0;
                n.Y = 0;
                n.Z = 0;
            }
            else
            {
                n.X = value.X / v_length;
                n.Y = value.Y / v_length;
                n.Z = value.Z / v_length;
            }
            return n;
        }
//         public static void Normalize(ref Vector3 value, out Vector3 result);
//         public static void OrthoNormalize(ref Vector3 normal, ref Vector3 tangent);
//         public static void OrthoNormalize(ref Vector3 normal, ref Vector3 tangent, ref Vector3 binormal);
//         public static Vector3 Project(Vector3 vector, Vector3 onNormal);
//         public static void Project(ref Vector3 vector, ref Vector3 onNormal, out Vector3 result);
//         public static Vector3 Reflect(Vector3 vector, Vector3 normal);
//         public static void Reflect(ref Vector3 vector, ref Vector3 normal, out Vector3 result);
//         public static Vector3 SmoothStep(Vector3 value1, Vector3 value2, float amount);
//         public static void SmoothStep(ref Vector3 value1, ref Vector3 value2, float amount, out Vector3 result);
//         public static Vector3 Sub(Vector3 value1, Vector3 value2);
//         public static void Sub(ref Vector3 value1, ref Vector3 value2, out Vector3 result);
        //public override string ToString();
    }
}
