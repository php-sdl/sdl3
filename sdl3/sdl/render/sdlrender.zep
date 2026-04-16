namespace Sdl3\SDL\Render;

%{
#include <SDL3/SDL.h>
#include <stdio.h>
}%
class SDLRender
{
    public static function SDLCreateRenderer(int window, var name = null) -> int
    {
        int ptr;

        %{
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            const char *renderer_name = (Z_TYPE_P(name) == IS_NULL) ? NULL : Z_STRVAL_P(name);
            SDL_Renderer *renderer = SDL_CreateRenderer(win, renderer_name);
            ptr = (zend_long)(uintptr_t) renderer;
        }%

        if ptr == 0 {
            throw new \RuntimeException("SDL_CreateRenderer failed: " . \Sdl3\SDL\SDLError::SDLGetError());
        }

        return ptr;
    }

    public static function SDLCreateSoftwareRenderer(int surface) -> int
    {
        int ptr;

        %{
            SDL_Surface  *surf     = (SDL_Surface *)(uintptr_t) surface;
            SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(surf);
            ptr = (zend_long)(uintptr_t) renderer;
        }%

        if ptr == 0 {
            throw new \RuntimeException("SDL_CreateSoftwareRenderer failed: " . \Sdl3\SDL\SDLError::SDLGetError());
        }

        return ptr;
    }

    public static function SDLRenderClear(int renderer) -> void
    {
        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_RenderClear(ren);
        }%
    }

    public static function SDLRenderPresent(int renderer) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_RenderPresent(ren);
        }%

        return result;
    }

    public static function SDLRenderTexture(int renderer, int texture, var srcrect = null, var dstrect = null) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Texture  *te  = (SDL_Texture *)(uintptr_t) texture;

            SDL_FRect src_buf = {0}, dst_buf = {0};
            const SDL_FRect *src_ptr = NULL;
            const SDL_FRect *dst_ptr = NULL;

            if (Z_TYPE_P(srcrect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(srcrect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(srcrect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(srcrect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(srcrect), 3);
                if (x && y && w && h) {
                    src_buf.x = (float) zval_get_double(x);
                    src_buf.y = (float) zval_get_double(y);
                    src_buf.w = (float) zval_get_double(w);
                    src_buf.h = (float) zval_get_double(h);
                    src_ptr = &src_buf;
                }
            }

            if (Z_TYPE_P(dstrect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(dstrect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(dstrect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(dstrect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(dstrect), 3);
                if (x && y && w && h) {
                    dst_buf.x = (float) zval_get_double(x);
                    dst_buf.y = (float) zval_get_double(y);
                    dst_buf.w = (float) zval_get_double(w);
                    dst_buf.h = (float) zval_get_double(h);
                    dst_ptr = &dst_buf;
                }
            }

            result = SDL_RenderTexture(ren, te, src_ptr, dst_ptr);
        }%

        return result;
    }

    public static function SDLRenderTextureRotated(int renderer, int texture, double angle, int flip, var srcrect = null, var dstrect = null, var center = null) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Texture  *te  = (SDL_Texture *)(uintptr_t) texture;

            SDL_FRect src_buf = {0}, dst_buf = {0};
            const SDL_FRect *src_ptr = NULL;
            const SDL_FRect *dst_ptr = NULL;

            if (Z_TYPE_P(srcrect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(srcrect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(srcrect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(srcrect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(srcrect), 3);
                if (x && y && w && h) {
                    src_buf.x = (float) zval_get_double(x);
                    src_buf.y = (float) zval_get_double(y);
                    src_buf.w = (float) zval_get_double(w);
                    src_buf.h = (float) zval_get_double(h);
                    src_ptr = &src_buf;
                }
            }

            if (Z_TYPE_P(dstrect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(dstrect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(dstrect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(dstrect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(dstrect), 3);
                if (x && y && w && h) {
                    dst_buf.x = (float) zval_get_double(x);
                    dst_buf.y = (float) zval_get_double(y);
                    dst_buf.w = (float) zval_get_double(w);
                    dst_buf.h = (float) zval_get_double(h);
                    dst_ptr = &dst_buf;
                }
            }

            SDL_FPoint cp, *cpp = NULL;
            if (Z_TYPE_P(center) == IS_ARRAY) {
                zval *cx = zend_hash_index_find(Z_ARRVAL_P(center), 0);
                zval *cy = zend_hash_index_find(Z_ARRVAL_P(center), 1);
                if (cx && cy) {
                    cp.x = (float) zval_get_double(cx);
                    cp.y = (float) zval_get_double(cy);
                    cpp = &cp;
                }
            }

            result = SDL_RenderTextureRotated(ren, te, src_ptr, dst_ptr, angle, cpp, (SDL_FlipMode) flip);
        }%

        return result;
    }

    public static function SDLSetRenderDrawColor(int renderer, int r, int g, int b, int a) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderDrawColor(ren, r, g, b, a);
        }%

        return result;
    }

    public static function SDLSetRenderDrawColorFloat(int renderer, double r, double g, double b, double a) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderDrawColorFloat(ren, (float) r, (float) g, (float) b, (float) a);
        }%

        return result;
    }

    public static function SDLCreateTexture(int renderer, int format, int access, int w, int h) -> array
    {
        int ptr;
        int tex_format;
        int tex_w;
        int tex_h;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Texture  *tex = SDL_CreateTexture(ren, (SDL_PixelFormat) format, (SDL_TextureAccess) access, (int) w, (int) h);

            if (!tex) {
                ptr = 0; tex_format = 0; tex_w = 0; tex_h = 0;
            } else {
                ptr        = (zend_long)(uintptr_t) tex;
                tex_format = (zend_long) format;
                tex_w      = (zend_long) w;
                tex_h      = (zend_long) h;
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "format": tex_format, "w": tex_w, "h": tex_h, "refcount": 1];
    }

    public static function SDLCreateTextureFromSurface(int renderer, int surface) -> array
    {
        int ptr;
        int format;
        int w;
        int h;

        %{
            SDL_Renderer *ren     = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Surface  *sur     = (SDL_Surface *)(uintptr_t) surface;
            SDL_Texture  *texture = SDL_CreateTextureFromSurface(ren, sur);

            if (!texture) {
                ptr = 0; format = 0; w = 0; h = 0;
            } else {
                ptr = (zend_long)(uintptr_t) texture;

                float fw = 0.0f, fh = 0.0f;
                SDL_GetTextureSize(texture, &fw, &fh);
                w = (zend_long) fw;
                h = (zend_long) fh;

                SDL_PropertiesID props = SDL_GetTextureProperties(texture);
                format = (zend_long) SDL_GetNumberProperty(props, SDL_PROP_TEXTURE_FORMAT_NUMBER, SDL_PIXELFORMAT_UNKNOWN);
            }
        }%

        if ptr == 0 {
            return [];
        }

        return ["ptr": ptr, "format": format, "w": w, "h": h, "refcount": 1];
    }

    public static function SDLLockTextureToSurface(int texture, var rect = null) -> array
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
            SDL_Texture *tex  = (SDL_Texture *)(uintptr_t) texture;
            SDL_Surface *surf = NULL;

            SDL_Rect rect_buf = {0};
            const SDL_Rect *rect_ptr = NULL;

            if (Z_TYPE_P(rect) == IS_ARRAY) {
                zval *rx = zend_hash_index_find(Z_ARRVAL_P(rect), 0);
                zval *ry = zend_hash_index_find(Z_ARRVAL_P(rect), 1);
                zval *rw = zend_hash_index_find(Z_ARRVAL_P(rect), 2);
                zval *rh = zend_hash_index_find(Z_ARRVAL_P(rect), 3);
                if (rx && ry && rw && rh) {
                    rect_buf.x = (int) zval_get_long(rx);
                    rect_buf.y = (int) zval_get_long(ry);
                    rect_buf.w = (int) zval_get_long(rw);
                    rect_buf.h = (int) zval_get_long(rh);
                    rect_ptr = &rect_buf;
                }
            }

            bool ok = SDL_LockTextureToSurface(tex, rect_ptr, &surf);

            if (!ok || !surf) {
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

    public static function SDLUnlockTexture(int texture) -> void
    {
        %{
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            SDL_UnlockTexture(te);
        }%
    }

    public static function SDLSetTextureColorModFloat(int texture, double r, double g, double b) -> bool
    {
        bool result;

        %{
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            result = SDL_SetTextureColorModFloat(te, (float) r, (float) g, (float) b);
        }%

        return result;
    }

    public static function SDLSetTextureScaleMode(int texture, int scaleMode) -> bool
    {
        bool result;

        %{
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            result = SDL_SetTextureScaleMode(te, (SDL_ScaleMode) scaleMode);
        }%

        return result;
    }

    public static function SDLGetTextureSize(int texture) -> array
    {
        int w;
        int h;
        bool result;

        %{
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            float fw = 0.0f, fh = 0.0f;
            result = SDL_GetTextureSize(te, &fw, &fh);
            w = (zend_long) fw;
            h = (zend_long) fh;
        }%

        if !result {
            return [];
        }

        return ["w": w, "h": h];
    }

    public static function SDLSetRenderLogicalPresentation(int renderer, int w, int h, int mode) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderLogicalPresentation(ren, (int) w, (int) h, (SDL_RendererLogicalPresentation) mode);
        }%

        return result;
    }

    public static function SDLDestroyRenderer(int renderer) -> void
    {
        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_DestroyRenderer(ren);
        }%
    }

    public static function SDLDestroyTexture(int texture) -> void
    {
        %{
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            SDL_DestroyTexture(te);
        }%
    }

    public static function SDLRenderFillRect(int renderer, var rect = null) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_FRect r, *rp = NULL;

            if (Z_TYPE_P(rect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(rect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(rect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(rect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(rect), 3);
                r.x = x ? (float)zval_get_double(x) : 0.0f;
                r.y = y ? (float)zval_get_double(y) : 0.0f;
                r.w = w ? (float)zval_get_double(w) : 0.0f;
                r.h = h ? (float)zval_get_double(h) : 0.0f;
                rp = &r;
            }

            result = SDL_RenderFillRect(ren, rp);
        }%

        return result;
    }

    public static function SDLSetRenderViewport(int renderer, var rect = null) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Rect r, *rp = NULL;

            if (Z_TYPE_P(rect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(rect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(rect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(rect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(rect), 3);
                r.x = x ? (int)zval_get_long(x) : 0;
                r.y = y ? (int)zval_get_long(y) : 0;
                r.w = w ? (int)zval_get_long(w) : 0;
                r.h = h ? (int)zval_get_long(h) : 0;
                rp = &r;
            }

            result = SDL_SetRenderViewport(ren, rp);
        }%

        return result;
    }

    public static function SDLSetRenderClipRect(int renderer, var rect = null) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Rect r, *rp = NULL;

            if (Z_TYPE_P(rect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(rect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(rect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(rect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(rect), 3);
                r.x = x ? (int)zval_get_long(x) : 0;
                r.y = y ? (int)zval_get_long(y) : 0;
                r.w = w ? (int)zval_get_long(w) : 0;
                r.h = h ? (int)zval_get_long(h) : 0;
                rp = &r;
            }

            result = SDL_SetRenderClipRect(ren, rp);
        }%

        return result;
    }

    public static function SDLRenderReadPixels(int renderer, var rect = null) -> array
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
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;

            SDL_Rect r, *rp = NULL;
            if (Z_TYPE_P(rect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(rect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(rect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(rect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(rect), 3);
                r.x = x ? (int)zval_get_long(x) : 0;
                r.y = y ? (int)zval_get_long(y) : 0;
                r.w = w ? (int)zval_get_long(w) : 0;
                r.h = h ? (int)zval_get_long(h) : 0;
                rp = &r;
            }

            SDL_Surface *surf = SDL_RenderReadPixels(ren, rp);
            if (!surf) {
                ptr = 0; flags = 0; format = 0; w = 0; h = 0; pitch = 0; pixels_ptr = 0; refcount = 0;
                array_init(&pixels_data);
            } else {
                ptr        = (zend_long)(uintptr_t) surf;
                flags      = (zend_long) surf->flags;
                format     = (zend_long) surf->format;
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

        return ["ptr": ptr, "flags": flags, "format": format, "w": w, "h": h, "pitch": pitch, "pixels": ["ptr": pixels_ptr, "data": pixels_data], "refcount": refcount];
    }

    public static function SDLUpdateTextureFromSurface(int texture, int surface) -> bool
    {
        bool result;

        %{
            SDL_Texture *tex  = (SDL_Texture *)(uintptr_t) texture;
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            result = SDL_UpdateTexture(tex, NULL, surf->pixels, surf->pitch);
        }%

        return result;
    }

    public static function SDLRenderDebugText(int renderer, double x, double y, string str) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_RenderDebugText(ren, (float) x, (float) y, Z_STRVAL(str));
        }%

        return result;
    }

    public static function SDLSetRenderScale(int renderer, double scaleX, double scaleY) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderScale(ren, (float) scaleX, (float) scaleY);
        }%

        return result;
    }

    public static function SDLRenderTextureAffine(int renderer, int texture, var origin, var right, var down, var srcrect = null) -> bool
    {
        bool result;

        if typeof origin != "array" || typeof right != "array" || typeof down != "array" {
            return false;
        }

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Texture  *tex = (SDL_Texture  *)(uintptr_t) texture;

            SDL_FRect sr, *srp = NULL;
            if (Z_TYPE_P(srcrect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(srcrect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(srcrect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(srcrect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(srcrect), 3);
                sr.x = x ? (float)zval_get_double(x) : 0.0f;
                sr.y = y ? (float)zval_get_double(y) : 0.0f;
                sr.w = w ? (float)zval_get_double(w) : 0.0f;
                sr.h = h ? (float)zval_get_double(h) : 0.0f;
                srp = &sr;
            }

            SDL_FPoint orig_pt = { 0.0f, 0.0f };
            SDL_FPoint right_pt = { 0.0f, 0.0f };
            SDL_FPoint down_pt  = { 0.0f, 0.0f };

            if (Z_TYPE_P(origin) == IS_ARRAY) {
                zval *ox = zend_hash_index_find(Z_ARRVAL_P(origin), 0);
                zval *oy = zend_hash_index_find(Z_ARRVAL_P(origin), 1);
                orig_pt.x = ox ? (float)zval_get_double(ox) : 0.0f;
                orig_pt.y = oy ? (float)zval_get_double(oy) : 0.0f;
            }
            if (Z_TYPE_P(right) == IS_ARRAY) {
                zval *rx = zend_hash_index_find(Z_ARRVAL_P(right), 0);
                zval *ry = zend_hash_index_find(Z_ARRVAL_P(right), 1);
                right_pt.x = rx ? (float)zval_get_double(rx) : 0.0f;
                right_pt.y = ry ? (float)zval_get_double(ry) : 0.0f;
            }
            if (Z_TYPE_P(down) == IS_ARRAY) {
                zval *dx = zend_hash_index_find(Z_ARRVAL_P(down), 0);
                zval *dy = zend_hash_index_find(Z_ARRVAL_P(down), 1);
                down_pt.x = dx ? (float)zval_get_double(dx) : 0.0f;
                down_pt.y = dy ? (float)zval_get_double(dy) : 0.0f;
            }

            result = SDL_RenderTextureAffine(ren, tex, srp, &orig_pt, &right_pt, &down_pt);
        }%

        return result;
    }

    public static function SDLRenderFillRects(int renderer, array rects, int count) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_FRect *frects = (SDL_FRect *) emalloc(sizeof(SDL_FRect) * count);
            zval *entry;
            int i = 0;

            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rects), entry) {
                if (Z_TYPE_P(entry) == IS_ARRAY && i < count) {
                    zval *x = zend_hash_index_find(Z_ARRVAL_P(entry), 0);
                    zval *y = zend_hash_index_find(Z_ARRVAL_P(entry), 1);
                    zval *w = zend_hash_index_find(Z_ARRVAL_P(entry), 2);
                    zval *h = zend_hash_index_find(Z_ARRVAL_P(entry), 3);
                    frects[i].x = x ? (float)zval_get_double(x) : 0.0f;
                    frects[i].y = y ? (float)zval_get_double(y) : 0.0f;
                    frects[i].w = w ? (float)zval_get_double(w) : 0.0f;
                    frects[i].h = h ? (float)zval_get_double(h) : 0.0f;
                    i++;
                }
            } ZEND_HASH_FOREACH_END();

            result = SDL_RenderFillRects(ren, frects, i);
            efree(frects);
        }%

        return result;
    }

    public static function SDLRenderRects(int renderer, array rects, int count) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_FRect *frects = (SDL_FRect *) emalloc(sizeof(SDL_FRect) * count);
            zval *entry;
            int i = 0;

            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rects), entry) {
                if (Z_TYPE_P(entry) == IS_ARRAY && i < count) {
                    zval *x = zend_hash_index_find(Z_ARRVAL_P(entry), 0);
                    zval *y = zend_hash_index_find(Z_ARRVAL_P(entry), 1);
                    zval *w = zend_hash_index_find(Z_ARRVAL_P(entry), 2);
                    zval *h = zend_hash_index_find(Z_ARRVAL_P(entry), 3);
                    frects[i].x = x ? (float)zval_get_double(x) : 0.0f;
                    frects[i].y = y ? (float)zval_get_double(y) : 0.0f;
                    frects[i].w = w ? (float)zval_get_double(w) : 0.0f;
                    frects[i].h = h ? (float)zval_get_double(h) : 0.0f;
                    i++;
                }
            } ZEND_HASH_FOREACH_END();

            result = SDL_RenderRects(ren, frects, i);
            efree(frects);
        }%

        return result;
    }

    public static function SDLRenderLine(int renderer, double x1, double y1, double x2, double y2) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_RenderLine(ren, (float) x1, (float) y1, (float) x2, (float) y2);
        }%

        return result;
    }

    public static function SDLRenderRect(int renderer, var rect = null) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_FRect r, *rp = NULL;

            if (Z_TYPE_P(rect) == IS_ARRAY) {
                zval *x = zend_hash_index_find(Z_ARRVAL_P(rect), 0);
                zval *y = zend_hash_index_find(Z_ARRVAL_P(rect), 1);
                zval *w = zend_hash_index_find(Z_ARRVAL_P(rect), 2);
                zval *h = zend_hash_index_find(Z_ARRVAL_P(rect), 3);
                r.x = x ? (float)zval_get_double(x) : 0.0f;
                r.y = y ? (float)zval_get_double(y) : 0.0f;
                r.w = w ? (float)zval_get_double(w) : 0.0f;
                r.h = h ? (float)zval_get_double(h) : 0.0f;
                rp = &r;
            }

            result = SDL_RenderRect(ren, rp);
        }%

        return result;
    }

    public static function SDLRenderPoints(int renderer, array points, int count) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_FPoint *fpoints = (SDL_FPoint *) emalloc(sizeof(SDL_FPoint) * count);
            zval *entry;
            int i = 0;

            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&points), entry) {
                if (Z_TYPE_P(entry) == IS_ARRAY && i < count) {
                    zval *x = zend_hash_index_find(Z_ARRVAL_P(entry), 0);
                    zval *y = zend_hash_index_find(Z_ARRVAL_P(entry), 1);
                    fpoints[i].x = x ? (float)zval_get_double(x) : 0.0f;
                    fpoints[i].y = y ? (float)zval_get_double(y) : 0.0f;
                    i++;
                }
            } ZEND_HASH_FOREACH_END();

            result = SDL_RenderPoints(ren, fpoints, i);
            efree(fpoints);
        }%

        return result;
    }

    public static function SDLRenderGeometry(int renderer, int texture, array vertices, int num_vertices, int num_indices, var indices = null) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_Texture  *tex = texture ? (SDL_Texture *)(uintptr_t) texture : NULL;

            SDL_Vertex *verts = (SDL_Vertex *) emalloc(sizeof(SDL_Vertex) * (size_t) num_vertices);
            memset(verts, 0, sizeof(SDL_Vertex) * (size_t) num_vertices);

            zval *item;
            zend_long idx = 0;
            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&vertices), item) {
                if (idx >= num_vertices) break;
                if (Z_TYPE_P(item) == IS_ARRAY) {
                    zval *v0 = zend_hash_index_find(Z_ARRVAL_P(item), 0);
                    zval *v1 = zend_hash_index_find(Z_ARRVAL_P(item), 1);
                    zval *v2 = zend_hash_index_find(Z_ARRVAL_P(item), 2);
                    zval *v3 = zend_hash_index_find(Z_ARRVAL_P(item), 3);
                    zval *v4 = zend_hash_index_find(Z_ARRVAL_P(item), 4);
                    zval *v5 = zend_hash_index_find(Z_ARRVAL_P(item), 5);
                    zval *v6 = zend_hash_index_find(Z_ARRVAL_P(item), 6);
                    zval *v7 = zend_hash_index_find(Z_ARRVAL_P(item), 7);
                    if (v0) verts[idx].position.x  = (float) zval_get_double(v0);
                    if (v1) verts[idx].position.y  = (float) zval_get_double(v1);
                    if (v2) verts[idx].color.r     = (float) zval_get_double(v2);
                    if (v3) verts[idx].color.g     = (float) zval_get_double(v3);
                    if (v4) verts[idx].color.b     = (float) zval_get_double(v4);
                    if (v5) verts[idx].color.a     = (float) zval_get_double(v5);
                    if (v6) verts[idx].tex_coord.x = (float) zval_get_double(v6);
                    if (v7) verts[idx].tex_coord.y = (float) zval_get_double(v7);
                }
                idx++;
            } ZEND_HASH_FOREACH_END();

            int *idx_buf = NULL;
            if (num_indices > 0 && Z_TYPE_P(indices) == IS_ARRAY) {
                idx_buf = (int *) emalloc(sizeof(int) * (size_t) num_indices);
                zend_long ii = 0;
                ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(indices), item) {
                    if (ii >= num_indices) break;
                    idx_buf[ii++] = (int) zval_get_long(item);
                } ZEND_HASH_FOREACH_END();
            }

            result = SDL_RenderGeometry(ren, tex, verts, (int) num_vertices, idx_buf, (int) num_indices);

            efree(verts);
            if (idx_buf) efree(idx_buf);
        }%

        return result;
    }

    public static function SDLRenderLines(int renderer, array points, int count) -> bool
    {
        bool result;

        %{
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_FPoint *fpoints = (SDL_FPoint *) emalloc(sizeof(SDL_FPoint) * count);
            zval *entry;
            int i = 0;

            ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&points), entry) {
                if (Z_TYPE_P(entry) == IS_ARRAY && i < count) {
                    zval *x = zend_hash_index_find(Z_ARRVAL_P(entry), 0);
                    zval *y = zend_hash_index_find(Z_ARRVAL_P(entry), 1);
                    fpoints[i].x = x ? (float)zval_get_double(x) : 0.0f;
                    fpoints[i].y = y ? (float)zval_get_double(y) : 0.0f;
                    i++;
                }
            } ZEND_HASH_FOREACH_END();

            result = SDL_RenderLines(ren, fpoints, i);
            efree(fpoints);
        }%

        return result;
    }
}
