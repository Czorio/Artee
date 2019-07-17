using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee
{
    class HitRecord
    {
        public Vec3 Intersection;
        public Vec3 Normal;
        public Vec3 Color;
        public float t = float.MaxValue;
        public int type = 0;

        public HitRecord()
        {

        }
    }
}
