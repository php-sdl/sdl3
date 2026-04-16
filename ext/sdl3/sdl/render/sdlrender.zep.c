
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"

#include <SDL3/SDL.h>
#include <stdio.h>



ZEPHIR_INIT_CLASS(Sdl3_SDL_Render_SDLRender)
{
	ZEPHIR_REGISTER_CLASS(Sdl3\\SDL\\Render, SDLRender, sdl3, sdl_render_sdlrender, sdl3_sdl_render_sdlrender_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateRenderer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, *name = NULL, name_sub, __$null, _0$$3, _1$$3, _2$$3;
	zend_long window, ZEPHIR_LAST_CALL_STATUS, ptr = 0;

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(window)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &window_param, &name);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            const char *renderer_name = (Z_TYPE_P(name) == IS_NULL) ? NULL : Z_STRVAL_P(name);
            SDL_Renderer *renderer = SDL_CreateRenderer(win, renderer_name);
            ptr = (zend_long)(uintptr_t) renderer;
        
	if (ptr == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_RuntimeException);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, sdl3_sdl_sdlerror_ce, "sdlgeterror", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "SDL_CreateRenderer failed: ", &_1$$3);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "sdl3/sdl/render/sdlrender.zep", 20);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(ptr);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateSoftwareRenderer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *surface_param = NULL, _0$$3, _1$$3, _2$$3;
	zend_long surface, ZEPHIR_LAST_CALL_STATUS, ptr = 0;

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &surface_param);
	
            SDL_Surface  *surf     = (SDL_Surface *)(uintptr_t) surface;
            SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(surf);
            ptr = (zend_long)(uintptr_t) renderer;
        
	if (ptr == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_RuntimeException);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, sdl3_sdl_sdlerror_ce, "sdlgeterror", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "SDL_CreateSoftwareRenderer failed: ", &_1$$3);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "sdl3/sdl/render/sdlrender.zep", 37);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(ptr);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderClear)
{
	zval *renderer_param = NULL;
	zend_long renderer;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(renderer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &renderer_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_RenderClear(ren);
        
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderPresent)
{
	zend_bool result = 0;
	zval *renderer_param = NULL;
	zend_long renderer;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(renderer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &renderer_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_RenderPresent(ren);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderTexture)
{
	zend_bool result = 0;
	zval *renderer_param = NULL, *texture_param = NULL, *srcrect = NULL, srcrect_sub, *dstrect = NULL, dstrect_sub, __$null;
	zend_long renderer, texture;

	ZVAL_UNDEF(&srcrect_sub);
	ZVAL_UNDEF(&dstrect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(texture)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(srcrect)
		Z_PARAM_ZVAL_OR_NULL(dstrect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 2, &renderer_param, &texture_param, &srcrect, &dstrect);
	if (!srcrect) {
		srcrect = &srcrect_sub;
		srcrect = &__$null;
	}
	if (!dstrect) {
		dstrect = &dstrect_sub;
		dstrect = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderTextureRotated)
{
	zend_bool result = 0;
	double angle;
	zval *renderer_param = NULL, *texture_param = NULL, *angle_param = NULL, *flip_param = NULL, *srcrect = NULL, srcrect_sub, *dstrect = NULL, dstrect_sub, *center = NULL, center_sub, __$null;
	zend_long renderer, texture, flip;

	ZVAL_UNDEF(&srcrect_sub);
	ZVAL_UNDEF(&dstrect_sub);
	ZVAL_UNDEF(&center_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 7)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(texture)
		Z_PARAM_ZVAL(angle)
		Z_PARAM_LONG(flip)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(srcrect)
		Z_PARAM_ZVAL_OR_NULL(dstrect)
		Z_PARAM_ZVAL_OR_NULL(center)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 3, &renderer_param, &texture_param, &angle_param, &flip_param, &srcrect, &dstrect, &center);
	angle = zephir_get_doubleval(angle_param);
	if (!srcrect) {
		srcrect = &srcrect_sub;
		srcrect = &__$null;
	}
	if (!dstrect) {
		dstrect = &dstrect_sub;
		dstrect = &__$null;
	}
	if (!center) {
		center = &center_sub;
		center = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderDrawColor)
{
	zend_bool result = 0;
	zval *renderer_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *a_param = NULL;
	zend_long renderer, r, g, b, a;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(r)
		Z_PARAM_LONG(g)
		Z_PARAM_LONG(b)
		Z_PARAM_LONG(a)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &renderer_param, &r_param, &g_param, &b_param, &a_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderDrawColor(ren, r, g, b, a);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderDrawColorFloat)
{
	zend_bool result = 0;
	double r, g, b, a;
	zval *renderer_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *a_param = NULL;
	zend_long renderer;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ZVAL(r)
		Z_PARAM_ZVAL(g)
		Z_PARAM_ZVAL(b)
		Z_PARAM_ZVAL(a)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &renderer_param, &r_param, &g_param, &b_param, &a_param);
	r = zephir_get_doubleval(r_param);
	g = zephir_get_doubleval(g_param);
	b = zephir_get_doubleval(b_param);
	a = zephir_get_doubleval(a_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderDrawColorFloat(ren, (float) r, (float) g, (float) b, (float) a);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateTexture)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *renderer_param = NULL, *format_param = NULL, *access_param = NULL, *w_param = NULL, *h_param = NULL, _0;
	zend_long renderer, format, access, w, h, ptr = 0, tex_format = 0, tex_w = 0, tex_h = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(access)
		Z_PARAM_LONG(w)
		Z_PARAM_LONG(h)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 5, 0, &renderer_param, &format_param, &access_param, &w_param, &h_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, tex_format);
	zephir_array_update_string(return_value, SL("format"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, tex_w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, tex_h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(return_value, SL("refcount"), 1);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateTextureFromSurface)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *renderer_param = NULL, *surface_param = NULL, _0;
	zend_long renderer, surface, ptr = 0, format = 0, w = 0, h = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &renderer_param, &surface_param);
	
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
        
	if (ptr == 0) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, ptr);
	zephir_array_update_string(return_value, SL("ptr"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, format);
	zephir_array_update_string(return_value, SL("format"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(return_value, SL("refcount"), 1);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLLockTextureToSurface)
{
	zval pixels_data, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *texture_param = NULL, *rect = NULL, rect_sub, __$null, _0;
	zend_long texture, ptr = 0, flags = 0, fmt = 0, w = 0, h = 0, pitch = 0, pixels_ptr = 0, refcount = 0;

	ZVAL_UNDEF(&rect_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(texture)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(rect)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &texture_param, &rect);
	if (!rect) {
		rect = &rect_sub;
		rect = &__$null;
	}
	
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

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLUnlockTexture)
{
	zval *texture_param = NULL;
	zend_long texture;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &texture_param);
	
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            SDL_UnlockTexture(te);
        
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetTextureColorModFloat)
{
	zend_bool result = 0;
	double r, g, b;
	zval *texture_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL;
	zend_long texture;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(texture)
		Z_PARAM_ZVAL(r)
		Z_PARAM_ZVAL(g)
		Z_PARAM_ZVAL(b)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &texture_param, &r_param, &g_param, &b_param);
	r = zephir_get_doubleval(r_param);
	g = zephir_get_doubleval(g_param);
	b = zephir_get_doubleval(b_param);
	
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            result = SDL_SetTextureColorModFloat(te, (float) r, (float) g, (float) b);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetTextureScaleMode)
{
	zend_bool result = 0;
	zval *texture_param = NULL, *scaleMode_param = NULL;
	zend_long texture, scaleMode;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(scaleMode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &texture_param, &scaleMode_param);
	
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            result = SDL_SetTextureScaleMode(te, (SDL_ScaleMode) scaleMode);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLGetTextureSize)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *texture_param = NULL, _0;
	zend_long texture, w = 0, h = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &texture_param);
	
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            float fw = 0.0f, fh = 0.0f;
            result = SDL_GetTextureSize(te, &fw, &fh);
            w = (zend_long) fw;
            h = (zend_long) fh;
        
	if (!(result)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_update_string(return_value, SL("w"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_update_string(return_value, SL("h"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderLogicalPresentation)
{
	zend_bool result = 0;
	zval *renderer_param = NULL, *w_param = NULL, *h_param = NULL, *mode_param = NULL;
	zend_long renderer, w, h, mode;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(w)
		Z_PARAM_LONG(h)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &renderer_param, &w_param, &h_param, &mode_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderLogicalPresentation(ren, (int) w, (int) h, (SDL_RendererLogicalPresentation) mode);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLDestroyRenderer)
{
	zval *renderer_param = NULL;
	zend_long renderer;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(renderer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &renderer_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            SDL_DestroyRenderer(ren);
        
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLDestroyTexture)
{
	zval *texture_param = NULL;
	zend_long texture;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &texture_param);
	
            SDL_Texture *te = (SDL_Texture *)(uintptr_t) texture;
            SDL_DestroyTexture(te);
        
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderFillRect)
{
	zend_bool result = 0;
	zval *renderer_param = NULL, *rect = NULL, rect_sub, __$null;
	zend_long renderer;

	ZVAL_UNDEF(&rect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(renderer)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(rect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 1, &renderer_param, &rect);
	if (!rect) {
		rect = &rect_sub;
		rect = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderViewport)
{
	zend_bool result = 0;
	zval *renderer_param = NULL, *rect = NULL, rect_sub, __$null;
	zend_long renderer;

	ZVAL_UNDEF(&rect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(renderer)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(rect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 1, &renderer_param, &rect);
	if (!rect) {
		rect = &rect_sub;
		rect = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderClipRect)
{
	zend_bool result = 0;
	zval *renderer_param = NULL, *rect = NULL, rect_sub, __$null;
	zend_long renderer;

	ZVAL_UNDEF(&rect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(renderer)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(rect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 1, &renderer_param, &rect);
	if (!rect) {
		rect = &rect_sub;
		rect = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderReadPixels)
{
	zval pixels_data, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *renderer_param = NULL, *rect = NULL, rect_sub, __$null, _0;
	zend_long renderer, ptr = 0, flags = 0, format = 0, w = 0, h = 0, pitch = 0, pixels_ptr = 0, refcount = 0;

	ZVAL_UNDEF(&rect_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pixels_data);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(renderer)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(rect)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &renderer_param, &rect);
	if (!rect) {
		rect = &rect_sub;
		rect = &__$null;
	}
	
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

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLUpdateTextureFromSurface)
{
	zend_bool result = 0;
	zval *texture_param = NULL, *surface_param = NULL;
	zend_long texture, surface;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &texture_param, &surface_param);
	
            SDL_Texture *tex  = (SDL_Texture *)(uintptr_t) texture;
            SDL_Surface *surf = (SDL_Surface *)(uintptr_t) surface;
            result = SDL_UpdateTexture(tex, NULL, surf->pixels, surf->pitch);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderDebugText)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval str;
	double x, y;
	zval *renderer_param = NULL, *x_param = NULL, *y_param = NULL, *str_param = NULL;
	zend_long renderer;

	ZVAL_UNDEF(&str);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_STR(str)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &renderer_param, &x_param, &y_param, &str_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	zephir_get_strval(&str, str_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_RenderDebugText(ren, (float) x, (float) y, Z_STRVAL(str));
        
	RETURN_MM_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderScale)
{
	zend_bool result = 0;
	double scaleX, scaleY;
	zval *renderer_param = NULL, *scaleX_param = NULL, *scaleY_param = NULL;
	zend_long renderer;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ZVAL(scaleX)
		Z_PARAM_ZVAL(scaleY)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &renderer_param, &scaleX_param, &scaleY_param);
	scaleX = zephir_get_doubleval(scaleX_param);
	scaleY = zephir_get_doubleval(scaleY_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_SetRenderScale(ren, (float) scaleX, (float) scaleY);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderTextureAffine)
{
	zend_bool result = 0, _0, _1;
	zval *renderer_param = NULL, *texture_param = NULL, *origin = NULL, origin_sub, *right = NULL, right_sub, *down = NULL, down_sub, *srcrect = NULL, srcrect_sub, __$null;
	zend_long renderer, texture;

	ZVAL_UNDEF(&origin_sub);
	ZVAL_UNDEF(&right_sub);
	ZVAL_UNDEF(&down_sub);
	ZVAL_UNDEF(&srcrect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 6)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(texture)
		Z_PARAM_ZVAL(origin)
		Z_PARAM_ZVAL(right)
		Z_PARAM_ZVAL(down)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(srcrect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 1, &renderer_param, &texture_param, &origin, &right, &down, &srcrect);
	if (!srcrect) {
		srcrect = &srcrect_sub;
		srcrect = &__$null;
	}
	_0 = Z_TYPE_P(origin) != IS_ARRAY;
	if (!(_0)) {
		_0 = Z_TYPE_P(right) != IS_ARRAY;
	}
	_1 = _0;
	if (!(_1)) {
		_1 = Z_TYPE_P(down) != IS_ARRAY;
	}
	if (_1) {
		RETURN_BOOL(0);
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderFillRects)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval rects;
	zval *renderer_param = NULL, *rects_param = NULL, *count_param = NULL;
	zend_long renderer, count;

	ZVAL_UNDEF(&rects);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ARRAY(rects)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &renderer_param, &rects_param, &count_param);
	zephir_get_arrval(&rects, rects_param);
	
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
        
	RETURN_MM_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderRects)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval rects;
	zval *renderer_param = NULL, *rects_param = NULL, *count_param = NULL;
	zend_long renderer, count;

	ZVAL_UNDEF(&rects);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ARRAY(rects)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &renderer_param, &rects_param, &count_param);
	zephir_get_arrval(&rects, rects_param);
	
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
        
	RETURN_MM_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderLine)
{
	zend_bool result = 0;
	double x1, y1, x2, y2;
	zval *renderer_param = NULL, *x1_param = NULL, *y1_param = NULL, *x2_param = NULL, *y2_param = NULL;
	zend_long renderer;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ZVAL(x1)
		Z_PARAM_ZVAL(y1)
		Z_PARAM_ZVAL(x2)
		Z_PARAM_ZVAL(y2)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &renderer_param, &x1_param, &y1_param, &x2_param, &y2_param);
	x1 = zephir_get_doubleval(x1_param);
	y1 = zephir_get_doubleval(y1_param);
	x2 = zephir_get_doubleval(x2_param);
	y2 = zephir_get_doubleval(y2_param);
	
            SDL_Renderer *ren = (SDL_Renderer *)(uintptr_t) renderer;
            result = SDL_RenderLine(ren, (float) x1, (float) y1, (float) x2, (float) y2);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderRect)
{
	zend_bool result = 0;
	zval *renderer_param = NULL, *rect = NULL, rect_sub, __$null;
	zend_long renderer;

	ZVAL_UNDEF(&rect_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(renderer)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(rect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 1, &renderer_param, &rect);
	if (!rect) {
		rect = &rect_sub;
		rect = &__$null;
	}
	
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
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderPoints)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval points;
	zval *renderer_param = NULL, *points_param = NULL, *count_param = NULL;
	zend_long renderer, count;

	ZVAL_UNDEF(&points);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ARRAY(points)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &renderer_param, &points_param, &count_param);
	zephir_get_arrval(&points, points_param);
	
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
        
	RETURN_MM_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderGeometry)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval vertices;
	zval *renderer_param = NULL, *texture_param = NULL, *vertices_param = NULL, *num_vertices_param = NULL, *num_indices_param = NULL, *indices = NULL, indices_sub, __$null;
	zend_long renderer, texture, num_vertices, num_indices;

	ZVAL_UNDEF(&indices_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&vertices);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 6)
		Z_PARAM_LONG(renderer)
		Z_PARAM_LONG(texture)
		Z_PARAM_ARRAY(vertices)
		Z_PARAM_LONG(num_vertices)
		Z_PARAM_LONG(num_indices)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(indices)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 5, 1, &renderer_param, &texture_param, &vertices_param, &num_vertices_param, &num_indices_param, &indices);
	zephir_get_arrval(&vertices, vertices_param);
	if (!indices) {
		indices = &indices_sub;
		indices = &__$null;
	}
	
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
        
	RETURN_MM_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderLines)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval points;
	zval *renderer_param = NULL, *points_param = NULL, *count_param = NULL;
	zend_long renderer, count;

	ZVAL_UNDEF(&points);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(renderer)
		Z_PARAM_ARRAY(points)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &renderer_param, &points_param, &count_param);
	zephir_get_arrval(&points, points_param);
	
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
        
	RETURN_MM_BOOL(result);
}

