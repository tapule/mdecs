/* SPDX-License-Identifier: MIT */
/**
 * ECS MegaDrive
 * Coded by: Juan Ángel Moreno Fernández (@_tapule) 2022
 * Github: https://github.com/tapule
 *
 * File: game.c
 * Main game object
 */

#include <mddev.h>
#include "game.h"
#include "vram.h"
#include "../res/res.h"


void game_load_resources(void)
{
    /* CHECKME: Resource loading must be here?
    kdebug_alert("Loading resources...");

    /* Palettes */
    pal_primary_set(PAL_0_INDEX, RES_PAL_PLAYER_SIZE, res_pal_player);
    pal_primary_set(PAL_1_INDEX, RES_PAL_COLLECTIBLES_SIZE, res_pal_collectibles);

    /* System font*/
    tiles_load_fast(res_font_sys, VRAM_INDEX_FONT, RES_FONT_SYS_SIZE);
    text_font_set(VRAM_INDEX_FONT);
    text_pal_set(PAL_0);

    /* Other resource load examples
    z80_bus_request();
        sound_sfx_set(64, res_sfx_door, RES_SFX_DOOR_SIZE);
        sound_sfx_set(65, res_sfx_spit, RES_SFX_SPIT_SIZE);
        sound_sfx_set(66, sfx_snd_death14, SFX_SND_DEATH14_SIZE);
    z80_bus_release();
    sound_music_play(mus_credits);
    */
}

void game_init(void)
{
    smd_ints_disable();
    game_load_resources();
    vid_display_enable();
    smd_ints_enable();
}

void game_run(void)
{
    while (1)
    {
        /* Game body background color */
        vid_background_color_set(5);
        //pad_update();

        /* Main game body goes here */
        //dma_queue_vram_transfer(font00_tiles, 100 * 16, 96 * 8 * 2, 2);
        //dma_queue_cram_transfer(font00_pal, 16, 16, 2);
        //dma_queue_vsram_transfer(data, 0, 2, 2);

        /* Wait vsync background color */
        vid_background_color_set(6);
        //wait(10);
        vid_vsync_wait();

        /* Vertical blank background color */
        vid_background_color_set(2);

        //sound_update();
        pal_update();
        spr_update();
        dma_queue_flush();
    }
}