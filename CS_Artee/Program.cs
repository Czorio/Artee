using System;
using System.Diagnostics;
using SixLabors.ImageSharp;
using SixLabors.ImageSharp.PixelFormats;

namespace CS_Artee
{
    class Program
    {
        const int imageWidth = 1920;
        const int imageHeight = 1080;
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Renderer r = new Renderer(imageWidth, imageHeight);
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            r.RenderFrame();
            stopwatch.Stop();
            char[,,] byteBuffer = r.GetOutput();

            Console.WriteLine("rendertime: {0} ms", stopwatch.ElapsedMilliseconds);

            Image<Rgba32> image = new Image<Rgba32>(imageWidth, imageHeight);

            for (int x = 0; x < imageWidth; x++)
            {
                for (int y = 0; y < imageHeight; y++)
                {
                    String hex = "";
                    hex += Convert.ToInt32(byteBuffer[x, y, 0]).ToString("X2");
                    hex += Convert.ToInt32(byteBuffer[x, y, 1]).ToString("X2");
                    hex += Convert.ToInt32(byteBuffer[x, y, 2]).ToString("X2");
                    hex += "FF";
                    image[x, y] = Rgba32.FromHex(hex);
                }
            }

            image.Save("Output.png");
        }
    }
}
