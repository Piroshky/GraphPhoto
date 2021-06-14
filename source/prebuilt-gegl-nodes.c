static Node* create_node__gegl_absolute() {
  s_Nodes.emplace_back(GetNextId(), "gegl:absolute", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_add() {
  s_Nodes.emplace_back(GetNextId(), "gegl:add", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_alien_map() {
  s_Nodes.emplace_back(GetNextId(), "gegl:alien-map", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-1-frequency", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-2-frequency", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-3-frequency", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-1-phaseshift", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-2-phaseshift", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-3-phaseshift", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-1-keep", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-2-keep", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cpn-3-keep", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_antialias() {
  s_Nodes.emplace_back(GetNextId(), "gegl:antialias", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_apply_lens() {
  s_Nodes.emplace_back(GetNextId(), "gegl:apply-lens", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "refraction-index", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "keep-surroundings", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_bayer_matrix() {
  s_Nodes.emplace_back(GetNextId(), "gegl:bayer-matrix", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "subdivisions", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-scale", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-scale", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "reflect", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amplitude", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exponent", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-offset", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-offset", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_bilateral_filter() {
  s_Nodes.emplace_back(GetNextId(), "gegl:bilateral-filter", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blur-radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "edge-preservation", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_bloom() {
  s_Nodes.emplace_back(GetNextId(), "gegl:bloom", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "softness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "strength", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "limit-exposure", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_border_align() {
  s_Nodes.emplace_back(GetNextId(), "gegl:border-align", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "horizontal-margin", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "vertical-margin", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "snap-integer", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_box_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:box-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_brightness_contrast() {
  s_Nodes.emplace_back(GetNextId(), "gegl:brightness-contrast", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "contrast", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "brightness", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_buffer_sink() {
  s_Nodes.emplace_back(GetNextId(), "gegl:buffer-sink", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_buffer_source() {
  s_Nodes.emplace_back(GetNextId(), "gegl:buffer-source", ImColor(255, 128, 128));
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_bump_map() {
  s_Nodes.emplace_back(GetNextId(), "gegl:bump-map", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "compensate", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "invert", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tiled", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "azimuth", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "elevation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "depth", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset-x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset-y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "waterlevel", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "ambient", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_c2g() {
  s_Nodes.emplace_back(GetNextId(), "gegl:c2g", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "samples", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "enhance-shadows", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_cache() {
  s_Nodes.emplace_back(GetNextId(), "gegl:cache", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_cartoon() {
  s_Nodes.emplace_back(GetNextId(), "gegl:cartoon", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "mask-radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pct-black", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_cast_format() {
  s_Nodes.emplace_back(GetNextId(), "gegl:cast-format", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_cast_space() {
  s_Nodes.emplace_back(GetNextId(), "gegl:cast-space", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "space-name", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_cell_noise() {
  s_Nodes.emplace_back(GetNextId(), "gegl:cell-noise", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shape", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rank", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "palettize", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_channel_mixer() {
  s_Nodes.emplace_back(GetNextId(), "gegl:channel-mixer", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "preserve-luminosity", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rr-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rg-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rb-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "gr-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "gg-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "gb-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "br-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bg-gain", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bb-gain", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_checkerboard() {
  s_Nodes.emplace_back(GetNextId(), "gegl:checkerboard", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-offset", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-offset", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_clone() {
  s_Nodes.emplace_back(GetNextId(), "gegl:clone", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "ref", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color", ImColor(255, 128, 128));
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_assimilation_grid() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-assimilation-grid", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "grid-size", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "saturation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "line-thickness", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_enhance() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-enhance", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_exchange() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-exchange", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red-threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green-threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue-threshold", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_overlay() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-overlay", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_rotate() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-rotate", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "src-clockwise", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "src-from", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "src-to", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "dest-clockwise", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "dest-from", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "dest-to", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "hue", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "saturation", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_temperature() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-temperature", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "original-temperature", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "intended-temperature", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_to_alpha() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-to-alpha", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "transparency-threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "opacity-threshold", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_color_warp() {
  s_Nodes.emplace_back(GetNextId(), "gegl:color-warp", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-0", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-5", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-6", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight-7", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "weight", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_component_extract() {
  s_Nodes.emplace_back(GetNextId(), "gegl:component-extract", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "invert", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "linear", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_contrast_curve() {
  s_Nodes.emplace_back(GetNextId(), "gegl:contrast-curve", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "sampling-points", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_convert_format() {
  s_Nodes.emplace_back(GetNextId(), "gegl:convert-format", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_convert_space() {
  s_Nodes.emplace_back(GetNextId(), "gegl:convert-space", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "space-name", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_convolution_matrix() {
  s_Nodes.emplace_back(GetNextId(), "gegl:convolution-matrix", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "a1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "a2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "a3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "a4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "a5", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "b1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "b2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "b3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "b4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "b5", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "c1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "c2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "c3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "c4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "c5", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "d1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "d2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "d3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "d4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "d5", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "e1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "e2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "e3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "e4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "e5", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "divisor", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "normalize", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha-weight", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_copy_buffer() {
  s_Nodes.emplace_back(GetNextId(), "gegl:copy-buffer", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_crop() {
  s_Nodes.emplace_back(GetNextId(), "gegl:crop", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "reset-origin", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_cubism() {
  s_Nodes.emplace_back(GetNextId(), "gegl:cubism", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-size", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-saturation", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_deinterlace() {
  s_Nodes.emplace_back(GetNextId(), "gegl:deinterlace", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "size", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_difference_of_gaussians() {
  s_Nodes.emplace_back(GetNextId(), "gegl:difference-of-gaussians", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius2", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_diffraction_patterns() {
  s_Nodes.emplace_back(GetNextId(), "gegl:diffraction-patterns", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red-frequency", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green-frequency", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue-frequency", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red-contours", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green-contours", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue-contours", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red-sedges", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green-sedges", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue-sedges", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "brightness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scattering", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "polarization", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_displace() {
  s_Nodes.emplace_back(GetNextId(), "gegl:displace", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux2", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_display() {
  s_Nodes.emplace_back(GetNextId(), "gegl:display", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "window-title", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_distance_transform() {
  s_Nodes.emplace_back(GetNextId(), "gegl:distance-transform", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold-lo", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold-hi", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "averaging", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "normalize", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_dither() {
  s_Nodes.emplace_back(GetNextId(), "gegl:dither", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red-levels", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green-levels", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue-levels", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha-levels", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_divide() {
  s_Nodes.emplace_back(GetNextId(), "gegl:divide", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_domain_transform() {
  s_Nodes.emplace_back(GetNextId(), "gegl:domain-transform", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "n-iterations", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "spatial-factor", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "edge-preservation", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_dropshadow() {
  s_Nodes.emplace_back(GetNextId(), "gegl:dropshadow", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "grow-radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "opacity", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_edge() {
  s_Nodes.emplace_back(GetNextId(), "gegl:edge", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_edge_laplace() {
  s_Nodes.emplace_back(GetNextId(), "gegl:edge-laplace", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_edge_neon() {
  s_Nodes.emplace_back(GetNextId(), "gegl:edge-neon", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_edge_sobel() {
  s_Nodes.emplace_back(GetNextId(), "gegl:edge-sobel", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "horizontal", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "vertical", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "keep-sign", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_emboss() {
  s_Nodes.emplace_back(GetNextId(), "gegl:emboss", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "azimuth", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "elevation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "depth", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_engrave() {
  s_Nodes.emplace_back(GetNextId(), "gegl:engrave", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "row-height", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "limit", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_exp_combine() {
  s_Nodes.emplace_back(GetNextId(), "gegl:exp-combine", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-99", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-98", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-97", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-96", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-95", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-94", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-93", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-92", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-91", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-90", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-89", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-88", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-87", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-86", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-85", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-84", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-83", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-82", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-81", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-80", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-79", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-78", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-77", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-76", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-75", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-74", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-73", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-72", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-71", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-70", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-69", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-68", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-67", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-66", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-65", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-64", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-63", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-62", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-61", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-60", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-59", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-58", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-57", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-56", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-55", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-54", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-53", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-52", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-51", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-50", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-49", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-48", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-47", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-46", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-45", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-44", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-43", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-42", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-41", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-40", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-39", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-38", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-37", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-36", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-35", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-34", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-33", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-32", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-31", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-30", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-29", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-28", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-27", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-26", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-25", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-24", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-23", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-22", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-21", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-20", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-19", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-18", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-17", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-16", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-15", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-14", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-13", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-12", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-11", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-10", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-9", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-8", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-7", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-6", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-5", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-4", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-3", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-2", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-1", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure-0", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposures", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "steps", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "sigma", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_exposure() {
  s_Nodes.emplace_back(GetNextId(), "gegl:exposure", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "black-level", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_exr_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:exr-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_exr_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:exr-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile", PinType::INT);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_fattal02() {
  s_Nodes.emplace_back(GetNextId(), "gegl:fattal02", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "beta", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "saturation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "noise", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_ff_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:ff-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frame", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frames", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "audio-sample-rate", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "audio-channels", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frame-rate", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "video-codec", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "audio-codec", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_ff_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:ff-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "audio-codec", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "audio-sample-rate", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "audio-bit-rate", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frame-rate", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "video-codec", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "video-bit-rate", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "video-bufsize", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "container-format", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_fill_path() {
  s_Nodes.emplace_back(GetNextId(), "gegl:fill-path", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "opacity", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "fill-rule", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "transform", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_focus_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:focus-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blur-radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlight-factor", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlight-threshold-low", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlight-threshold-high", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "focus", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "midpoint", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aspect-ratio", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rotation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "high-quality", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_fractal_explorer() {
  s_Nodes.emplace_back(GetNextId(), "gegl:fractal-explorer", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iter", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "zoom", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shiftx", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shifty", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cx", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cy", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "redstretch", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "greenstretch", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bluestretch", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "redinvert", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "greeninvert", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blueinvert", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "ncolors", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "useloglog", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_fractal_trace() {
  s_Nodes.emplace_back(GetNextId(), "gegl:fractal-trace", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "X1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "X2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "Y1", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "Y2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "JX", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "JY", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "depth", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bailout", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gamma() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gamma", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gaussian_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gaussian-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "std-dev-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "std-dev-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clip-extent", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gaussian_blur_selective() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gaussian-blur-selective", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blur-radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "max-delta", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gblur_1d() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gblur-1d", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "std-dev", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clip-extent", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gegl() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gegl", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "string", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "error", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gegl_buffer_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gegl-buffer-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gegl_buffer_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gegl-buffer-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gif_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gif-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frame", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frames", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frame-delay", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_gray() {
  s_Nodes.emplace_back(GetNextId(), "gegl:gray", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_grid() {
  s_Nodes.emplace_back(GetNextId(), "gegl:grid", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-offset", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-offset", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "line-width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "line-height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_high_pass() {
  s_Nodes.emplace_back(GetNextId(), "gegl:high-pass", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "std-dev", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "contrast", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_hue_chroma() {
  s_Nodes.emplace_back(GetNextId(), "gegl:hue-chroma", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "hue", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "chroma", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "lightness", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_icc_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:icc-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_icc_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:icc-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_illusion() {
  s_Nodes.emplace_back(GetNextId(), "gegl:illusion", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "division", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_image_compare() {
  s_Nodes.emplace_back(GetNextId(), "gegl:image-compare", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "wrong-pixels", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "max-diff", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "avg-diff-wrong", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "avg-diff-total", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_image_gradient() {
  s_Nodes.emplace_back(GetNextId(), "gegl:image-gradient", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_introspect() {
  s_Nodes.emplace_back(GetNextId(), "gegl:introspect", ImColor(255, 128, 128));
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_invert_gamma() {
  s_Nodes.emplace_back(GetNextId(), "gegl:invert-gamma", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_invert_linear() {
  s_Nodes.emplace_back(GetNextId(), "gegl:invert-linear", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_jp2_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:jp2-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_jpg_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:jpg-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_jpg_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:jpg-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "quality", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "smoothing", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "optimize", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "progressive", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "grayscale", PinType::BOOLEAN);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_json_dropshadow2() {
  s_Nodes.emplace_back(GetNextId(), "gegl:json:dropshadow2", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "opacity", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_json_grey2() {
  s_Nodes.emplace_back(GetNextId(), "gegl:json:grey2", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_layer() {
  s_Nodes.emplace_back(GetNextId(), "gegl:layer", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "composite-op", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "opacity", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "src", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_lcms_from_profile() {
  s_Nodes.emplace_back(GetNextId(), "gegl:lcms-from-profile", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "black-point-compensation", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_lens_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:lens-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlight-factor", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlight-threshold-low", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlight-threshold-high", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clip", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "linear-mask", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_lens_distortion() {
  s_Nodes.emplace_back(GetNextId(), "gegl:lens-distortion", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "main", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "edge", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "zoom", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-shift", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-shift", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "brighten", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_lens_flare() {
  s_Nodes.emplace_back(GetNextId(), "gegl:lens-flare", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pos-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pos-y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_levels() {
  s_Nodes.emplace_back(GetNextId(), "gegl:levels", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "in-low", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "in-high", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "out-low", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "out-high", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_linear_gradient() {
  s_Nodes.emplace_back(GetNextId(), "gegl:linear-gradient", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "start-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "start-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "end-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "end-y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_linear_sinusoid() {
  s_Nodes.emplace_back(GetNextId(), "gegl:linear-sinusoid", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-period", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-period", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-amplitude", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-amplitude", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-phase", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-phase", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exponent", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-offset", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-offset", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rotation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "supersampling", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_long_shadow() {
  s_Nodes.emplace_back(GetNextId(), "gegl:long-shadow", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "length", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "midpoint", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "midpoint-rel", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_magick_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:magick-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_mantiuk06() {
  s_Nodes.emplace_back(GetNextId(), "gegl:mantiuk06", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "contrast", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "saturation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "detail", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_map_absolute() {
  s_Nodes.emplace_back(GetNextId(), "gegl:map-absolute", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_map_relative() {
  s_Nodes.emplace_back(GetNextId(), "gegl:map-relative", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scaling", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_matting_global() {
  s_Nodes.emplace_back(GetNextId(), "gegl:matting-global", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_matting_levin() {
  s_Nodes.emplace_back(GetNextId(), "gegl:matting-levin", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "epsilon", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "lambda", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "levels", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "active-levels", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_maze() {
  s_Nodes.emplace_back(GetNextId(), "gegl:maze", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tileable", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_mblur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:mblur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "dampness", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_mean_curvature_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:mean-curvature-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_median_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:median-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "percentile", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha-percentile", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "high-precision", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_mirrors() {
  s_Nodes.emplace_back(GetNextId(), "gegl:mirrors", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "m-angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "r-angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "n-segs", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "c-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "c-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "o-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "o-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "trim-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "trim-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input-scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "output-scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clip", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "warp", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_mix() {
  s_Nodes.emplace_back(GetNextId(), "gegl:mix", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "ratio", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_mono_mixer() {
  s_Nodes.emplace_back(GetNextId(), "gegl:mono-mixer", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "preserve-luminosity", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_mosaic() {
  s_Nodes.emplace_back(GetNextId(), "gegl:mosaic", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-size", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-height", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-neatness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "color-variation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "color-averaging", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-surface", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-allow-split", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-spacing", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "light-dir", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "antialiasing", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_motion_blur_circular() {
  s_Nodes.emplace_back(GetNextId(), "gegl:motion-blur-circular", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_motion_blur_linear() {
  s_Nodes.emplace_back(GetNextId(), "gegl:motion-blur-linear", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "length", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_motion_blur_zoom() {
  s_Nodes.emplace_back(GetNextId(), "gegl:motion-blur-zoom", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "factor", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_multiply() {
  s_Nodes.emplace_back(GetNextId(), "gegl:multiply", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_negative_darkroom() {
  s_Nodes.emplace_back(GetNextId(), "gegl:negative-darkroom", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exposure", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "expC", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "expM", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "expY", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clip", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "boost", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "dodge", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "preflash", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "flashC", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "flashM", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "flashY", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_newsprint() {
  s_Nodes.emplace_back(GetNextId(), "gegl:newsprint", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "period2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle2", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "period3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle3", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "period4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle4", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "period", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "black-pullout", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aa-samples", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "turbulence", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blocksize", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angleboost", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_cie_lch() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-cie-lch", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "holdness", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "lightness-distance", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "chroma-distance", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "hue-distance", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_hsv() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-hsv", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "holdness", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "hue-distance", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "saturation-distance", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value-distance", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_hurl() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-hurl", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pct-random", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "repeat", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_pick() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-pick", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pct-random", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "repeat", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_reduction() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-reduction", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_rgb() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-rgb", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "correlated", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "independent", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "linear", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "gaussian", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "red", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "green", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blue", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_slur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-slur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pct-random", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "repeat", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_solid() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-solid", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-size", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-size", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "detail", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tileable", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "turbulent", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_noise_spread() {
  s_Nodes.emplace_back(GetNextId(), "gegl:noise-spread", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount-x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount-y", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_nop() {
  s_Nodes.emplace_back(GetNextId(), "gegl:nop", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_normal_map() {
  s_Nodes.emplace_back(GetNextId(), "gegl:normal-map", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "flip-x", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "flip-y", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "full-z", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tileable", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_npd() {
  s_Nodes.emplace_back(GetNextId(), "gegl:npd", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "square-size", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rigidity", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "asap-deformation", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "mls-weights", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "mls-weights-alpha", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "preserve-model", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_npy_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:npy-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_oilify() {
  s_Nodes.emplace_back(GetNextId(), "gegl:oilify", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux2", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "mask-radius", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "exponent", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "intensities", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "use-inten", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_opacity() {
  s_Nodes.emplace_back(GetNextId(), "gegl:opacity", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_open_buffer() {
  s_Nodes.emplace_back(GetNextId(), "gegl:open-buffer", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_pack() {
  s_Nodes.emplace_back(GetNextId(), "gegl:pack", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "gap", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "align", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_panorama_projection() {
  s_Nodes.emplace_back(GetNextId(), "gegl:panorama-projection", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pan", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tilt", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "spin", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "zoom", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "inverse", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_path() {
  s_Nodes.emplace_back(GetNextId(), "gegl:path", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "stroke-width", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "stroke-opacity", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "stroke-hardness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "fill-rule", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "transform", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "fill-opacity", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_pdf_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:pdf-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "page", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pages", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "ppi", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "password", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_perlin_noise() {
  s_Nodes.emplace_back(GetNextId(), "gegl:perlin-noise", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "zoff", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "n", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_photocopy() {
  s_Nodes.emplace_back(GetNextId(), "gegl:photocopy", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "mask-radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "sharpness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "black", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "white", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_piecewise_blend() {
  s_Nodes.emplace_back(GetNextId(), "gegl:piecewise-blend", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux16", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux15", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux14", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux13", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux12", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux11", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux10", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux9", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux8", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux7", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux6", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux5", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux4", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux3", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux2", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux1", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "levels", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "gamma", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "linear-mask", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_pixbuf() {
  s_Nodes.emplace_back(GetNextId(), "gegl:pixbuf", ImColor(255, 128, 128));
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_pixelize() {
  s_Nodes.emplace_back(GetNextId(), "gegl:pixelize", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "size-x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "size-y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset-x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset-y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "ratio-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "ratio-y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_plasma() {
  s_Nodes.emplace_back(GetNextId(), "gegl:plasma", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "turbulence", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_png_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:png-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_png_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:png-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "compression", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bitdepth", PinType::INT);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_polar_coordinates() {
  s_Nodes.emplace_back(GetNextId(), "gegl:polar-coordinates", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "depth", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bw", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "top", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "polar", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pole-x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pole-y", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "middle", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_posterize() {
  s_Nodes.emplace_back(GetNextId(), "gegl:posterize", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "levels", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_ppm_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:ppm-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_ppm_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:ppm-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rawformat", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bitdepth", PinType::INT);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_radial_gradient() {
  s_Nodes.emplace_back(GetNextId(), "gegl:radial-gradient", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "start-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "start-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "end-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "end-y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_raw_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:raw-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "image-num", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "quality", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_rectangle() {
  s_Nodes.emplace_back(GetNextId(), "gegl:rectangle", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_recursive_transform() {
  s_Nodes.emplace_back(GetNextId(), "gegl:recursive-transform", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "transform", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "first-iteration", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "fade-opacity", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "paste-below", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_red_eye_removal() {
  s_Nodes.emplace_back(GetNextId(), "gegl:red-eye-removal", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_reflect() {
  s_Nodes.emplace_back(GetNextId(), "gegl:reflect", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_reinhard05() {
  s_Nodes.emplace_back(GetNextId(), "gegl:reinhard05", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "brightness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "chromatic", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "light", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_remap() {
  s_Nodes.emplace_back(GetNextId(), "gegl:remap", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux2", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_reset_origin() {
  s_Nodes.emplace_back(GetNextId(), "gegl:reset-origin", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_rgb_clip() {
  s_Nodes.emplace_back(GetNextId(), "gegl:rgb-clip", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clip-low", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "low-limit", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clip-high", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "high-limit", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_rgbe_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:rgbe-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_rgbe_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:rgbe-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_ripple() {
  s_Nodes.emplace_back(GetNextId(), "gegl:ripple", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amplitude", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "period", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "phi", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tileable", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_rotate() {
  s_Nodes.emplace_back(GetNextId(), "gegl:rotate", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "degrees", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_rotate_on_center() {
  s_Nodes.emplace_back(GetNextId(), "gegl:rotate-on-center", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "degrees", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_saturation() {
  s_Nodes.emplace_back(GetNextId(), "gegl:saturation", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_save_pixbuf() {
  s_Nodes.emplace_back(GetNextId(), "gegl:save-pixbuf", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_scale_ratio() {
  s_Nodes.emplace_back(GetNextId(), "gegl:scale-ratio", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_scale_size() {
  s_Nodes.emplace_back(GetNextId(), "gegl:scale-size", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_scale_size_keepaspect() {
  s_Nodes.emplace_back(GetNextId(), "gegl:scale-size-keepaspect", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_sdl2_display() {
  s_Nodes.emplace_back(GetNextId(), "gegl:sdl2-display", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "window-title", PinType::STRING);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_seamless_clone() {
  s_Nodes.emplace_back(GetNextId(), "gegl:seamless-clone", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "max-refine-scale", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "xoff", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "yoff", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "error-msg", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_seamless_clone_compose() {
  s_Nodes.emplace_back(GetNextId(), "gegl:seamless-clone-compose", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "max-refine-scale", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "xoff", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "yoff", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "error-msg", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_sepia() {
  s_Nodes.emplace_back(GetNextId(), "gegl:sepia", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_shadows_highlights() {
  s_Nodes.emplace_back(GetNextId(), "gegl:shadows-highlights", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shadows", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlights", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "whitepoint", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "compress", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shadows-ccorrect", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlights-ccorrect", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_shadows_highlights_correction() {
  s_Nodes.emplace_back(GetNextId(), "gegl:shadows-highlights-correction", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shadows", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlights", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "whitepoint", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "compress", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shadows-ccorrect", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "highlights-ccorrect", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_shear() {
  s_Nodes.emplace_back(GetNextId(), "gegl:shear", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_shift() {
  s_Nodes.emplace_back(GetNextId(), "gegl:shift", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "shift", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_simplex_noise() {
  s_Nodes.emplace_back(GetNextId(), "gegl:simplex-noise", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_sinus() {
  s_Nodes.emplace_back(GetNextId(), "gegl:sinus", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x-scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y-scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "complexity", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tiling", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "perturbation", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "blend-power", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_slic() {
  s_Nodes.emplace_back(GetNextId(), "gegl:slic", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "cluster-size", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "compactness", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_snn_mean() {
  s_Nodes.emplace_back(GetNextId(), "gegl:snn-mean", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pairs", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_soft_light() {
  s_Nodes.emplace_back(GetNextId(), "gegl:soft-light", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_softglow() {
  s_Nodes.emplace_back(GetNextId(), "gegl:softglow", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "glow-radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "brightness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "sharpness", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_spherize() {
  s_Nodes.emplace_back(GetNextId(), "gegl:spherize", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "angle-of-view", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "curvature", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amount", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_spiral() {
  s_Nodes.emplace_back(GetNextId(), "gegl:spiral", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "base", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "balance", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rotation", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_stereographic_projection() {
  s_Nodes.emplace_back(GetNextId(), "gegl:stereographic-projection", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pan", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tilt", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "spin", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "zoom", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "inverse", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_stress() {
  s_Nodes.emplace_back(GetNextId(), "gegl:stress", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "samples", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "iterations", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "enhance-shadows", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_stretch_contrast() {
  s_Nodes.emplace_back(GetNextId(), "gegl:stretch-contrast", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "keep-colors", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "perceptual", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_stretch_contrast_hsv() {
  s_Nodes.emplace_back(GetNextId(), "gegl:stretch-contrast-hsv", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_subtract() {
  s_Nodes.emplace_back(GetNextId(), "gegl:subtract", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_supernova() {
  s_Nodes.emplace_back(GetNextId(), "gegl:supernova", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "center-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "spokes-count", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "random-hue", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_svg_huerotate() {
  s_Nodes.emplace_back(GetNextId(), "gegl:svg-huerotate", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "values", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_svg_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:svg-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_svg_luminancetoalpha() {
  s_Nodes.emplace_back(GetNextId(), "gegl:svg-luminancetoalpha", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_svg_matrix() {
  s_Nodes.emplace_back(GetNextId(), "gegl:svg-matrix", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "values", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_svg_saturate() {
  s_Nodes.emplace_back(GetNextId(), "gegl:svg-saturate", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "values", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_text() {
  s_Nodes.emplace_back(GetNextId(), "gegl:text", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "string", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "font", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "size", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "wrap", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "vertical-wrap", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alignment", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "vertical-alignment", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_texturize_canvas() {
  s_Nodes.emplace_back(GetNextId(), "gegl:texturize-canvas", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "depth", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_threshold() {
  s_Nodes.emplace_back(GetNextId(), "gegl:threshold", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_tiff_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:tiff-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "directory", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_tiff_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:tiff-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bitdepth", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "fp", PinType::INT);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_tile() {
  s_Nodes.emplace_back(GetNextId(), "gegl:tile", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset-x", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "offset-y", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_tile_glass() {
  s_Nodes.emplace_back(GetNextId(), "gegl:tile-glass", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-height", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_tile_paper() {
  s_Nodes.emplace_back(GetNextId(), "gegl:tile-paper", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "tile-height", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "move-rate", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "wrap-around", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "centering", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_tile_seamless() {
  s_Nodes.emplace_back(GetNextId(), "gegl:tile-seamless", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_transform() {
  s_Nodes.emplace_back(GetNextId(), "gegl:transform", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "transform", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_translate() {
  s_Nodes.emplace_back(GetNextId(), "gegl:translate", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "origin-y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "near-z", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_unpremultiply() {
  s_Nodes.emplace_back(GetNextId(), "gegl:unpremultiply", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_unsharp_mask() {
  s_Nodes.emplace_back(GetNextId(), "gegl:unsharp-mask", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "std-dev", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "scale", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_v4l() {
  s_Nodes.emplace_back(GetNextId(), "gegl:v4l", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "height", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "frame", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "fps", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_value_invert() {
  s_Nodes.emplace_back(GetNextId(), "gegl:value-invert", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_value_propagate() {
  s_Nodes.emplace_back(GetNextId(), "gegl:value-propagate", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "lower-threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "upper-threshold", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rate", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "top", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "left", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "right", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "bottom", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "value", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "alpha", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_variable_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:variable-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "linear-mask", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "high-quality", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_vector_stroke() {
  s_Nodes.emplace_back(GetNextId(), "gegl:vector-stroke", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "width", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "opacity", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "transform", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_video_degradation() {
  s_Nodes.emplace_back(GetNextId(), "gegl:video-degradation", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "additive", PinType::BOOLEAN);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rotated", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_vignette() {
  s_Nodes.emplace_back(GetNextId(), "gegl:vignette", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "softness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "gamma", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "proportion", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "squeeze", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "rotation", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_warp() {
  s_Nodes.emplace_back(GetNextId(), "gegl:warp", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "strength", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "size", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "hardness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "spacing", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_waterpixels() {
  s_Nodes.emplace_back(GetNextId(), "gegl:waterpixels", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "size", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "smoothness", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "regularization", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_watershed_transform() {
  s_Nodes.emplace_back(GetNextId(), "gegl:watershed-transform", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "flag-component", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_wavelet_blur() {
  s_Nodes.emplace_back(GetNextId(), "gegl:wavelet-blur", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_wavelet_blur_1d() {
  s_Nodes.emplace_back(GetNextId(), "gegl:wavelet-blur-1d", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_waves() {
  s_Nodes.emplace_back(GetNextId(), "gegl:waves", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "x", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "y", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "amplitude", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "period", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "phi", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aspect", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "clamp", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_webp_load() {
  s_Nodes.emplace_back(GetNextId(), "gegl:webp-load", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "uri", PinType::STRING);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_webp_save() {
  s_Nodes.emplace_back(GetNextId(), "gegl:webp-save", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "path", PinType::STRING);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "quality", PinType::INT);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_weighted_blend() {
  s_Nodes.emplace_back(GetNextId(), "gegl:weighted-blend", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_whirl_pinch() {
  s_Nodes.emplace_back(GetNextId(), "gegl:whirl-pinch", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "whirl", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "pinch", PinType::DOUBLE);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "radius", PinType::DOUBLE);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_wind() {
  s_Nodes.emplace_back(GetNextId(), "gegl:wind", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "threshold", PinType::INT);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "strength", PinType::INT);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__gegl_write_buffer() {
  s_Nodes.emplace_back(GetNextId(), "gegl:write-buffer", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_clear() {
  s_Nodes.emplace_back(GetNextId(), "svg:clear", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_color_burn() {
  s_Nodes.emplace_back(GetNextId(), "svg:color-burn", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_color_dodge() {
  s_Nodes.emplace_back(GetNextId(), "svg:color-dodge", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_darken() {
  s_Nodes.emplace_back(GetNextId(), "svg:darken", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_difference() {
  s_Nodes.emplace_back(GetNextId(), "svg:difference", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_dst() {
  s_Nodes.emplace_back(GetNextId(), "svg:dst", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_dst_atop() {
  s_Nodes.emplace_back(GetNextId(), "svg:dst-atop", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_dst_in() {
  s_Nodes.emplace_back(GetNextId(), "svg:dst-in", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_dst_out() {
  s_Nodes.emplace_back(GetNextId(), "svg:dst-out", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_dst_over() {
  s_Nodes.emplace_back(GetNextId(), "svg:dst-over", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_exclusion() {
  s_Nodes.emplace_back(GetNextId(), "svg:exclusion", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_hard_light() {
  s_Nodes.emplace_back(GetNextId(), "svg:hard-light", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_lighten() {
  s_Nodes.emplace_back(GetNextId(), "svg:lighten", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_overlay() {
  s_Nodes.emplace_back(GetNextId(), "svg:overlay", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_plus() {
  s_Nodes.emplace_back(GetNextId(), "svg:plus", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_screen() {
  s_Nodes.emplace_back(GetNextId(), "svg:screen", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_src() {
  s_Nodes.emplace_back(GetNextId(), "svg:src", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_src_atop() {
  s_Nodes.emplace_back(GetNextId(), "svg:src-atop", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_src_in() {
  s_Nodes.emplace_back(GetNextId(), "svg:src-in", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_src_out() {
  s_Nodes.emplace_back(GetNextId(), "svg:src-out", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_src_over() {
  s_Nodes.emplace_back(GetNextId(), "svg:src-over", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

static Node* create_node__svg_xor() {
  s_Nodes.emplace_back(GetNextId(), "svg:xor", ImColor(255, 128, 128));
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "aux", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "input", PinType::GEGL_BUFFER);
  s_Nodes.back().Inputs.emplace_back(GetNextId(), "srgb", PinType::BOOLEAN);
  s_Nodes.back().Outputs.emplace_back(GetNextId(), "output", PinType::GEGL_BUFFER);
  BuildNode(&s_Nodes.back());
  return &s_Nodes.back();
}

#define IF_STRING_IS(string) if (strcmp(name, string) == 0)
static Node* create_node_by_name(char *name) {
  IF_STRING_IS("gegl:absolute") {
    return create_node__gegl_absolute();
  } else IF_STRING_IS("gegl:add") {
    return create_node__gegl_add();
  } else IF_STRING_IS("gegl:alien-map") {
    return create_node__gegl_alien_map();
  } else IF_STRING_IS("gegl:antialias") {
    return create_node__gegl_antialias();
  } else IF_STRING_IS("gegl:apply-lens") {
    return create_node__gegl_apply_lens();
  } else IF_STRING_IS("gegl:bayer-matrix") {
    return create_node__gegl_bayer_matrix();
  } else IF_STRING_IS("gegl:bilateral-filter") {
    return create_node__gegl_bilateral_filter();
  } else IF_STRING_IS("gegl:bloom") {
    return create_node__gegl_bloom();
  } else IF_STRING_IS("gegl:border-align") {
    return create_node__gegl_border_align();
  } else IF_STRING_IS("gegl:box-blur") {
    return create_node__gegl_box_blur();
  } else IF_STRING_IS("gegl:brightness-contrast") {
    return create_node__gegl_brightness_contrast();
  } else IF_STRING_IS("gegl:buffer-sink") {
    return create_node__gegl_buffer_sink();
  } else IF_STRING_IS("gegl:buffer-source") {
    return create_node__gegl_buffer_source();
  } else IF_STRING_IS("gegl:bump-map") {
    return create_node__gegl_bump_map();
  } else IF_STRING_IS("gegl:c2g") {
    return create_node__gegl_c2g();
  } else IF_STRING_IS("gegl:cache") {
    return create_node__gegl_cache();
  } else IF_STRING_IS("gegl:cartoon") {
    return create_node__gegl_cartoon();
  } else IF_STRING_IS("gegl:cast-format") {
    return create_node__gegl_cast_format();
  } else IF_STRING_IS("gegl:cast-space") {
    return create_node__gegl_cast_space();
  } else IF_STRING_IS("gegl:cell-noise") {
    return create_node__gegl_cell_noise();
  } else IF_STRING_IS("gegl:channel-mixer") {
    return create_node__gegl_channel_mixer();
  } else IF_STRING_IS("gegl:checkerboard") {
    return create_node__gegl_checkerboard();
  } else IF_STRING_IS("gegl:clone") {
    return create_node__gegl_clone();
  } else IF_STRING_IS("gegl:color") {
    return create_node__gegl_color();
  } else IF_STRING_IS("gegl:color-assimilation-grid") {
    return create_node__gegl_color_assimilation_grid();
  } else IF_STRING_IS("gegl:color-enhance") {
    return create_node__gegl_color_enhance();
  } else IF_STRING_IS("gegl:color-exchange") {
    return create_node__gegl_color_exchange();
  } else IF_STRING_IS("gegl:color-overlay") {
    return create_node__gegl_color_overlay();
  } else IF_STRING_IS("gegl:color-rotate") {
    return create_node__gegl_color_rotate();
  } else IF_STRING_IS("gegl:color-temperature") {
    return create_node__gegl_color_temperature();
  } else IF_STRING_IS("gegl:color-to-alpha") {
    return create_node__gegl_color_to_alpha();
  } else IF_STRING_IS("gegl:color-warp") {
    return create_node__gegl_color_warp();
  } else IF_STRING_IS("gegl:component-extract") {
    return create_node__gegl_component_extract();
  } else IF_STRING_IS("gegl:contrast-curve") {
    return create_node__gegl_contrast_curve();
  } else IF_STRING_IS("gegl:convert-format") {
    return create_node__gegl_convert_format();
  } else IF_STRING_IS("gegl:convert-space") {
    return create_node__gegl_convert_space();
  } else IF_STRING_IS("gegl:convolution-matrix") {
    return create_node__gegl_convolution_matrix();
  } else IF_STRING_IS("gegl:copy-buffer") {
    return create_node__gegl_copy_buffer();
  } else IF_STRING_IS("gegl:crop") {
    return create_node__gegl_crop();
  } else IF_STRING_IS("gegl:cubism") {
    return create_node__gegl_cubism();
  } else IF_STRING_IS("gegl:deinterlace") {
    return create_node__gegl_deinterlace();
  } else IF_STRING_IS("gegl:difference-of-gaussians") {
    return create_node__gegl_difference_of_gaussians();
  } else IF_STRING_IS("gegl:diffraction-patterns") {
    return create_node__gegl_diffraction_patterns();
  } else IF_STRING_IS("gegl:displace") {
    return create_node__gegl_displace();
  } else IF_STRING_IS("gegl:display") {
    return create_node__gegl_display();
  } else IF_STRING_IS("gegl:distance-transform") {
    return create_node__gegl_distance_transform();
  } else IF_STRING_IS("gegl:dither") {
    return create_node__gegl_dither();
  } else IF_STRING_IS("gegl:divide") {
    return create_node__gegl_divide();
  } else IF_STRING_IS("gegl:domain-transform") {
    return create_node__gegl_domain_transform();
  } else IF_STRING_IS("gegl:dropshadow") {
    return create_node__gegl_dropshadow();
  } else IF_STRING_IS("gegl:edge") {
    return create_node__gegl_edge();
  } else IF_STRING_IS("gegl:edge-laplace") {
    return create_node__gegl_edge_laplace();
  } else IF_STRING_IS("gegl:edge-neon") {
    return create_node__gegl_edge_neon();
  } else IF_STRING_IS("gegl:edge-sobel") {
    return create_node__gegl_edge_sobel();
  } else IF_STRING_IS("gegl:emboss") {
    return create_node__gegl_emboss();
  } else IF_STRING_IS("gegl:engrave") {
    return create_node__gegl_engrave();
  } else IF_STRING_IS("gegl:exp-combine") {
    return create_node__gegl_exp_combine();
  } else IF_STRING_IS("gegl:exposure") {
    return create_node__gegl_exposure();
  } else IF_STRING_IS("gegl:exr-load") {
    return create_node__gegl_exr_load();
  } else IF_STRING_IS("gegl:exr-save") {
    return create_node__gegl_exr_save();
  } else IF_STRING_IS("gegl:fattal02") {
    return create_node__gegl_fattal02();
  } else IF_STRING_IS("gegl:ff-load") {
    return create_node__gegl_ff_load();
  } else IF_STRING_IS("gegl:ff-save") {
    return create_node__gegl_ff_save();
  } else IF_STRING_IS("gegl:fill-path") {
    return create_node__gegl_fill_path();
  } else IF_STRING_IS("gegl:focus-blur") {
    return create_node__gegl_focus_blur();
  } else IF_STRING_IS("gegl:fractal-explorer") {
    return create_node__gegl_fractal_explorer();
  } else IF_STRING_IS("gegl:fractal-trace") {
    return create_node__gegl_fractal_trace();
  } else IF_STRING_IS("gegl:gamma") {
    return create_node__gegl_gamma();
  } else IF_STRING_IS("gegl:gaussian-blur") {
    return create_node__gegl_gaussian_blur();
  } else IF_STRING_IS("gegl:gaussian-blur-selective") {
    return create_node__gegl_gaussian_blur_selective();
  } else IF_STRING_IS("gegl:gblur-1d") {
    return create_node__gegl_gblur_1d();
  } else IF_STRING_IS("gegl:gegl") {
    return create_node__gegl_gegl();
  } else IF_STRING_IS("gegl:gegl-buffer-load") {
    return create_node__gegl_gegl_buffer_load();
  } else IF_STRING_IS("gegl:gegl-buffer-save") {
    return create_node__gegl_gegl_buffer_save();
  } else IF_STRING_IS("gegl:gif-load") {
    return create_node__gegl_gif_load();
  } else IF_STRING_IS("gegl:gray") {
    return create_node__gegl_gray();
  } else IF_STRING_IS("gegl:grid") {
    return create_node__gegl_grid();
  } else IF_STRING_IS("gegl:high-pass") {
    return create_node__gegl_high_pass();
  } else IF_STRING_IS("gegl:hue-chroma") {
    return create_node__gegl_hue_chroma();
  } else IF_STRING_IS("gegl:icc-load") {
    return create_node__gegl_icc_load();
  } else IF_STRING_IS("gegl:icc-save") {
    return create_node__gegl_icc_save();
  } else IF_STRING_IS("gegl:illusion") {
    return create_node__gegl_illusion();
  } else IF_STRING_IS("gegl:image-compare") {
    return create_node__gegl_image_compare();
  } else IF_STRING_IS("gegl:image-gradient") {
    return create_node__gegl_image_gradient();
  } else IF_STRING_IS("gegl:introspect") {
    return create_node__gegl_introspect();
  } else IF_STRING_IS("gegl:invert-gamma") {
    return create_node__gegl_invert_gamma();
  } else IF_STRING_IS("gegl:invert-linear") {
    return create_node__gegl_invert_linear();
  } else IF_STRING_IS("gegl:jp2-load") {
    return create_node__gegl_jp2_load();
  } else IF_STRING_IS("gegl:jpg-load") {
    return create_node__gegl_jpg_load();
  } else IF_STRING_IS("gegl:jpg-save") {
    return create_node__gegl_jpg_save();
  } else IF_STRING_IS("gegl:json:dropshadow2") {
    return create_node__gegl_json_dropshadow2();
  } else IF_STRING_IS("gegl:json:grey2") {
    return create_node__gegl_json_grey2();
  } else IF_STRING_IS("gegl:layer") {
    return create_node__gegl_layer();
  } else IF_STRING_IS("gegl:lcms-from-profile") {
    return create_node__gegl_lcms_from_profile();
  } else IF_STRING_IS("gegl:lens-blur") {
    return create_node__gegl_lens_blur();
  } else IF_STRING_IS("gegl:lens-distortion") {
    return create_node__gegl_lens_distortion();
  } else IF_STRING_IS("gegl:lens-flare") {
    return create_node__gegl_lens_flare();
  } else IF_STRING_IS("gegl:levels") {
    return create_node__gegl_levels();
  } else IF_STRING_IS("gegl:linear-gradient") {
    return create_node__gegl_linear_gradient();
  } else IF_STRING_IS("gegl:linear-sinusoid") {
    return create_node__gegl_linear_sinusoid();
  } else IF_STRING_IS("gegl:load") {
    return create_node__gegl_load();
  } else IF_STRING_IS("gegl:long-shadow") {
    return create_node__gegl_long_shadow();
  } else IF_STRING_IS("gegl:magick-load") {
    return create_node__gegl_magick_load();
  } else IF_STRING_IS("gegl:mantiuk06") {
    return create_node__gegl_mantiuk06();
  } else IF_STRING_IS("gegl:map-absolute") {
    return create_node__gegl_map_absolute();
  } else IF_STRING_IS("gegl:map-relative") {
    return create_node__gegl_map_relative();
  } else IF_STRING_IS("gegl:matting-global") {
    return create_node__gegl_matting_global();
  } else IF_STRING_IS("gegl:matting-levin") {
    return create_node__gegl_matting_levin();
  } else IF_STRING_IS("gegl:maze") {
    return create_node__gegl_maze();
  } else IF_STRING_IS("gegl:mblur") {
    return create_node__gegl_mblur();
  } else IF_STRING_IS("gegl:mean-curvature-blur") {
    return create_node__gegl_mean_curvature_blur();
  } else IF_STRING_IS("gegl:median-blur") {
    return create_node__gegl_median_blur();
  } else IF_STRING_IS("gegl:mirrors") {
    return create_node__gegl_mirrors();
  } else IF_STRING_IS("gegl:mix") {
    return create_node__gegl_mix();
  } else IF_STRING_IS("gegl:mono-mixer") {
    return create_node__gegl_mono_mixer();
  } else IF_STRING_IS("gegl:mosaic") {
    return create_node__gegl_mosaic();
  } else IF_STRING_IS("gegl:motion-blur-circular") {
    return create_node__gegl_motion_blur_circular();
  } else IF_STRING_IS("gegl:motion-blur-linear") {
    return create_node__gegl_motion_blur_linear();
  } else IF_STRING_IS("gegl:motion-blur-zoom") {
    return create_node__gegl_motion_blur_zoom();
  } else IF_STRING_IS("gegl:multiply") {
    return create_node__gegl_multiply();
  } else IF_STRING_IS("gegl:negative-darkroom") {
    return create_node__gegl_negative_darkroom();
  } else IF_STRING_IS("gegl:newsprint") {
    return create_node__gegl_newsprint();
  } else IF_STRING_IS("gegl:noise-cie-lch") {
    return create_node__gegl_noise_cie_lch();
  } else IF_STRING_IS("gegl:noise-hsv") {
    return create_node__gegl_noise_hsv();
  } else IF_STRING_IS("gegl:noise-hurl") {
    return create_node__gegl_noise_hurl();
  } else IF_STRING_IS("gegl:noise-pick") {
    return create_node__gegl_noise_pick();
  } else IF_STRING_IS("gegl:noise-reduction") {
    return create_node__gegl_noise_reduction();
  } else IF_STRING_IS("gegl:noise-rgb") {
    return create_node__gegl_noise_rgb();
  } else IF_STRING_IS("gegl:noise-slur") {
    return create_node__gegl_noise_slur();
  } else IF_STRING_IS("gegl:noise-solid") {
    return create_node__gegl_noise_solid();
  } else IF_STRING_IS("gegl:noise-spread") {
    return create_node__gegl_noise_spread();
  } else IF_STRING_IS("gegl:nop") {
    return create_node__gegl_nop();
  } else IF_STRING_IS("gegl:normal-map") {
    return create_node__gegl_normal_map();
  } else IF_STRING_IS("gegl:npd") {
    return create_node__gegl_npd();
  } else IF_STRING_IS("gegl:npy-save") {
    return create_node__gegl_npy_save();
  } else IF_STRING_IS("gegl:oilify") {
    return create_node__gegl_oilify();
  } else IF_STRING_IS("gegl:opacity") {
    return create_node__gegl_opacity();
  } else IF_STRING_IS("gegl:open-buffer") {
    return create_node__gegl_open_buffer();
  } else IF_STRING_IS("gegl:pack") {
    return create_node__gegl_pack();
  } else IF_STRING_IS("gegl:panorama-projection") {
    return create_node__gegl_panorama_projection();
  } else IF_STRING_IS("gegl:path") {
    return create_node__gegl_path();
  } else IF_STRING_IS("gegl:pdf-load") {
    return create_node__gegl_pdf_load();
  } else IF_STRING_IS("gegl:perlin-noise") {
    return create_node__gegl_perlin_noise();
  } else IF_STRING_IS("gegl:photocopy") {
    return create_node__gegl_photocopy();
  } else IF_STRING_IS("gegl:piecewise-blend") {
    return create_node__gegl_piecewise_blend();
  } else IF_STRING_IS("gegl:pixbuf") {
    return create_node__gegl_pixbuf();
  } else IF_STRING_IS("gegl:pixelize") {
    return create_node__gegl_pixelize();
  } else IF_STRING_IS("gegl:plasma") {
    return create_node__gegl_plasma();
  } else IF_STRING_IS("gegl:png-load") {
    return create_node__gegl_png_load();
  } else IF_STRING_IS("gegl:png-save") {
    return create_node__gegl_png_save();
  } else IF_STRING_IS("gegl:polar-coordinates") {
    return create_node__gegl_polar_coordinates();
  } else IF_STRING_IS("gegl:posterize") {
    return create_node__gegl_posterize();
  } else IF_STRING_IS("gegl:ppm-load") {
    return create_node__gegl_ppm_load();
  } else IF_STRING_IS("gegl:ppm-save") {
    return create_node__gegl_ppm_save();
  } else IF_STRING_IS("gegl:radial-gradient") {
    return create_node__gegl_radial_gradient();
  } else IF_STRING_IS("gegl:raw-load") {
    return create_node__gegl_raw_load();
  } else IF_STRING_IS("gegl:rectangle") {
    return create_node__gegl_rectangle();
  } else IF_STRING_IS("gegl:recursive-transform") {
    return create_node__gegl_recursive_transform();
  } else IF_STRING_IS("gegl:red-eye-removal") {
    return create_node__gegl_red_eye_removal();
  } else IF_STRING_IS("gegl:reflect") {
    return create_node__gegl_reflect();
  } else IF_STRING_IS("gegl:reinhard05") {
    return create_node__gegl_reinhard05();
  } else IF_STRING_IS("gegl:remap") {
    return create_node__gegl_remap();
  } else IF_STRING_IS("gegl:reset-origin") {
    return create_node__gegl_reset_origin();
  } else IF_STRING_IS("gegl:rgb-clip") {
    return create_node__gegl_rgb_clip();
  } else IF_STRING_IS("gegl:rgbe-load") {
    return create_node__gegl_rgbe_load();
  } else IF_STRING_IS("gegl:rgbe-save") {
    return create_node__gegl_rgbe_save();
  } else IF_STRING_IS("gegl:ripple") {
    return create_node__gegl_ripple();
  } else IF_STRING_IS("gegl:rotate") {
    return create_node__gegl_rotate();
  } else IF_STRING_IS("gegl:rotate-on-center") {
    return create_node__gegl_rotate_on_center();
  } else IF_STRING_IS("gegl:saturation") {
    return create_node__gegl_saturation();
  } else IF_STRING_IS("gegl:save") {
    return create_node__gegl_save();
  } else IF_STRING_IS("gegl:save-pixbuf") {
    return create_node__gegl_save_pixbuf();
  } else IF_STRING_IS("gegl:scale-ratio") {
    return create_node__gegl_scale_ratio();
  } else IF_STRING_IS("gegl:scale-size") {
    return create_node__gegl_scale_size();
  } else IF_STRING_IS("gegl:scale-size-keepaspect") {
    return create_node__gegl_scale_size_keepaspect();
  } else IF_STRING_IS("gegl:sdl2-display") {
    return create_node__gegl_sdl2_display();
  } else IF_STRING_IS("gegl:seamless-clone") {
    return create_node__gegl_seamless_clone();
  } else IF_STRING_IS("gegl:seamless-clone-compose") {
    return create_node__gegl_seamless_clone_compose();
  } else IF_STRING_IS("gegl:sepia") {
    return create_node__gegl_sepia();
  } else IF_STRING_IS("gegl:shadows-highlights") {
    return create_node__gegl_shadows_highlights();
  } else IF_STRING_IS("gegl:shadows-highlights-correction") {
    return create_node__gegl_shadows_highlights_correction();
  } else IF_STRING_IS("gegl:shear") {
    return create_node__gegl_shear();
  } else IF_STRING_IS("gegl:shift") {
    return create_node__gegl_shift();
  } else IF_STRING_IS("gegl:simplex-noise") {
    return create_node__gegl_simplex_noise();
  } else IF_STRING_IS("gegl:sinus") {
    return create_node__gegl_sinus();
  } else IF_STRING_IS("gegl:slic") {
    return create_node__gegl_slic();
  } else IF_STRING_IS("gegl:snn-mean") {
    return create_node__gegl_snn_mean();
  } else IF_STRING_IS("gegl:soft-light") {
    return create_node__gegl_soft_light();
  } else IF_STRING_IS("gegl:softglow") {
    return create_node__gegl_softglow();
  } else IF_STRING_IS("gegl:spherize") {
    return create_node__gegl_spherize();
  } else IF_STRING_IS("gegl:spiral") {
    return create_node__gegl_spiral();
  } else IF_STRING_IS("gegl:stereographic-projection") {
    return create_node__gegl_stereographic_projection();
  } else IF_STRING_IS("gegl:stress") {
    return create_node__gegl_stress();
  } else IF_STRING_IS("gegl:stretch-contrast") {
    return create_node__gegl_stretch_contrast();
  } else IF_STRING_IS("gegl:stretch-contrast-hsv") {
    return create_node__gegl_stretch_contrast_hsv();
  } else IF_STRING_IS("gegl:subtract") {
    return create_node__gegl_subtract();
  } else IF_STRING_IS("gegl:supernova") {
    return create_node__gegl_supernova();
  } else IF_STRING_IS("gegl:svg-huerotate") {
    return create_node__gegl_svg_huerotate();
  } else IF_STRING_IS("gegl:svg-load") {
    return create_node__gegl_svg_load();
  } else IF_STRING_IS("gegl:svg-luminancetoalpha") {
    return create_node__gegl_svg_luminancetoalpha();
  } else IF_STRING_IS("gegl:svg-matrix") {
    return create_node__gegl_svg_matrix();
  } else IF_STRING_IS("gegl:svg-saturate") {
    return create_node__gegl_svg_saturate();
  } else IF_STRING_IS("gegl:text") {
    return create_node__gegl_text();
  } else IF_STRING_IS("gegl:texturize-canvas") {
    return create_node__gegl_texturize_canvas();
  } else IF_STRING_IS("gegl:threshold") {
    return create_node__gegl_threshold();
  } else IF_STRING_IS("gegl:tiff-load") {
    return create_node__gegl_tiff_load();
  } else IF_STRING_IS("gegl:tiff-save") {
    return create_node__gegl_tiff_save();
  } else IF_STRING_IS("gegl:tile") {
    return create_node__gegl_tile();
  } else IF_STRING_IS("gegl:tile-glass") {
    return create_node__gegl_tile_glass();
  } else IF_STRING_IS("gegl:tile-paper") {
    return create_node__gegl_tile_paper();
  } else IF_STRING_IS("gegl:tile-seamless") {
    return create_node__gegl_tile_seamless();
  } else IF_STRING_IS("gegl:transform") {
    return create_node__gegl_transform();
  } else IF_STRING_IS("gegl:translate") {
    return create_node__gegl_translate();
  } else IF_STRING_IS("gegl:unpremultiply") {
    return create_node__gegl_unpremultiply();
  } else IF_STRING_IS("gegl:unsharp-mask") {
    return create_node__gegl_unsharp_mask();
  } else IF_STRING_IS("gegl:v4l") {
    return create_node__gegl_v4l();
  } else IF_STRING_IS("gegl:value-invert") {
    return create_node__gegl_value_invert();
  } else IF_STRING_IS("gegl:value-propagate") {
    return create_node__gegl_value_propagate();
  } else IF_STRING_IS("gegl:variable-blur") {
    return create_node__gegl_variable_blur();
  } else IF_STRING_IS("gegl:vector-stroke") {
    return create_node__gegl_vector_stroke();
  } else IF_STRING_IS("gegl:video-degradation") {
    return create_node__gegl_video_degradation();
  } else IF_STRING_IS("gegl:vignette") {
    return create_node__gegl_vignette();
  } else IF_STRING_IS("gegl:warp") {
    return create_node__gegl_warp();
  } else IF_STRING_IS("gegl:waterpixels") {
    return create_node__gegl_waterpixels();
  } else IF_STRING_IS("gegl:watershed-transform") {
    return create_node__gegl_watershed_transform();
  } else IF_STRING_IS("gegl:wavelet-blur") {
    return create_node__gegl_wavelet_blur();
  } else IF_STRING_IS("gegl:wavelet-blur-1d") {
    return create_node__gegl_wavelet_blur_1d();
  } else IF_STRING_IS("gegl:waves") {
    return create_node__gegl_waves();
  } else IF_STRING_IS("gegl:webp-load") {
    return create_node__gegl_webp_load();
  } else IF_STRING_IS("gegl:webp-save") {
    return create_node__gegl_webp_save();
  } else IF_STRING_IS("gegl:weighted-blend") {
    return create_node__gegl_weighted_blend();
  } else IF_STRING_IS("gegl:whirl-pinch") {
    return create_node__gegl_whirl_pinch();
  } else IF_STRING_IS("gegl:wind") {
    return create_node__gegl_wind();
  } else IF_STRING_IS("gegl:write-buffer") {
    return create_node__gegl_write_buffer();
  } else IF_STRING_IS("svg:clear") {
    return create_node__svg_clear();
  } else IF_STRING_IS("svg:color-burn") {
    return create_node__svg_color_burn();
  } else IF_STRING_IS("svg:color-dodge") {
    return create_node__svg_color_dodge();
  } else IF_STRING_IS("svg:darken") {
    return create_node__svg_darken();
  } else IF_STRING_IS("svg:difference") {
    return create_node__svg_difference();
  } else IF_STRING_IS("svg:dst") {
    return create_node__svg_dst();
  } else IF_STRING_IS("svg:dst-atop") {
    return create_node__svg_dst_atop();
  } else IF_STRING_IS("svg:dst-in") {
    return create_node__svg_dst_in();
  } else IF_STRING_IS("svg:dst-out") {
    return create_node__svg_dst_out();
  } else IF_STRING_IS("svg:dst-over") {
    return create_node__svg_dst_over();
  } else IF_STRING_IS("svg:exclusion") {
    return create_node__svg_exclusion();
  } else IF_STRING_IS("svg:hard-light") {
    return create_node__svg_hard_light();
  } else IF_STRING_IS("svg:lighten") {
    return create_node__svg_lighten();
  } else IF_STRING_IS("svg:overlay") {
    return create_node__svg_overlay();
  } else IF_STRING_IS("svg:plus") {
    return create_node__svg_plus();
  } else IF_STRING_IS("svg:screen") {
    return create_node__svg_screen();
  } else IF_STRING_IS("svg:src") {
    return create_node__svg_src();
  } else IF_STRING_IS("svg:src-atop") {
    return create_node__svg_src_atop();
  } else IF_STRING_IS("svg:src-in") {
    return create_node__svg_src_in();
  } else IF_STRING_IS("svg:src-out") {
    return create_node__svg_src_out();
  } else IF_STRING_IS("svg:src-over") {
    return create_node__svg_src_over();
  } else IF_STRING_IS("svg:xor") {
    return create_node__svg_xor();
  } else {
    fprintf(stderr, "ERROR: unrecognized operation name %s", name);
    return NULL;
  }
}
