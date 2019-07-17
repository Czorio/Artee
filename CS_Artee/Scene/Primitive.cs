using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee.Scene
{
    abstract class Primitive : IIntersectable
    {
        private protected Material material;

        public abstract HitRecord Hit(Ray r);
    }
}
