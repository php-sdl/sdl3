# php-sdl3

[![PHP](https://img.shields.io/badge/php-%E2%89%A5%208.2-777bb4?logo=php&logoColor=white)](https://www.php.net)
[![SDL3](https://img.shields.io/badge/SDL3-%E2%89%A5%203.4.0-1d4ed8)](https://www.libsdl.org/)
[![Built with Zephir](https://img.shields.io/badge/built%20with-Zephir-ff6a00)](https://zephir-lang.com/)
[![Platform](https://img.shields.io/badge/platform-linux%20%7C%20macOS-lightgrey)](#requirements)
[![License: MIT](https://img.shields.io/badge/license-MIT-green)](#license)

> PHP extension for SDL3 — built with [Zephir](https://zephir-lang.com/), installable via [PHP PIE](https://github.com/php/pie).

`sdl3` exposes SDL3's core, video, render, surface, timer, and event APIs to
PHP 8.2+ as a set of namespaced classes under `Sdl3\SDL\…`. The extension links
against the system `libSDL3`, so it is as fast as a native SDL3 program and
supports both hardware-accelerated windows and the headless software renderer.

---

## Table of contents

- [Requirements](#requirements)
- [Installation](#installation)
  - [Via PHP PIE (recommended)](#via-php-pie-recommended)
  - [Platform installers](#platform-installers)
  - [Manual build with `phpize`](#manual-build-with-phpize)
- [Verifying the install](#verifying-the-install)
- [Quick start](#quick-start)
- [API reference](#api-reference)
- [License](#license)

---

## Requirements

| Component            | Minimum version | Notes                                                                 |
| -------------------- | --------------- | --------------------------------------------------------------------- |
| PHP                  | 8.2             | ZTS and NTS builds both supported.                                    |
| SDL3                 | 3.4.0           | Must be discoverable via `pkg-config sdl3` or the usual search paths. |
| OS                   | Linux / macOS   | Windows is not currently supported.                                   |
| Compiler             | C11 toolchain   | `gcc`, `clang`, or Apple Clang.                                       |
| `php-dev` / `phpize` | matches PHP     | Required for any build path that is not PIE.                          |

Tested on macOS (Apple Silicon + Intel), Debian Trixie, Raspberry Pi OS
(arm64 / armhf), and NVIDIA JetPack 6 (Jetson Orin).

---

## Installation

### Via PHP PIE (recommended)

PIE reads the `php-ext` block from `composer.json` and runs the full build
pipeline (phpize → configure → make → install) on your behalf:

```bash
pie install php-io-extensions/sdl3
```

PIE will invoke the `--enable-sdl3` configure option automatically. Make sure
SDL3 ≥ 3.4.0 is already installed on the system (see the platform installers
below if it is not).

### Platform installers

Three installer scripts live at the repository root. They install SDL3 if it
is missing, then build and enable the extension for every available PHP SAPI.

**macOS** (Homebrew):

```bash
bash install-macos.sh
```

**Debian Trixie / Raspberry Pi OS** (amd64, arm64, armhf):

```bash
bash install-debian-trixie.sh
```

**JetPack 6 / Ubuntu 22.04** (builds SDL3 from source, since apt ships no
compatible version):

```bash
bash install-jetpack6.sh
```

Each script writes a full build log to `./build.log` and prints concise
failure diagnostics if anything goes wrong.

### Manual build with `phpize`

For full control, build from the pre-generated C source in `ext/`:

```bash
cd ext
phpize
./configure --enable-sdl3
make -j"$(nproc 2>/dev/null || sysctl -n hw.logicalcpu)"
sudo make install
```

Then enable it for the CLI (and any other SAPI you use) by adding
`extension=sdl3.so` to the appropriate `php.ini` file, or drop a file into
your distribution's conf.d directory:

```ini
; /etc/php/8.3/cli/conf.d/20-sdl3.ini
extension=sdl3.so
```

If SDL3 is installed in a non-standard prefix, export
`PKG_CONFIG_PATH=/usr/local/lib/pkgconfig` (or the equivalent) before running
`./configure`.

---

## Verifying the install

Run the bundled proof-of-work script — it exercises the full surface and
software-renderer pipeline headlessly, so it works without a display server:

```bash
php examples/proof_of_work.php
```

Expected tail of the output:

```
── Summary ──
  All checks passed — sdl3 extension is working correctly.
```

A one-liner sanity check:

```bash
php -r 'echo Sdl3\SDL\SDL::SDLGetPlatform(), PHP_EOL;'
```

---

## Quick start

```php
<?php
use Sdl3\SDL\SDL;
use Sdl3\SDL\Video\SDLVideo;
use Sdl3\SDL\Render\SDLRender;
use Sdl3\SDL\Events\SDLEvents;

const SDL_INIT_VIDEO = 0x20;
const SDL_EVENT_QUIT = 0x100;

SDL::SDLInit(SDL_INIT_VIDEO);

[$window, $renderer] = array_values(
    SDLVideo::SDLCreateWindowAndRenderer('Hello SDL3', 640, 480, 0)
);

$running = true;
while ($running) {
    while (($ev = SDLEvents::SDLPollEvent()) !== null) {
        if (($ev['type'] ?? 0) === SDL_EVENT_QUIT) {
            $running = false;
        }
    }

    SDLRender::SDLSetRenderDrawColor($renderer, 30, 30, 60, 255);
    SDLRender::SDLRenderClear($renderer);
    SDLRender::SDLSetRenderDrawColor($renderer, 255, 200, 0, 255);
    SDLRender::SDLRenderDebugText($renderer, 20.0, 20.0, 'Hello from PHP + SDL3!');
    SDLRender::SDLRenderPresent($renderer);
}

SDLRender::SDLDestroyRenderer($renderer);
SDLVideo::SDLDestroyWindow($window);
SDL::SDLQuit();
```

See `examples/proof_of_work.php` for a headless surface/renderer example.

---

## API reference

All classes live under the `Sdl3\SDL` namespace. The PHP stubs that drive your
IDE's autocomplete are published under `ide/0.2.0/` — this reference mirrors
them exactly.

### `Sdl3\SDL\SDL` — lifecycle, version, platform

| Method                                                                                      | Returns   |
| -------------------------------------------------------------------------------------------- | --------- |
| `SDLInit(int $flags)`                                                                        | `bool`    |
| `SDLInitSubSystem(int $flags)`                                                               | `bool`    |
| `SDLWasInit(int $flags)`                                                                     | `int`     |
| `SDLQuit()`                                                                                  | `void`    |
| `SDLQuitSubSystem(int $flags)`                                                               | `void`    |
| `SDLExitProcess(int $exitcode)`                                                              | `void`    |
| `SDLGetPixelFormatDetails(int $format)`                                                      | `array`   |
| `SDLGetRGBA(int $pixel, int $format_ptr, mixed $palette_ptr = null)`                         | `array`   |
| `SDLMapRGBA(int $format_ptr, mixed $palette_ptr, int $r, int $g, int $b, int $a)`            | `int`     |
| `SDLGetSandbox()`                                                                            | `int`     |
| `SDLGetVersion()`                                                                            | `int`     |
| `SDLGetRevision()`                                                                           | `string`  |
| `SDLGetPlatform()`                                                                           | `string`  |
| `SDLIsTablet()`                                                                              | `bool`    |
| `SDLIsTV()`                                                                                  | `bool`    |
| `SDLSetAppMetadata(string $appname, string $appversion, string $appidentifier)`              | `bool`    |
| `SDLSetAppMetadataProperty(string $name, string $value)`                                     | `bool`    |
| `SDLGetAppMetadataProperty(string $name)`                                                    | `string`  |
| `SDLSetMainReady()`                                                                          | `void`    |
| `SDLIsMainThread()`                                                                          | `bool`    |
| `SDLRand(int $n)`                                                                            | `int`     |
| `SDLRandf()`                                                                                 | `float`   |

`SDLGetVersion()` returns SDL's packed integer: `major = v / 1_000_000`,
`minor = (v / 1_000) % 1_000`, `patch = v % 1_000`.

### `Sdl3\SDL\SDLError` — error handling

| Method                          | Returns  |
| ------------------------------- | -------- |
| `SDLGetError()`                 | `string` |
| `SDLSetError(string $message)`  | `bool`   |
| `SDLOutOfMemory()`              | `bool`   |
| `SDLClearError()`               | `bool`   |

### `Sdl3\SDL\Surface\SDLSurface` — surfaces & pixel operations

| Method                                                                                       | Returns |
| -------------------------------------------------------------------------------------------- | ------- |
| `SDLCreateSurface(int $width, int $height, int $format)`                                     | `array` |
| `SDLDuplicateSurface(int $surface)`                                                          | `array` |
| `SDLConvertSurface(int $surface, int $format)`                                               | `array` |
| `SDLSurfaceToBlackAndWhite(int $surface)`                                                    | `void`  |
| `SDLBlitSurface(int $src, mixed $srcrect, int $dst, mixed $dstrect = null)`                  | `bool`  |
| `SDLFillSurfaceRect(int $surface, int $color, mixed $rect = null)`                           | `bool`  |
| `SDLMapRGB(int $format, int $palette, int $r, int $g, int $b)`                               | `int`   |
| `SDLLockSurface(int $surface)`                                                               | `bool`  |
| `SDLUnlockSurface(int $surface)`                                                             | `void`  |
| `SDLDestroySurface(int $surface)`                                                            | `void`  |
| `SDLLoadPNG(string $file)`                                                                   | `array` |
| `SDLLoadBMP(string $file)`                                                                   | `array` |
| `SDLWriteSurfacePixelAt(int $surface, int $x, int $y, int $pixel)`                           | `bool`  |
| `SDLWriteSurfacePixels(int $surface, array $data)`                                           | `bool`  |
| `SDLReadSurfacePixels(int $surface)`                                                         | `array` |
| `SDLGetSurfacePalette(int $surface)`                                                         | `array` |

`SDLCreateSurface` returns `['ptr' => int, 'w' => int, 'h' => int, 'pitch' => int, …]`.
`SDLReadSurfacePixels` returns `['pixels_data' => int[], …]` — one packed
integer per pixel, row-major.

### `Sdl3\SDL\Render\SDLRender` — renderer & drawing primitives

| Method                                                                                                       | Returns |
| ------------------------------------------------------------------------------------------------------------ | ------- |
| `SDLCreateRenderer(int $window, mixed $name = null)`                                                         | `int`   |
| `SDLCreateSoftwareRenderer(int $surface)`                                                                    | `int`   |
| `SDLRenderClear(int $renderer)`                                                                              | `void`  |
| `SDLRenderPresent(int $renderer)`                                                                            | `bool`  |
| `SDLRenderTexture(int $renderer, int $texture, mixed $srcrect = null, mixed $dstrect = null)`               | `bool`  |
| `SDLRenderTextureRotated(int $renderer, int $texture, float $angle, int $flip, …)`                           | `bool`  |
| `SDLRenderTextureAffine(int $renderer, int $texture, mixed $origin, mixed $right, mixed $down, …)`           | `bool`  |
| `SDLSetRenderDrawColor(int $renderer, int $r, int $g, int $b, int $a)`                                       | `bool`  |
| `SDLSetRenderDrawColorFloat(int $renderer, float $r, float $g, float $b, float $a)`                          | `bool`  |
| `SDLCreateTexture(int $renderer, int $format, int $access, int $w, int $h)`                                  | `array` |
| `SDLCreateTextureFromSurface(int $renderer, int $surface)`                                                   | `array` |
| `SDLLockTextureToSurface(int $texture, mixed $rect = null)`                                                  | `array` |
| `SDLUnlockTexture(int $texture)`                                                                             | `void`  |
| `SDLSetTextureColorModFloat(int $texture, float $r, float $g, float $b)`                                    | `bool`  |
| `SDLSetTextureScaleMode(int $texture, int $scaleMode)`                                                       | `bool`  |
| `SDLGetTextureSize(int $texture)`                                                                            | `array` |
| `SDLSetRenderLogicalPresentation(int $renderer, int $w, int $h, int $mode)`                                  | `bool`  |
| `SDLDestroyRenderer(int $renderer)`                                                                          | `void`  |
| `SDLDestroyTexture(int $texture)`                                                                            | `void`  |
| `SDLRenderFillRect(int $renderer, mixed $rect = null)`                                                       | `bool`  |
| `SDLRenderFillRects(int $renderer, array $rects, int $count)`                                                | `bool`  |
| `SDLRenderRect(int $renderer, mixed $rect = null)`                                                           | `bool`  |
| `SDLRenderRects(int $renderer, array $rects, int $count)`                                                    | `bool`  |
| `SDLRenderLine(int $renderer, float $x1, float $y1, float $x2, float $y2)`                                   | `bool`  |
| `SDLRenderLines(int $renderer, array $points, int $count)`                                                   | `bool`  |
| `SDLRenderPoints(int $renderer, array $points, int $count)`                                                  | `bool`  |
| `SDLRenderGeometry(int $renderer, int $texture, array $vertices, int $num_vertices, int $num_indices, …)`    | `bool`  |
| `SDLRenderReadPixels(int $renderer, mixed $rect = null)`                                                     | `array` |
| `SDLUpdateTextureFromSurface(int $texture, int $surface)`                                                    | `bool`  |
| `SDLRenderDebugText(int $renderer, float $x, float $y, string $str)`                                         | `bool`  |
| `SDLSetRenderScale(int $renderer, float $scaleX, float $scaleY)`                                             | `bool`  |
| `SDLSetRenderViewport(int $renderer, mixed $rect = null)`                                                    | `bool`  |
| `SDLSetRenderClipRect(int $renderer, mixed $rect = null)`                                                    | `bool`  |

### `Sdl3\SDL\Video\SDLVideo` — window management

| Method                                                                               | Returns |
| ------------------------------------------------------------------------------------ | ------- |
| `SDLCreateWindow(string $title, int $width, int $height, int $flags)`                | `int`   |
| `SDLCreateWindowAndRenderer(string $title, int $w, int $h, int $flags)`              | `array` |
| `SDLGetWindowSize(int $window)`                                                      | `array` |
| `SDLGetWindowPosition(int $window)`                                                  | `array` |
| `SDLGetWindowSizeInPixels(int $window)`                                              | `array` |
| `SDLGetWindowMinimumSize(int $window)`                                               | `array` |
| `SDLGetWindowMaximumSize(int $window)`                                               | `array` |
| `SDLGetWindowAspectRatio(int $window)`                                               | `array` |
| `SDLSetWindowIcon(int $window, int $surface)`                                        | `bool`  |
| `SDLDestroyWindow(int $window)`                                                      | `void`  |

`SDLCreateWindowAndRenderer` returns `['window' => int, 'renderer' => int, …]`.

### `Sdl3\SDL\Timer\SDLTimer` — timing utilities

| Method                | Returns |
| --------------------- | ------- |
| `SDLDelay(int $ms)`   | `void`  |
| `SDLGetTicks()`       | `int`   |

### `Sdl3\SDL\Events\SDLEvents` — event queue

| Method                                                                                | Returns        |
| ------------------------------------------------------------------------------------- | -------------- |
| `SDLPollEvent()`                                                                      | `array\|null`  |
| `SDLWaitEvent()`                                                                      | `array\|null`  |
| `SDLWaitEventTimeout(int $timeout_ms)`                                                | `int`          |
| `SDLReadEvent(int $ptr, string $key)`                                                 | `array`        |
| `SDLPeepEvents(int $action, int $min_type, int $max_type, int $numevents = 1)`        | `array`        |
| `SDLHasEvent(int $type)`                                                              | `bool`         |
| `SDLHasEvents(int $min_type, int $max_type)`                                          | `bool`         |
| `SDLFlushEvent(int $type)`                                                            | `void`         |
| `SDLFlushEvents(int $min_type, int $max_type)`                                        | `void`         |
| `SDLPushEvent(int $event_ptr)`                                                        | `bool`         |
| `SDLFreeEvent(int $ptr)`                                                              | `void`         |
| `SDLPumpEvents()`                                                                     | `void`         |
| `SDLGetKeyboardState()`                                                               | `array`        |

Each event array always carries a numeric `type` key matching the
`SDL_EVENT_*` enum.

### `Sdl3\SDL\Events\SDLCategories` — event filtering & metadata

| Method                                                       | Returns  |
| ------------------------------------------------------------ | -------- |
| `SDLSetEventEnabled(int $type, bool $enabled)`               | `void`   |
| `SDLEventEnabled(int $type)`                                 | `bool`   |
| `SDLRegisterEvents(int $numevents)`                          | `int`    |
| `SDLGetWindowFromEvent(int $event_ptr)`                      | `int`    |
| `SDLGetEventDescription(int $event_ptr, int $buflen = 256)`  | `string` |

### `Sdl3\SDL\Events\SDLKeyboard` — keyboard input & text entry

| Method                                                                        | Returns       |
| ----------------------------------------------------------------------------- | ------------- |
| `SDLHasKeyboard()`                                                            | `bool`        |
| `SDLGetKeyboards()`                                                           | `array`       |
| `SDLGetKeyboardNameForID(int $instance_id)`                                   | `string`      |
| `SDLGetKeyboardFocus()`                                                       | `int`         |
| `SDLGetKeyboardState()`                                                       | `array`       |
| `SDLGetModState()`                                                            | `int`         |
| `SDLSetModState(int $modstate)`                                               | `void`        |
| `SDLGetKeyFromScancode(int $scancode, int $modstate = 0, bool $key_event = true)` | `int`     |
| `SDLGetScancodeFromKey(int $key)`                                             | `array`       |
| `SDLSetScancodeName(int $scancode, string $name)`                             | `bool`        |
| `SDLGetScancodeName(int $scancode)`                                           | `string`      |
| `SDLGetScancodeFromName(string $name)`                                        | `int`         |
| `SDLGetKeyName(int $key)`                                                     | `string`      |
| `SDLGetKeyFromName(string $name)`                                             | `int`         |
| `SDLStartTextInput(int $window)`                                              | `bool`        |
| `SDLStartTextInputWithProperties(int $window, int $props)`                    | `bool`        |
| `SDLTextInputActive(int $window)`                                             | `bool`        |
| `SDLStopTextInput(int $window)`                                               | `bool`        |
| `SDLClearComposition(int $window)`                                            | `bool`        |
| `SDLSetTextInputArea(int $window, mixed $rect = null, int $cursor = 0)`       | `bool`        |
| `SDLGetTextInputArea(int $window)`                                            | `array\|null` |
| `SDLHasScreenKeyboardSupport()`                                               | `bool`        |
| `SDLScreenKeyboardShown(int $window)`                                         | `bool`        |
| `SDLReadKeyboardEvent(int $ptr)`                                              | `array`       |
| `SDLReadTextInputEvent(int $ptr)`                                             | `array`       |
| `SDLReadTextEditingEvent(int $ptr)`                                           | `array`       |
| `SDLReadTextEditingCandidatesEvent(int $ptr)`                                 | `array`       |
| `SDLReadKeyboardDeviceEvent(int $ptr)`                                        | `array`       |

### `Sdl3\SDL\Events\SDLMouse` — mouse devices, cursors, event arms

| Method                                                                               | Returns |
| ------------------------------------------------------------------------------------ | ------- |
| `SDLHasMouse()`                                                                      | `bool`  |
| `SDLGetMice()`                                                                       | `array` |
| `SDLGetMouseNameForID(int $instance_id)`                                             | `string`|
| `SDLGetMouseFocus()`                                                                 | `int`   |
| `SDLGetMouseState()`                                                                 | `array` |
| `SDLGetGlobalMouseState()`                                                           | `array` |
| `SDLGetRelativeMouseState()`                                                         | `array` |
| `SDLWarpMouseInWindow(int $window, float $x, float $y)`                              | `void`  |
| `SDLWarpMouseGlobal(float $x, float $y)`                                             | `bool`  |
| `SDLSetWindowRelativeMouseMode(int $window, bool $enabled)`                          | `bool`  |
| `SDLGetWindowRelativeMouseMode(int $window)`                                         | `bool`  |
| `SDLCaptureMouse(bool $enabled)`                                                     | `bool`  |
| `SDLCreateCursor(string $data, string $mask, int $w, int $h, int $hot_x, int $hot_y)`| `int`   |
| `SDLCreateColorCursor(int $surface, int $hot_x, int $hot_y)`                         | `int`   |
| `SDLCreateAnimatedCursor(array $frames, int $hot_x, int $hot_y)`                     | `int`   |
| `SDLCreateSystemCursor(int $id)`                                                     | `int`   |
| `SDLSetCursor(mixed $cursor = null)`                                                 | `bool`  |
| `SDLGetCursor()`                                                                     | `int`   |
| `SDLGetDefaultCursor()`                                                              | `int`   |
| `SDLDestroyCursor(int $cursor)`                                                      | `void`  |
| `SDLShowCursor()`                                                                    | `bool`  |
| `SDLHideCursor()`                                                                    | `bool`  |
| `SDLCursorVisible()`                                                                 | `bool`  |
| `SDLReadMouseDeviceEvent(int $ptr)`                                                  | `array` |
| `SDLReadMouseMotionEvent(int $ptr)`                                                  | `array` |
| `SDLReadMouseButtonEvent(int $ptr)`                                                  | `array` |
| `SDLReadMouseWheelEvent(int $ptr)`                                                   | `array` |

### `Sdl3\SDL\Events\SDLDisplayEvents` — displays & display modes

| Method                                                                                                           | Returns |
| ---------------------------------------------------------------------------------------------------------------- | ------- |
| `SDLReadDisplayEvent(int $ptr)`                                                                                  | `array` |
| `SDLGetDisplays()`                                                                                               | `array` |
| `SDLGetPrimaryDisplay()`                                                                                         | `int`   |
| `SDLGetDisplayName(int $display_id)`                                                                             | `string`|
| `SDLGetDisplayBounds(int $display_id)`                                                                           | `array` |
| `SDLGetDisplayForWindow(int $window)`                                                                            | `int`   |
| `SDLGetNaturalDisplayOrientation(int $display_id)`                                                               | `int`   |
| `SDLGetCurrentDisplayOrientation(int $display_id)`                                                               | `int`   |
| `SDLGetDisplayContentScale(int $display_id)`                                                                     | `float` |
| `SDLGetFullscreenDisplayModes(int $display_id)`                                                                  | `array` |
| `SDLGetDesktopDisplayMode(int $display_id)`                                                                      | `array` |
| `SDLGetCurrentDisplayMode(int $display_id)`                                                                      | `array` |
| `SDLGetClosestFullscreenDisplayMode(int $display_id, int $w, int $h, float $refresh_rate = 0.0, bool $include_high_density_modes = false)` | `array` |

### `Sdl3\SDL\Events\SDLClipboardEvents` — clipboard & primary selection

| Method                                       | Returns  |
| -------------------------------------------- | -------- |
| `SDLReadClipboardEvent(int $ptr)`            | `array`  |
| `SDLSetClipboardText(string $text)`          | `bool`   |
| `SDLGetClipboardText()`                      | `string` |
| `SDLHasClipboardText()`                      | `bool`   |
| `SDLSetPrimarySelectionText(string $text)`   | `bool`   |
| `SDLGetPrimarySelectionText()`               | `string` |
| `SDLHasPrimarySelectionText()`               | `bool`   |
| `SDLGetClipboardMimeTypes()`                 | `array`  |
| `SDLHasClipboardData(string $mime_type)`     | `bool`   |
| `SDLClearClipboardData()`                    | `void`   |

### `Sdl3\SDL\Events\SDLDropEvents` — drag-and-drop payloads

| Method                        | Returns |
| ----------------------------- | ------- |
| `SDLReadDropEvent(int $ptr)`  | `array` |

### `Sdl3\SDL\Events\SDLEventWatch` — filters & watchers

| Method                                            | Returns |
| ------------------------------------------------- | ------- |
| `SDLSetEventFilter(mixed $callback = null)`       | `void`  |
| `SDLGetEventFilter()`                             | `bool`  |
| `SDLAddEventWatch(mixed $callback)`               | `int`   |
| `SDLRemoveEventWatch(int $watch_id)`              | `bool`  |
| `SDLFilterEvents(mixed $callback)`                | `void`  |

### `Sdl3\SDL\Events\SDLQuit` — quit event payload

| Method                         | Returns |
| ------------------------------ | ------- |
| `SDLReadQuitEvent(int $ptr)`   | `array` |

### Supporting / reserved classes

These classes are part of the public surface but currently ship without
methods; they are reserved for upcoming SDL3 subsystem bindings:

- `Sdl3\SDL\SDLAssert`
- `Sdl3\SDL\SDLList`
- `Sdl3\SDL\SDLLog`
- `Sdl3\SDL\SDLProperties`
- `Sdl3\SDL\SDLUtils`
- `Sdl3\SDL\Events\SDLKeymap`
- `Sdl3\SDL\Events\SDLScancodeTables`
- `Sdl3\SDL\Events\SDLWindowEvents`

---

## License

MIT © Project Saturn Studios, LLC.
