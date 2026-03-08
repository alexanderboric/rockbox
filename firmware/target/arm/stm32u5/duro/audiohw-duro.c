#include "audiohw.h"

void audiohw_init(void)
{
}

void audiohw_postinit(void)
{
}

void audiohw_close(void)
{
}

void audio_set_output_source(int source)
{
    (void)source;
}

void audiohw_set_recvol(int left, int right, int type)
{
    (void)left;
    (void)right;
    (void)type;
}

void audiohw_set_volume(int vol_l, int vol_r)
{
    (void)vol_l;
    (void)vol_r;
}

void audio_input_mux(int source, unsigned flags)
{
    (void)source;
    (void)flags;
}

