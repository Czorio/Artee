using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee.Scene
{
    class Material
    {
        private Vec3 color;
        private float specularity;

        public float Specularity { get => specularity; set => specularity = value; }
        public Vec3 Color { get => color; set => color = value; }

        public Material(Vec3 color, float specularity)
        {
            this.color = color;
            this.specularity = specularity;
        }

    }
}
