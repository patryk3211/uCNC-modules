// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: uCNC-GFX

#include "ui.h"


// COMPONENT AxisInfo

lv_obj_t * ui_container_axisinfo_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_container_axisinfo;
    cui_container_axisinfo = lv_obj_create(comp_parent);
    lv_obj_remove_style_all(cui_container_axisinfo);
    lv_obj_set_width(cui_container_axisinfo, lv_pct(32));
    lv_obj_set_height(cui_container_axisinfo, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(cui_container_axisinfo, LV_ALIGN_LEFT_MID);
    lv_obj_set_flex_flow(cui_container_axisinfo, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_container_axisinfo, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_remove_flag(cui_container_axisinfo, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(cui_container_axisinfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cui_container_axisinfo, lv_color_hex(0x303030), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_container_axisinfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(cui_container_axisinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_container_axisinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_container_axisinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_container_axisinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(cui_container_axisinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(cui_container_axisinfo, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_label_axislabel;
    cui_label_axislabel = lv_label_create(cui_container_axisinfo);
    lv_obj_set_width(cui_label_axislabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_label_axislabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_label_axislabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(cui_label_axislabel, "X:");

    lv_obj_t * cui_label_axisvalue;
    cui_label_axisvalue = lv_label_create(cui_container_axisinfo);
    lv_obj_set_width(cui_label_axisvalue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_label_axisvalue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_label_axisvalue, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(cui_label_axisvalue, "9999.999");

    lv_obj_t ** children = lv_malloc(sizeof(lv_obj_t *) * _UI_COMP_CONTAINER_AXISINFO_NUM);
    children[UI_COMP_CONTAINER_AXISINFO_CONTAINER_AXISINFO] = cui_container_axisinfo;
    children[UI_COMP_CONTAINER_AXISINFO_LABEL_AXISLABEL] = cui_label_axislabel;
    children[UI_COMP_CONTAINER_AXISINFO_LABEL_AXISVALUE] = cui_label_axisvalue;
    lv_obj_add_event_cb(cui_container_axisinfo, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_container_axisinfo, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_container_axisinfo_create_hook(cui_container_axisinfo);
    return cui_container_axisinfo;
}

