#include "gui.hh"
#include <string>

void draw_window(nk_context *ctx){
    if (nk_begin(ctx, "TempView", nk_rect(50, 50, 200, 200),
            NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
            NK_WINDOW_CLOSABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        nk_layout_row_dynamic(ctx, 20, 1);
        
        static int target_temp = temp_sensor::target_temp; // make it persistent across frames.
        if (nk_slider_int(ctx, 0, &target_temp, 60, 1)) {
            temp_sensor::target_temp = target_temp;    // Update the static variable in the class.
        }
        
        std::string cur_temp = std::to_string(temp_sensor::get_temp());
        nk_label(ctx, ("Target temp: " + std::to_string(target_temp)).c_str(), NK_TEXT_LEFT);
        nk_temp_view(ctx, target_temp, 0, 60);
}
    nk_end(ctx);
}