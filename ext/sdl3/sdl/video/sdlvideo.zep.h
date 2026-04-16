
extern zend_class_entry *sdl3_sdl_video_sdlvideo_ce;

ZEPHIR_INIT_CLASS(Sdl3_SDL_Video_SDLVideo);

PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLCreateWindow);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowSize);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowPosition);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowSizeInPixels);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowMinimumSize);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowMaximumSize);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLGetWindowAspectRatio);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLSetWindowIcon);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLDestroyWindow);
PHP_METHOD(Sdl3_SDL_Video_SDLVideo, SDLCreateWindowAndRenderer);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlcreatewindow, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowsize, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowposition, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowsizeinpixels, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowminimumsize, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowmaximumsize, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowaspectratio, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlsetwindowicon, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdldestroywindow, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_video_sdlvideo_sdlcreatewindowandrenderer, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sdl3_sdl_video_sdlvideo_method_entry) {
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLCreateWindow, arginfo_sdl3_sdl_video_sdlvideo_sdlcreatewindow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLGetWindowSize, arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLGetWindowPosition, arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLGetWindowSizeInPixels, arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowsizeinpixels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLGetWindowMinimumSize, arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowminimumsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLGetWindowMaximumSize, arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowmaximumsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLGetWindowAspectRatio, arginfo_sdl3_sdl_video_sdlvideo_sdlgetwindowaspectratio, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLSetWindowIcon, arginfo_sdl3_sdl_video_sdlvideo_sdlsetwindowicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLDestroyWindow, arginfo_sdl3_sdl_video_sdlvideo_sdldestroywindow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Video_SDLVideo, SDLCreateWindowAndRenderer, arginfo_sdl3_sdl_video_sdlvideo_sdlcreatewindowandrenderer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
