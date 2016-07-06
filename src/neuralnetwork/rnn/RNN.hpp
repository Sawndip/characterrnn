
#pragma once

#include "../../common/Common.hpp"
#include "../../math/Math.hpp"
#include "../SamplesProvider.hpp"
#include "RNNSpec.hpp"

namespace neuralnetwork {
namespace rnn {

class RNN {
public:
  RNN(const RNNSpec &spec);
  virtual ~RNN();

  void ClearMemory(void);
  EVector Process(const EVector &input);
  void Update(const SamplesProvider &samplesProvider);

private:
  struct RNNImpl;
  uptr<RNNImpl> impl;
};
}
}
