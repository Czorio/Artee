using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee
{
    /// <summary>
    /// A 3D vector class. Has many uses, such as: Position in 3D, Direction in 3D, RGB Color.
    /// Also provides a range of functions associated with a vector.
    /// </summary>
    class Vec3
    {
        private float x, y, z;

        public float X { get => x; set => x = value; }
        public float Y { get => y; set => y = value; }
        public float Z { get => z; set => z = value; }

        /// <summary>
        /// Default constructor for the Vec3 class. Initializes all values to 0.0f.
        /// </summary>
        public Vec3()
        {
            x = y = z = 0.0f;
        }

        /// <summary>
        /// Constructor for the Vec3 class. Broadcasts a to all values.
        /// </summary>
        /// <param name="a">The value to broadcast</param>
        public Vec3(float a)
        {
            x = y = z = a;
        }

        /// <summary>
        /// Constructor for the Vec3 class. Sets each value separately.
        /// </summary>
        /// <param name="x">x value</param>
        /// <param name="y">y value</param>
        /// <param name="z">z value</param>
        public Vec3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        /// <summary>
        /// Normalizes the vector in-place.
        /// </summary>
        public void Normalize()
        {
            float l = GetLength();

            x /= l;
            y /= l;
            z /= l;
        }

        /// <summary>
        /// Normalizes and returns a copy of the vector.
        /// </summary>
        /// <returns>A Normalzied copy of the vector</returns>
        public Vec3 Normalized()
        {
            float l = GetLength();
            return new Vec3(x / l, y / l, z / l);
        }

        /// <summary>
        /// Calculates the length of the vector.
        /// </summary>
        /// <returns>The length of the vector</returns>
        public float GetLength()
        {
            return (float)Math.Sqrt(GetSquaredLength());
        }

        /// <summary>
        /// Calculates the squared length of the vector. Skips the square root step, increasing performance.
        /// </summary>
        /// <returns>The squared length of the vector</returns>
        public float GetSquaredLength()
        {
            return x * x + y * y + z * z;
        }

        /// <summary>
        /// Calculates and returns a dot product with the vector and another vector.
        /// A dot product is equal to the Cos(a) between two vectors, where a is the angle between vectors.
        /// </summary>
        /// <param name="b">The other vector</param>
        /// <returns>The dot product between two vectors</returns>
        public float Dot(Vec3 b)
        {
            return x * b.x + y * b.y + z * b.z;
        }

        /// <summary>
        /// Calculates and returns a cross product with the vector and another vector.
        /// A cross product results in another (right-handed) vector that is perpendicular to both operands.
        /// </summary>
        /// <param name="b">The other vector</param>
        /// <returns>The cross product between two vectors</returns>
        public Vec3 Cross(Vec3 b)
        {
            return new Vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
        }

        public static Vec3 operator +(Vec3 a, Vec3 b)
        {
            return new Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
        }

        public static Vec3 operator -(Vec3 a, Vec3 b)
        {
            return new Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
        }

        public static Vec3 operator -(Vec3 a)
        {
            return new Vec3(-a.x, -a.y, -a.z);
        }

        public static Vec3 operator *(Vec3 a, Vec3 b)
        {
            return new Vec3(a.x * b.x, a.y * b.y, a.z * b.z);
        }

        public static Vec3 operator *(Vec3 a, float f)
        {
            return new Vec3(a.x * f, a.y * f, a.z * f);
        }
        public static Vec3 operator *(float f, Vec3 a)
        {
            return new Vec3(a.x * f, a.y * f, a.z * f);
        }

        public static Vec3 operator /(Vec3 a, Vec3 b)
        {
            return new Vec3(a.x / b.x, a.y / b.y, a.z / b.z);
        }

        public static Vec3 operator /(Vec3 a, float f)
        {
            return new Vec3(a.x / f, a.y / f, a.z / f);
        }

        /// <summary>
        /// Normalizes a vector.
        /// </summary>
        /// <param name="v">The vector to normalize</param>
        /// <returns>A normalized copy of the vector</returns>
        public static Vec3 Normalize(Vec3 v)
        {
            float l = v.GetLength();
            return new Vec3(v.x / l, v.y / l, v.z / l);
        }

        /// <summary>
        /// Calculates the dot product between two vectors.
        /// </summary>
        /// <param name="a">The first operand</param>
        /// <param name="b">The second operand</param>
        /// <returns>The dot product between two vectors</returns>
        public static float Dot(Vec3 a, Vec3 b)
        {
            return a.x * b.x + a.y * b.y + a.z * b.z;
        }

        /// <summary>
        /// Calculates the cross product between two vectors.
        /// </summary>
        /// <param name="a">The first operand</param>
        /// <param name="b">The second operand</param>
        /// <returns>The cross product between two vectors</returns>
        public static Vec3 Cross(Vec3 a, Vec3 b)
        {
            return new Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
        }
    }
}
