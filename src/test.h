#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

namespace SDL2
{

class Renderer
{
    private:
        SDL_Renderer *renderer;

    public:
        Renderer(SDL_Renderer *renderer);
        Renderer(Renderer &&other);
        Renderer();

        ~Renderer();

        Renderer &operator =(Renderer &&other);

        operator SDL_Renderer*();
};


class Window
{
    private:
        SDL_Window *window;

        string title;
        int width;
        int height;

    public:
        Window(string title, int width, int height);
        Window();

        Renderer CreateRenderer();

        ~Window();

        operator SDL_Window*();
};

}
