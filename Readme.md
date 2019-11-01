# Artee

Artee, as the name might suggest is a Raytracer (or, RT), that I have been working on for a little bit. The intention is that this can function as a simple reference for people that want to learn about the inner workings of Ray and Path tracing.

## Build

This project is written using Visual Studio 2019 Community. The included project files should work no problem using that. If you use a different IDE, you'll have to work around that, but VS doesn't do any weird things to the source files, so that shouldn't be a terrible hurdle.

At present, the only external library that is used is SDL2, which I included using VCPKG. I did this because I could never get the hang of including external libraries the "proper" way, and this method works out of the box.

Make sure to enable your compiler's OpenMP option as well.

## Contributing

I am completely open for contributions of any kind, though I would like to keep this project relatively simple so relative beginners, or people not entirely familiar with C++ (I am no Bjarne Stroustrup, either) can still figure out what is going on with some research.

If you are capable with another programming language, I'm open to exploring adding parallel projects in those languages. Open up an issue so we can go over viability.

### Coding Style

I personally use the Allman bracket style for brackets:

```c++
if (condition)
{
    operation();
}
```

Additionally, I use `CamelCase` for class/struct names, `ALL_CAPS` for constants and `dromedaryCase` for class variables and functions. Furthermore, I have taken to appending an underscore after private variable names.

```c++
struct AmazingStruct
{
    float amazingValue;
}

class AmazingClass
{
public:
    AmazingClass();
    ~AmazingClass();

    void greatMethod(int goodNumber);

private:
    int amazingValue_;
    std::vector<float> niceList_;
}
```
