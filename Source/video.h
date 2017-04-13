/* Software's video settings */

#define MaxWres 1920 /* Maximum width resolution. */
#define MaxHres 1080 /* Maximum height resolution. */
#define MinWres 640 /* Minimum width resolution. */
#define MinHres 480 /* Minimum height resolution. */
#define DFullScreen false /* Will the software's device run in fullscreen? */
#define DResizable true
#define CustomRes /* Custom screen resolution. */
#ifdef CustomRes
#define Wres 1024 /* Custom width resolution. */
#define Hres 768 /* Custom Height resolution. */
#endif