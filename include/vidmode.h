#ifndef _ADAMANTIUM_VIDMODE_H
#define _ADAMANTIUM_VIDMODE_H

/* Just start with these for testing */
#if defined(VIDEO_MODE_1024x768)
#define VIDEO_MODE_WIDTH					1024
#define VIDEO_MODE_HEIGHT					768
#elif defined(VIDEO_MODE_1280x720)
#define VIDEO_MODE_WIDTH					1280
#define VIDEO_MODE_HEIGHT					720
#else
#define VIDEO_MODE_WIDTH					640
#define VIDEO_MODE_HEIGHT					480
#endif

#endif
