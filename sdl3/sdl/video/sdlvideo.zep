namespace Sdl3\SDL\Video;

%{
#include <SDL3/SDL.h>
#include <stdio.h>
}%

class SDLVideo
{
    public static function SDLCreateWindow(string title, int width, int height, int flags) -> int
    {
        int ptr;

        %{
            SDL_Window *window = SDL_CreateWindow(Z_STRVAL(title), (int) width, (int) height, (SDL_WindowFlags) flags);
            ptr = (zend_long)(uintptr_t) window;
        }%

        if ptr == 0 {
            throw new \RuntimeException("SDL_CreateWindow failed: " . \Sdl3\SDL\SDLError::SDLGetError());
        }

        return ptr;
    }

    public static function SDLGetWindowSize(int window) -> array
    {
        int w;
        int h;

        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int ww = 0, wh = 0;
            SDL_GetWindowSize(win, &ww, &wh);
            w = (zend_long) ww;
            h = (zend_long) wh;
        }%

        return [w, h];
    }

    public static function SDLGetWindowPosition(int window) -> array
    {
        int x;
        int y;

        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int wx = 0, wy = 0;
            SDL_GetWindowPosition(win, &wx, &wy);
            x = (zend_long) wx;
            y = (zend_long) wy;
        }%

        return [x,y];
    }

    public static function SDLGetWindowSizeInPixels(int window) -> array
    {
        int w;
        int h;

        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int pw = 0, ph = 0;
            SDL_GetWindowSizeInPixels(win, &pw, &ph);
            w = (zend_long) pw;
            h = (zend_long) ph;
        }%


        return [w,h];
    }

    public static function SDLGetWindowMinimumSize(int window) -> array
    {
        int min_w;
        int min_h;

        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int pw = 0, ph = 0;
            SDL_GetWindowMinimumSize(win, &pw, &ph);
            min_w = (zend_long) pw;
            min_h = (zend_long) ph;

        }%

        return [min_w,min_h];
    }

    public static function SDLGetWindowMaximumSize(int window) -> array
    {
        int max_w;
        int max_h;

        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int pw = 0, ph = 0;
            SDL_GetWindowMaximumSize(win, &pw, &ph);
            max_w = (zend_long) pw;
            max_h = (zend_long) ph;

        }%

        return [max_w,max_h];
    }

    public static function SDLGetWindowAspectRatio(int window) -> array
    {
        double min_aspect;
        double max_aspect;

        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            float mn = 0.0f, mx = 0.0f;
            SDL_GetWindowAspectRatio(win, &mn, &mx);
            min_aspect = (double) mn;
            max_aspect = (double) mx;
        }%

        return [min_aspect, max_aspect];
    }

    public static function SDLSetWindowIcon(int window, int surface) -> bool
    {
        bool result;

        %{
            SDL_Window  *win  = (SDL_Window *)(uintptr_t) window;
            SDL_Surface *icon = (SDL_Surface *)(uintptr_t) surface;
            result = SDL_SetWindowIcon(win, icon);
        }%

        return result;
    }

    public static function SDLDestroyWindow(int window) -> void
    {
        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            SDL_DestroyWindow(win);
        }%
    }

    public static function SDLCreateWindowAndRenderer(string title, int w, int h, int flags) -> array
    {
        int window_ptr;
        int renderer_ptr;
        bool result;

        %{
            SDL_Window   *win = NULL;
            SDL_Renderer *ren = NULL;
            result = SDL_CreateWindowAndRenderer(Z_STRVAL(title), (int) w, (int) h, (SDL_WindowFlags) flags, &win, &ren);
            window_ptr   = (zend_long)(uintptr_t) win;
            renderer_ptr = (zend_long)(uintptr_t) ren;
        }%

        if !result {
            return [];
        }

        return ["window": window_ptr, "renderer": renderer_ptr];
    }

}
