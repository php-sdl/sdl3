
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



ZEPHIR_INIT_CLASS(Sdl3_SDL_Video_SDLVideo)
{
	ZEPHIR_REGISTER_CLASS(Sdl3\\SDL\\Video, SDLVideo, sdl3, sdl_video_sdlvideo, sdl3_sdl_video_sdlvideo_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLCreateWindow)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long width, height, flags, ZEPHIR_LAST_CALL_STATUS, ptr = 0;
	zval *title_param = NULL, *width_param = NULL, *height_param = NULL, *flags_param = NULL, _0$$3, _1$$3, _2$$3;
	zval title;

	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(title)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &title_param, &width_param, &height_param, &flags_param);
	zephir_get_strval(&title, title_param);
	
            SDL_Window *window = SDL_CreateWindow(Z_STRVAL(title), (int) width, (int) height, (SDL_WindowFlags) flags);
            ptr = (zend_long)(uintptr_t) window;
        
	if (ptr == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_RuntimeException);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, sdl3_sdl_sdlerror_ce, "sdlgeterror", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "SDL_CreateWindow failed: ", &_1$$3);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "sdl3/sdl/video/sdlvideo.zep", 19);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(ptr);
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowSize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, _0;
	zend_long window, w = 0, h = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &window_param);
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int ww = 0, wh = 0;
            SDL_GetWindowSize(win, &ww, &wh);
            w = (zend_long) ww;
            h = (zend_long) wh;
        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowPosition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, _0;
	zend_long window, x = 0, y = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &window_param);
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int wx = 0, wy = 0;
            SDL_GetWindowPosition(win, &wx, &wy);
            x = (zend_long) wx;
            y = (zend_long) wy;
        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, x);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, y);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowSizeInPixels)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, _0;
	zend_long window, w = 0, h = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &window_param);
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int pw = 0, ph = 0;
            SDL_GetWindowSizeInPixels(win, &pw, &ph);
            w = (zend_long) pw;
            h = (zend_long) ph;
        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, w);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, h);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowMinimumSize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, _0;
	zend_long window, min_w = 0, min_h = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &window_param);
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int pw = 0, ph = 0;
            SDL_GetWindowMinimumSize(win, &pw, &ph);
            min_w = (zend_long) pw;
            min_h = (zend_long) ph;

        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, min_w);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, min_h);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowMaximumSize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, _0;
	zend_long window, max_w = 0, max_h = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &window_param);
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            int pw = 0, ph = 0;
            SDL_GetWindowMaximumSize(win, &pw, &ph);
            max_w = (zend_long) pw;
            max_h = (zend_long) ph;

        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, max_w);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, max_h);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowAspectRatio)
{
	double min_aspect = 0, max_aspect = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, _0;
	zend_long window;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &window_param);
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            float mn = 0.0f, mx = 0.0f;
            SDL_GetWindowAspectRatio(win, &mn, &mx);
            min_aspect = (double) mn;
            max_aspect = (double) mx;
        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_DOUBLE(&_0, min_aspect);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_DOUBLE(&_0, max_aspect);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLSetWindowIcon)
{
	zend_bool result = 0;
	zval *window_param = NULL, *surface_param = NULL;
	zend_long window, surface;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(window)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &window_param, &surface_param);
	
            SDL_Window  *win  = (SDL_Window *)(uintptr_t) window;
            SDL_Surface *icon = (SDL_Surface *)(uintptr_t) surface;
            result = SDL_SetWindowIcon(win, icon);
        
	RETURN_BOOL(result);
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLDestroyWindow)
{
	zval *window_param = NULL;
	zend_long window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &window_param);
	
            SDL_Window *win = (SDL_Window *)(uintptr_t) window;
            SDL_DestroyWindow(win);
        
}

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLCreateWindowAndRenderer)
{
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long w, h, flags, window_ptr = 0, renderer_ptr = 0;
	zval *title_param = NULL, *w_param = NULL, *h_param = NULL, *flags_param = NULL, _0;
	zval title;

	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(title)
		Z_PARAM_LONG(w)
		Z_PARAM_LONG(h)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &title_param, &w_param, &h_param, &flags_param);
	zephir_get_strval(&title, title_param);
	
            SDL_Window   *win = NULL;
            SDL_Renderer *ren = NULL;
            result = SDL_CreateWindowAndRenderer(Z_STRVAL(title), (int) w, (int) h, (SDL_WindowFlags) flags, &win, &ren);
            window_ptr   = (zend_long)(uintptr_t) win;
            renderer_ptr = (zend_long)(uintptr_t) ren;
        
	if (!(result)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, window_ptr);
	zephir_array_update_string(return_value, SL("window"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, renderer_ptr);
	zephir_array_update_string(return_value, SL("renderer"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

