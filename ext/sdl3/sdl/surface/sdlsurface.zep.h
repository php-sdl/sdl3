
extern zend_class_entry *sdl3_sdl_surface_sdlsurface_ce;

ZEPHIR_INIT_CLASS(Sdl3_SDL_Surface_SDLSurface);

PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLCreateSurface);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLDuplicateSurface);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLConvertSurface);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLSurfaceToBlackAndWhite);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLBlitSurface);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLFillSurfaceRect);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLMapRGB);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLLockSurface);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLUnlockSurface);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLDestroySurface);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLLoadPNG);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLLoadBMP);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLWriteSurfacePixelAt);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLWriteSurfacePixels);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLReadSurfacePixels);
PHP_METHOD(Sdl3_SDL_Surface_SDLSurface, SDLGetSurfacePalette);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlcreatesurface, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlduplicatesurface, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlconvertsurface, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlsurfacetoblackandwhite, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlblitsurface, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, src, IS_LONG, 0)
	ZEND_ARG_INFO(0, srcrect)
	ZEND_ARG_TYPE_INFO(0, dst, IS_LONG, 0)
	ZEND_ARG_INFO(0, dstrect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlfillsurfacerect, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
	ZEND_ARG_INFO(0, rect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlmaprgb, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, palette, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdllocksurface, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlunlocksurface, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdldestroysurface, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlloadpng, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlloadbmp, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlwritesurfacepixelat, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlwritesurfacepixels, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlreadsurfacepixels, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_surface_sdlsurface_sdlgetsurfacepalette, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sdl3_sdl_surface_sdlsurface_method_entry) {
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLCreateSurface, arginfo_sdl3_sdl_surface_sdlsurface_sdlcreatesurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLDuplicateSurface, arginfo_sdl3_sdl_surface_sdlsurface_sdlduplicatesurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLConvertSurface, arginfo_sdl3_sdl_surface_sdlsurface_sdlconvertsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLSurfaceToBlackAndWhite, arginfo_sdl3_sdl_surface_sdlsurface_sdlsurfacetoblackandwhite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLBlitSurface, arginfo_sdl3_sdl_surface_sdlsurface_sdlblitsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLFillSurfaceRect, arginfo_sdl3_sdl_surface_sdlsurface_sdlfillsurfacerect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLMapRGB, arginfo_sdl3_sdl_surface_sdlsurface_sdlmaprgb, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLLockSurface, arginfo_sdl3_sdl_surface_sdlsurface_sdllocksurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLUnlockSurface, arginfo_sdl3_sdl_surface_sdlsurface_sdlunlocksurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLDestroySurface, arginfo_sdl3_sdl_surface_sdlsurface_sdldestroysurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLLoadPNG, arginfo_sdl3_sdl_surface_sdlsurface_sdlloadpng, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLLoadBMP, arginfo_sdl3_sdl_surface_sdlsurface_sdlloadbmp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLWriteSurfacePixelAt, arginfo_sdl3_sdl_surface_sdlsurface_sdlwritesurfacepixelat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLWriteSurfacePixels, arginfo_sdl3_sdl_surface_sdlsurface_sdlwritesurfacepixels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLReadSurfacePixels, arginfo_sdl3_sdl_surface_sdlsurface_sdlreadsurfacepixels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Surface_SDLSurface, SDLGetSurfacePalette, arginfo_sdl3_sdl_surface_sdlsurface_sdlgetsurfacepalette, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
