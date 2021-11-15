// Copyright 2017-2019, Nicholas Sharp and the Polyscope contributors. http://polyscope.run.
#pragma once

#include "polyscope/render/engine.h"
#include "polyscope/scalar_quantity.h"


#include <string>
#include <vector>


namespace polyscope {

class ImageColorArtist {

public:
  // ImageColorArtist(, DataType dataType);
  ImageColorArtist(std::string displayName, size_t dimX, size_t dimY, const std::vector<glm::vec4>& data);

  // An alternate constructor which bypasses the float array and just reads directly from the texture. Limits will be
  // set arbitrarily. This is a bit of a hack, and mainly used for visualizing internal rendering buffers.
  // ImageColorArtist(std::string name, std::shared_ptr<render::TextureBuffer>& texturebuffer, size_t dimX, size_t
  // dimY);

  void renderSource();      // (re-)render the data to the internal texture
  void showFullscreen();    // render the image fullscreen
  void showInImGuiWindow(); // build a floating imgui window showing the texture
  void refresh();           // clear out and reinitialze

  const std::string displayName;
  const size_t dimX, dimY;
  const std::vector<glm::vec4> data;
  const bool readFromTex = false; // hack to also support pulling directly from a texture


  // === Get/set visualization parameters


private:
  // UI internals
  std::shared_ptr<render::TextureBuffer> textureRaw, textureRendered;
  std::shared_ptr<render::FrameBuffer> framebuffer;
  std::shared_ptr<render::ShaderProgram> sourceProgram, fullscreenProgram;

  void prepare();
  void prepareSource();
};

} // namespace polyscope
