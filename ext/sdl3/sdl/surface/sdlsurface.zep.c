
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"

#include <SDL3/SDL.h>
#include <stdio.h>



ZEPHIR_INIT_CLASS(Sdl3_SDL_Surface_SDLSurface)
{
	ZEPHIR_REGISTER_CLASS(Sdl3\\SDL\\Surface, SDLSurface, sdl3, sdl_surface_sdlsurface, sdl3_sdl_surface_sdlsurface_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLCreateSurface)
{
	zval pixels_data, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *width_param = NULL, *height_param = NULL, *format_param = NULL, _0;
	zend_long width, height, format, ptr = 0, flags = 0, fmt = 0, w = 0, h = 0, pitch = 0, pixels_ptr = 0, refcount = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(format)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &width_param, &height_param, &format_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 8, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, flags);
	zephir_array_update_string(return_value, SL("flags"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, fmt);
	zephir_array_update_string(return_value, SL("format"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pitch);
	zephir_array_update_string(return_value, SL("pitch"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pixels_ptr);
	zephir_array_update_string(&_1, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("data"), &pixels_data, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("pixels"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, refcount);
	zephir_array_update_string(return_value, SL("refcount"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLDuplicateSurface)
{
	zval pixels_data, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *surface_param = NULL, _0;
	zend_long surface, ptr = 0, flags = 0, fmt = 0, w = 0, h = 0, pitch = 0, pixels_ptr = 0, refcount = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &surface_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 8, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, flags);
	zephir_array_update_string(return_value, SL("flags"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, fmt);
	zephir_array_update_string(return_value, SL("format"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pitch);
	zephir_array_update_string(return_value, SL("pitch"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pixels_ptr);
	zephir_array_update_string(&_1, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("data"), &pixels_data, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("pixels"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, refcount);
	zephir_array_update_string(return_value, SL("refcount"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLConvertSurface)
{
	zval pixels_data, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *surface_param = NULL, *format_param = NULL, _0;
	zend_long surface, format, ptr = 0, flags = 0, fmt = 0, w = 0, h = 0, pitch = 0, pixels_ptr = 0, refcount = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(format)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &surface_param, &format_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 8, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, flags);
	zephir_array_update_string(return_value, SL("flags"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, fmt);
	zephir_array_update_string(return_value, SL("format"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pitch);
	zephir_array_update_string(return_value, SL("pitch"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pixels_ptr);
	zephir_array_update_string(&_1, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("data"), &pixels_data, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("pixels"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, refcount);
	zephir_array_update_string(return_value, SL("refcount"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLSurfaceToBlackAndWhite)
{
	zval *surface_param = NULL;
	zend_long surface;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &surface_param);
	
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
        
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLBlitSurface)
{
	zend_bool result = 0;
	zval *src_param = NULL, *srcrect = NULL, srcrect_sub, *dst_param = NULL, *dstrect = NULL, dstrect_sub, __$null;
	zend_long src, dst;

	ZVAL_UNDEF(&srcrect_sub);
	ZVAL_UNDEF(&dstrect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(src)
		Z_PARAM_LONG(dst)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(srcrect)
		Z_PARAM_ZVAL_OR_NULL(dstrect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 2, &src_param, &srcrect, &dst_param, &dstrect);
	if (!srcrect) {
		srcrect = &srcrect_sub;
		srcrect = &__$null;
	}
	if (!dstrect) {
		dstrect = &dstrect_sub;
		dstrect = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLFillSurfaceRect)
{
	zend_bool result = 0;
	zval *surface_param = NULL, *color_param = NULL, *rect = NULL, rect_sub, __$null;
	zend_long surface, color;

	ZVAL_UNDEF(&rect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(color)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(rect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 1, &surface_param, &color_param, &rect);
	if (!rect) {
		rect = &rect_sub;
		rect = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLMapRGB)
{
	zval *format_param = NULL, *palette_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL;
	zend_long format, palette, r, g, b, result = 0;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(palette)
		Z_PARAM_LONG(r)
		Z_PARAM_LONG(g)
		Z_PARAM_LONG(b)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &format_param, &palette_param, &r_param, &g_param, &b_param);
	
            const SDL_PixelFormatDetails *fmt = (const SDL_PixelFormatDetails *)(uintptr_t) format;
            const SDL_Palette            *pal = palette ? (const SDL_Palette *)(uintptr_t) palette : NULL;
            result = (zend_long) SDL_MapRGB(fmt, pal, (Uint8) r, (Uint8) g, (Uint8) b);
        
	RETURN_LONG(result);
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLLockSurface)
{
	zend_bool result = 0;
	zval *surface_param = NULL;
	zend_long surface;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &surface_param);
	
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            result = SDL_LockSurface(surf);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLUnlockSurface)
{
	zval *surface_param = NULL;
	zend_long surface;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &surface_param);
	
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            SDL_UnlockSurface(surf);
        
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLDestroySurface)
{
	zval *surface_param = NULL;
	zend_long surface;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &surface_param);
	
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            SDL_DestroySurface(surf);
        
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLLoadPNG)
{
	zval pixels_data, _1;
	zend_long ptr = 0, flags = 0, format = 0, w = 0, h = 0, pitch = 0, pixels_ptr = 0, refcount = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *file_param = NULL, _0;
	zval file;

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &file_param);
	zephir_get_strval(&file, file_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 8, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, flags);
	zephir_array_update_string(return_value, SL("flags"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, format);
	zephir_array_update_string(return_value, SL("format"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pitch);
	zephir_array_update_string(return_value, SL("pitch"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pixels_ptr);
	zephir_array_update_string(&_1, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("data"), &pixels_data, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("pixels"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, refcount);
	zephir_array_update_string(return_value, SL("refcount"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLLoadBMP)
{
	zval pixels_data, _1;
	zend_long ptr = 0, flags = 0, format = 0, w = 0, h = 0, pitch = 0, pixels_ptr = 0, refcount = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *file_param = NULL, _0;
	zval file;

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &file_param);
	zephir_get_strval(&file, file_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 8, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, flags);
	zephir_array_update_string(return_value, SL("flags"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, format);
	zephir_array_update_string(return_value, SL("format"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pitch);
	zephir_array_update_string(return_value, SL("pitch"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, pixels_ptr);
	zephir_array_update_string(&_1, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("data"), &pixels_data, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("pixels"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, refcount);
	zephir_array_update_string(return_value, SL("refcount"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLWriteSurfacePixelAt)
{
	zend_bool result = 0;
	zval *surface_param = NULL, *x_param = NULL, *y_param = NULL, *pixel_param = NULL;
	zend_long surface, x, y, pixel;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(pixel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &surface_param, &x_param, &y_param, &pixel_param);
	
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            if (!surf || !surf->pixels || x < 0 || y < 0 || x >= surf->w || y >= surf->h) {
                result = 0;
            } else {
                Uint32 *row = (Uint32 *)(((Uint8 *)surf->pixels) + y * surf->pitch);
                row[x] = (Uint32)(zend_ulong)pixel;
                result = 1;
            }
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLWriteSurfacePixels)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval data;
	zval *surface_param = NULL, *data_param = NULL;
	zend_long surface;

	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(surface)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &surface_param, &data_param);
	zephir_get_arrval(&data, data_param);
	
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
        
	RETURN_MM_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLReadSurfacePixels)
{
	zval pixels_data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *surface_param = NULL, _0;
	zend_long surface, pixels_ptr = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &surface_param);
	
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
        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, pixels_ptr);
	zephir_array_update_string(return_value, SL("pixels_ptr"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("pixels_data"), &pixels_data, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLGetSurfacePalette)
{
	zval colors;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *surface_param = NULL, _0;
	zend_long surface, ptr = 0, ncolors = 0, version = 0, refcount = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&colors);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &surface_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, ncolors);
	zephir_array_update_string(return_value, SL("ncolors"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("colors"), &colors, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, version);
	zephir_array_update_string(return_value, SL("version"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, refcount);
	zephir_array_update_string(return_value, SL("refcount"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

