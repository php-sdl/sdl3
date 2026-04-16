namespace Sdl3\SDL\Surface;

%{
#include <SDL3/SDL.h>
#include <stdio.h>
}%

class SDLSurface
{
    public static function SDLCreateSurface(int width, int height, int format) -> array
    {
        int ptr;
        int flags;
        int fmt;
        int w;
        int h;
        int pitch;
        int pixels_ptr;
        array pixels_data;
        int refcount;

        %{
            SDL_Surface *surf = SDL_CreateSurface((int) width, (int) height, (SDL_PixelFormat) format);

            if (!surf) {
                ptr = 0; flags = 0; fmt = 0; w = 0; h = 0; pitch = 0; pixels_ptr = 0; refcount = 0;
                array_init(&pixels_data);
            } else {
                ptr        = (zend_long)(uintptr_t) surf;
                flags      = (zend_long) surf->flags;
                fmt        = (zend_long) surf->format;
                w          = (zend_long) surf->w;
                h          = (zend_long) surf->h;
                pitch      = (zend_long) surf->pitch;
                pixels_ptr = surf->pixels ? (zend_long)(uintptr_t) surf->pixels : 0;
                refcount   = (zend_long) surf->refcount;
                array_init(&pixels_data);
                if (surf->pixels) {
                    for (int py = 0; py < surf->h; py++) {
                        Uint32 *row = (Uint32 *)(((Uint8 *)surf->pixels) + py * surf->pitch);
                        for (int px = 0; px < surf->w; px++) {
                            add_next_index_long(&pixels_data, (zend_long)(zend_ulong)row[px]);
                        }
                    }
                }
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "flags": flags, "format": fmt, "w": w, "h": h, "pitch": pitch, "pixels": ["ptr": pixels_ptr, "data": pixels_data], "refcount": refcount];
    }

    public static function SDLDuplicateSurface(int surface) -> array
    {
        int ptr;
        int flags;
        int fmt;
        int w;
        int h;
        int pitch;
        int pixels_ptr;
        array pixels_data;
        int refcount;

        %{
            SDL_Surface *src  = (SDL_Surface *)(uintptr_t) surface;
            SDL_Surface *surf = SDL_DuplicateSurface(src);

            if (!surf) {
                ptr = 0; flags = 0; fmt = 0; w = 0; h = 0; pitch = 0; pixels_ptr = 0; refcount = 0;
                array_init(&pixels_data);
            } else {
                ptr        = (zend_long)(uintptr_t) surf;
                flags      = (zend_long) surf->flags;
                fmt        = (zend_long) surf->format;
                w          = (zend_long) surf->w;
                h          = (zend_long) surf->h;
                pitch      = (zend_long) surf->pitch;
                pixels_ptr = surf->pixels ? (zend_long)(uintptr_t) surf->pixels : 0;
                refcount   = (zend_long) surf->refcount;
                array_init(&pixels_data);
                if (surf->pixels) {
                    for (int py = 0; py < surf->h; py++) {
                        Uint32 *row = (Uint32 *)(((Uint8 *)surf->pixels) + py * surf->pitch);
                        for (int px = 0; px < surf->w; px++) {
                            add_next_index_long(&pixels_data, (zend_long)(zend_ulong)row[px]);
                        }
                    }
                }
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "flags": flags, "format": fmt, "w": w, "h": h, "pitch": pitch, "pixels": ["ptr": pixels_ptr, "data": pixels_data], "refcount": refcount];
    }

    public static function SDLConvertSurface(int surface, int format) -> array
    {
        int ptr;
        int flags;
        int fmt;
        int w;
        int h;
        int pitch;
        int pixels_ptr;
        array pixels_data;
        int refcount;

        %{
            SDL_Surface *src  = (SDL_Surface *)(uintptr_t) surface;
            SDL_Surface *surf = SDL_ConvertSurface(src, (SDL_PixelFormat) format);

            if (!surf) {
                ptr = 0; flags = 0; fmt = 0; w = 0; h = 0; pitch = 0; pixels_ptr = 0; refcount = 0;
                array_init(&pixels_data);
            } else {
                ptr        = (zend_long)(uintptr_t) surf;
                flags      = (zend_long) surf->flags;
                fmt        = (zend_long) surf->format;
                w          = (zend_long) surf->w;
                h          = (zend_long) surf->h;
                pitch      = (zend_long) surf->pitch;
                pixels_ptr = surf->pixels ? (zend_long)(uintptr_t) surf->pixels : 0;
                refcount   = (zend_long) surf->refcount;
                array_init(&pixels_data);
                if (surf->pixels) {
                    for (int py = 0; py < surf->h; py++) {
                        Uint32 *row = (Uint32 *)(((Uint8 *)surf->pixels) + py * surf->pitch);
                        for (int px = 0; px < surf->w; px++) {
                            add_next_index_long(&pixels_data, (zend_long)(zend_ulong)row[px]);
                        }
                    }
                }
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "flags": flags, "format": fmt, "w": w, "h": h, "pitch": pitch, "pixels": ["ptr": pixels_ptr, "data": pixels_data], "refcount": refcount];
    }

    public static function SDLSurfaceToBlackAndWhite(int surface) -> void
    {
        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            int x, y;
            for (y = 0; y < surf->h; y++) {
                Uint32 *pixels = (Uint32 *)(((Uint8 *) surf->pixels) + (y * surf->pitch));
                for (x = 0; x < surf->w; x++) {
                    Uint8 *p = (Uint8 *)(&pixels[x]);
                    const Uint32 average = (((Uint32) p[1]) + ((Uint32) p[2]) + ((Uint32) p[3])) / 3;
                    if (average == 0) {
                        p[0] = p[3] = 0xFF; p[1] = p[2] = 0;
                    } else {
                        p[1] = p[2] = p[3] = (average > 50) ? 0xFF : 0x00;
                    }
                }
            }
        }%
    }

    public static function SDLBlitSurface(int src, var srcrect = null, int dst, var dstrect = null) -> bool
    {
        bool result;

        %{
            SDL_Surface *src_surf = (SDL_Surface *)(uintptr_t) src;
            SDL_Surface *dst_surf = (SDL_Surface *)(uintptr_t) dst;

            SDL_Rect src_buf = {0}, dst_buf = {0};
            const SDL_Rect *src_ptr = NULL;
            const SDL_Rect *dst_ptr = NULL;

            if (Z_TYPE_P(srcrect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(srcrect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(srcrect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(srcrect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(srcrect), 3);
                if (x && y && w && h) {
                    src_buf.x = (int) zval_get_long(x);
                    src_buf.y = (int) zval_get_long(y);
                    src_buf.w = (int) zval_get_long(w);
                    src_buf.h = (int) zval_get_long(h);
                    src_ptr = &src_buf;
                }
            }

            if (Z_TYPE_P(dstrect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(dstrect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(dstrect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(dstrect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(dstrect), 3);
                if (x && y && w && h) {
                    dst_buf.x = (int) zval_get_long(x);
                    dst_buf.y = (int) zval_get_long(y);
                    dst_buf.w = (int) zval_get_long(w);
                    dst_buf.h = (int) zval_get_long(h);
                    dst_ptr = &dst_buf;
                }
            }

            result = SDL_BlitSurface(src_surf, src_ptr, dst_surf, dst_ptr);
        }%

        return result;
    }

    public static function SDLFillSurfaceRect(int surface, int color, var rect = null) -> bool
    {
        bool result;

        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            SDL_Rect r, *rp = NULL;

            if (Z_TYPE_P(rect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(rect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(rect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(rect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(rect), 3);
                if (x && y && w && h) {
                    r.x = (int) zval_get_long(x);
                    r.y = (int) zval_get_long(y);
                    r.w = (int) zval_get_long(w);
                    r.h = (int) zval_get_long(h);
                    rp = &r;
                }
            }

            result = SDL_FillSurfaceRect(surf, rp, (Uint32) color);
        }%

        return result;
    }

    public static function SDLMapRGB(int format, int palette, int r, int g, int b) -> int
    {
        int result;

        %{
            const SDL_PixelFormatDetails *fmt = (const SDL_PixelFormatDetails *)(uintptr_t) format;
            const SDL_Palette            *pal = palette ? (const SDL_Palette *)(uintptr_t) palette : NULL;
            result = (zend_long) SDL_MapRGB(fmt, pal, (Uint8) r, (Uint8) g, (Uint8) b);
        }%

        return result;
    }

    public static function SDLLockSurface(int surface) -> bool
    {
        bool result;

        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            result = SDL_LockSurface(surf);
        }%

        return result;
    }

    public static function SDLUnlockSurface(int surface) -> void
    {
        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            SDL_UnlockSurface(surf);
        }%
    }

    public static function SDLDestroySurface(int surface) -> void
    {
        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            SDL_DestroySurface(surf);
        }%
    }

    public static function SDLLoadPNG(string file) -> array
    {
        int ptr;
        int flags;
        int format;
        int w;
        int h;
        int pitch;
        int pixels_ptr;
        array pixels_data;
        int refcount;

        %{
            SDL_Surface *surface = SDL_LoadPNG(Z_STRVAL(file));
            if (!surface) {
                ptr = 0; flags = 0; format = 0; w = 0; h = 0; pitch = 0; pixels_ptr = 0; refcount = 0;
                array_init(&pixels_data);
            } else {
                ptr        = (zend_long)(uintptr_t) surface;
                flags      = (zend_long) surface->flags;
                format     = (zend_long) surface->format;
                w          = (zend_long) surface->w;
                h          = (zend_long) surface->h;
                pitch      = (zend_long) surface->pitch;
                pixels_ptr = surface->pixels ? (zend_long)(uintptr_t) surface->pixels : 0;
                refcount   = (zend_long) surface->refcount;
                array_init(&pixels_data);
                if (surface->pixels) {
                    for (int py = 0; py < surface->h; py++) {
                        Uint32 *row = (Uint32 *)(((Uint8 *)surface->pixels) + py * surface->pitch);
                        for (int px = 0; px < surface->w; px++) {
                            add_next_index_long(&pixels_data, (zend_long)(zend_ulong)row[px]);
                        }
                    }
                }
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "flags": flags, "format": format, "w": w, "h": h, "pitch": pitch, "pixels": ["ptr": pixels_ptr, "data": pixels_data], "refcount": refcount];
    }

    public static function SDLLoadBMP(string file) -> array
    {
        int ptr;
        int flags;
        int format;
        int w;
        int h;
        int pitch;
        int pixels_ptr;
        array pixels_data;
        int refcount;

        %{
            SDL_Surface *surface = SDL_LoadBMP(Z_STRVAL(file));
            if (!surface) {
                ptr = 0; flags = 0; format = 0; w = 0; h = 0; pitch = 0; pixels_ptr = 0; refcount = 0;
                array_init(&pixels_data);
            } else {
                ptr        = (zend_long)(uintptr_t) surface;
                flags      = (zend_long) surface->flags;
                format     = (zend_long) surface->format;
                w          = (zend_long) surface->w;
                h          = (zend_long) surface->h;
                pitch      = (zend_long) surface->pitch;
                pixels_ptr = surface->pixels ? (zend_long)(uintptr_t) surface->pixels : 0;
                refcount   = (zend_long) surface->refcount;
                array_init(&pixels_data);
                if (surface->pixels) {
                    for (int py = 0; py < surface->h; py++) {
                        Uint32 *row = (Uint32 *)(((Uint8 *)surface->pixels) + py * surface->pitch);
                        for (int px = 0; px < surface->w; px++) {
                            add_next_index_long(&pixels_data, (zend_long)(zend_ulong)row[px]);
                        }
                    }
                }
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "flags": flags, "format": format, "w": w, "h": h, "pitch": pitch, "pixels": ["ptr": pixels_ptr, "data": pixels_data], "refcount": refcount];
    }

    public static function SDLWriteSurfacePixelAt(int surface, int x, int y, int pixel) -> bool
    {
        bool result;

        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            if (!surf || !surf->pixels || x < 0 || y < 0 || x >= surf->w || y >= surf->h) {
                result = 0;
            } else {
                Uint32 *row = (Uint32 *)(((Uint8 *)surf->pixels) + y * surf->pitch);
                row[x] = (Uint32)(zend_ulong)pixel;
                result = 1;
            }
        }%

        return result;
    }

    public static function SDLWriteSurfacePixels(int surface, array data) -> bool
    {
        bool result;

        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            if (!surf || !surf->pixels) {
                result = 0;
            } else {
                zval *entry;
                zend_ulong index;
                ZEND_HASH_FOREACH_NUM_KEY_VAL(Z_ARRVAL_P(&data), index, entry) {
                    int py = (int)index / surf->w;
                    int px = (int)index % surf->w;
                    if (py < surf->h && px < surf->w) {
                        Uint32 *row = (Uint32 *)(((Uint8 *)surf->pixels) + py * surf->pitch);
                        row[px] = (Uint32)(zend_ulong)zval_get_long(entry);
                    }
                } ZEND_HASH_FOREACH_END();
                result = 1;
            }
        }%

        return result;
    }

    public static function SDLReadSurfacePixels(int surface) -> array
    {
        int pixels_ptr;
        array pixels_data;

        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            array_init(&pixels_data);
            if (surf && surf->pixels) {
                pixels_ptr = (zend_long)(uintptr_t) surf->pixels;
                for (int py = 0; py < surf->h; py++) {
                    Uint32 *row = (Uint32 *)(((Uint8 *)surf->pixels) + py * surf->pitch);
                    for (int px = 0; px < surf->w; px++) {
                        add_next_index_long(&pixels_data, (zend_long)(zend_ulong)row[px]);
                    }
                }
            } else {
                pixels_ptr = 0;
            }
        }%

        return ["pixels_ptr": pixels_ptr, "pixels_data": pixels_data];
    }

    public static function SDLGetSurfacePalette(int surface) -> array
    {
        int ptr;
        int ncolors;
        int version;
        int refcount;
        array colors;

        %{
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            SDL_Palette *pal  = SDL_GetSurfacePalette(surf);

            if (!pal) {
                ptr = 0; ncolors = 0; version = 0; refcount = 0;
                array_init(&colors);
            } else {
                ptr      = (zend_long)(uintptr_t) pal;
                ncolors  = (zend_long) pal->ncolors;
                version  = (zend_long) pal->version;
                refcount = (zend_long) pal->refcount;

                array_init(&colors);
                for (int i = 0; i < pal->ncolors; i++) {
                    zval entry;
                    array_init(&entry);
                    add_assoc_long(&entry, "r", (zend_long) pal->colors[i].r);
                    add_assoc_long(&entry, "g", (zend_long) pal->colors[i].g);
                    add_assoc_long(&entry, "b", (zend_long) pal->colors[i].b);
                    add_assoc_long(&entry, "a", (zend_long) pal->colors[i].a);
                    add_next_index_zval(&colors, &entry);
                }
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "ncolors": ncolors, "colors": colors, "version": version, "refcount": refcount];
    }
}
