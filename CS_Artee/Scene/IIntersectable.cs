using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee.Scene
{
    interface IIntersectable
    {
        HitRecord Hit(Ray r);
    }
}
