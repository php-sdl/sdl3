
extern zend_class_entry *sdl3_sdl_render_sdlrender_ce;

ZEPHIR_INIT_CLASS(Sdl3_SDL_Render_SDLRender);

PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateRenderer);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateSoftwareRenderer);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderClear);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderPresent);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderTexture);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderTextureRotated);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderDrawColor);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderDrawColorFloat);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateTexture);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLCreateTextureFromSurface);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLLockTextureToSurface);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLUnlockTexture);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetTextureColorModFloat);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetTextureScaleMode);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLGetTextureSize);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderLogicalPresentation);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLDestroyRenderer);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLDestroyTexture);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderFillRect);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderViewport);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderClipRect);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderReadPixels);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLUpdateTextureFromSurface);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderDebugText);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLSetRenderScale);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderTextureAffine);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderFillRects);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderRects);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderLine);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderRect);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderPoints);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderGeometry);
PHP_METHOD(Sdl3_SDL_Render_SDLRender, SDLRenderLines);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlcreaterenderer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlcreatesoftwarerenderer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderclear, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderpresent, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrendertexture, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_INFO(0, srcrect)
	ZEND_ARG_INFO(0, dstrect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrendertexturerotated, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, flip, IS_LONG, 0)
	ZEND_ARG_INFO(0, srcrect)
	ZEND_ARG_INFO(0, dstrect)
	ZEND_ARG_INFO(0, center)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderdrawcolor, 0, 5, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderdrawcolorfloat, 0, 5, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlcreatetexture, 0, 5, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, access, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlcreatetexturefromsurface, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdllocktexturetosurface, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_INFO(0, rect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlunlocktexture, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsettexturecolormodfloat, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsettexturescalemode, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, scaleMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlgettexturesize, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderlogicalpresentation, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, h, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdldestroyrenderer, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdldestroytexture, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderfillrect, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_INFO(0, rect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderviewport, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_INFO(0, rect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsetrendercliprect, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_INFO(0, rect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderreadpixels, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_INFO(0, rect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlupdatetexturefromsurface, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderdebugtext, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderscale, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, scaleX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, scaleY, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrendertextureaffine, 0, 5, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_INFO(0, origin)
	ZEND_ARG_INFO(0, right)
	ZEND_ARG_INFO(0, down)
	ZEND_ARG_INFO(0, srcrect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderfillrects, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, rects, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderrects, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, rects, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderline, 0, 5, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderrect, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_INFO(0, rect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderpoints, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, points, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrendergeometry, 0, 5, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, vertices, 0)
	ZEND_ARG_TYPE_INFO(0, num_vertices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_indices, IS_LONG, 0)
	ZEND_ARG_INFO(0, indices)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sdl3_sdl_render_sdlrender_sdlrenderlines, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, renderer, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, points, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sdl3_sdl_render_sdlrender_method_entry) {
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLCreateRenderer, arginfo_sdl3_sdl_render_sdlrender_sdlcreaterenderer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLCreateSoftwareRenderer, arginfo_sdl3_sdl_render_sdlrender_sdlcreatesoftwarerenderer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderClear, arginfo_sdl3_sdl_render_sdlrender_sdlrenderclear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderPresent, arginfo_sdl3_sdl_render_sdlrender_sdlrenderpresent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderTexture, arginfo_sdl3_sdl_render_sdlrender_sdlrendertexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderTextureRotated, arginfo_sdl3_sdl_render_sdlrender_sdlrendertexturerotated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetRenderDrawColor, arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderdrawcolor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetRenderDrawColorFloat, arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderdrawcolorfloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLCreateTexture, arginfo_sdl3_sdl_render_sdlrender_sdlcreatetexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLCreateTextureFromSurface, arginfo_sdl3_sdl_render_sdlrender_sdlcreatetexturefromsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLLockTextureToSurface, arginfo_sdl3_sdl_render_sdlrender_sdllocktexturetosurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLUnlockTexture, arginfo_sdl3_sdl_render_sdlrender_sdlunlocktexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetTextureColorModFloat, arginfo_sdl3_sdl_render_sdlrender_sdlsettexturecolormodfloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetTextureScaleMode, arginfo_sdl3_sdl_render_sdlrender_sdlsettexturescalemode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLGetTextureSize, arginfo_sdl3_sdl_render_sdlrender_sdlgettexturesize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetRenderLogicalPresentation, arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderlogicalpresentation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLDestroyRenderer, arginfo_sdl3_sdl_render_sdlrender_sdldestroyrenderer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLDestroyTexture, arginfo_sdl3_sdl_render_sdlrender_sdldestroytexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderFillRect, arginfo_sdl3_sdl_render_sdlrender_sdlrenderfillrect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetRenderViewport, arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderviewport, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetRenderClipRect, arginfo_sdl3_sdl_render_sdlrender_sdlsetrendercliprect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderReadPixels, arginfo_sdl3_sdl_render_sdlrender_sdlrenderreadpixels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLUpdateTextureFromSurface, arginfo_sdl3_sdl_render_sdlrender_sdlupdatetexturefromsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderDebugText, arginfo_sdl3_sdl_render_sdlrender_sdlrenderdebugtext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLSetRenderScale, arginfo_sdl3_sdl_render_sdlrender_sdlsetrenderscale, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderTextureAffine, arginfo_sdl3_sdl_render_sdlrender_sdlrendertextureaffine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderFillRects, arginfo_sdl3_sdl_render_sdlrender_sdlrenderfillrects, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderRects, arginfo_sdl3_sdl_render_sdlrender_sdlrenderrects, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderLine, arginfo_sdl3_sdl_render_sdlrender_sdlrenderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderRect, arginfo_sdl3_sdl_render_sdlrender_sdlrenderrect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderPoints, arginfo_sdl3_sdl_render_sdlrender_sdlrenderpoints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderGeometry, arginfo_sdl3_sdl_render_sdlrender_sdlrendergeometry, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Sdl3_SDL_Render_SDLRender, SDLRenderLines, arginfo_sdl3_sdl_render_sdlrender_sdlrenderlines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
