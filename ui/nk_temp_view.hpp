#pragma once
#include "../nuklear.h"

inline void nk_temp_view(struct nk_context *ctx, float temp, float min, float max)
{
    const int offset = 5;
    
    struct nk_command_buffer *canvas;
    struct nk_input *input = &ctx->input;
    canvas = nk_window_get_canvas(ctx);

    struct nk_rect space;
    struct nk_rect tempbar;
    struct nk_rect label_space;

    enum nk_widget_layout_states state;
    state = nk_widget(&space, ctx);
    if (!state) return;

    //calculate bar size
    tempbar = space;
    
    tempbar.y += offset;
    tempbar.h -= offset*2;

    tempbar.x += offset;
    tempbar.w = ((float)space.w / 100.0f) * ((temp / max) * 100.0f);
    tempbar.w -= offset*2;

    //calculate label pos
    label_space = space;
    label_space.y += space.h + offset*2;
    label_space.x += offset;

    nk_fill_rect(canvas, space, 5, nk_rgb(35,35,35));
    nk_fill_rect(canvas, tempbar, 5, nk_rgb(((255.0f/100.0f) * (temp / max) * 100.0f),128,(255 - ((255.0f/100.0f) * (temp / max) * 100.0f))));

    //if (state != NK_WIDGET_ROM)
        //update_your_widget_by_user_input(...);
        //nk_fill_rect(canvas, space, 0, nk_rgb(255,0,0));
}