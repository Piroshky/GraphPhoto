Node *show_generic_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("generic")) {
    if (ImGui::MenuItem("gegl:gegl"))
      ret = create_node__gegl_gegl();
    if (ImGui::MenuItem("gegl:convolution-matrix"))
      ret = create_node__gegl_convolution_matrix();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_layout_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("layout")) {
    if (ImGui::MenuItem("gegl:pack"))
      ret = create_node__gegl_pack();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_render_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("render")) {
    if (ImGui::MenuItem("gegl:rectangle"))
      ret = create_node__gegl_rectangle();
    if (ImGui::MenuItem("gegl:plasma"))
      ret = create_node__gegl_plasma();
    if (ImGui::MenuItem("gegl:text"))
      ret = create_node__gegl_text();
    if (ImGui::MenuItem("gegl:introspect"))
      ret = create_node__gegl_introspect();
    if (ImGui::MenuItem("gegl:spiral"))
      ret = create_node__gegl_spiral();
    if (ImGui::MenuItem("gegl:sinus"))
      ret = create_node__gegl_sinus();
    if (ImGui::MenuItem("gegl:noise-solid"))
      ret = create_node__gegl_noise_solid();
    if (ImGui::MenuItem("gegl:linear-sinusoid"))
      ret = create_node__gegl_linear_sinusoid();
    if (ImGui::MenuItem("gegl:fractal-explorer"))
      ret = create_node__gegl_fractal_explorer();
    if (ImGui::MenuItem("gegl:diffraction-patterns"))
      ret = create_node__gegl_diffraction_patterns();
    if (ImGui::MenuItem("gegl:bayer-matrix"))
      ret = create_node__gegl_bayer_matrix();
    if (ImGui::MenuItem("gegl:radial-gradient"))
      ret = create_node__gegl_radial_gradient();
    if (ImGui::MenuItem("gegl:simplex-noise"))
      ret = create_node__gegl_simplex_noise();
    if (ImGui::MenuItem("gegl:perlin-noise"))
      ret = create_node__gegl_perlin_noise();
    if (ImGui::MenuItem("gegl:cell-noise"))
      ret = create_node__gegl_cell_noise();
    if (ImGui::MenuItem("gegl:linear-gradient"))
      ret = create_node__gegl_linear_gradient();
    if (ImGui::MenuItem("gegl:grid"))
      ret = create_node__gegl_grid();
    if (ImGui::MenuItem("gegl:color"))
      ret = create_node__gegl_color();
    if (ImGui::MenuItem("gegl:checkerboard"))
      ret = create_node__gegl_checkerboard();
    if (ImGui::MenuItem("gegl:maze"))
      ret = create_node__gegl_maze();
    if (ImGui::MenuItem("gegl:path"))
      ret = create_node__gegl_path();
    if (ImGui::MenuItem("gegl:vector-stroke"))
      ret = create_node__gegl_vector_stroke();
    if (ImGui::MenuItem("gegl:fill-path"))
      ret = create_node__gegl_fill_path();
    if (ImGui::MenuItem("gegl:vignette"))
      ret = create_node__gegl_vignette();
    if (ImGui::MenuItem("gegl:newsprint"))
      ret = create_node__gegl_newsprint();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_meta_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("meta")) {
    if (ImGui::MenuItem("gegl:load"))
      ret = create_node__gegl_load();
    if (ImGui::MenuItem("gegl:json:grey2"))
      ret = create_node__gegl_json_grey2();
    if (ImGui::MenuItem("gegl:json:dropshadow2"))
      ret = create_node__gegl_json_dropshadow2();
    if (ImGui::MenuItem("gegl:layer"))
      ret = create_node__gegl_layer();
    if (ImGui::MenuItem("gegl:seamless-clone-compose"))
      ret = create_node__gegl_seamless_clone_compose();
    if (ImGui::MenuItem("gegl:save"))
      ret = create_node__gegl_save();
    if (ImGui::MenuItem("gegl:display"))
      ret = create_node__gegl_display();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_hidden_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("hidden")) {
    if (ImGui::MenuItem("gegl:shadows-highlights-correction"))
      ret = create_node__gegl_shadows_highlights_correction();
    if (ImGui::MenuItem("gegl:tiff-load"))
      ret = create_node__gegl_tiff_load();
    if (ImGui::MenuItem("gegl:exr-load"))
      ret = create_node__gegl_exr_load();
    if (ImGui::MenuItem("gegl:jp2-load"))
      ret = create_node__gegl_jp2_load();
    if (ImGui::MenuItem("gegl:gif-load"))
      ret = create_node__gegl_gif_load();
    if (ImGui::MenuItem("gegl:webp-load"))
      ret = create_node__gegl_webp_load();
    if (ImGui::MenuItem("gegl:rgbe-load"))
      ret = create_node__gegl_rgbe_load();
    if (ImGui::MenuItem("gegl:magick-load"))
      ret = create_node__gegl_magick_load();
    if (ImGui::MenuItem("gegl:icc-load"))
      ret = create_node__gegl_icc_load();
    if (ImGui::MenuItem("gegl:gegl-buffer-load"))
      ret = create_node__gegl_gegl_buffer_load();
    if (ImGui::MenuItem("gegl:jpg-load"))
      ret = create_node__gegl_jpg_load();
    if (ImGui::MenuItem("gegl:png-load"))
      ret = create_node__gegl_png_load();
    if (ImGui::MenuItem("gegl:raw-load"))
      ret = create_node__gegl_raw_load();
    if (ImGui::MenuItem("gegl:ppm-load"))
      ret = create_node__gegl_ppm_load();
    if (ImGui::MenuItem("gegl:watershed-transform"))
      ret = create_node__gegl_watershed_transform();
    if (ImGui::MenuItem("gegl:gblur-1d"))
      ret = create_node__gegl_gblur_1d();
    if (ImGui::MenuItem("gegl:wavelet-blur-1d"))
      ret = create_node__gegl_wavelet_blur_1d();
    if (ImGui::MenuItem("gegl:gegl-buffer-save"))
      ret = create_node__gegl_gegl_buffer_save();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_svgfilter_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("svgfilter")) {
    if (ImGui::MenuItem("gegl:soft-light"))
      ret = create_node__gegl_soft_light();
    if (ImGui::MenuItem("svg:screen"))
      ret = create_node__svg_screen();
    if (ImGui::MenuItem("svg:plus"))
      ret = create_node__svg_plus();
    if (ImGui::MenuItem("svg:overlay"))
      ret = create_node__svg_overlay();
    if (ImGui::MenuItem("svg:lighten"))
      ret = create_node__svg_lighten();
    if (ImGui::MenuItem("svg:hard-light"))
      ret = create_node__svg_hard_light();
    if (ImGui::MenuItem("svg:exclusion"))
      ret = create_node__svg_exclusion();
    if (ImGui::MenuItem("svg:difference"))
      ret = create_node__svg_difference();
    if (ImGui::MenuItem("svg:darken"))
      ret = create_node__svg_darken();
    if (ImGui::MenuItem("svg:color-dodge"))
      ret = create_node__svg_color_dodge();
    if (ImGui::MenuItem("svg:color-burn"))
      ret = create_node__svg_color_burn();
    if (ImGui::MenuItem("gegl:svg-saturate"))
      ret = create_node__gegl_svg_saturate();
    if (ImGui::MenuItem("gegl:svg-matrix"))
      ret = create_node__gegl_svg_matrix();
    if (ImGui::MenuItem("gegl:svg-luminancetoalpha"))
      ret = create_node__gegl_svg_luminancetoalpha();
    if (ImGui::MenuItem("gegl:svg-huerotate"))
      ret = create_node__gegl_svg_huerotate();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_light_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("light")) {
    if (ImGui::MenuItem("gegl:shadows-highlights"))
      ret = create_node__gegl_shadows_highlights();
    if (ImGui::MenuItem("gegl:dropshadow"))
      ret = create_node__gegl_dropshadow();
    if (ImGui::MenuItem("gegl:bloom"))
      ret = create_node__gegl_bloom();
    if (ImGui::MenuItem("gegl:bump-map"))
      ret = create_node__gegl_bump_map();
    if (ImGui::MenuItem("gegl:long-shadow"))
      ret = create_node__gegl_long_shadow();
    if (ImGui::MenuItem("gegl:emboss"))
      ret = create_node__gegl_emboss();
    if (ImGui::MenuItem("gegl:supernova"))
      ret = create_node__gegl_supernova();
    if (ImGui::MenuItem("gegl:lens-flare"))
      ret = create_node__gegl_lens_flare();
    if (ImGui::MenuItem("gegl:vignette"))
      ret = create_node__gegl_vignette();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_artistic_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("artistic")) {
    if (ImGui::MenuItem("gegl:oilify"))
      ret = create_node__gegl_oilify();
    if (ImGui::MenuItem("gegl:tile-paper"))
      ret = create_node__gegl_tile_paper();
    if (ImGui::MenuItem("gegl:photocopy"))
      ret = create_node__gegl_photocopy();
    if (ImGui::MenuItem("gegl:cartoon"))
      ret = create_node__gegl_cartoon();
    if (ImGui::MenuItem("gegl:tile-glass"))
      ret = create_node__gegl_tile_glass();
    if (ImGui::MenuItem("gegl:softglow"))
      ret = create_node__gegl_softglow();
    if (ImGui::MenuItem("gegl:mosaic"))
      ret = create_node__gegl_mosaic();
    if (ImGui::MenuItem("gegl:cubism"))
      ret = create_node__gegl_cubism();
    if (ImGui::MenuItem("gegl:texturize-canvas"))
      ret = create_node__gegl_texturize_canvas();
    if (ImGui::MenuItem("gegl:alien-map"))
      ret = create_node__gegl_alien_map();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_core_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("core")) {
    if (ImGui::MenuItem("gegl:crop"))
      ret = create_node__gegl_crop();
    if (ImGui::MenuItem("gegl:convert-space"))
      ret = create_node__gegl_convert_space();
    if (ImGui::MenuItem("gegl:cast-space"))
      ret = create_node__gegl_cast_space();
    if (ImGui::MenuItem("gegl:nop"))
      ret = create_node__gegl_nop();
    if (ImGui::MenuItem("gegl:convert-format"))
      ret = create_node__gegl_convert_format();
    if (ImGui::MenuItem("gegl:clone"))
      ret = create_node__gegl_clone();
    if (ImGui::MenuItem("gegl:cast-format"))
      ret = create_node__gegl_cast_format();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_programming_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("programming")) {
    if (ImGui::MenuItem("gegl:image-compare"))
      ret = create_node__gegl_image_compare();
    if (ImGui::MenuItem("gegl:pixbuf"))
      ret = create_node__gegl_pixbuf();
    if (ImGui::MenuItem("gegl:buffer-source"))
      ret = create_node__gegl_buffer_source();
    if (ImGui::MenuItem("gegl:cache"))
      ret = create_node__gegl_cache();
    if (ImGui::MenuItem("gegl:copy-buffer"))
      ret = create_node__gegl_copy_buffer();
    if (ImGui::MenuItem("gegl:write-buffer"))
      ret = create_node__gegl_write_buffer();
    if (ImGui::MenuItem("gegl:buffer-sink"))
      ret = create_node__gegl_buffer_sink();
    if (ImGui::MenuItem("gegl:save-pixbuf"))
      ret = create_node__gegl_save_pixbuf();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_dither_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("dither")) {
    if (ImGui::MenuItem("gegl:dither"))
      ret = create_node__gegl_dither();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_map_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("map")) {
    if (ImGui::MenuItem("gegl:recursive-transform"))
      ret = create_node__gegl_recursive_transform();
    if (ImGui::MenuItem("gegl:map-relative"))
      ret = create_node__gegl_map_relative();
    if (ImGui::MenuItem("gegl:map-absolute"))
      ret = create_node__gegl_map_absolute();
    if (ImGui::MenuItem("gegl:whirl-pinch"))
      ret = create_node__gegl_whirl_pinch();
    if (ImGui::MenuItem("gegl:tile-paper"))
      ret = create_node__gegl_tile_paper();
    if (ImGui::MenuItem("gegl:polar-coordinates"))
      ret = create_node__gegl_polar_coordinates();
    if (ImGui::MenuItem("gegl:illusion"))
      ret = create_node__gegl_illusion();
    if (ImGui::MenuItem("gegl:fractal-trace"))
      ret = create_node__gegl_fractal_trace();
    if (ImGui::MenuItem("gegl:displace"))
      ret = create_node__gegl_displace();
    if (ImGui::MenuItem("gegl:apply-lens"))
      ret = create_node__gegl_apply_lens();
    if (ImGui::MenuItem("gegl:distance-transform"))
      ret = create_node__gegl_distance_transform();
    if (ImGui::MenuItem("gegl:spherize"))
      ret = create_node__gegl_spherize();
    if (ImGui::MenuItem("gegl:panorama-projection"))
      ret = create_node__gegl_panorama_projection();
    if (ImGui::MenuItem("gegl:stereographic-projection"))
      ret = create_node__gegl_stereographic_projection();
    if (ImGui::MenuItem("gegl:tile-glass"))
      ret = create_node__gegl_tile_glass();
    if (ImGui::MenuItem("gegl:normal-map"))
      ret = create_node__gegl_normal_map();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_grayscale_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("grayscale")) {
    if (ImGui::MenuItem("gegl:c2g"))
      ret = create_node__gegl_c2g();
    if (ImGui::MenuItem("gegl:gray"))
      ret = create_node__gegl_gray();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_porter_duff_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("porter-duff")) {
    if (ImGui::MenuItem("svg:src-over"))
      ret = create_node__svg_src_over();
    if (ImGui::MenuItem("svg:xor"))
      ret = create_node__svg_xor();
    if (ImGui::MenuItem("svg:src"))
      ret = create_node__svg_src();
    if (ImGui::MenuItem("svg:src-out"))
      ret = create_node__svg_src_out();
    if (ImGui::MenuItem("svg:src-in"))
      ret = create_node__svg_src_in();
    if (ImGui::MenuItem("svg:src-atop"))
      ret = create_node__svg_src_atop();
    if (ImGui::MenuItem("svg:dst"))
      ret = create_node__svg_dst();
    if (ImGui::MenuItem("svg:dst-over"))
      ret = create_node__svg_dst_over();
    if (ImGui::MenuItem("svg:dst-out"))
      ret = create_node__svg_dst_out();
    if (ImGui::MenuItem("svg:dst-in"))
      ret = create_node__svg_dst_in();
    if (ImGui::MenuItem("svg:dst-atop"))
      ret = create_node__svg_dst_atop();
    if (ImGui::MenuItem("svg:clear"))
      ret = create_node__svg_clear();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_input_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("input")) {
    if (ImGui::MenuItem("gegl:load"))
      ret = create_node__gegl_load();
    if (ImGui::MenuItem("gegl:pixbuf"))
      ret = create_node__gegl_pixbuf();
    if (ImGui::MenuItem("gegl:pdf-load"))
      ret = create_node__gegl_pdf_load();
    if (ImGui::MenuItem("gegl:v4l"))
      ret = create_node__gegl_v4l();
    if (ImGui::MenuItem("gegl:ff-load"))
      ret = create_node__gegl_ff_load();
    if (ImGui::MenuItem("gegl:svg-load"))
      ret = create_node__gegl_svg_load();
    if (ImGui::MenuItem("gegl:open-buffer"))
      ret = create_node__gegl_open_buffer();
    if (ImGui::MenuItem("gegl:buffer-source"))
      ret = create_node__gegl_buffer_source();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_video_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("video")) {
    if (ImGui::MenuItem("gegl:v4l"))
      ret = create_node__gegl_v4l();
    if (ImGui::MenuItem("gegl:ff-load"))
      ret = create_node__gegl_ff_load();
    if (ImGui::MenuItem("gegl:mblur"))
      ret = create_node__gegl_mblur();
    if (ImGui::MenuItem("gegl:ff-save"))
      ret = create_node__gegl_ff_save();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_output_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("output")) {
    if (ImGui::MenuItem("gegl:rgbe-save"))
      ret = create_node__gegl_rgbe_save();
    if (ImGui::MenuItem("gegl:ppm-save"))
      ret = create_node__gegl_ppm_save();
    if (ImGui::MenuItem("gegl:npy-save"))
      ret = create_node__gegl_npy_save();
    if (ImGui::MenuItem("gegl:png-save"))
      ret = create_node__gegl_png_save();
    if (ImGui::MenuItem("gegl:ff-save"))
      ret = create_node__gegl_ff_save();
    if (ImGui::MenuItem("gegl:write-buffer"))
      ret = create_node__gegl_write_buffer();
    if (ImGui::MenuItem("gegl:save"))
      ret = create_node__gegl_save();
    if (ImGui::MenuItem("gegl:icc-save"))
      ret = create_node__gegl_icc_save();
    if (ImGui::MenuItem("gegl:buffer-sink"))
      ret = create_node__gegl_buffer_sink();
    if (ImGui::MenuItem("gegl:jpg-save"))
      ret = create_node__gegl_jpg_save();
    if (ImGui::MenuItem("gegl:tiff-save"))
      ret = create_node__gegl_tiff_save();
    if (ImGui::MenuItem("gegl:save-pixbuf"))
      ret = create_node__gegl_save_pixbuf();
    if (ImGui::MenuItem("gegl:webp-save"))
      ret = create_node__gegl_webp_save();
    if (ImGui::MenuItem("gegl:exr-save"))
      ret = create_node__gegl_exr_save();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_illusions_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("illusions")) {
    if (ImGui::MenuItem("gegl:color-assimilation-grid"))
      ret = create_node__gegl_color_assimilation_grid();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_enhance_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("enhance")) {
    if (ImGui::MenuItem("gegl:unsharp-mask"))
      ret = create_node__gegl_unsharp_mask();
    if (ImGui::MenuItem("gegl:gaussian-blur-selective"))
      ret = create_node__gegl_gaussian_blur_selective();
    if (ImGui::MenuItem("gegl:stretch-contrast"))
      ret = create_node__gegl_stretch_contrast();
    if (ImGui::MenuItem("gegl:stretch-contrast-hsv"))
      ret = create_node__gegl_stretch_contrast_hsv();
    if (ImGui::MenuItem("gegl:fattal02"))
      ret = create_node__gegl_fattal02();
    if (ImGui::MenuItem("gegl:domain-transform"))
      ret = create_node__gegl_domain_transform();
    if (ImGui::MenuItem("gegl:color-enhance"))
      ret = create_node__gegl_color_enhance();
    if (ImGui::MenuItem("gegl:deinterlace"))
      ret = create_node__gegl_deinterlace();
    if (ImGui::MenuItem("gegl:antialias"))
      ret = create_node__gegl_antialias();
    if (ImGui::MenuItem("gegl:stress"))
      ret = create_node__gegl_stress();
    if (ImGui::MenuItem("gegl:snn-mean"))
      ret = create_node__gegl_snn_mean();
    if (ImGui::MenuItem("gegl:noise-reduction"))
      ret = create_node__gegl_noise_reduction();
    if (ImGui::MenuItem("gegl:bilateral-filter"))
      ret = create_node__gegl_bilateral_filter();
    if (ImGui::MenuItem("gegl:red-eye-removal"))
      ret = create_node__gegl_red_eye_removal();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_tonemapping_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("tonemapping")) {
    if (ImGui::MenuItem("gegl:reinhard05"))
      ret = create_node__gegl_reinhard05();
    if (ImGui::MenuItem("gegl:mantiuk06"))
      ret = create_node__gegl_mantiuk06();
    if (ImGui::MenuItem("gegl:fattal02"))
      ret = create_node__gegl_fattal02();
    if (ImGui::MenuItem("gegl:stress"))
      ret = create_node__gegl_stress();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_sharpen_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("sharpen")) {
    if (ImGui::MenuItem("gegl:unsharp-mask"))
      ret = create_node__gegl_unsharp_mask();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_blend_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("blend")) {
    if (ImGui::MenuItem("gegl:piecewise-blend"))
      ret = create_node__gegl_piecewise_blend();
    if (ImGui::MenuItem("gegl:seamless-clone-compose"))
      ret = create_node__gegl_seamless_clone_compose();
    if (ImGui::MenuItem("gegl:seamless-clone"))
      ret = create_node__gegl_seamless_clone();
    if (ImGui::MenuItem("gegl:weighted-blend"))
      ret = create_node__gegl_weighted_blend();
    if (ImGui::MenuItem("gegl:mix"))
      ret = create_node__gegl_mix();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_gradient_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("gradient")) {
    if (ImGui::MenuItem("gegl:radial-gradient"))
      ret = create_node__gegl_radial_gradient();
    if (ImGui::MenuItem("gegl:linear-gradient"))
      ret = create_node__gegl_linear_gradient();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_fractal_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("fractal")) {
    if (ImGui::MenuItem("gegl:fractal-explorer"))
      ret = create_node__gegl_fractal_explorer();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_color_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("color")) {
    if (ImGui::MenuItem("gegl:convert-space"))
      ret = create_node__gegl_convert_space();
    if (ImGui::MenuItem("gegl:cast-space"))
      ret = create_node__gegl_cast_space();
    if (ImGui::MenuItem("gegl:threshold"))
      ret = create_node__gegl_threshold();
    if (ImGui::MenuItem("gegl:negative-darkroom"))
      ret = create_node__gegl_negative_darkroom();
    if (ImGui::MenuItem("gegl:convert-format"))
      ret = create_node__gegl_convert_format();
    if (ImGui::MenuItem("gegl:cast-format"))
      ret = create_node__gegl_cast_format();
    if (ImGui::MenuItem("gegl:lcms-from-profile"))
      ret = create_node__gegl_lcms_from_profile();
    if (ImGui::MenuItem("gegl:stretch-contrast"))
      ret = create_node__gegl_stretch_contrast();
    if (ImGui::MenuItem("gegl:stretch-contrast-hsv"))
      ret = create_node__gegl_stretch_contrast_hsv();
    if (ImGui::MenuItem("gegl:slic"))
      ret = create_node__gegl_slic();
    if (ImGui::MenuItem("gegl:color-enhance"))
      ret = create_node__gegl_color_enhance();
    if (ImGui::MenuItem("gegl:c2g"))
      ret = create_node__gegl_c2g();
    if (ImGui::MenuItem("gegl:color-to-alpha"))
      ret = create_node__gegl_color_to_alpha();
    if (ImGui::MenuItem("gegl:color-exchange"))
      ret = create_node__gegl_color_exchange();
    if (ImGui::MenuItem("gegl:channel-mixer"))
      ret = create_node__gegl_channel_mixer();
    if (ImGui::MenuItem("gegl:value-invert"))
      ret = create_node__gegl_value_invert();
    if (ImGui::MenuItem("gegl:unpremultiply"))
      ret = create_node__gegl_unpremultiply();
    if (ImGui::MenuItem("gegl:sepia"))
      ret = create_node__gegl_sepia();
    if (ImGui::MenuItem("gegl:saturation"))
      ret = create_node__gegl_saturation();
    if (ImGui::MenuItem("gegl:rgb-clip"))
      ret = create_node__gegl_rgb_clip();
    if (ImGui::MenuItem("gegl:posterize"))
      ret = create_node__gegl_posterize();
    if (ImGui::MenuItem("gegl:mono-mixer"))
      ret = create_node__gegl_mono_mixer();
    if (ImGui::MenuItem("gegl:levels"))
      ret = create_node__gegl_levels();
    if (ImGui::MenuItem("gegl:invert-linear"))
      ret = create_node__gegl_invert_linear();
    if (ImGui::MenuItem("gegl:invert-gamma"))
      ret = create_node__gegl_invert_gamma();
    if (ImGui::MenuItem("gegl:hue-chroma"))
      ret = create_node__gegl_hue_chroma();
    if (ImGui::MenuItem("gegl:gray"))
      ret = create_node__gegl_gray();
    if (ImGui::MenuItem("gegl:exposure"))
      ret = create_node__gegl_exposure();
    if (ImGui::MenuItem("gegl:contrast-curve"))
      ret = create_node__gegl_contrast_curve();
    if (ImGui::MenuItem("gegl:component-extract"))
      ret = create_node__gegl_component_extract();
    if (ImGui::MenuItem("gegl:color-warp"))
      ret = create_node__gegl_color_warp();
    if (ImGui::MenuItem("gegl:color-temperature"))
      ret = create_node__gegl_color_temperature();
    if (ImGui::MenuItem("gegl:color-rotate"))
      ret = create_node__gegl_color_rotate();
    if (ImGui::MenuItem("gegl:color-overlay"))
      ret = create_node__gegl_color_overlay();
    if (ImGui::MenuItem("gegl:brightness-contrast"))
      ret = create_node__gegl_brightness_contrast();
    if (ImGui::MenuItem("gegl:absolute"))
      ret = create_node__gegl_absolute();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_noise_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("noise")) {
    if (ImGui::MenuItem("gegl:noise-slur"))
      ret = create_node__gegl_noise_slur();
    if (ImGui::MenuItem("gegl:noise-spread"))
      ret = create_node__gegl_noise_spread();
    if (ImGui::MenuItem("gegl:noise-pick"))
      ret = create_node__gegl_noise_pick();
    if (ImGui::MenuItem("gegl:noise-rgb"))
      ret = create_node__gegl_noise_rgb();
    if (ImGui::MenuItem("gegl:noise-hurl"))
      ret = create_node__gegl_noise_hurl();
    if (ImGui::MenuItem("gegl:noise-hsv"))
      ret = create_node__gegl_noise_hsv();
    if (ImGui::MenuItem("gegl:noise-cie-lch"))
      ret = create_node__gegl_noise_cie_lch();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_json_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("json")) {
    if (ImGui::MenuItem("gegl:json:grey2"))
      ret = create_node__gegl_json_grey2();
    if (ImGui::MenuItem("gegl:json:dropshadow2"))
      ret = create_node__gegl_json_dropshadow2();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_segmentation_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("segmentation")) {
    if (ImGui::MenuItem("gegl:waterpixels"))
      ret = create_node__gegl_waterpixels();
    if (ImGui::MenuItem("gegl:slic"))
      ret = create_node__gegl_slic();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_edge_detect_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("edge-detect")) {
    if (ImGui::MenuItem("gegl:difference-of-gaussians"))
      ret = create_node__gegl_difference_of_gaussians();
    if (ImGui::MenuItem("gegl:edge-neon"))
      ret = create_node__gegl_edge_neon();
    if (ImGui::MenuItem("gegl:edge"))
      ret = create_node__gegl_edge();
    if (ImGui::MenuItem("gegl:edge-laplace"))
      ret = create_node__gegl_edge_laplace();
    if (ImGui::MenuItem("gegl:image-gradient"))
      ret = create_node__gegl_image_gradient();
    if (ImGui::MenuItem("gegl:edge-sobel"))
      ret = create_node__gegl_edge_sobel();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_compositors_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("compositors")) {
    if (ImGui::MenuItem("gegl:piecewise-blend"))
      ret = create_node__gegl_piecewise_blend();
    if (ImGui::MenuItem("gegl:remap"))
      ret = create_node__gegl_remap();
    if (ImGui::MenuItem("gegl:seamless-clone-compose"))
      ret = create_node__gegl_seamless_clone_compose();
    if (ImGui::MenuItem("gegl:weighted-blend"))
      ret = create_node__gegl_weighted_blend();
    if (ImGui::MenuItem("svg:src-over"))
      ret = create_node__svg_src_over();
    if (ImGui::MenuItem("gegl:mix"))
      ret = create_node__gegl_mix();
    if (ImGui::MenuItem("svg:xor"))
      ret = create_node__svg_xor();
    if (ImGui::MenuItem("gegl:subtract"))
      ret = create_node__gegl_subtract();
    if (ImGui::MenuItem("svg:src"))
      ret = create_node__svg_src();
    if (ImGui::MenuItem("svg:src-out"))
      ret = create_node__svg_src_out();
    if (ImGui::MenuItem("svg:src-in"))
      ret = create_node__svg_src_in();
    if (ImGui::MenuItem("svg:src-atop"))
      ret = create_node__svg_src_atop();
    if (ImGui::MenuItem("gegl:soft-light"))
      ret = create_node__gegl_soft_light();
    if (ImGui::MenuItem("svg:screen"))
      ret = create_node__svg_screen();
    if (ImGui::MenuItem("svg:plus"))
      ret = create_node__svg_plus();
    if (ImGui::MenuItem("svg:overlay"))
      ret = create_node__svg_overlay();
    if (ImGui::MenuItem("gegl:multiply"))
      ret = create_node__gegl_multiply();
    if (ImGui::MenuItem("svg:lighten"))
      ret = create_node__svg_lighten();
    if (ImGui::MenuItem("svg:hard-light"))
      ret = create_node__svg_hard_light();
    if (ImGui::MenuItem("gegl:gamma"))
      ret = create_node__gegl_gamma();
    if (ImGui::MenuItem("svg:exclusion"))
      ret = create_node__svg_exclusion();
    if (ImGui::MenuItem("svg:dst"))
      ret = create_node__svg_dst();
    if (ImGui::MenuItem("svg:dst-over"))
      ret = create_node__svg_dst_over();
    if (ImGui::MenuItem("svg:dst-out"))
      ret = create_node__svg_dst_out();
    if (ImGui::MenuItem("svg:dst-in"))
      ret = create_node__svg_dst_in();
    if (ImGui::MenuItem("svg:dst-atop"))
      ret = create_node__svg_dst_atop();
    if (ImGui::MenuItem("gegl:divide"))
      ret = create_node__gegl_divide();
    if (ImGui::MenuItem("svg:difference"))
      ret = create_node__svg_difference();
    if (ImGui::MenuItem("svg:darken"))
      ret = create_node__svg_darken();
    if (ImGui::MenuItem("svg:color-dodge"))
      ret = create_node__svg_color_dodge();
    if (ImGui::MenuItem("svg:color-burn"))
      ret = create_node__svg_color_burn();
    if (ImGui::MenuItem("svg:clear"))
      ret = create_node__svg_clear();
    if (ImGui::MenuItem("gegl:add"))
      ret = create_node__gegl_add();
    if (ImGui::MenuItem("gegl:exp-combine"))
      ret = create_node__gegl_exp_combine();
    if (ImGui::MenuItem("gegl:svg-saturate"))
      ret = create_node__gegl_svg_saturate();
    if (ImGui::MenuItem("gegl:svg-matrix"))
      ret = create_node__gegl_svg_matrix();
    if (ImGui::MenuItem("gegl:svg-luminancetoalpha"))
      ret = create_node__gegl_svg_luminancetoalpha();
    if (ImGui::MenuItem("gegl:svg-huerotate"))
      ret = create_node__gegl_svg_huerotate();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_frequency_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("frequency")) {
    if (ImGui::MenuItem("gegl:high-pass"))
      ret = create_node__gegl_high_pass();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_vector_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("vector")) {
    if (ImGui::MenuItem("gegl:path"))
      ret = create_node__gegl_path();
    if (ImGui::MenuItem("gegl:vector-stroke"))
      ret = create_node__gegl_vector_stroke();
    if (ImGui::MenuItem("gegl:fill-path"))
      ret = create_node__gegl_fill_path();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_tile_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("tile")) {
    if (ImGui::MenuItem("gegl:tile"))
      ret = create_node__gegl_tile();
    if (ImGui::MenuItem("gegl:tile-seamless"))
      ret = create_node__gegl_tile_seamless();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_matting_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("matting")) {
    if (ImGui::MenuItem("gegl:matting-levin"))
      ret = create_node__gegl_matting_levin();
    if (ImGui::MenuItem("gegl:matting-global"))
      ret = create_node__gegl_matting_global();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_transparency_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("transparency")) {
    if (ImGui::MenuItem("gegl:opacity"))
      ret = create_node__gegl_opacity();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_noise_reduction_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("noise-reduction")) {
    if (ImGui::MenuItem("gegl:gaussian-blur-selective"))
      ret = create_node__gegl_gaussian_blur_selective();
    if (ImGui::MenuItem("gegl:domain-transform"))
      ret = create_node__gegl_domain_transform();
    if (ImGui::MenuItem("gegl:snn-mean"))
      ret = create_node__gegl_snn_mean();
    if (ImGui::MenuItem("gegl:noise-reduction"))
      ret = create_node__gegl_noise_reduction();
    if (ImGui::MenuItem("gegl:bilateral-filter"))
      ret = create_node__gegl_bilateral_filter();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_blur_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("blur")) {
    if (ImGui::MenuItem("gegl:variable-blur"))
      ret = create_node__gegl_variable_blur();
    if (ImGui::MenuItem("gegl:focus-blur"))
      ret = create_node__gegl_focus_blur();
    if (ImGui::MenuItem("gegl:wavelet-blur"))
      ret = create_node__gegl_wavelet_blur();
    if (ImGui::MenuItem("gegl:gaussian-blur"))
      ret = create_node__gegl_gaussian_blur();
    if (ImGui::MenuItem("gegl:lens-blur"))
      ret = create_node__gegl_lens_blur();
    if (ImGui::MenuItem("gegl:mirrors"))
      ret = create_node__gegl_mirrors();
    if (ImGui::MenuItem("gegl:mblur"))
      ret = create_node__gegl_mblur();
    if (ImGui::MenuItem("gegl:gblur-1d"))
      ret = create_node__gegl_gblur_1d();
    if (ImGui::MenuItem("gegl:motion-blur-zoom"))
      ret = create_node__gegl_motion_blur_zoom();
    if (ImGui::MenuItem("gegl:motion-blur-circular"))
      ret = create_node__gegl_motion_blur_circular();
    if (ImGui::MenuItem("gegl:wavelet-blur-1d"))
      ret = create_node__gegl_wavelet_blur_1d();
    if (ImGui::MenuItem("gegl:pixelize"))
      ret = create_node__gegl_pixelize();
    if (ImGui::MenuItem("gegl:motion-blur-linear"))
      ret = create_node__gegl_motion_blur_linear();
    if (ImGui::MenuItem("gegl:median-blur"))
      ret = create_node__gegl_median_blur();
    if (ImGui::MenuItem("gegl:mean-curvature-blur"))
      ret = create_node__gegl_mean_curvature_blur();
    if (ImGui::MenuItem("gegl:box-blur"))
      ret = create_node__gegl_box_blur();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_math_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("math")) {
    if (ImGui::MenuItem("gegl:subtract"))
      ret = create_node__gegl_subtract();
    if (ImGui::MenuItem("gegl:multiply"))
      ret = create_node__gegl_multiply();
    if (ImGui::MenuItem("gegl:gamma"))
      ret = create_node__gegl_gamma();
    if (ImGui::MenuItem("gegl:divide"))
      ret = create_node__gegl_divide();
    if (ImGui::MenuItem("gegl:add"))
      ret = create_node__gegl_add();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_display_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("display")) {
    if (ImGui::MenuItem("gegl:display"))
      ret = create_node__gegl_display();
    if (ImGui::MenuItem("gegl:sdl2-display"))
      ret = create_node__gegl_sdl2_display();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_scramble_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("scramble")) {
    if (ImGui::MenuItem("gegl:mosaic"))
      ret = create_node__gegl_mosaic();
    if (ImGui::MenuItem("gegl:cubism"))
      ret = create_node__gegl_cubism();
    if (ImGui::MenuItem("gegl:pixelize"))
      ret = create_node__gegl_pixelize();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_distort_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("distort")) {
    if (ImGui::MenuItem("gegl:wind"))
      ret = create_node__gegl_wind();
    if (ImGui::MenuItem("gegl:whirl-pinch"))
      ret = create_node__gegl_whirl_pinch();
    if (ImGui::MenuItem("gegl:lens-distortion"))
      ret = create_node__gegl_lens_distortion();
    if (ImGui::MenuItem("gegl:spherize"))
      ret = create_node__gegl_spherize();
    if (ImGui::MenuItem("gegl:waves"))
      ret = create_node__gegl_waves();
    if (ImGui::MenuItem("gegl:value-propagate"))
      ret = create_node__gegl_value_propagate();
    if (ImGui::MenuItem("gegl:shift"))
      ret = create_node__gegl_shift();
    if (ImGui::MenuItem("gegl:ripple"))
      ret = create_node__gegl_ripple();
    if (ImGui::MenuItem("gegl:engrave"))
      ret = create_node__gegl_engrave();
    if (ImGui::MenuItem("gegl:video-degradation"))
      ret = create_node__gegl_video_degradation();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_transform_menu() {
  Node *ret = nullptr;
  if (ImGui::BeginMenu("transform")) {
    if (ImGui::MenuItem("gegl:polar-coordinates"))
      ret = create_node__gegl_polar_coordinates();
    if (ImGui::MenuItem("gegl:warp"))
      ret = create_node__gegl_warp();
    if (ImGui::MenuItem("gegl:npd"))
      ret = create_node__gegl_npd();
    if (ImGui::MenuItem("gegl:rotate-on-center"))
      ret = create_node__gegl_rotate_on_center();
    if (ImGui::MenuItem("gegl:reset-origin"))
      ret = create_node__gegl_reset_origin();
    if (ImGui::MenuItem("gegl:transform"))
      ret = create_node__gegl_transform();
    if (ImGui::MenuItem("gegl:translate"))
      ret = create_node__gegl_translate();
    if (ImGui::MenuItem("gegl:shear"))
      ret = create_node__gegl_shear();
    if (ImGui::MenuItem("gegl:reflect"))
      ret = create_node__gegl_reflect();
    if (ImGui::MenuItem("gegl:rotate"))
      ret = create_node__gegl_rotate();
    if (ImGui::MenuItem("gegl:scale-size-keepaspect"))
      ret = create_node__gegl_scale_size_keepaspect();
    if (ImGui::MenuItem("gegl:scale-size"))
      ret = create_node__gegl_scale_size();
    if (ImGui::MenuItem("gegl:scale-ratio"))
      ret = create_node__gegl_scale_ratio();
    if (ImGui::MenuItem("gegl:border-align"))
      ret = create_node__gegl_border_align();
    ImGui::EndMenu();
  }
  return ret;
}
Node *show_all_category_menus() {
  Node *ret  = nullptr;
  Node *temp = nullptr;
  temp = show_generic_menu();
  if (temp) { ret = temp; }
  temp = show_layout_menu();
  if (temp) { ret = temp; }
  temp = show_render_menu();
  if (temp) { ret = temp; }
  temp = show_meta_menu();
  if (temp) { ret = temp; }
  temp = show_hidden_menu();
  if (temp) { ret = temp; }
  temp = show_svgfilter_menu();
  if (temp) { ret = temp; }
  temp = show_light_menu();
  if (temp) { ret = temp; }
  temp = show_artistic_menu();
  if (temp) { ret = temp; }
  temp = show_core_menu();
  if (temp) { ret = temp; }
  temp = show_programming_menu();
  if (temp) { ret = temp; }
  temp = show_dither_menu();
  if (temp) { ret = temp; }
  temp = show_map_menu();
  if (temp) { ret = temp; }
  temp = show_grayscale_menu();
  if (temp) { ret = temp; }
  temp = show_porter_duff_menu();
  if (temp) { ret = temp; }
  temp = show_input_menu();
  if (temp) { ret = temp; }
  temp = show_video_menu();
  if (temp) { ret = temp; }
  temp = show_output_menu();
  if (temp) { ret = temp; }
  temp = show_illusions_menu();
  if (temp) { ret = temp; }
  temp = show_enhance_menu();
  if (temp) { ret = temp; }
  temp = show_tonemapping_menu();
  if (temp) { ret = temp; }
  temp = show_sharpen_menu();
  if (temp) { ret = temp; }
  temp = show_blend_menu();
  if (temp) { ret = temp; }
  temp = show_gradient_menu();
  if (temp) { ret = temp; }
  temp = show_fractal_menu();
  if (temp) { ret = temp; }
  temp = show_color_menu();
  if (temp) { ret = temp; }
  temp = show_noise_menu();
  if (temp) { ret = temp; }
  temp = show_json_menu();
  if (temp) { ret = temp; }
  temp = show_segmentation_menu();
  if (temp) { ret = temp; }
  temp = show_edge_detect_menu();
  if (temp) { ret = temp; }
  temp = show_compositors_menu();
  if (temp) { ret = temp; }
  temp = show_frequency_menu();
  if (temp) { ret = temp; }
  temp = show_vector_menu();
  if (temp) { ret = temp; }
  temp = show_tile_menu();
  if (temp) { ret = temp; }
  temp = show_matting_menu();
  if (temp) { ret = temp; }
  temp = show_transparency_menu();
  if (temp) { ret = temp; }
  temp = show_noise_reduction_menu();
  if (temp) { ret = temp; }
  temp = show_blur_menu();
  if (temp) { ret = temp; }
  temp = show_math_menu();
  if (temp) { ret = temp; }
  temp = show_display_menu();
  if (temp) { ret = temp; }
  temp = show_scramble_menu();
  if (temp) { ret = temp; }
  temp = show_distort_menu();
  if (temp) { ret = temp; }
  temp = show_transform_menu();
  if (temp) { ret = temp; }
  return ret;
}
