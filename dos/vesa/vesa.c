#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vesa.h"

void ShowVesaModes(void)
{
    char sbuf[80];
    char nbuf[20];
    struct VbeInfo vbe_info;

    printf("Querying VESA Video modes INT 0x10, AX=0x4f00\n");
    int gi_status = VBE_GetInfo(&vbe_info);

    if (gi_status == 0x004f) { // data in vbe_info is valid
        int total_memory = vbe_info.TotalMemory << 16;
        uint16_t *modes = (uint16_t *)(vbe_info.VideoModePtr[1] << 16 | vbe_info.VideoModePtr[0]);

        strncpy(sbuf, vbe_info.VbeSignature, 4);
        sbuf[4] = 0;
        printf("Signature: ");
        puts(sbuf);
        printf("Vbe Version: 0x%04x\n", vbe_info.VbeVersion);
        printf("Total Memory: %8d", total_memory);
        printf("Video Mode Pointer: 0x%p", modes);

        printf("Modes:\n");
        for (int i = 0; modes[i] != 0xffff; i++) {
            struct VbeModeInfo inf;
            int gmi_status = VBE_GetModeInfo(&inf, modes[i]);
            if (gmi_status != 0x004f)
                continue;

            // Check if this is a graphics mode with linear frame buffer support
            if ((inf.attributes & 0x90) != 0x90)
                continue;

            // Check if this is a packed pixel or direct color mode
            if ( inf.memory_model != 4 && inf.memory_model != 6 )
                continue;

            printf("mode: 0x%3x");
            printf("  res: %4d x %4d x %2d", inf.Xres, inf.Yres, inf.bpp);
            printf("  fbuf: 0x%p", inf.physbase);
            if (inf.memory_model == 4) {
                printf("  packed-pixel");
            } else {
                printf("  direct-color");
            }
            printf("\n");

            if (i % 16 == 4) {
                getchar();
            }
        }
    } else {
        printf("VBE GetInfo failed, returned 0x%04x\n", gi_status);
    }
}

void main()
{
    ShowVesaModes();
}
